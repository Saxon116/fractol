/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:29:43 by nkellum           #+#    #+#             */
/*   Updated: 2019/08/21 12:46:09 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Cool colors:
	226 237 185
*/

void	plot(int x, int y, t_mlx *mlx, int iteration)
{
	int index;

	index = 4 * (y * 600) + 4 * x;
	mlx->img_str[index] = (char)226*iteration;
	mlx->img_str[index + 1] = (char)237*iteration;
	mlx->img_str[index + 2] = (char)185*iteration;
}

void plot_point(t_mlx *mlx, int x, int y)
{
	plot(x - 1, y - 1, mlx, 0);
	plot(x, y - 1, mlx, 0);
	plot(x + 1, y - 1, mlx, 0);
	plot(x - 1, y, mlx, 0);
	plot(x, y, mlx, 0);
	plot(x + 1, y, mlx, 0);
	plot(x - 1, y + 1, mlx, 0);
	plot(x, y + 1, mlx, 0);
	plot(x + 1, y + 1, mlx, 0);
}

void draw_cross(t_mlx *mlx)
{
	int i = 0;
	while(i < 600)
	{
		plot(i, 300, mlx, 0);
		i++;
	}
	i = 0;
	while(i < 600)
	{
		plot(300, i, mlx, 0);
		i++;
	}
}

void redraw(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 600, 600);
	mandelbrot(mlx);
	// plot_point(mlx, 300, 300);
	// plot_point(mlx, 0, 300);
	draw_cross(mlx);
	mlx->img_str =  mlx_get_data_addr(mlx->img_ptr,
		&(mlx->bpp), &(mlx->size_line), &(mlx->endian));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

int deal_key(int key, void *param)
{
	t_mlx *mlx;
	double direction;

	direction = 0;
	double offset = 0.01;
	mlx = (t_mlx *) param;
	//printf("key %d\n", key);

	if(key == 53 || key == 65307)
		exit(0);
	if(key == 15) // RESET with 'r'
	{
		mlx->zoom = 1;
		mlx->horiz = 0;
		mlx->vert = 0;
		redraw(mlx);
	}
	if(key == 69)
	{
		mlx->vert = 0;
		redraw(mlx);
	}
	if(key == 8) // print colors with with 'c'
		printf("r: %d g: %d b: %d\n", mlx->r, mlx->g, mlx->b);
	if(key == 24 || key == 69) // PLUS KEY
	{
		mlx->zoom *= 2;
		if(mlx->zoom == 2)
			mlx->oldvert = 0;
		if(mlx->zoom == 4)
			mlx->oldvert = 0.375;
		if(mlx->zoom > 4 && mlx->vert_last)
			mlx->oldvert /= 2;
		if(mlx->zoom == 2)
			mlx->vert += 0.75;
		else
			mlx->vert += mlx->oldvert;
		mlx->vert_last = 1;

		if(mlx->zoom == 2)
			mlx->oldhoriz = 0;
		if(mlx->zoom == 4)
			mlx->oldhoriz = 0.43;
		if(mlx->zoom > 4 && mlx->horiz_last)
			mlx->oldhoriz /= 2;
		if(mlx->zoom == 2)
			mlx->horiz += 0.88;
		else
			mlx->horiz += mlx->oldhoriz;
		mlx->horiz_last = 1;
		redraw(mlx);
	}
	if((key == 27 || key == 76) && mlx->zoom > 1) // MINUS KEY
	{
		mlx->zoom /= 2;
		if(mlx->zoom == 2)
			mlx->oldvert = 0.375;
		if(mlx->zoom >= 4 && !mlx->vert_last)
			mlx->oldvert *= 2;
		if(mlx->zoom == 1)
			mlx->vert -= 0.75;
		else
			mlx->vert -= mlx->oldvert;
		mlx->vert_last = 0;

		if(mlx->zoom == 2)
			mlx->oldhoriz = 0.375;
		if(mlx->zoom >= 4 && !mlx->horiz_last)
			mlx->oldhoriz *= 2;
		if(mlx->zoom == 1)
			mlx->horiz -= 0.75;
		else
			mlx->horiz -= mlx->oldhoriz;
		mlx->horiz_last = 0;
		redraw(mlx);
	}
	if(key == 53 || key == 65307)
		exit(0);
	if(key == 123) // LEFT
	{
		mlx->horiz -= offset;
		redraw(mlx);
	}
	if(key == 124) // RIGHT
	{
		mlx->horiz += offset;
		redraw(mlx);
	}
	if(key == 126) // UP
	{
		mlx->vert -= offset;
		redraw(mlx);
	}
	if(key == 125) // DOWN
	{
		mlx->vert += offset;
		redraw(mlx);
	}
	//printf("zoom: %f vert: %f offset: %f\n", mlx->zoom, mlx->vert, mlx->offset);
	return (0);
}




void initialize_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->offset = 0.1;
	mlx->zoom = 1;
	mlx->horiz = 0;
	mlx->horiz_last = 0;
	mlx->vert = 0;
	mlx->oldvert = 0;
	mlx->vert_last = 0;
	mlx->oldhoriz = 0;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 600, 600, "Fractol");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 600, 600);
	mlx->img_str =  mlx_get_data_addr(mlx->img_ptr, &(mlx->bpp),
	&(mlx->size_line), &(mlx->endian));
}

float map(double val, double start1, double stop1, double start2, double stop2)
{
	return start2 + (stop2 - start2) * ((val - start1) / (stop1 - start1));
}

int main(int argc, char **argv)
{
	int        fd;
	t_mlx *mlx;

	if((mlx = malloc(sizeof(t_mlx))) == NULL)
    	return (0);
	initialize_mlx(mlx);


	mandelbrot(mlx);
	draw_cross(mlx);


	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_hook(mlx->win_ptr, 2, 0, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
}
