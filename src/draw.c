/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:54:02 by nkellum           #+#    #+#             */
/*   Updated: 2019/09/04 16:44:02 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** DESCRIPTION:
** This function controls what is redrawn on screen when the mouse or
** keyboard is used. It destroys the current mlx image, creates a new
** image, fills the new image with the pixel data from the fractals,
** then displays the new image to the screen.
** The display_controls function is called at the end since it is not
** a part of the image, but is rather drawn separately over it.
*/

void	redraw(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 600, 600);
	fill_background(mlx, 600, 600);
	if (mlx->fractal == 1)
		mandelbrot(mlx);
	if (mlx->fractal == 2)
		julia(mlx);
	if (mlx->fractal == 3)
		burning_ship(mlx);
	if (mlx->fractal == 4)
		tricorn(mlx);
	if (mlx->show_controls)
		fill_background(mlx, 240, 230);
	else
		fill_background(mlx, 40, 30);
	mlx->img_str = mlx_get_data_addr(mlx->img_ptr,
		&(mlx->bpp), &(mlx->size_line), &(mlx->endian));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	display_controls(mlx);
}

/*
** DESCRIPTION:
** This function writes one pixel of data to the mlx image at the correct
** x, y location in the image.
** The image/pixel data is stored in one long string, stored in mlx->img_str.
*/

void	plot(int x, int y, t_mlx *mlx, int iteration)
{
	int index;

	index = 4 * (y * 600) + 4 * x;
	mlx->img_str[index] = (char)mlx->r * iteration;
	mlx->img_str[index + 1] = (char)mlx->g * iteration;
	mlx->img_str[index + 2] = (char)mlx->b * iteration;
}

/*
** DESCRIPTION:
** This function draws a background behind the fractals for a smooth color
** transition. It is also used as a background for showing the controls.
*/

void	fill_background(t_mlx *mlx, int width, int height)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			plot(x, y, mlx, 0);
			x++;
		}
		y++;
	}
}
