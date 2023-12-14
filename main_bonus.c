/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:59:00 by pabeckha          #+#    #+#             */
/*   Updated: 2023/12/14 13:42:19 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;
	int		count_1;
	int		count_2;
	int		count_3;

	fd1 = open("text_1.txt", O_RDONLY);
	// fd2 = open("text_2.txt", O_RDONLY);
	// fd3 = open("lines_around_10.txt", O_RDONLY);
	count_1 = 0;
	// count_2 = 0;
	// count_3 = 0;
	if (fd1 == -1)
	{
		printf("Error opening files");
		return (1);
	}
	while (1)
	{
		close(fd1);
		line = get_next_line(fd1);
		if (line == NULL)
			break ;
		count_1++;
		printf("[%d]: %s\n", count_1, line);
		free(line);
		// line = get_next_line(fd2);
		// if (line == NULL)
		// 	break ;
		// count_2++;
		// printf("[%d]: %s\n", count_2, line);
		// free(line);
		// line = get_next_line(fd3);
		// if (line == NULL)
		// 	break ;
		// count_3++;
		// printf("[%d]: %s\n", count_3, line);
		// free(line);
	}
	free(line);
	close(fd1);
	// close(fd2);
	// close(fd3);
	return (0);
}
