#include "../fractol.h"

int	clean_exit(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->image);
	mlx_destroy_window(fractol->mlx, fractol->window);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(EXIT_SUCCESS);
}

void	color_pixel(t_fractol *fractol, int x, int y, int color)
{
	int	*buffer;

	buffer = fractol->pointer_to_image;
	buffer[(y * fractol->size_line / 4) + x] = color;
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
