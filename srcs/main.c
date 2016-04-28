/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:36:57 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/28 14:34:13 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf(t_env *env)
{
	t_proj *tmp;

	tmp = env->proj;
	mlx_clear_window(env->mlx->mlx, env->mlx->win);
	while (tmp)
	{
		draw_line(env, tmp);
		tmp = tmp->next;
	}
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
