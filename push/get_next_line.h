#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

void		*ft_memmove(void *b1, const void *b2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
char		*get_next_line(int fd);

#endif