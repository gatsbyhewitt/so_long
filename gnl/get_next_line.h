/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abestaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 08:36:50 by abestaev          #+#    #+#             */
/*   Updated: 2021/12/08 10:40:40 by abestaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

size_t	ft_strlen_gnl(char *str);
int		ft_find_newline(char *str);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_substr_free(char *s, unsigned int start, int len, int free_s);
char	*get_next_line(int fd);

#endif
