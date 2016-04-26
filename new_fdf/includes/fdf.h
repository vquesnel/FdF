/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:39:03 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/26 13:44:36 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "struct.h"
# include <mlx.h>
# include <math.h>
# define CTE1 0.9
# define CTE2 0.9

void		draw_affine(t_env *env, t_proj *start, t_proj *end);
void			draw_line(t_env *env, t_proj *start);
void		draw_vertical(t_env *env, t_proj *start, t_proj *end);
t_node			*get_map(int fd);
int		get_xmax(t_node *node);
int		get_ymax(t_node *node);
int		get_xsize(t_proj *proj);
int		get_ysize(t_proj *proj);
t_coord		init_coord(int x, int y, int z);
t_env		*init_env(void);
t_env		*new_env(int fd);
t_env		*insert_env(t_env *env, t_node *map, t_proj *proj, t_mlx *mlx);
t_mlx		*init_mlx(t_param *param);
t_node		*init_node(void);
t_node		*new_node(t_coord coord, int color);
t_node		*insert_node(t_node *list, t_coord coord, int color);
t_param		*init_param(void);
t_param		*new_param(t_node *node, t_proj *proj);
t_proj		*init_proj(void);
t_proj		*new_proj(t_node *node);
t_proj		*insert_proj(t_proj *proj, t_node *node);
void		fdf(t_env *env, t_proj *proj);
t_proj		*searchinlist(t_proj *proj, t_param *param);

#endif
