/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:30:45 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/26 13:37:13 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	int				x_iso;
	int				y_iso;
	int				x_para;
	int				y_para;
	int				color;
	struct s_proj	*next;
}					t_proj;

typedef struct		t_mlx
{
	void			*mlx;
	void			*win;
}					s_mlx;

typedef struct		s_param
{
	int				x_max;
	int				y_max;
	int				zoom;
	int				x_size;
	int				y_size;
	int				proj;
}					t_param;

typedef struct		s_env
{
	t_node			*map;
	t_proj			*proj;
	t_mlx			*mlx;
	t_param			*param;
}					t_env;

#endif
