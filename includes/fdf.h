/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:39:03 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/28 18:51:39 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "struct.h"
# include "define.h"
# include <mlx.h>
# include <math.h>

void		draw_affine(t_env *env, t_proj *start, t_proj *end);
void		draw_line(t_env *env, t_proj *start);
void		draw_vertical(t_env *env, t_proj *start, t_proj *end);
t_node		*get_map(int fd);
int			get_xmax(t_node *node);
int			get_ymax(t_node *node);
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
int			menu(t_env *env);
void		body(t_env *env);
void		left_wing(t_env *env);
void		right_wing(t_env *env);

#endif
