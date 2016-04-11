/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 13:28:11 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/07 12:23:37 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				read_file(int fd, char **text)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	tmp = NULL;
	ret = -42;
	while (!ft_strchr(*text, '\n'))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		else
		{
			buf[ret] = 0;
			tmp = *text;
			if (!(*text = ft_strjoin(*text, buf)))
				return (-1);
			free(tmp);
		}
		if (ret < BUFF_SIZE)
			return (ret);
	}
	return (ret);
}

char			*get_one_line(char *text, char **line)
{
	char		*tmp;
	int			i;

	tmp = NULL;
	i = 0;
	while (text[i])
	{
		if (text[i] == '\n')
		{
			*line = ft_strsub(text, 0, i);
			tmp = text;
			text = ft_strdup(text + i + 1);
			free(tmp);
			return (text);
		}
		i++;
	}
	*line = ft_strdup(text);
	ft_strclr(text);
	return (text);
}

int				get_next_line(int const fd, char **line)
{
	static char	*text[MAX_FILES];
	int			ret;

	if (fd < 0 || fd >= MAX_FILES || !line)
		return (-1);
	if (!(text[fd]))
		text[fd] = ft_strnew(0);
	if ((ret = read_file(fd, &text[fd])) == -1)
		return (-1);
	text[fd] = get_one_line(text[fd], line);
	if (!ft_strlen(text[fd]) && !ft_strlen(*line) && !ret)
		return (0);
	else
		return (1);
}
