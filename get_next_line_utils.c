/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:10:21 by rnaka             #+#    #+#             */
/*   Updated: 2022/12/17 18:54:19 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

void	*ft_memmove(void *b1, const void *b2, size_t n)
{
	size_t		i;
	char		*buf1;
	const char	*buf2;

	buf2 = b2;
	if (b1 == b2 || n == 0)
		return (b1);
	buf1 = b1;
	i = 0;
	if (buf1 < buf2)
	{
		while (i < n)
		{
			buf1[i] = buf2[i];
			i++;
		}
	}
	else if (buf1 > buf2)
		while (i < n--)
			buf1[n] = buf2[n];
	return (buf1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*re;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) < (size_t)start)
		return (ft_strdup(""));
	if (ft_strlen(s) - (size_t)start < len)
		re = malloc(ft_strlen(s) - (size_t)start + 1);
	else
		re = malloc(len + 1);
	if (re == NULL)
		return (NULL);
	while (len != 0 && s[i] != '\0')
	{
		re[i] = s[start + i];
		i++;
		len--;
	}
	re[i] = '\0';
	return (re);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*u_str;
	unsigned char	u_ch;

	i = 0;
	u_ch = (unsigned char)c;
	u_str = (unsigned char *)s;
	if (u_str[i] == u_ch)
		return ((char *)u_str);
	while (u_str[i++] != 0)
		if (u_str[i] == u_ch)
			return ((char *)(u_str + i));
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*src;
	char	*save;

	src = (char *)s;
	dest = malloc(ft_strlen(src)+1);
	if (dest == NULL)
		return (NULL);
	save = dest;
	while (*src)
		*save++ = *src++;
	*save = 0;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*chap;
	char	*save;

	if (!s1 || !s2)
		return (NULL);
	chap = (char *)malloc(ft_strlen(s1) + ft_strlen(s2)+1);
	if (!chap)
		return (NULL);
	save = chap;
	while (*s1 != '\0')
		*chap++ = *s1++;
	while (*s2 != '\0')
		*chap++ = *s2++;
	*chap = '\0';
	return (save);
}
