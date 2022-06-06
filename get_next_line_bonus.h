/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:35:34 by cbourajl          #+#    #+#             */
/*   Updated: 2022/01/07 13:35:36 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

size_t	ft_strlen(char *s);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *first, char *second);
char	*get_line(char *str);
char	*next_line(char *str);
char	*read_line(int fd, char *str);
char	*get_next_line(int fd);

#endif
