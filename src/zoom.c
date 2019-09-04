/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:42:39 by nkellum           #+#    #+#             */
/*   Updated: 2019/09/04 16:54:18 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** DESCRIPTION:
** Both functions control the zoom variable. The first values are hardcoded
** and represent the center x and y of the window. The next values are doubled
** every time. These functions zoom into the center of the window, but the
** location of the zoom changes depending on the position of the mouse which
** is seen in the scroll_zoom function in mouse.c
*/

void	zoom_in(t_mlx *mlx)
{
	mlx->zoom *= 2.0;
	if (mlx->zoom == 2)
		mlx->oldvert = 0;
	if (mlx->zoom == 4)
		mlx->oldvert = 0.375;
	if (mlx->zoom > 4 && mlx->vert_last)
		mlx->oldvert /= 2.0;
	if (mlx->zoom == 2)
		mlx->vert += 0.75;
	else
		mlx->vert += mlx->oldvert;
	mlx->vert_last = 1;
	if (mlx->zoom == 2)
		mlx->oldhoriz = 0;
	if (mlx->zoom == 4)
		mlx->oldhoriz = 0.44;
	if (mlx->zoom > 4 && mlx->horiz_last)
		mlx->oldhoriz /= 2.0;
	if (mlx->zoom == 2)
		mlx->horiz += 0.87;
	else
		mlx->horiz += mlx->oldhoriz;
	mlx->horiz_last = 1;
	redraw(mlx);
}

void	zoom_out(t_mlx *mlx)
{
	mlx->zoom /= 2.0;
	if (mlx->zoom == 2)
		mlx->oldvert = 0.375;
	if (mlx->zoom >= 4 && !mlx->vert_last)
		mlx->oldvert *= 2.0;
	if (mlx->zoom == 1)
		mlx->vert -= 0.75;
	else
		mlx->vert -= mlx->oldvert;
	mlx->vert_last = 0;
	if (mlx->zoom == 2)
		mlx->oldhoriz = 0.44;
	if (mlx->zoom >= 4 && !mlx->horiz_last)
		mlx->oldhoriz *= 2.0;
	if (mlx->zoom == 1)
		mlx->horiz -= 0.87;
	else
		mlx->horiz -= mlx->oldhoriz;
	mlx->horiz_last = 0;
	redraw(mlx);
}
