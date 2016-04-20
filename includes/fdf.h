/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:03:55 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/20 13:36:49 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "struct.h"
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# define CTE1 0.6
# define CTE2 0.75
# define X_SIZE 1000
# define Y_SIZE 1000
# define ZOOM 25

t_node		*get_map(char *file);
t_node		*init_node(void);
t_node		*new_node(int x, int y, int z, int index);
t_node		*insert_node(t_node *list, int x, int y, int z, int index);
void		draw_line(t_mlx *new, t_node *start, t_coordmax coord);
t_node		*searchinlist(t_node *list, t_coordmax coord);
int			get_ymax(t_node *cc);
int			get_xmax(t_node *cc);
t_mlx		*init_mlx(void);
t_node		*searchnextinlist(t_node *list);

#endif
