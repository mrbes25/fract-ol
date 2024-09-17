/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:22:19 by bschmid           #+#    #+#             */
/*   Updated: 2024/09/17 18:54:52 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	draw_fractol(t_fractol *fractol)
{
	if (fractol->mandelbrot == 1)
		draw_mandelbrot(fractol);
	else if (fractol->julia == 1)
		draw_julia(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image, 0,
		0);
	return (0);
}

void	*draw_mandelbrot(void *fractol_void)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)fractol_void;
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < WIDTH)
	{
		while (fractol->y < HEIGHT)
		{
			compute_mandelbrot(fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
	return (NULL);
}

void	draw_julia(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < WIDTH)
	{
		while (fractol->y < HEIGHT)
		{
			compute_julia(fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
}

void	draw_first_fractol(t_fractol *fractol, int argc, char **argv)
{
	if (fractol->mandelbrot == 1)
		draw_mandelbrot(fractol);
	else if (fractol->julia == 1)
		draw_first_julia(fractol, argc, argv);
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image, 0,
		0);
	return ;
}

void	draw_first_julia(t_fractol *fractol, int argc, char **argv)
{
	if (argc == 4)
	{
		fractol->cx = ft_atod(argv[2]);
		fractol->cy = ft_atod(argv[3]);
		draw_julia(fractol);
	}
	return ;
}
