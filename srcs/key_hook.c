/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:25:35 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/21 17:48:42 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_funct(int keycode, t_mlx *new)
{
	if (new == NULL)
		return (0);
	if (keycode == CLOSE)
		exit(EXIT_SUCCESS);
//	new->zoom += (keycode == U_ZOOM) ? 1 : 0;
//	new->zoom -= (keycode == D_ZOOM) ? 1 : 0;
	return (0);
}
