/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:09:19 by nkellum           #+#    #+#             */
/*   Updated: 2019/09/04 16:52:05 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** DESCRIPTION:
** These two functions calculate and render the mandelbrot fractal.
** Pseudocode was found on wikipedia.
*/

void	calc_mandelbrot(t_mlx *mlx, int p_x, int p_y, int iteration)
{
	double x0;
	double y0;
	double xtemp;
	double x;
	double y;

	while (p_x < 600)
	{
		x0 = -2.5 + 3.5 * ((p_x - 0) / (600 * mlx->zoom - 0))
		+ 0.5 + mlx->horiz;
		y0 = -1 + 2 * ((p_y - 0) / (400 * mlx->zoom - 0)) - 0.5 + mlx->vert;
		x = 0.0;
		y = 0.0;
		iteration = 1;
		while (x * x + y * y <= 4 && iteration < mlx->max_iteration)
		{
			xtemp = x * x - y * y + x0;
			y = 2 * x * y + y0;
			x = xtemp;
			iteration++;
		}
		plot(p_x, p_y, mlx, iteration);
		p_x++;
	}
}

void	mandelbrot(t_mlx *mlx)
{
	int p_y;

	p_y = 0;
	while (p_y < 600)
	{
		calc_mandelbrot(mlx, 0, p_y, 0);
		p_y++;
	}
}
