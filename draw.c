/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:54:02 by nkellum           #+#    #+#             */
/*   Updated: 2019/09/02 16:50:05 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void redraw(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 600, 600);
	fill_background(mlx);
	if(mlx->fractal == 1)
		mandelbrot(mlx);
	if(mlx->fractal == 2)
		julia(mlx);
	if(mlx->fractal == 3)
		burning_ship(mlx);
	if(mlx->fractal == 4)
		tricorn(mlx);
	display_controls(mlx);
	mlx->img_str =  mlx_get_data_addr(mlx->img_ptr,
		&(mlx->bpp), &(mlx->size_line), &(mlx->endian));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void	plot(int x, int y, t_mlx *mlx, int iteration)
{
	int index;

	index = 4 * (y * 600) + 4 * x;
	mlx->img_str[index] = (char)mlx->r * iteration;
	mlx->img_str[index + 1] = (char)mlx->g * iteration;
	mlx->img_str[index + 2] = (char)mlx->b * iteration;
}

void fill_background(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < 600)
	{
		x = 0;
		while(x < 600)
		{
			plot(x, y, mlx, 1);
			x++;
		}
		y++;
	}
}
