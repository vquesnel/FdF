/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:25:12 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/01 16:23:22 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		high(t_env *env, int keycode, t_param hook)
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

void		zoom(t_env *env, int keycode, t_param hook)
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

void		moove(t_env *env, int keycode, t_param hook)
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

void		projection(t_env *env, int keycode)
{
	if (keycode == ISO)
		env->proj = 0;
	else if (keycode == PARA)
		env->proj = 1;
	ft_memdel((void **)&env->img);
	env->img = init_img(env);
	fdf(env);
}

void		origin(t_env *env, int keycode, t_param hook)
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
