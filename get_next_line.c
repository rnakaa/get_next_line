/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:33:56 by rnaka             #+#    #+#             */
/*   Updated: 2022/12/17 19:07:12 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

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

static int ft_strlib(char **c)
{
	free(*c);
	*c = NULL;
	return (NULL);
}

static char *ft_read_line(int fd,char *buf, char **re_line)
{
	char *connect;
	size_t n;
	
	while (1)
	{	
		connect = ft_strjoin(buf, *re_line);
		if (connect == NULL)
			return NULL;
		ft_strlib(*re_line);
		*re_line = connect;
		
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (ft_strlib(re_line));
		if (n < BUFFER_SIZE)
			return(n);
		if (!ft_strchr(*re_line,'\n'))
			return (n);

	}
}









char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1UL];
	char *re_line;
	size_t n;
	char *p;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	re_line = ft_strdup("");
	if (re_line == NULL)
		return (NULL);
	n = ft_read_line(fd, &buf, &re_line);
	if (n == NULL)
		return NULL;
	p = ft_strchr(buf, '\n');
	printf("8");
	if (!n)
	{
		n = ft_strlen(p);	
		ft_memmove(buf,p,ft_strlen(p));
	}
	p = ft_substr(re_line,0,ft_strlen(p)-n);
	free(re_line);
	
	
	return(re_line);
}










int main()
{
	static char aaa[10];
	int fd = open("nnn.txt",O_RDONLY);
	int a = 3;

	// while (a != 0)
	// {
	// 	a--;
		printf("%s",get_next_line(fd));
	// }
		
	return 0;
}



