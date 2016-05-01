/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:25:12 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/01 11:57:05 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*static t_proj		*change_color(t_env *env, int keycode)
{
	t_proj *tmp;

	tmp = env->proj;
	if (keycode == COLOR_A)
	{
		while (tmp)
		{
		tmp->color = (tmp->z > -10) ? BLUE : tmp->color;
		tmp->color = (tmp->z <= -10 && tmp->z > -20) ? GREEN : tmp->color;
		tmp->color = (tmp->z <= -20 && tmp->z > -40) ? BROWN : tmp->color;
		tmp->color = (tmp->z <= -40) ? WHITE : tmp->color;
		tmp = tmp->next;
		}
		env->mlx->color = 1;
	}
	if (keycode == COLOR_B)
	{
		env->mlx->color = 0;
		return (env->proj);
	}
	return (env->proj);
}*/
/*static void		color(t_env *env, int keycode)
{
	if (keycode == COLOR_A)
		env->proj = change_color(env, keycode);
	fdf(env);
}
*/

static void		high(t_env *env, int keycode, t_param hook)
{
	if (keycode == A_HIGH)
		hook.high += 1;
	if (keycode == S_HIGH)
		hook.high -= 1;
	env->param = new_param(env->param, hook);
	ft_memdel((void **)&env->img);
	env->img = init_img(env);
	fdf(env);
}

static void		zoom(t_env *env, int keycode, t_param hook)
{
	if (keycode == P_ZOOM)
		hook.zoom += (hook.zoom >= 100) ? 10 : 1;
	else if (keycode == M_ZOOM && hook.zoom > 1)
		hook.zoom -= (hook.zoom >= 100) ? 10 : 1;
	env->param = new_param(env->param, hook);
	ft_memdel((void **)&env->img);
	env->img = init_img(env);
	fdf(env);
}

static void		moove(t_env *env, int keycode, t_param hook)
{
	if (keycode == L_MOOVE)
		hook.xdefault -= 5;
	else if (keycode == R_MOOVE)
		hook.xdefault += 5;
	else if (keycode == D_MOOVE)
		hook.ydefault -= 5;
	else if (keycode == U_MOOVE)
		hook.ydefault += 5;
	env->param = new_param(env->param, hook);
	ft_memdel((void **)&env->img);
	env->img = init_img(env);
	fdf(env);
}

static void		projection(t_env *env, int keycode)
{
	if (keycode == ISO)
		env->proj = 0;
	else if (keycode == PARA)
		env->proj = 1;
	ft_memdel((void **)&env->img);
	env->img = init_img(env);
	fdf(env);
}

static void		origin(t_env *env, int keycode, t_param hook)
{
	if (keycode == MIDDLE)
	{
		hook.zoom = 3;
		hook.xdefault = 512;
		hook.ydefault = 425;
		hook.high = 0;
		env->param = new_param(env->param, hook);
	}
	ft_memdel((void **)&env->img);
	env->img = init_img(env);
	fdf(env);
}

int				key_funct(int keycode, t_env *env)
{
	t_param	hook;

	hook.zoom = env->param->zoom;
	hook.xdefault = env->param->xdefault;
	hook.ydefault = env->param->ydefault;
	hook.high = env->param->high;
	if (env->mlx == NULL)
		return (0);
	if (keycode == CLOSE)
		exit(EXIT_SUCCESS);
	if (keycode == SPACE)
		menu(env);
	if (keycode == P_ZOOM || keycode == M_ZOOM)
		zoom(env, keycode, hook);
	if (keycode == L_MOOVE || keycode == R_MOOVE || keycode == U_MOOVE || \
			keycode == D_MOOVE)
		moove(env, keycode, hook);
	if (keycode == ISO || keycode == PARA)
		projection(env, keycode);
	if (keycode == MIDDLE)
		origin(env, keycode, hook);
	if (keycode == A_HIGH || keycode == S_HIGH)
		high(env, keycode, hook);
	return (0);
}
