/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:43:36 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/11 18:14:19 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "fdf.h"

  static void		draw_vertical(t_mlx *new, t_iso *start, t_iso *end)
  {
  double		x;

  if (start->X > end->X)
  return (draw_vertical(new, end, start));
  x = start->X - end->X;
  if (x == 0)
  {
  if (start->Y > end->Y)
  ft_swap((int *)(&(start->Y)), (int *)(&(end->Y)));
  while (start->Y <= end->Y)
  {
  mlx_pixel_put(new->mlx, new->win, start->X, start->Y, 0xFF0000);
  start->Y++;
  }
  }
  }

  static void		draw_horizontal(t_mlx *new, t_iso *start, t_iso *end)
  {
  double		y;

  if (start->X > end->X)
  return (draw_horizontal(new, end, start));
  y = start->Y - end->Y;
  if (y == 0)
  {
  while (start->X >= end->X)
  {
  mlx_pixel_put(new->mlx, new->win, start->X, start->Y, 0x00FF00);
  start->X++;
  }
  }
  }

  static void		draw_affine(t_mlx *new, t_iso *start, t_iso *end)
  {
  t_iso	*coef;
  double y;

  coef = init_node_iso();
  coef->X = (end->Y - start->Y) / (end->X - start->X);
  coef->Y = start->Y - (coef->X * start->X);
  if (start->X > end->X)
  ft_swap((int *)(&(start->X)), (int *)(&(end->X)));
  while (start->X < end->X)
  {
  y = coef->X * start->X + coef->Y;
  while ( y > coef->X * (start->X + 1) + coef->Y)
  {
  mlx_pixel_put(new->mlx, new->win, start->X, y, 0x0000FF);
  y--;
  }
  start->X++;
  }
  }


  void		draw_lines(t_mlx *new, t_iso *start, t_iso *end)
  {
  t_iso	*cons2;

  cons2 = init_node_iso();
  if (start->X < end->X)
  return (draw_lines(new, end, start));
  if (start->X - end->X == 0)
  draw_vertical(new, start, end);
  else
{
	if (start->Y - end->Y == 0)
		draw_horizontal(new, start, end);
	else
		draw_affine(new, start, end);
}
}*/


#include "fdf.h"

static void		draw_y_rev(t_mlx *new, t_iso *start, t_iso *end)
{
	t_iso		pos;

	pos.Y = start->Y;
	while (pos.Y >= end->Y)
	{
		printf("draw_y_rev\n");
		pos.X = start->X + ((end->X - start->X) * (pos.Y - start->Y))
			/ (end->Y - start->Y);
		mlx_pixel_put(new->mlx, new->win, pos.X, pos.Y, 0xFF0000);
		pos.Y--;
	}
}

static void			draw_y(t_mlx *new, t_iso *start, t_iso *end)
{
	t_iso		pos;

	if (end->Y < start->Y)
		return (draw_y_rev(new, start, end));
	pos.Y = start->Y;
	printf("pos.Y == %d\n", pos.Y);
	printf("ed->Y == %d\n", end->Y);
	while (pos.Y <= end->Y)
	{
		printf("draw_y\n");
		pos.X = start->X + ((end->X - start->X) * (pos.Y - start->Y))
			/ (end->Y - start->Y);
		printf("pos.X == %d\n", pos.X);
		mlx_pixel_put(new->mlx, new->win, pos.X, pos.Y, 0xFF0000);
		pos.Y++;
	}
}

static void			draw_x_rev(t_mlx *new, t_iso *start, t_iso *end)
{
	t_iso		pos;

	pos.X = start->X;
	while (pos.X >= end->X)
	{
		printf("draw_x_rev\n");
		pos.Y = start->Y + ((end->Y - start->Y) * (pos.X - start->X))
			/ (end->X - start->X);
		mlx_pixel_put(new->mlx, new->mlx, pos.X, pos.Y, 0xFF0000);
		pos.X--;
	}
}

static void			draw_x(t_mlx *new, t_iso *start, t_iso *end)
{
	t_iso		pos;

	if (end->X < start->X)
		return (draw_x_rev(new, start, end));
	pos.X = start->X;
	while (pos.X <= end->X)
	{
		printf("draw_x\n");
		pos.Y = start->Y + ((end->Y - start->Y) * (pos.X - start->X))
			/ (end->X - start->X);
		mlx_pixel_put(new->mlx, new->win, pos.X, pos.Y, 0xFF0000);
		pos.X++;
	}
}

void		draw_line(t_mlx *new, t_iso *start, t_iso *end)
{
	int		x;
	int		y;

	x = end->X - start->X;
	y = end->Y - start->Y;
	printf("---------------\nx = %d// y = %d\n", x, y);
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	if (x == 0 && y == 0)
		return ;
	else if (y == 0 || x >= y)
		draw_x(new, start, end);
	else if (x == 0 || y >= x)
		draw_y(new, start, end);
}
