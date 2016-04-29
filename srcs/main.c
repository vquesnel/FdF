/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:36:57 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/29 17:00:36 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf(t_env *env)
{
	t_proj	*tmp;
	char	*str;

	str = ft_itoa(env->param->zoom);
	tmp = env->proj;
	mlx_clear_window(env->mlx->mlx, env->mlx->win);
	while (tmp)
	{
		draw_line(env, tmp);
		tmp = tmp->next;
	}
	mlx_put_image_to_window(env->mlx->mlx, env->mlx->win, env->img->img, 0, 0);
	mlx_string_put(env->mlx->mlx, env->mlx->win, 695, 791, 0xAEECFE, "Current zoom x");
	mlx_string_put(env->mlx->mlx, env->mlx->win, 839, 791, 0xFFFFFF, str);
	free(str);
	str = ft_itoa(env->param->xdefault);
	mlx_string_put(env->mlx->mlx, env->mlx->win, 170, 791, 0xAEECFE, "position.x =  ");
	mlx_string_put(env->mlx->mlx, env->mlx->win, 300, 791, 0xFFFFFF, str);
	free(str);
	str = ft_itoa(env->param->ydefault);
	mlx_string_put(env->mlx->mlx, env->mlx->win, 170, 811, 0xAEECFE, "position.y =  ");
	mlx_string_put(env->mlx->mlx, env->mlx->win, 300, 811, 0xFFFFFF, str);
	if (env->mlx->proj == 1)
		mlx_string_put(env->mlx->mlx, env->mlx->win, 695, 811, 0xAEECFE, \
				"Current proj : par");
	else if (env->mlx->proj == 0)
		mlx_string_put(env->mlx->mlx, env->mlx->win, 695, 811, 0xAEECFE, \
				"Current proj : iso");
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	t_env	*env;
	t_proj	*tmp;

	if (ac != 2)
	{
		ft_putstr("Usage: ./fdf <filename>\n");
		return (0);
	}
	if (!(ft_strstr(av[1], ".fdf")))
		ft_error("\033[31;1mFile isn't a fdf map.\033[0m");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error("\033[31;1mError when openning file.\033[0m");
	env = insert_env(fd);
	fdf(env);
	tmp = env->proj;
	mlx_hook(env->mlx->win, 2, 3, key_funct, env);
	mlx_loop(env->mlx->mlx);
	return (0);
}
