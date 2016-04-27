/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:16:47 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/27 12:04:55 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_lines(t_env *env, t_proj *start, t_proj *end)
{
	if ((start->x_iso - end->x_iso) == 0)
		draw_vertical(env, start, end);
	else
		draw_affine(env, start, end);
}

void			draw_line(t_env *env, t_proj *start)
{
	if (start->x != env->param->x_max && start->y != env->param->y_max)
	{
		draw_lines(env, start, start->next);
		draw_lines(env, start, searchinlist(start, env->param));
	}
	else if (start->x == env->param->x_max && start->y != env->param->y_max)
		draw_lines(env, start, searchinlist(start, env->param));
	else if (start->x != env->param->x_max && start->y == env->param->y_max)
		draw_lines(env, start, start->next);
}
