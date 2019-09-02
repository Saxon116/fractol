/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:55:38 by nkellum           #+#    #+#             */
/*   Updated: 2019/09/02 16:23:45 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void num_keys(t_mlx *mlx, int key)
{
	if(key == 18)
	{
		mlx->fractal = 1;
		key = 15;
		redraw(mlx);
	}
	if(key == 19)
	{
		mlx->fractal = 2;
		key = 15;
		redraw(mlx);
	}
	if(key == 20)
	{
		mlx->fractal = 3;
		key = 15;
		redraw(mlx);
	}
	if(key == 21)
	{
		mlx->fractal = 4;
		key = 15;
		redraw(mlx);
	}
}

void arrow_keys(t_mlx *mlx, int key)
{
	if(key == 123) // LEFT
	{
		mlx->horiz -= 0.3 / mlx->zoom;
		redraw(mlx);
	}
	if(key == 124) // RIGHT
	{
		mlx->horiz += 0.3 / mlx->zoom;
		redraw(mlx);
	}
	if(key == 126) // UP
	{
		mlx->vert -= 0.3 / mlx->zoom;
		redraw(mlx);
	}
	if(key == 125) // DOWN
	{
		mlx->vert += 0.3 / mlx->zoom;
		redraw(mlx);
	}
}

void zoom_and_reset(t_mlx *mlx, int key)
{
	if(key == 24) // '-' key (+)
	{
		mlx->max_iteration += 10;
		redraw(mlx);
	}
	if(key == 27) // '=' key (-)
	{
		mlx->max_iteration += 10;
		redraw(mlx);
	}
	if(key == 15) // RESET with 'r'
	{
		mlx->zoom = 1.0;
		mlx->horiz = 0;
		mlx->vert = 0;
		mlx->r = 226;
		mlx->g = 237;
		mlx->b = 185;
		mlx->max_iteration = 100;
		mlx->frozen = (mlx->fractal != 2);
		redraw(mlx);
	}
}

int deal_key(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *) param;
	if(key == 53)
		exit(0);
	num_keys(mlx, key);
	arrow_keys(mlx, key);
	zoom_and_reset(mlx, key);
	if(key == 1) // s for one color
	{
		mlx->r = 1;
		mlx->g = 1;
		mlx->b = 1;
		redraw(mlx);
	}
	return (0);
}
