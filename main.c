/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:29:43 by nkellum           #+#    #+#             */
/*   Updated: 2019/04/29 17:17:23 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	plot(int x, int y, t_mlx *mlx, int iteration)
{
	int index;

	index = 4 * (y * 600) + 4 * x;
	mlx->img_str[index] = (char)243*iteration;
	mlx->img_str[index + 1] = (char)100*iteration;
	mlx->img_str[index + 2] = (char)10*iteration;
}

int deal_key(int key, void *param)
{
  t_mlx *mlx;
  double direction;

  direction = 0;
  mlx = (t_mlx *) param;

  if(key == 53 || key == 65307)
      exit(0);
  return (0);
}



void initialize_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
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


	double x0 = -2.5;
	double y0 = -1.0;
	int p_x;
	int p_y = 0;
	int iteration = 0;
	int max_iteration = 100;
	double xtemp = 0;
	double x = 0.0;
	double y = 0.0;

	while(p_y < 600)
	{
		p_x = 0;
		while(p_x < 600)
		{
			x0 = map(p_x, 0, 500, -2, 1);
			y0 = map(p_y, 0, 400, -1, 1);
			//printf("x is %d and map is %f\n", p_x, x0);
			x = 0.0;
			y = 0.0;
			iteration = 0;
			while (x * x + y * y <= 2 * 2  &&  iteration < max_iteration) {
		      xtemp = x * x - y * y + x0;
		      y = 2 * x * y + y0;
		      x = xtemp;
		      iteration++;
		    }
			plot(p_x, p_y, mlx, iteration);
			p_x++;
		}
		//printf("y is %d and map is %f\n", p_y, y0);
		p_y++;
	}




	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_hook(mlx->win_ptr, 2, 0, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
}
