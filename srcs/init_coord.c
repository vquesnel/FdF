/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:41:36 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/26 17:31:17 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		init_coord(int x, int y, int z)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	coord.z = z;
	return (coord);
}
