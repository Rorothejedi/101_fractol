/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 11:34:27 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 14:35:21 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(const int fd, char **line, char **rest)
{
	if ((line == NULL || fd < 0 || BUFF_SIZE <= 0 || (read(fd, *line, 0) < 0)))
		return (-1);
	if (!*rest)
	{
		if (!(*rest = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
	}
	return (0);
}

static int		ft_next(const int fd, char **line, char **rest)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	if ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = *rest;
		*rest = ft_strjoin(tmp, buff);
		free(tmp);
		return (get_next_line(fd, line));
	}
	if (ret == -1)
		return (-1);
	if (ft_strlen(*rest) > 0)
	{
		tmp = *rest;
		*line = ft_strdup(tmp);
		*rest = ft_strnew(0);
		free(tmp);
		return (1);
	}
	free(*rest);
	*rest = NULL;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*rest[0];
	int				pos;
	char			*tmp;

	if (ft_check(fd, line, &rest[fd]) == -1)
		return (-1);
	pos = -1;
	if ((pos = ft_strichr(rest[fd], '\n')) != -1)
	{
		*line = ft_strsub(rest[fd], 0, pos);
		tmp = rest[fd];
		if (pos + 1 < (int)ft_strlen(rest[fd]))
			rest[fd] = ft_strsub(tmp, pos + 1,
					(int)ft_strlen(rest[fd]) - pos - 1);
		else
			rest[fd] = ft_strnew(0);
		free(tmp);
		return (1);
	}
	return (ft_next(fd, line, &rest[fd]));
}
