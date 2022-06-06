/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:35:26 by cbourajl          #+#    #+#             */
/*   Updated: 2022/01/08 18:32:23 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *first, char *second)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!first)
	{
		first = (char *)malloc(1 * sizeof(char));
		first[0] = '\0';
	}
	if (!first || !second)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(first) + ft_strlen(second) + 1));
	if (!res)
		return (NULL);
	i = -1;
	if (first)
		while (first[++i] != '\0')
			res[i] = first[i];
	j = 0;
	while (second[j] != '\0')
		res[i++] = second[j++];
	res[ft_strlen(first) + ft_strlen(second)] = '\0';
	free (first);
	return (res);
}
