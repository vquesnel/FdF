/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:03:50 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/29 17:12:18 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	*init_env(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->map = NULL;
	env->proj = NULL;
	env->param = NULL;
	env->mlx = NULL;
	env->img = NULL;
	return (env);
}

t_env	*insert_env(int fd)
{
	t_env	*env;

	if (!(env = init_env()))
		return (NULL);
	env->map = get_map(fd);
	env->param = init_param(env->map, 2, 512, 425, 1);
	env->proj = init_iso(env->map, env->param);
	env->mlx = init_mlx(fd);
	env->img = init_img(env);
	return (env);
}
