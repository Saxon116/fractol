/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:31:29 by nkellum           #+#    #+#             */
/*   Updated: 2019/09/04 16:57:35 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <stdlib.h>

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_str;
	int			bpp;
	int			size_line;
	int			endian;
	int			r;
	int			g;
	int			b;
	int			horiz_last;
	int			vert_last;
	int			frozen;
	int			max_iteration;
	int			fractal;
	int			show_controls;
	double		offset;
	double		horiz;
	double		vert;
	double		oldvert;
	double		oldhoriz;
	double		zoom;
	double		cx;
	double		cy;
}				t_mlx;

void			mandelbrot(t_mlx *mlx);
void			plot(int x, int y, t_mlx *mlx, int iteration);
void			redraw(t_mlx *mlx);
void			zoom_in(t_mlx *mlx);
void			zoom_out(t_mlx *mlx);
void			julia(t_mlx *mlx);
void			burning_ship(t_mlx *mlx);
void			tricorn(t_mlx *mlx);
void			fill_background(t_mlx *mlx, int width, int height);
int				mouse_pressed(int button, int x, int y, void *param);
int				mouse_moved(int x, int y, void *param);
int				deal_key(int key, void *param);
int				win_close(void *param);
void			display_controls(t_mlx *mlx);
void			initialize_mlx(t_mlx *mlx);
int				check_args(int argc, char **argv);

#endif
