/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:09:19 by nkellum           #+#    #+#             */
/*   Updated: 2019/08/22 15:18:07 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandelbrot(t_mlx *mlx) {

	double x0 = 0;
	double y0 = 0;
	int p_x;
	int p_y = 0;
	int iteration = 0;
	double xtemp = 0;
	double x = 0.0;
	double y = 0.0;

	while(p_y < 600)
	{
		p_x = 0;
		while(p_x < 600)
		{
			x0 = map(p_x, 0 , 600 * mlx->zoom, -2.5 , 1) + 0.5 + mlx->horiz;
			y0 = map(p_y, 0 , 400 * mlx->zoom, -1, 1) - 0.5 + mlx->vert;
			x = 0.0;
			y = 0.0;
			iteration = 1;
			while (x * x + y * y <= 4  &&  iteration < mlx->max_iteration)
			{
				xtemp = x * x - y * y + x0;
				y = 2 * x * y + y0;
				x = xtemp;
				iteration++;
			}
			plot(p_x, p_y, mlx, iteration);
			p_x++;
		}
		p_y++;
	}
}
