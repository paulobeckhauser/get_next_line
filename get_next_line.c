/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:00:01 by pabeckha          #+#    #+#             */
/*   Updated: 2023/12/08 19:16:53 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *store)
{
	char	*buffer;
	char	*temp;
	int		read_bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(store, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), free(store), NULL);
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(store, buffer);
		free(store);
		store = temp;
	}
	return (free(buffer), store);
}

char	*ft_line(char *store, int i)
{
	char	*str;

	if (!store[i])
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\n')
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
	{
		str[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
	{
		str[i] = store[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_save_string(char *store)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i])
		return (free(store), NULL);
	str = malloc((ft_strlen(store) - i + 1) * sizeof(char));
	if (!str)
		return (free(store), NULL);
	i++;
	j = 0;
	while (store[i])
		str[j++] = store[i++];
	str[j] = '\0';
	return (free(store), str);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!store)
		store = ft_strdup("");
	store = ft_read(fd, store);
	if (!store)
		return (NULL);
	line = ft_line(store, i);
	store = ft_save_string(store);
	return (line);
}
