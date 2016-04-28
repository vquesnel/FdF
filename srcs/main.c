/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:36:57 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/28 15:23:46 by vquesnel         ###   ########.fr       */
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
	mlx_string_put(env->mlx->mlx, env->mlx->win, 10, 40, 0x00FF00,\
			"Current zoom x");
	mlx_string_put(env->mlx->mlx, env->mlx->win, 150, 40, 0x00FF00, str);
	if (env->mlx->proj == 1)
		mlx_string_put(env->mlx->mlx, env->mlx->win, 10, 10, 0xFF0000, \
				"Current projection is parallel");
	else if (env->mlx->proj == 0)
		mlx_string_put(env->mlx->mlx, env->mlx->win, 10, 10, 0x0000FF, \
				"Current projection is isometrique");
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
	mlx_expose_hook(env->mlx->win, fdf, env);
	mlx_key_hook(env->mlx->win, key_funct, env);
	mlx_loop(env->mlx->mlx);
	return (0);
}
