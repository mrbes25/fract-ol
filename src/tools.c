/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastian <bastian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:14:19 by bschmid           #+#    #+#             */
/*   Updated: 2024/09/17 22:40:33 by bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	clean_exit(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->image);
	mlx_destroy_window(fractol->mlx, fractol->window);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
    exit(EXIT_SUCCESS);
}

double	ft_atod(char *s)
{
	long	integral;
	double	fractional;
	double	power;
	int		sign;

	integral = 0;
	fractional = 0;
	sign = 1;
	power = 1;
	while (*s == ' ' || (*s >= '\t' && *s <= '\n'))
		++s;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		integral = (integral * 10) + (*s++ - '0');
	if (*s == '.')
		++s;
	while (*s)
	{
		power /= 10;
		fractional = fractional + (*s++ - '0') * power;
	}
	return ((integral + fractional) * sign);
}

int	arg_check(int argc, char **argv, t_fractol *fractol)
{
	if (argc < 2 || argc == 3 || argc > 4)
	{
		ft_printf("To run Fractol use Format:\n");
		ft_printf("mandelbrot: -- ./fractol mandelbrot\n");
		ft_printf("julia: -- ./fractol julia <number(y)> <number(x)>\n");
		return (1);
	}
	if (argc == 4 && (ft_strncmp(argv[1], "julia", 5) == 0))
	{
		fractol->julia = 1;
		fractol->mandelbrot = 0;
	}
	else if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		fractol->mandelbrot = 1;
		fractol->julia = 0;
	}
	else if (argc == 2 && (ft_strncmp(argv[1], "julia", 5) == 0))
	{
		ft_printf("To run Julia use Format: ");
		ft_printf("./fractol julia <number> <number>\n");
		return (1);
	}
	return (0);
}
