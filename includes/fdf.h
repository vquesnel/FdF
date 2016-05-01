/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:39:03 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/01 11:56:39 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "struct.h"
# include "define.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

void		check_affine(t_env *env, t_node *start, t_node *end);
void		draw_line(t_env *env, t_node *start);
void		draw_vertical(t_env *env, t_node *start, t_node *end);
t_node		*get_map(int fd, t_param **param);
int			get_xmax(t_node *node);
int			get_ymax(t_node *node);
t_env		*init_env(void);
t_env		*insert_env(int fd);
t_node		*init_node(void);
t_node		*new_node(t_coord coord, int colo);
t_node		*insert_node(t_node *list, t_node *elem);
t_param		*init_param(int x, int y, int z, int a);
t_param		*new_param(t_param *param, t_param hook);
int			fdf(t_env *env);
t_node		*searchinlist(t_node *proj, t_param *param);
int			key_funct(int keycode, t_env *env);
int			menu(t_env *env);
void		body(t_env *env);
void		left_wing(t_env *env);
void		right_wing(t_env *env);
t_img		*init_img(t_env *env);
void		mlx_put_pixel_to_image(t_env *env, t_affine *pixel, int color);
int			in_img(t_affine *affine);

#endif
