/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:07:09 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/13 22:52:49 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_node
{
	int				x;
	int				y;
	int				z;
	int			index;
	struct s_node	*next;
}					t_node;

typedef struct		s_iso
{
	int			X;
	int			Y;
	struct s_iso	*next;
}					t_iso;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
}					t_mlx;

#endif
