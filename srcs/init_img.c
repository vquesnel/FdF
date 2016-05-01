/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 14:26:15 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/01 18:51:05 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img		*init_img(t_env *env)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		ft_error("Can't create image.");
	img->img = mlx_new_image(env->mlx, X_SIZE, Y_SIZE);
	img->data = mlx_get_data_addr(img->img, &img->bpp, \
			&img->sizeline, &img->endian);
	return (img);
}

void		mlx_put_pixel_to_image(t_env *env, t_affine *c, int color)
{
	int		octet;

	octet = env->img->bpp / 8;
	if (c->x > 0 && c->x < X_SIZE && c->y > 0 && c->y < Y_SIZE)
		ft_memcpy(&env->img->data[octet * (c->x + env->img->sizeline / \
					octet * c->y)], &color, octet);
}
