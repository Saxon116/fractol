/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:29:43 by nkellum           #+#    #+#             */
/*   Updated: 2019/09/02 16:59:09 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void display_controls(t_mlx *mlx)
{
  mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0xFFFFFF, "Zoom: '+' and '-'");
  mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 30, 0xFFFFFF, "Height: '_' and '='");
  mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 50, 0xFFFFFF, "Projection: 'p'");
  mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 70, 0xFFFFFF, "Colors: 'c'");
  mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 90, 0xFFFFFF, "Move: arrow keys");
  mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 110, 0xFFFFFF, "Quit: Esc");
}

void initialize_mlx(t_mlx *mlx)
{
	mlx->r = 226;
	mlx->g = 237;
	mlx->b = 185;
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
	mlx->img_str =  mlx_get_data_addr(mlx->img_ptr, &(mlx->bpp),
	&(mlx->size_line), &(mlx->endian));
}

double map(double val, double start1, double stop1, double start2, double stop2)
{
	return start2 + (stop2 - start2) * ((val - start1) / (stop1 - start1));
}

int main(int argc, char **argv)
{
	int        fd;
	int fractal;
	t_mlx *mlx;

	fractal = -1;
	if(argc != 2)
	{
		ft_putstr("usage: ./fractol [mandelbrot | julia | burningship | tricorn]\n");
		exit(0);
	}
	if(ft_strcmp(argv[1], "mandelbrot") == 0)
		fractal = 1;
	if(ft_strcmp(argv[1], "julia") == 0)
		fractal = 2;
	if(ft_strcmp(argv[1], "burningship") == 0)
		fractal = 3;
	if(ft_strcmp(argv[1], "tricorn") == 0)
		fractal = 4;
	if(fractal == -1)
	{
		ft_putstr("usage: ./fractol [mandelbrot | julia | burningship | tricorn]\n");
		exit(0);
	}
	if((mlx = malloc(sizeof(t_mlx))) == NULL)
    	return (0);
	initialize_mlx(mlx);
	mlx->fractal = fractal;
	mlx->frozen = (mlx->fractal != 2);
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
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_hook(mlx->win_ptr, 2, 0, deal_key, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_pressed, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, win_close, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_moved, mlx);
	mlx_loop(mlx->mlx_ptr);
}
