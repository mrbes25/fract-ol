/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:10:50 by bschmid           #+#    #+#             */
/*   Updated: 2024/09/27 09:12:02 by bschmid          ###   ########.ch       */
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

static	void	print_instructions(void)
{
	ft_printf("To run Fractol use Format:\n");
	ft_printf("mandelbrot: -- ./fractol mandelbrot\n");
	ft_printf("julia: -- ./fractol julia <number(y)> <number(x)>\n");
}

int	arg_check(int argc, char **argv, t_fractol *fractol)
{
	if (argc != 2 && argc != 4)
	{
		print_instructions();
		return (1);
	}
	if ((argc == 4 && (ft_strncmp(argv[1], "julia", 5) == 0))
		|| (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0))
	{
		if (argc == 4 && (ft_strncmp(argv[1], "julia", 5) == 0))
			fractol->julia = 1;
		else if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
			fractol->mandelbrot = 1;
		return (0);
	}
	print_instructions();
	return (1);
}
