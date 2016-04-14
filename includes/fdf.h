/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:03:55 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/14 14:35:54 by vquesnel         ###   ########.fr       */
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
# define ZOOM 3

t_node			*get_map(char *file);
t_node		*init_node(void);
t_node		*new_node(int x, int y, int z, int index);
t_node		*insert_node(t_node *list, int x, int y, int z, int index);
t_iso		*init_node_iso(void);
t_iso		*new_node_iso(t_node *list);
t_iso		*insert_node_iso(t_iso *list, t_node *cc);
t_iso		*parallel(t_node *cc);
//void		draw_lines(t_mlx *new, t_iso *start, t_iso *end);
void		draw_line(t_mlx *new, t_iso *start, t_iso *end);

t_mlx		*init_mlx(void);


#endif
