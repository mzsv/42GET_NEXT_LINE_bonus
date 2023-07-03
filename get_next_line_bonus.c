/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:28:03 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/24 07:02:56 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_emptypocket(char **pocket)
{
	if (*pocket != NULL && !ft_findchr(*pocket, '\0'))
	{
		free(*pocket);
		*pocket = NULL;
	}
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*pocket[FD_MAX];
	char			*l;
	ssize_t			n;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > FD_MAX)
		return (NULL);
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	n = 1;
	while (n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n >= 0)
			buffer[n] = '\0';
		else
			buffer[0] = '\0';
		pocket[fd] = ft_strjoinfree(pocket[fd], buffer);
		l = ft_getl(pocket[fd], &n);
		pocket[fd] = ft_fillpocket(pocket[fd], &n);
	}
	ft_emptypocket(&pocket[fd]);
	free(buffer);
	return (l);
}
/* int main(int argc, char **argv)
{
	int fd;
    int fd1;
	char *line;
	size_t i;

	(void)argc;
	(void)argv;
	if (argc > 1)
	{
		fd = open(argv[1], 00);
        fd1 = open(argv[2], 00);
		i = 0;
		while (i < 7)
		{
			line = get_next_line(fd);
			printf("result(%ld)=.%s.\n", i, line);
			free(line);
			line = get_next_line(fd1);
			printf("result(%ld)=.%s.\n", i, line);
			free(line);
			i++;
		}
		close(fd);
        close(fd1);
	}
	else
	{
		fd = 0;
		i = 0;
		line = get_next_line(fd);
		printf("result(%ld)=.%s.", i, line);
		free(line);
	}
	return (0);
} */