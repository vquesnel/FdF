/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:36:57 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/20 15:24:02 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdf(t_env *env)
{
	t_node	*tmp;
	char	*str;

	str = ft_itoa(env->param->zoom);
	tmp = env->map;
	while (tmp)
	{
		draw_line(env, tmp);
		tmp = tmp->next;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	mlx_string_put(env->mlx, env->win, 695, 791, 0xAEECFE, "Current zoom x");
	mlx_string_put(env->mlx, env->win, 839, 791, 0xFFFFFF, str);
	free(str);
	str = ft_itoa(env->param->xdefault);
	mlx_string_put(env->mlx, env->win, 170, 791, 0xAEECFE, "position.x =  ");
	mlx_string_put(env->mlx, env->win, 300, 791, 0xFFFFFF, str);
	free(str);
	str = ft_itoa(env->param->ydefault);
	mlx_string_put(env->mlx, env->win, 170, 811, 0xAEECFE, "position.y =  ");
	mlx_string_put(env->mlx, env->win, 300, 811, 0xFFFFFF, str);
	free(str);
	str = (env->proj) ? "Current proj : par" : "Current proj : iso";
	mlx_string_put(env->mlx, env->win, 695, 811, 0xAEECFE, str);
	return (0);
}

static int	close_win(t_env *env)
{
	free(env);
	exit(EXIT_SUCCESS);
}

int			main(int ac, char **av)
{
	int		fd;
	t_env	*env;

	if (ac != 2)
	{
		ft_putstr("Usage: ./fdf <filename>\n");
		return (0);
	}
	if (!(ft_strstr(av[1], ".fdf")))
		ft_error("\033[31;1mFile isn't a fdf map.\033[0m");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error("\033[31;1mError when openning file.\033[0m");
	env = init_env(fd);
	close(fd);
	fdf(env);
	mlx_hook(env->win, 2, 3, key_funct, env);
	mlx_hook(env->win, 17, 1l << 17, close_win, env);
	mlx_mouse_hook(env->win, mouse_funct, env);
	mlx_loop(env->mlx);
	return (0);
}
