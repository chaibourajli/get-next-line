/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 13:34:42 by cbourajl          #+#    #+#             */
/*   Updated: 2022/01/08 16:42:40 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	while (str[j] != '\0' && str[j] != '\n')
	{
		res[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
	{
		res[j] = str[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*next_line(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!res)
		return (NULL);
	i++;
	while (str[i] != '\0')
		res[j++] = str[i++];
	res[j] = '\0';
	free (str);
	return (res);
}

char	*read_line(int fd, char *str)
{
	char	*buffer;
	ssize_t	rd_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd_bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = next_line(str);
	return (line);
}
