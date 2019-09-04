/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:46:09 by nkellum           #+#    #+#             */
/*   Updated: 2019/09/04 16:43:39 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** DESCRIPTION:
** These two functions calculate and render the burning ship fractal.
** Pseudocode was found on wikipedia.
*/

float	flt_abs(float f)
{
	if (f < 0.0)
		return (-f);
	return (f);
}

void	calc_burning_ship(t_mlx *mlx, int p_x, int p_y, int iteration)
{
	double zx;
	double zy;
	double x;
	double y;
	double xtemp;

	while (p_x < 600)
	{
		x = -2.5 + 3.5 * ((p_x - 0) / (600 * mlx->zoom - 0))
		+ 0.35 + mlx->horiz;
		y = -1 + 2 * ((p_y - 0) / (400 * mlx->zoom - 0)) - 0.8 + mlx->vert;
		zx = x;
		zy = y;
		iteration = 1;
		while (zx * zx + zy * zy < 4 && iteration < mlx->max_iteration)
		{
			xtemp = zx * zx - zy * zy + x;
			zy = flt_abs(2 * zx * zy) + y;
			zx = flt_abs(xtemp);
			iteration++;
		}
		plot(p_x, p_y, mlx, iteration);
		p_x++;
	}
}

void	burning_ship(t_mlx *mlx)
{
	int p_y;

	p_y = 0;
	while (p_y < 600)
	{
		calc_burning_ship(mlx, 0, p_y, 0);
		p_y++;
	}
}
