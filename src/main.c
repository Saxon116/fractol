/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:29:43 by nkellum           #+#    #+#             */
/*   Updated: 2019/09/04 16:50:51 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Fractol by Nicolas Kellum
**
** Fractol is a fractal explorer program that contains 4 fractals:
** Mandelbrot, Julia, Burning Ship, and Tricorn.
**
**
** In this main function, the mlx structure is initialized to be
** used to store information about fractals, controls, and the
** window. The arguments are parsed to determine which fractal
** should be loaded first. The mlx_loop and mlx_hook functions
** are called to listen for the mouse and keyboard, as well as
** update the contents displayed on screen.
*/

int	main(int argc, char **argv)
{
	int		fractal;
	t_mlx	*mlx;

	if ((mlx = malloc(sizeof(t_mlx))) == NULL)
		return (0);
	initialize_mlx(mlx);
	mlx->fractal = check_args(argc, argv);
	mlx->frozen = (mlx->fractal != 2);
	fill_background(mlx, 600, 600);
	if (mlx->fractal == 1)
		mandelbrot(mlx);
	if (mlx->fractal == 2)
		julia(mlx);
	if (mlx->fractal == 3)
		burning_ship(mlx);
	if (mlx->fractal == 4)
		tricorn(mlx);
	fill_background(mlx, 240, 230);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	display_controls(mlx);
	mlx_hook(mlx->win_ptr, 2, 0, deal_key, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_pressed, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, win_close, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_moved, mlx);
	mlx_loop(mlx->mlx_ptr);
}
