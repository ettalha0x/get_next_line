/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:51:44 by nettalha          #+#    #+#             */
/*   Updated: 2023/01/02 11:02:34 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd0;
	int	fd1;

	fd0 = open("../test0.txt", O_RDONLY);
	fd1 = open("../test1.txt", O_RDONLY);
	printf("%s", get_next_line(fd0));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd0));
	printf("%s", get_next_line(fd1));
}
