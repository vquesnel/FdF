/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:25:35 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/27 17:26:23 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_funct(int keycode, t_env *env)
{
	void	*win2;
	int		x;
	int		i;
	int		j;
	static int		check;

	win2 = NULL;
	printf("check == %d\n", check);
	x = env->param->zoom;
	i = env->param->xdefault;
	j = env->param->ydefault;
	if (env->mlx == NULL)
		return (0);
	if (keycode == CLOSE)
		exit(EXIT_SUCCESS);
	if (keycode == SPACE && check == 0)
	{
		win2 = mlx_new_window(env->mlx->mlx, 300, 90, "Menu");
		mlx_string_put(env->mlx->mlx, win2, 5, 5, 0xFFFFFF, "FDF Menu :");
		mlx_string_put(env->mlx->mlx, win2, 5, 20, 0xFFFFFF, "-Echap = esc");
		mlx_string_put(env->mlx->mlx, win2, 5, 35, 0xFFFFFF, "-Zoom = +/-");
		mlx_string_put(env->mlx->mlx, win2, 5, 50, 0xFFFFFF, "-Move = arrows");
		mlx_loop(env->mlx->mlx);
		check++;
	}
	if (keycode == SPACE && check)
		mlx_destroy_window(env->mlx->mlx, win2);
	if (keycode == 24)
	{
		mlx_clear_window(env->mlx->mlx, env->mlx->win);
		x = env->param->zoom + 2;
		ft_memdel((void **)&env->param);
		ft_memdel((void **)&env->proj);
		env->param = init_param(env->map, x, i, j);
		env->proj = insert_proj(env->map, env->param);
		fdf(env);
	}
	if (keycode == 27)
	{
		mlx_clear_window(env->mlx->mlx, env->mlx->win);
		x = env->param->zoom - 2;
		if (x >= 1)
		{
			ft_memdel((void **)&env->param);
			ft_memdel((void **)&env->proj);
			env->param = init_param(env->map, x, i, j);
			env->proj = insert_proj(env->map, env->param);
		}
		fdf(env);
	}
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
	{
		mlx_clear_window(env->mlx->mlx, env->mlx->win);
		ft_memdel((void **)&env->param);
		ft_memdel((void **)&env->proj);
		if (keycode == 123)
		{
			i -= 20;
			env->param = init_param(env->map, x, i, j);
			env->proj = insert_proj(env->map, env->param);
		}
		if (keycode == 124)
		{
			i += 20;
			env->param = init_param(env->map, x, i, j);
			env->proj = insert_proj(env->map, env->param);
		}
		if (keycode == 126)
		{
			j -= 20;
			env->param = init_param(env->map, x, i, j);
			env->proj = insert_proj(env->map, env->param);
		}
		if (keycode == 125)
		{
			j += 20;
			env->param = init_param(env->map, x, i, j);
			env->proj = insert_proj(env->map, env->param);
		}
		fdf(env);
	}
	return (0);
}
