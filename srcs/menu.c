#include "fdf.h"

static void	write_fdf(t_env *env, void *win2)
{
	mlx_string_put(env->mlx->mlx, win2, 280, 10, 0xAEECFE, "@@@@@@ @@@@@   \
@@@@@@");
	mlx_string_put(env->mlx->mlx, win2, 280, 20, 0xAEECFE, "@@@@@@ @@@@@@  \
@@@@@@");
	mlx_string_put(env->mlx->mlx, win2, 280, 30, 0xAEECFE, "@@     @@  @@@ @@");
	mlx_string_put(env->mlx->mlx, win2, 280, 40, 0xAEECFE, "@@@@@  @@  @@@ \
@@@@@");
	mlx_string_put(env->mlx->mlx, win2, 280, 50, 0xAEECFE, "@@     @@@@@@  @@");
	mlx_string_put(env->mlx->mlx, win2, 280, 60, 0xAEECFE, "@@     @@@@@   @@");
	mlx_string_put(env->mlx->mlx, win2, 280, 65, 0xFEAEEE, "                   \
	42");
	mlx_string_put(env->mlx->mlx, win2, 300, 100, 0xFFFFFF, "------      \
-----");

}
static void	write_menu(t_env *env, void *win2)
{
	write_fdf(env, win2);
	mlx_string_put(env->mlx->mlx, win2, 302, 100, 0xAEECFE, "       MENU");
	mlx_string_put(env->mlx->mlx, win2, 300, 140, 0xFCFEAE, "moove    ");
	mlx_string_put(env->mlx->mlx, win2, 300, 140, 0xFFFFFF, "         :  \
arrow");
	mlx_string_put(env->mlx->mlx, win2, 300, 160, 0xFFFFFF, "         :    +");
	mlx_string_put(env->mlx->mlx, win2, 300, 160, 0xFCFEAE, "zoom +    ");
	mlx_string_put(env->mlx->mlx, win2, 300, 180, 0xFFFFFF, "         :    -");
	mlx_string_put(env->mlx->mlx, win2, 300, 180, 0xFCFEAE, "zoom -   ");
	mlx_string_put(env->mlx->mlx, win2, 300, 200, 0xFFFFFF, "         :    p");
	mlx_string_put(env->mlx->mlx, win2, 300, 200, 0xFCFEAE, "proj     ");
	mlx_string_put(env->mlx->mlx, win2, 300, 220, 0xFFFFFF, "         :  Escp");
	mlx_string_put(env->mlx->mlx, win2, 300, 220, 0xFCFEAE, "exit     ");

}
int			menu(t_env *env)
{
	int			color;
	int			x;
	int			y;
	void		*win2;

	y = 0;
	color = 22122;
	win2 = mlx_new_window(env->mlx->mlx, 512, 256, "Menu");
	while (y <= 512)
	{
		x = -1;
		while (x++ <= 256)
		{
			mlx_pixel_put(env->mlx->mlx, win2, x, y, color);
			color = color + 32896;
		}
		y++;
	}
	write_menu(env, win2);
	mlx_loop(env->mlx->mlx);
	return (0);
}
