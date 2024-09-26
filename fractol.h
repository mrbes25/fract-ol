/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:54:05 by bschmid           #+#    #+#             */
/*   Updated: 2024/09/26 16:54:09 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibX/mlx.h"
# include "my_lib/my_lib.h"
# include <X11/X.h>
# include <math.h>
# include <stdlib.h>

// ADJUSTABLES
# define WIDTH 1000
# define HEIGHT 600
# define MAX_ITERATIONS 40

// KEYCODES
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define MOUSE_MOVE 6

typedef struct s_fractol
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
	double	zoom;
	int		max_iterations;
	int		mandelbrot;
	int		julia;
}			t_fractol;

// compute.c
void		compute_mandelbrot(t_fractol *fractol);
void		compute_julia(t_fractol *fractol);

// draw.c
int			draw_fractol(t_fractol *fractol);
void		*draw_mandelbrot(void *fractol_void);
void		draw_julia(t_fractol *fractol);
void		draw_first_fractol(t_fractol *fractol, int argc, char **argv);
void		draw_first_julia(t_fractol *fractol, int argc, char **argv);

// events.c
void		zoom(t_fractol *fractol, int x, int y, int zoom);
int			key_hook(int key_code, t_fractol *fractol);
int			mouse_hook(int mouse_code, int x, int y, t_fractol *fractol);
// int			julia_track(int y, int x, t_fractol *fractol);

// inits.c
void		init_fractol(t_fractol *fractol);
void		init_mlx(t_fractol *fractol);
void 		hooks(t_fractol *fractol);

// main.c
int			main(int argc, char **argv);

// tools.c
int			clean_exit(t_fractol *fractol);
double		ft_atod(char *s);
int			arg_check(int argc, char **argv, t_fractol *fractol);

#endif
