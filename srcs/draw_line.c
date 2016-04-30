/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:16:47 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/30 19:48:33 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_node	*isometric(t_env *env, t_node *coor)
{
	t_coord	tmp;

	tmp.z = coor->z + env->param->high;
	tmp.y = (CTE1 * coor->x - CTE2 * coor->y) * env->param->zoom + \
			env->param->xdefault;
	if (coor->z == 0)
		tmp.x = ((CTE1 / 2) * coor->x + (CTE2 / 2) * coor->y - coor->z) \
				* env->param->zoom + env->param->ydefault;
	else
		tmp.x = ((CTE1 / 2) * coor->x + (CTE2 / 2) * coor->y - tmp.z) * \
				env->param->zoom + env->param->ydefault;
	return (new_node(tmp, coor->color));
}

static t_node	*parallel(t_env *env, t_node *coor)
{
	t_coord	tmp;

	tmp.z = -coor->z + env->param->high;
	if (coor->z == 0)
	{
		tmp.y = (coor->x + CTE1 * -coor->z) * env->param->zoom + \
			env->param->xdefault;
		tmp.x = ((CTE1 / 2) * -coor->z + coor->y) * env->param->zoom + \
			env->param->ydefault;
	}
	else
	{tmp.y = (coor->x + CTE1 * tmp.z) * env->param->zoom + \
			env->param->xdefault;
	tmp.x = ((CTE1 / 2) * tmp.z + coor->y) * env->param->zoom + \
			env->param->ydefault;
	}
	return (new_node(tmp, coor->color));
}

void			draw_lines(t_env *env, t_node *start, t_node *end)
{
	t_node		*tmp;
	t_node		*tmp2;

	tmp = (env->proj == 0) ? isometric(env, start) : parallel(env, start);
	tmp2 = (env->proj == 0) ? isometric(env, end) : parallel(env, end);
	if ((tmp->x - tmp2->x) == 0)
		draw_vertical(env, tmp, tmp2);
	else
		check_affine(env, tmp, tmp2);
}

void			draw_line(t_env *env, t_node *start)
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
