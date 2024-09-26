/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:23:36 by bschmid           #+#    #+#             */
/*   Updated: 2024/09/26 16:23:36 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	fractol->zx = 0.0;
    fractol->zy = 0.0;
    fractol->cx = 0.0;
    fractol->cy = 0.0;
	fractol->zoom = 100;
	fractol->offset_y = -3;
	fractol->max_iterations = MAX_ITERATIONS;
	if (fractol->mandelbrot == 1)
		fractol->offset_x = -3.5;
	else if (fractol->julia == 1)
		fractol->offset_x = -3;

}
static void destroy_display(t_fractol *fractol)
{
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(1);
}

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		exit(EXIT_FAILURE);
	fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!fractol->window)
		destroy_display(fractol);
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->image)
	{
		mlx_destroy_window(fractol->mlx, fractol->window);
		destroy_display(fractol);

	}
	fractol->pointer_to_image = mlx_get_data_addr(fractol->image,
			&fractol->bits_per_pixel, &fractol->size_line, &fractol->endian);

}
void hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->window, key_hook, fractol);
	mlx_mouse_hook(fractol->window, mouse_hook, fractol);
	mlx_hook(fractol->window, DestroyNotify, StructureNotifyMask, clean_exit, fractol);
}
