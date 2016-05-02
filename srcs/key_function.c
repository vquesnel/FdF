/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 15:46:05 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/02 10:48:06 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_funct(int keycode, t_env *env)
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
	if (keycode == L_MOOVE || keycode == R_MOOVE || keycode == U_MOOVE || \
			keycode == D_MOOVE)
		moove(env, keycode, hook);
	if (keycode == MIDDLE)
		origin(env, keycode, hook);
	if (keycode == A_HIGH || keycode == S_HIGH)
		high(env, keycode, hook);
	return (0);
}

int		mouse_funct(int button, int x, int y, t_env *env)
{
	t_param	hook;

	hook.zoom = env->param->zoom;
	hook.xdefault = env->param->xdefault;
	hook.ydefault = env->param->ydefault;
	hook.high = env->param->high;
	(void)x;
	(void)y;
	(void)env;
	if (button == P_ZOOM || button == M_ZOOM)
		zoom(env, button, hook);
	if (button == PARA || button == ISO)
		projection(env, button);
	return (0);
}
