/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:16:43 by yumaohno          #+#    #+#             */
/*   Updated: 2022/12/17 16:50:03 by rnaka            ###   ########.fr       */
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

static char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char	*ft_readline(int fd, char **line, char *buf, ssize_t *read_size)
{
	char		*tmp;
	while (1)
	{
		tmp = ft_strjoin(*line, buf);
		free(*line);
		// if (!tmp)
		// 	return (NULL);
		*line = tmp;
		if (ft_strchr(*line, '\n'))
			return (*line);
		*read_size = read(fd, buf, BUFFER_SIZE);
		// if (*read_size == -1)
		// 	return (ft_free(line));
		buf[*read_size] = '\0';//NULL止め
		// if (*read_size == 0 && *line[0] == '\0')
		// 	return (ft_free(line));
		// if (*read_size == 0)
		// 	return (*line);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	ssize_t		read_size;
	static char	buf[BUFFER_SIZE + 1ul];
	char		*line;
	char		*tmp;
	char		*new_line_ptr;

	// if (fd < 0 || BUFFER_SIZE <= 0)
	// 	return (NULL);
	line = ft_strdup("");
	// if (!line)
	// 	return (NULL);
	// if (!ft_readline(fd, &line, buf, &read_size))
	// 	return (NULL);
	// if (!read_size)
	//	return (line);
	// new_line_ptr = ft_strchr(line, '\n');
	ft_memmove(buf, new_line_ptr + 1, ft_strlen(new_line_ptr));
	tmp = ft_substr(line, 0, (new_line_ptr + 1) - line);
	free(line);
	if (!tmp)
		return (NULL);
	line = tmp;
	return (line);
}

/* 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
			break ;
		free(line);
	}
	free(line);
	close(fd);
	system("leaks a.out");
	return (0);
}
 */
