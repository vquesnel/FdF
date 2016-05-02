/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:30:45 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/02 10:50:47 by vquesnel         ###   ########.fr       */
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

typedef struct		s_param
{
	int				x_max;
	int				y_max;
	int				zoom;
	int				xdefault;
	int				ydefault;
	double			high;
}					t_param;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_node			*map;
	t_img			*img;
	t_param			*param;
	int				proj;
}					t_env;

#endif
