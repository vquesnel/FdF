/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:03:50 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/27 16:32:27 by vquesnel         ###   ########.fr       */
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
	return (env);
}

t_env	*insert_env(int fd)
{
	t_env	*env;

	if (!(env = init_env()))
		return (NULL);
	env->map = get_map(fd);
	env->param = init_param(env->map, 2, 500, 500);
	env->proj = insert_proj(env->map, env->param);
	env->mlx = init_mlx(fd);
//	env->next = NULL;
	return (env);
}
