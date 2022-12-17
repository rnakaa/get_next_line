#include "get_next_line.h"
#define malloc ft_malloc//質問

static void	ft_free(char **ptr)//freeする関数
{
	free(*ptr);
	*ptr = NULL;
}

static char	*ft_error(char **buf, char **over)//errorが起きた時用の関数
{
	ft_free(buf);
	ft_free(over);
	return (NULL);
}

static char	*ft_make_ret_over(char **ptr, char **over, char **ret)
{
	char	*tmp;

	*ptr = ft_strchr(*over, '\n');
	if (!*ptr)
	{
		if (!ft_strlen(*over))
		{
			ft_free(over);
			return (NULL);
		}
		*ret = ft_strdup(*over);
		ft_free(over);
	}
	else
	{
		*ret = ft_substr(*over, 0, *ptr - *over + 1);
		tmp = ft_strdup(*over + (*ptr - *over + 1));
		ft_free(over);
		*over = tmp;
	}
	return (*ret);
}

static char	*ft_readline(int fd, char **over, char **ptr, char **tmp)
{
	ssize_t	size;
	char	*buf;//バッファ

	buf = (char *)malloc(BUFFER_SIZE + 1ul);//バッファサイズ分確保//質問　1ul
	if (!buf)//失敗した時用
	{
		ft_free(*over);
		return (NULL);
	}

	while (1)
	{
		*ptr = ft_strchr(*over, '\n');//改行文字を探している
		if (*ptr)
			break ;
		size = read(fd, buf, BUFFER_SIZE);//読み込めたサイズを保存
		if (size < 0)//失敗している
			return (ft_error(&buf, over));
		buf[size] = 0;//NULL止めしてる？質問
		if (size == 0)//読み込めなかった。ファイルの最後
			break ;
		*tmp = ft_strjoin(*over, buf);//すでに読み込まれた文字列に付け足してる
		ft_free(over);
		if (!*tmp)
			break ;
		*over = *tmp;
	}
	ft_free(&buf);
	return (*over);
}

char	*get_next_line(int fd)
{
	static char	*over;
	char		*ret;
	char		*ptr;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!over)
		over = ft_strdup("");
	if (!over)
		return (NULL);
	over = ft_readline(fd, &over, &ptr, &tmp);
	if (!over)
		return (NULL);
	ret = ft_make_ret_over(&ptr, &over, &ret);
	return (ret);
}