/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:28:23 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/24 19:45:15 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 10000
# endif

char	*get_next_line(int fd);
size_t	ft_findchr(char *s, char c);
char	*ft_strjoinfree(char *s1, char *s2);
char	*ft_substrfree(char *s, unsigned int start, size_t len, int f);
char	*ft_getl(char *pocket, ssize_t	*n);
char	*ft_fillpocket(char *pocket, ssize_t *n);

#endif