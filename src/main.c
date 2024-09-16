#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	if (fractol == NULL)
	{
		free(fractol);
		return(1);
	}
	if (error_handling(argc, argv, fractol) == 1)
		return(1);
	init_fractol(fractol, argc); //initializes the struct
	init_mlx(fractol); //initielizes the minilibX
	mlx_key_hook(fractol->window, key_hook, fractol);
	mlx_mouse_hook(fractol->window, mouse_hook, fractol);
	if (ft_strncmp(argv[1], "julia", 5) == 0)
		mlx_hook(fractol->window, MotionNotify, PointerMotionMask, julia_track, fractol);
	mlx_hook(fractol->window, 17, 0, clean_exit, fractol);
	draw_first_fractol(fractol, argc, argv);
	mlx_loop(fractol->mlx);
	return (0);
}
