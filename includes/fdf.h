/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:39:03 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/27 20:44:02 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "struct.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# define CTE1 0.6
# define CTE2 0.9
# define D_COLOR 0xFFFFFF
# define CLOSE 53
# define SPACE 49

void		draw_affine(t_env *env, t_proj *start, t_proj *end);
void		draw_line(t_env *env, t_proj *start);
void		draw_vertical(t_env *env, t_proj *start, t_proj *end);
t_node		*get_map(int fd);
int			get_xmax(t_node *node);
int			get_ymax(t_node *node);
int			get_xsize_max(t_proj *proj);
int			get_xsize_min(t_proj *proj);
int			get_ysize_max(t_proj *proj);
int			get_ysize_min(t_proj *proj);
t_coord		init_coord(int x, int y, int z);
t_env		*init_env(void);
t_env		*insert_env(int fd);
t_mlx		*init_mlx(int fd);
t_node		*init_node(void);
t_node		*new_node(t_coord coord, int color);
t_node		*insert_node(t_node *list, t_coord coord, int color);
t_param		*init_param(t_node *node, int zoom, int x, int y);
t_proj		*init_iso(t_node *node, t_param *param);
t_proj		*init_para(t_node *node, t_param *param);
int			fdf(t_env *env);
t_proj		*searchinlist(t_proj *proj, t_param *param);
int			key_funct(int keycode, t_env *env);
int			mouse_funct(int mousecode, t_env *env);

#endif
