/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:30:45 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/27 21:06:04 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_affine
{
	int				x;
	int				y;
	float			coef;
	float			cst;
}					t_affine;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
}					t_coord;

typedef struct		s_node
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_node	*next;
}					t_node;

typedef struct		s_proj
{
	int				x;
	int				y;
	int				z;
	int				x_iso;
	int				y_iso;
	int				color;
	struct s_proj	*next;
}					t_proj;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	int				fd;
	int				proj;
}					t_mlx;

typedef struct		s_param
{
	int				x_max;
	int				y_max;
	int				zoom;
	int				xdefault;
	int				ydefault;
}					t_param;

typedef struct		s_env
{
	t_node			*map;
	t_proj			*proj;
	t_mlx			*mlx;
	t_param			*param;
}					t_env;

#endif
