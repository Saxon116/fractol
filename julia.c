/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:06:41 by nkellum           #+#    #+#             */
/*   Updated: 2019/09/02 14:51:58 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void calc_julia(t_mlx *mlx, int p_x, int p_y, int iteration)
{
	double zx;
	double zy;
	double xtemp;

	while(p_x < 600)
	{
		zx = map(p_x, 0 , 600 * mlx->zoom, -2.5 , 1) + 0.75 + mlx->horiz;
		zy = map(p_y, 0 , 400 * mlx->zoom, -1, 1) - 0.5 + mlx->vert;
		iteration = 1;
		while (zx * zx + zy * zy < 4 &&  iteration < mlx->max_iteration)
		{
			xtemp = zx * zx - zy * zy;
			zy = 2 * zx * zy  + mlx->cy;
			zx = xtemp + mlx->cx;
			iteration++;
		}
		plot(p_x, p_y, mlx, iteration);
		p_x++;
	}
}

void julia(t_mlx *mlx) {
	int p_y;

	p_y = 0;
	while(p_y < 600)
	{
		calc_julia(mlx, 0, p_y,  0);
		p_y++;
	}
}
