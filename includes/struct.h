/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:07:09 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/22 10:51:45 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_node
{
	int				x;
	int				y;
	int				z;
	int				x_iso;
	int				y_iso;
	int				index;
	int				color;
	struct s_node	*next;
}					t_node;

typedef struct		s_coef
{
	float			coef;
	float			cons;
}					t_coef;

typedef struct		s_coordmax
{
	int				x_max;
	int				y_max;
}					t_coordmax;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
}					t_coord;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	int				fd;
	int				zoom;
}					t_mlx;

#endif
