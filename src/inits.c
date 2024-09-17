/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:20:28 by bschmid           #+#    #+#             */
/*   Updated: 2024/09/17 10:20:28 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	if (fractol->mandelbrot == 1)
	{
		fractol->zoom = 100;
		fractol->offset_x = -3.5;
		fractol->offset_y = -3;
	}
	else
	{
		fractol->zoom = 100;
		fractol->offset_x = -3;
		fractol->offset_y = -3;
	}
	fractol->max_iterations = MAX_ITERATIONS;
}

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fract-ol");
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->pointer_to_image = mlx_get_data_addr(fractol->image,
			&fractol->bits_per_pixel, &fractol->size_line, &fractol->endian);
}
