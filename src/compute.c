/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:21:45 by bschmid           #+#    #+#             */
/*   Updated: 2024/09/17 10:21:49 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	color_pixel(t_fractol *fractol, int x, int y, int color)
{
	int	*buffer;

	buffer = fractol->pointer_to_image;
	buffer[(y * fractol->size_line / 4) + x] = color;
}

static int	get_psychedelic_color(int iteration, int max_iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iteration / max_iterations;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

static int	get_glowy_color(int iteration, int max_iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iteration / max_iterations;
	r = (int)(255 * pow(t, 0.3));
	g = (int)(255 * pow(t, 0.5));
	b = (int)(255 * pow(t, 0.7));
	return ((r << 16) | (g << 8) | b);
}

void	compute_mandelbrot(t_fractol *fractol)
{
	int		i;
	double	x_temp;
	int		color;

	i = 0;
	fractol->zx = 0.0;
	fractol->zy = 0.0;
	fractol->cx = (fractol->x / fractol->zoom) + fractol->offset_x;
	fractol->cy = (fractol->y / fractol->zoom) + fractol->offset_y;
	while (++i < fractol->max_iterations)
	{
		x_temp = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = 2. * fractol->zx * fractol->zy + fractol->cy;
		fractol->zx = x_temp;
		if (fractol->zx * fractol->zx + fractol->zy
			* fractol->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractol->max_iterations)
		color = 0x000000;
	else
		color = get_psychedelic_color(i, fractol->max_iterations);
	color_pixel(fractol, fractol->x, fractol->y, color);
}

void	compute_julia(t_fractol *fractol)
{
	int		i;
	double	tmp;
	int		color;

	fractol->zx = fractol->x / fractol->zoom + fractol->offset_x;
	fractol->zy = fractol->y / fractol->zoom + fractol->offset_y;
	i = 0;
	while (++i < fractol->max_iterations)
	{
		tmp = fractol->zx;
		fractol->zx = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = 2 * fractol->zy * tmp + fractol->cy;
		if (fractol->zx * fractol->zx + fractol->zy
			* fractol->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractol->max_iterations)
		color = 0x000000;
	else
		color = get_glowy_color(i, fractol->max_iterations);
	color_pixel(fractol, fractol->x, fractol->y, color);
}
