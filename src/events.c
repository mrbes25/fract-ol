/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:22:49 by bschmid           #+#    #+#             */
/*   Updated: 2024/09/17 10:22:56 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom(t_fractol *fractol, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x) - (x
				/ (fractol->zoom * zoom_level));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y) - (y
				/ (fractol->zoom * zoom_level));
		fractol->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x) - (x
				/ (fractol->zoom / zoom_level));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y) - (y
				/ (fractol->zoom / zoom_level));
		fractol->zoom /= zoom_level;
	}
	else
		return ;
}

int	key_hook(int key_code, t_fractol *fractol)
{
	if (key_code == ESC)
		exit(1);
	else if (key_code == LEFT)
		fractol->offset_x -= 42 / fractol->zoom;
	else if (key_code == RIGHT)
		fractol->offset_x += 42 / fractol->zoom;
	else if (key_code == UP)
		fractol->offset_y -= 42 / fractol->zoom;
	else if (key_code == DOWN)
		fractol->offset_y += 42 / fractol->zoom;
	draw_fractol(fractol);
	return (0);
}

int	julia_track(int x, int y, t_fractol *fract)
{
	double	range_min;
	double	range_max;
	double	range_width;

	range_min = -2;
	range_max = 2;
	range_width = range_max - range_min;
	fract->cx = range_min + (range_width * x / WIDTH);
	fract->cy = range_min + (range_width * y / HEIGHT);
	draw_fractol(fract);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractol *fractol)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractol, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractol, x, y, -1);
	draw_fractol(fractol);
	return (0);
}
