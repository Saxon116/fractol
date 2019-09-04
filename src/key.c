/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:55:38 by nkellum           #+#    #+#             */
/*   Updated: 2019/09/04 16:49:45 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** DESCRIPTION:
** This function resets the fractal that is being viewed to its original
** zoom, position, colors, iterations, and frozen state. It then redraws
** the fractal.
*/

void	reset(t_mlx *mlx)
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

/*
** DESCRIPTION:
** This function changes the fractal that is drawn if keys 1-4 are pressed.
*/

void	num_keys(t_mlx *mlx, int key)
{
	if (key == 18 || key == 83)
	{
		mlx->fractal = 1;
		reset(mlx);
		redraw(mlx);
	}
	if (key == 19 || key == 84)
	{
		mlx->fractal = 2;
		reset(mlx);
		redraw(mlx);
	}
	if (key == 20 || key == 85)
	{
		mlx->fractal = 3;
		reset(mlx);
		redraw(mlx);
	}
	if (key == 21 || key == 86)
	{
		mlx->fractal = 4;
		reset(mlx);
		redraw(mlx);
	}
}

/*
** DESCRIPTION:
** This function changes the position of the fractal if the arrow keys
** are pressed. The number by which the position changes scales with
** the zoom, so that if you are zoomed in, the position does not change
** drastically.
*/

void	arrow_keys(t_mlx *mlx, int key)
{
	if (key == 123)
	{
		mlx->horiz -= 0.3 / mlx->zoom;
		redraw(mlx);
	}
	if (key == 124)
	{
		mlx->horiz += 0.3 / mlx->zoom;
		redraw(mlx);
	}
	if (key == 126)
	{
		mlx->vert -= 0.3 / mlx->zoom;
		redraw(mlx);
	}
	if (key == 125)
	{
		mlx->vert += 0.3 / mlx->zoom;
		redraw(mlx);
	}
}

/*
** DESCRIPTION:
** This function controls the zoom, iterations and resets the fractal
** if the corresponding keys are pressed.
** Iterations are controlled with the '-' and '=' keys
** Toggling the controls with 't'
** Reset the fractal with 'r'
*/

void	zoom_and_reset(t_mlx *mlx, int key)
{
	if (key == 24)
	{
		mlx->max_iteration += 10;
		redraw(mlx);
	}
	if (key == 27)
	{
		mlx->max_iteration -= 10;
		redraw(mlx);
	}
	if (key == 17)
	{
		mlx->show_controls = !mlx->show_controls;
		redraw(mlx);
	}
	if (key == 15)
		reset(mlx);
}

/*
** DESCRIPTION:
** This function calles the other key handling functions above, as
** well as the greyscale mode ('s') and random colors ('c').
*/

int		deal_key(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (key == 53)
		exit(0);
	num_keys(mlx, key);
	arrow_keys(mlx, key);
	zoom_and_reset(mlx, key);
	if (key == 1)
	{
		mlx->r = 1;
		mlx->g = 1;
		mlx->b = 1;
		redraw(mlx);
	}
	if (key == 8)
	{
		srand(time(NULL));
		mlx->r = rand() % 255;
		mlx->g = rand() % 255;
		mlx->b = rand() % 255;
		redraw(mlx);
	}
	return (0);
}
