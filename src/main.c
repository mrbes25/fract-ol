/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:23:08 by bschmid           #+#    #+#             */
/*   Updated: 2024/09/17 10:23:47 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	if (fractol == NULL)
	{
		free(fractol);
		return (1);
	}
	if (arg_check(argc, argv, fractol) == 1)
		return (1);
	init_fractol(fractol);
	init_mlx(fractol);
	mlx_key_hook(fractol->window, key_hook, fractol);
	mlx_mouse_hook(fractol->window, mouse_hook, fractol);
	if (fractol->julia == 1)
		mlx_hook(fractol->window, MotionNotify, PointerMotionMask, julia_track,
			fractol);
	mlx_hook(fractol->window, 17, 0, clean_exit, fractol);
	draw_first_fractol(fractol, argc, argv);
	mlx_loop(fractol->mlx);
	return (0);
}
