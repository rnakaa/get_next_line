/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:33:56 by rnaka             #+#    #+#             */
/*   Updated: 2022/12/20 17:56:03 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

static ssize_t	*ft_strlib(char **c)
{
	free(*c);
	*c = NULL;
	return (NULL);
}

static ssize_t	*ft_read_line(int fd, char *buf, char **re_line, ssize_t *n)
{
	char	*connect;

	*n = 1;
	while (1)
	{
		connect = ft_strjoin(*re_line, buf);
		free(*re_line);
		if (connect == NULL)
			break ;
		*re_line = connect;
		if (ft_strchr(*re_line, '\n'))
			return (n);
		*n = read(fd, buf, BUFFER_SIZE);
		if (*n == -1)
			return (ft_strlib(re_line));
		buf[*n] = '\0';
		if (*n == 0)
		{
			if (*re_line[0] == '\0')
				return (ft_strlib(re_line));
			return (n);
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1UL];
	ssize_t		n;
	char		*re_line;
	char		*p;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	re_line = ft_strdup("");
	if (re_line == NULL)
		return (NULL);
	if (!ft_read_line(fd, buf, &re_line, &n))
		return (NULL);
	if (n == 0)
		return (re_line);
	ft_memmove(buf, ft_strchr(re_line, '\n') + 1, ft_strlen(ft_strchr(re_line,
				'\n')));
	p = ft_substr(re_line, 0, ft_strlen(re_line) - ft_strlen(ft_strchr(re_line,
					'\n')) + 1);
	ft_strlib(&re_line);
	re_line = p;
	return (re_line);
}

int	main(int argc, const char *argv[])
{
	int		fd;
	char	*a;

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{
		a = get_next_line(fd);
		printf("%s", a);
		if (!a)
			break ;
		free(a);
	}
	free(a);
	return (0);
}
