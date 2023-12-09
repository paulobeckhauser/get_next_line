/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:00:03 by pabeckha          #+#    #+#             */
/*   Updated: 2023/12/09 15:20:19 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef	BUFFER_SIZE
#define BUFFER_SIZE 3
#endif

# include <stdlib.h> // malloc function
# include <unistd.h> // read function

void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);

#endif