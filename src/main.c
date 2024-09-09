#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc < 2)
	{
		ft_printf("Try: ./fractol <fractol>\nFractols: mandelbrot or julia\n");
		return (0);
	}
	fractol = malloc(sizeof(t_fractol));
	init_fractol(fractol);
	init_mlx(fractol);
	mlx_key_hook(fractol->window, key_hook, fractol);
	mlx_mouse_hook(fractol->window, mouse_hook, fractol);
	mlx_hook(fractol->window, 17, 0, clean_exit, fractol);
	draw_first_fractol(fractol, argc, argv);
	mlx_loop(fractol->mlx);
	return (0);
}
