/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:03:50 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/01 15:44:25 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	*new_env(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->mlx = NULL;
	env->win = NULL;
	env->map = NULL;
	env->param = NULL;
	env->img = NULL;
	env->proj = 0;
	return (env);
}

t_env	*init_env(int fd)
{
	t_env	*env;

	if (!(env = new_env()))
		return (NULL);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, 1024, 850, "Vquesnel's FDF");
	env->param = init_param(3, X_SIZE / 2, Y_SIZE / 2, 0);
	env->map = get_map(fd, &env->param);
	env->img = init_img(env);
	return (env);
}
