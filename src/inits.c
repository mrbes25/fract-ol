#include "../fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	fractol->color = GREEN;
	fractol->zoom = 300;
	fractol->offset_x = -1.5;
	fractol->offset_y = -0.82;
	fractol->max_iterations = MAX_ITERATIONS;
}

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fract-ol");
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->pointer_to_image = mlx_get_data_addr(fractol->image,
			&fractol->bits_per_pixel,
			&fractol->size_line,
			&fractol->endian);
}
