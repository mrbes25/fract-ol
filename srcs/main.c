#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2)
	{
		ft_printf("Try: ./fractol <fractal>\nFractols: mandelbrot or julia\n");
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0, exit_fractal, fractal);
	draw_first_fractal(fractal, argc, argv);
	mlx_loop(fractal->mlx);
	return (0);
}