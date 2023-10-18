/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:33:05 by dcandan           #+#    #+#             */
/*   Updated: 2022/11/24 13:33:05 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	ft_bzero3(void *s, size_t n);
size_t	ft_strlen3(const char *str);
void	*ft_calloc3(size_t count, size_t size);
char	*ft_strjoin3(char *s1, char *s2);
char	*ft_strchr3(const char *s, int c);

char	*get_next_line(int fd);

#endif