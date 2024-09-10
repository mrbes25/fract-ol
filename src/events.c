#include "../fractol.h"

void	zoom(t_fractol *fractol, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x) - (x
				/ (fractol->zoom * zoom_level));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y) - (y
				/ (fractol->zoom * zoom_level));
		fractol->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x) - (x
				/ (fractol->zoom / zoom_level));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y) - (y
				/ (fractol->zoom / zoom_level));
		fractol->zoom /= zoom_level;
	}
	else
		return ;
}

int	key_hook(int key_code, t_fractol *fractol)
{
	if (key_code == ESC)
		exit(1);
	else if (key_code == LEFT)
		fractol->offset_x -= 42 / fractol->zoom;
	else if (key_code == RIGHT)
		fractol->offset_x += 42 / fractol->zoom;
	else if (key_code == UP)
		fractol->offset_y -= 42 / fractol->zoom;
	else if (key_code == DOWN)
		fractol->offset_y += 42 / fractol->zoom;
	draw_fractol(fractol, fractol->name);
	return (0);
}
//add function to track mouse movement for julia
static int julia_track(int x, int y, t_fractol *fract)
{
    // Calculate the new value for the real and imaginary components of the Julia constant
    fract->cx = (x - WIDTH / 2) / (0.5 * WIDTH * fract->zoom) + fract->offset_x;
    fract->cy = (y - HEIGHT / 2) / (0.5 * HEIGHT * fract->zoom) + fract->offset_y;
    draw_fractol(fract, fract->name); // Update and refresh the rendering with the new Julia constant values
    return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractol *fractol)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractol, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractol, x, y, -1);
	else if (mouse_code == MOUSE_MOVE && !ft_strncmp(fractol->name, "Julia", 5))
		julia_track(x, y, fractol);
	draw_fractol(fractol, fractol->name);
	return (0);
}
