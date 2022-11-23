/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:20:25 by nettalha          #+#    #+#             */
/*   Updated: 2022/10/31 20:25:59 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *container)
{
	char	*buff;
	int		readed;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	readed = 1;
	while (!ft_strchr(container, '\n') && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buff);
			free(container);
			return (NULL);
		}
		buff[readed] = '\0';
		container = ft_strjoin(container, buff);
	}
	free(buff);
	return (container);
}

char	*ft_get_line(char *container)
{
	int		i;
	char	*s;

	i = 0;
	if (!container[i])
		return (NULL);
	while (container[i] && container[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (container[i] && container[i] != '\n')
	{
		s[i] = container[i];
		i++;
	}
	if (container[i] == '\n')
	{
		s[i] = container[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_clean(char *container)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (container[i] && container[i] != '\n')
		i++;
	if (!container[i])
	{
		free(container);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen(container) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (container[i])
		s[j++] = container[i++];
	s[j] = '\0';
	free(container);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*container[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	container[fd] = ft_read(fd, container[fd]);
	if (!container[fd])
		return (NULL);
	line = ft_get_line(container[fd]);
	container[fd] = ft_clean(container[fd]);
	return (line);
}
