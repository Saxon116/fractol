/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:57:04 by nkellum           #+#    #+#             */
/*   Updated: 2019/09/10 12:15:07 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** DESCRIPTION:
** This function checks the arguments passed through the command line
** to see if a valid fractal was chosen. If it is, it returns an int
** corresponding to that specific fractal to be loaded first.
** If the name of the fractal is incorrect or the number of argumants
** passed isn't right, the program exits.
*/

int		check_args(int argc, char **argv)
{
	int fractal;

	fractal = -1;
	if (argc != 2)
	{
		ft_putstr("usage: ./fractol [mandelbrot | julia | burningship | \
tricorn]\n");
		exit(1);
	}
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		return (1);
	if (ft_strcmp(argv[1], "julia") == 0)
		return (2);
	if (ft_strcmp(argv[1], "burningship") == 0)
		return (3);
	if (ft_strcmp(argv[1], "tricorn") == 0)
		return (4);
	ft_putstr("usage: ./fractol [mandelbrot | julia | burningship | \
tricorn]\n");
	exit(1);
}

/*
** DESCRIPTION:
** This function displays the controls used to explore the fractals.
*/

void	display_controls(t_mlx *mlx)
{
	if (mlx->show_controls)
	{
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0xFFFFFF,
			"Toggle controls: 't'");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 40, 0xFFFFFF,
			"Zoom: mousewheel");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 60, 0xFFFFFF,
			"Move: arrow keys");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 80, 0xFFFFFF,
			"Reset: 'r'");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 100, 0xFFFFFF,
			"Colors: 'c'");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 120, 0xFFFFFF,
			"Greyscale: 's'");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 140, 0xFFFFFF,
			"Change Fractal: 1-4");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 160, 0xFFFFFF,
			"Julia Freeze: click");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 180, 0xFFFFFF,
			"Iterations: '-' and '='");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 200, 0xFFFFFF,
			"Quit: 'Esc'");
	}
	else
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 5, 5, 0xFFFFFF, "'t'");
}

/*
** DESCRIPTION:
** This function initializes the mlx structure to be used
** to store information about fractals, controls, and the
** window.
*/

void	initialize_mlx(t_mlx *mlx)
{
	mlx->r = 226;
	mlx->g = 237;
	mlx->b = 185;
	mlx->show_controls = 1;
	mlx->mlx_ptr = mlx_init();
	mlx->offset = 0.1;
	mlx->zoom = 1.0;
	mlx->horiz = 0;
	mlx->horiz_last = 0;
	mlx->vert = 0;
	mlx->oldvert = 0;
	mlx->vert_last = 0;
	mlx->oldhoriz = 0;
	mlx->max_iteration = 100;
	mlx->fractal = -1;
	mlx->cx = 0.0;
	mlx->cy = 0.0;
	mlx->frozen = 0;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 600, 600, "Fractol");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 600, 600);
	mlx->img_str = mlx_get_data_addr(mlx->img_ptr, &(mlx->bpp),
	&(mlx->size_line), &(mlx->endian));
}
