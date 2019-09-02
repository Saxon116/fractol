/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:55:15 by nkellum           #+#    #+#             */
/*   Updated: 2019/09/02 16:52:22 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void scroll_zoom(t_mlx *mlx, int button, int x, int y)
{
	if(button == 4 && mlx->frozen) // scroll in
	{
		if(x >= 300)
			mlx->horiz += (0.00583333 / mlx->zoom) * (x - 300);
		else
			mlx->horiz -= (300 - x) * 0.00583333 / mlx->zoom;
		if(y >= 300)
			mlx->vert += (0.005 / mlx->zoom) * (y - 300);
		else
			mlx->vert -= (300 - y) * (0.005 / mlx->zoom);
		zoom_in(mlx);
	}
	if(button == 5 && mlx->zoom > 1 && mlx->frozen) // scroll out
	{
		if(x >= 300)
			mlx->horiz += (0.00583333 / mlx->zoom) * (x - 300);
		else
			mlx->horiz -= (300 - x) * 0.00583333 / mlx->zoom;
		if(y >= 300)
			mlx->vert += (0.005 / mlx->zoom) * (y - 300);
		else
			mlx->vert -= (300 - y) * (0.005 / mlx->zoom);
		zoom_out(mlx);
	}
}

int mouse_pressed(int button, int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *) param;
	if(button == 1 && mlx->fractal == 2)
		mlx->frozen = mlx->frozen ? 0 : 1;
	scroll_zoom(mlx, button, x, y);
	return 1;
}

int	win_close(void *param)
{
	(void)param;
	exit(0);
}

int	mouse_moved(int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *) param;
	if(!mlx->frozen && mlx->fractal == 2)
	{
		mlx->cx = map(x, 0, 600, -1, 1);
		mlx->cy = map(y, 0, 600, -1, 1);
		redraw(mlx);
	}
	return 1;
}
