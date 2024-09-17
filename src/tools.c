/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:24:05 by bschmid           #+#    #+#             */
/*   Updated: 2024/09/17 10:25:57 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	clean_exit(t_fractol *fractol)
{
	if (fractol->mlx)
	{
		if (fractol->pointer_to_image)
			mlx_destroy_image(fractol->mlx, fractol->pointer_to_image);
		if (fractol->window)
			mlx_destroy_window(fractol->mlx, fractol->window);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
	free(fractol);
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
		fractol->julia = 1;
	else if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		fractol->mandelbrot = 1;
	else if (argc == 2 && (ft_strncmp(argv[1], "julia", 5) == 0))
	{
		ft_printf("To run Julia use Format: ");
		ft_printf("./fractol julia <number> <number>\n");
		return (1);
	}
	return (0);
}
