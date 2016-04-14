/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 21:17:10 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/14 09:33:26 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line		*init_list(const int fd)
{
	t_line	*new;

	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	new->fd = fd;
	new->line = ft_strnew(0);
	new->next = NULL;
	return (new);
}

void		add_elem(t_line *list, t_line *new)
{
	while (list)
	{
		if (list->next == NULL)
		{
			list->next = new;
			new->next = NULL;
		}
		list = list->next;
	}
}

int			read_file(int fd, t_line *list)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	tmp = NULL;
	ret = -42;
	while (!ft_strchr(list->line, EOL))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		else
		{
			buf[ret] = 0;
			tmp = list->line;
			if (!(list->line = ft_strjoin(list->line, buf)))
				return (-1);
			free(tmp);
		}
		if (ret < BUFF_SIZE)
			return (ret);
	}
	return (ret);
}

char		*get_line(t_line *list, char **line)
{
	char	*tmp;
	char	*text;
	int		i;

	tmp = NULL;
	i = 0;
	text = list->line;
	while (text[i])
	{
		if (text[i] == EOL)
		{
			*line = ft_strsub(text, 0, i);
			tmp = text;
			text = ft_strdup(text + (i + 1));
			free(tmp);
			return (text);
		}
		i++;
	}
	*line = ft_strdup(text);
	ft_strclr(text);
	ft_strclr(list->line);
	return (text);
}

int			get_next_line(int const fd, char **line)
{
	static	t_line		*file;
	int					ret;
	t_line				*tmp;

	if (!file)
		file = init_list(fd);
	tmp = file;
	if (fd < 0 || !line)
		return (-1);
	while (tmp)
	{
		if (tmp->fd == fd)
			break ;
		if (tmp->next == NULL)
			add_elem(tmp, init_list(fd));
		tmp = tmp->next;
	}
	if ((ret = read_file(fd, tmp)) == -1)
		return (-1);
	tmp->line = get_line(tmp, line);
	if (!ft_strlen(tmp->line) && !ft_strlen(*line) && !ret)
		return (0);
	else
		return (1);
}
