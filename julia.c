/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:06:41 by nkellum           #+#    #+#             */
/*   Updated: 2019/08/21 16:27:38 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void julia(t_mlx *mlx) {

	double zx = 0;
	double zy = 0;
	int p_x;
	int p_y = 0;
	int iteration = 0;
	int max_iteration = 100;
	double xtemp = 0;


	while(p_y < 600)
	{
		p_x = 0;
		while(p_x < 600)
		{
			zx = map(p_x, 0 , 600 * mlx->zoom, -2.5 , 1) + 0.75 + mlx->horiz;
			zy = map(p_y, 0 , 400 * mlx->zoom, -1, 1) - 0.5 + mlx->vert;
			iteration = 0;
			while (zx * zx + zy * zy < 4 &&  iteration < max_iteration)
			{
				xtemp = zx * zx - zy * zy;
				zy = 2 * zx * zy  + mlx->cy;
				zx = xtemp + mlx->cx;
				iteration++;
			}
			plot(p_x, p_y, mlx, iteration);
			p_x++;
		}
		p_y++;
	}
}
