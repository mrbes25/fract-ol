/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:24:18 by bschmid           #+#    #+#             */
/*   Updated: 2024/09/27 08:24:18 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (arg_check(argc, argv, &fractol) == 1)
		return (1);
	init_fractol(&fractol);
	init_mlx(&fractol);
	hooks(&fractol);
	draw_first_fractol(&fractol, argc, argv);
	mlx_loop(fractol.mlx);
	return (0);
}
