/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 18:11:05 by nkellum           #+#    #+#             */
/*   Updated: 2019/09/02 14:40:11 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void calc_tricorn(t_mlx *mlx, int p_x, int p_y, int iteration)
{
	double zx;
	double zy;
	double x;
	double y;
	double xtemp;

	while(p_x < 600)
	{
		x = map(p_x, 0 , 600 * mlx->zoom, -2.5 , 1) + 0.6 + mlx->horiz;
		y = map(p_y, 0 , 400 * mlx->zoom, -1, 1) - 0.4 + mlx->vert;
		zx = x;
		zy = y;
		iteration = 1;
		while (zx * zx + zy * zy < 4 &&  iteration < mlx->max_iteration)
		{
			xtemp = zx * zx - zy * zy + x;
			zy = -2 * zx * zy + y;
			zx = xtemp;
			iteration++;
		}
		plot(p_x, p_y, mlx, iteration);
		p_x++;
	}
}

void tricorn(t_mlx *mlx) {

	int p_y;


	p_y = 0;
	while(p_y < 600)
	{
		calc_tricorn(mlx, 0, p_y, 0);
		p_y++;
	}
}
