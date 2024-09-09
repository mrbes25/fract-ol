#include "../fractol.h"

int	draw_fractol(t_fractol *fractol, char *input)
{
	if (!ft_strncmp(input, "mandelbrot", 11))
		draw_mandelbrot(fractol);
	else if (!ft_strncmp(input, "julia", 6))
	{
		if (!fractol->cx && !fractol->cy)
		{
			fractol->cx = -0.70176;
			fractol->cy = -0.3842;
		}
		draw_julia(fractol);
	}
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
	if (argc < 2 || argc == 3 || argc > 4)
	{
		ft_printf("Usage: ./fractol <fractol> [<cx> <cy>]\n");
		clean_exit(fractol);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		draw_mandelbrot(fractol);
	else if (!ft_strncmp(argv[1], "julia", 6))
		draw_first_julia(fractol, argc, argv);
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image, \
		0, 0);
	return ;
}

void	draw_first_julia(t_fractol *fractol, int argc, char **argv)
{
	if (argc == 4)
	{
		fractol->cx = ft_atod(argv[2]);
		fractol->cy = ft_atod(argv[3]);
	}
	else
	{
		fractol->cx = -0.70176;
		fractol->cy = -0.3842;
	}
	draw_julia(fractol);
	return ;
}
