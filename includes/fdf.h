/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:03:55 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/21 15:08:03 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "struct.h"
# include "define.h"
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

t_node		*get_map(int fd);
t_node		*init_node(void);
t_node		*new_node(t_coord coord, int index, int color);
t_coord		insert_coord(int x, int y, int z);
t_node		*insert_node(t_node *list, t_coord coord, int index, int color);
void		draw_line(t_mlx *new, t_node *start, t_coordmax coord);
void		draw_lines(t_mlx *new, t_node *start, t_node *end);
int			get_ymax(t_node *cc);
int			get_xmax(t_node *cc);
t_mlx		*init_mlx(void);
t_node		*searchinlist(t_node *list, t_coordmax coord);
int			ft_isfdf(char c);
void		ft_error(void);

#endif
