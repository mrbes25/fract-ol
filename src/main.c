/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastian <bastian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:54:49 by bschmid           #+#    #+#             */
/*   Updated: 2024/09/17 22:37:49 by bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (arg_check(argc, argv, &fractol) == 1)
		return(1);
	init_fractol(&fractol);
	init_mlx(&fractol);
	hooks(&fractol);
	draw_first_fractol(&fractol, argc, argv);
	mlx_loop(fractol.mlx);
	return (0);
}
