/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:55:15 by nkellum           #+#    #+#             */
/*   Updated: 2019/09/04 17:02:18 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** DESCRIPTION:
** This function controls the zoom with the mousewheel. The zoom_in and
** zoom_out functions zoom from the center of the window. This function
** takes the current mouse position, and shifts the position of the fractal
** so that the zoom points towards the mouse position.
*/

void	scroll_zoom(t_mlx *mlx, int button, int x, int y)
{
	if (button == 4 && mlx->frozen)
	{
		if (x >= 300)
			mlx->horiz += (0.00583333 / mlx->zoom) * (x - 300);
		else
			mlx->horiz -= (300 - x) * 0.00583333 / mlx->zoom;
		if (y >= 300)
			mlx->vert += (0.005 / mlx->zoom) * (y - 300);
		else
			mlx->vert -= (300 - y) * (0.005 / mlx->zoom);
		zoom_in(mlx);
	}
	if (button == 5 && mlx->zoom > 1 && mlx->frozen)
	{
		if (x >= 300)
			mlx->horiz += (0.00583333 / mlx->zoom) * (x - 300);
		else
			mlx->horiz -= (300 - x) * 0.00583333 / mlx->zoom;
		if (y >= 300)
			mlx->vert += (0.005 / mlx->zoom) * (y - 300);
		else
			mlx->vert -= (300 - y) * (0.005 / mlx->zoom);
		zoom_out(mlx);
	}
}

/*
** DESCRIPTION:
** This function handles the frozen state for the julia fractal and
** calls scroll_zoom to handle the zoom.
*/

int		mouse_pressed(int button, int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (button == 1 && mlx->fractal == 2)
		mlx->frozen = mlx->frozen ? 0 : 1;
	scroll_zoom(mlx, button, x, y);
	return (1);
}

/*
** DESCRIPTION:
** This function is called from the mlx_hook listener (main.c) that triggers
** when the red x is clicked. The program simply exits.
*/

int		win_close(void *param)
{
	(void)param;
	exit(0);
}

/*
** DESCRIPTION:
** This function is called from the mlx_hook listener (main.c) that triggers
** when the mouse moves. This is used to be able to change the variables
** that control the julia fractal shape depending on the mouse position.
*/

int		mouse_moved(int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (!mlx->frozen && mlx->fractal == 2)
	{
		mlx->cx = -1.0 + 2.0 * (((double)x - 0.0) / (600.0 - 0.0));
		mlx->cy = -1.0 + 2.0 * (((double)y - 0.0) / (600.0 - 0.0));
		redraw(mlx);
	}
	return (1);
}
