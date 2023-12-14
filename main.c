/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:59:00 by pabeckha          #+#    #+#             */
/*   Updated: 2023/12/13 16:28:56 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" //malloc(ft_calloc) and read functions
#include <fcntl.h>         //open function
#include <stdio.h>         //printf function

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("lines_around_10.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening File!");
		return (1);
	}
	while (1)
	{
		next_line = get_next_line(3);
		if (next_line == NULL)
			break ;
		count++;
		printf("[%d]: %s\n", count, next_line);
		free(next_line);
	}
	close(fd);
	return (0);
}
