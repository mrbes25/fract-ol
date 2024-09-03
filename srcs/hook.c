//handles additional key events
int key_hook2(int keycode, t_fractol *data)
{
    if (keycode == 19)
        data->color = 2050;
    else if (keycode == 20)
        data->color = 265;
    else if (keycode == 35)
        data->julia_mouse = !data->julia_mouse;
    else if (keycode == 34)
        data->show_text = !data->show_text;
    return (0);
}
// Keycode 19: Corresponds to the number 2 key.
//Keycode 20: Corresponds to the number 3 key.
//Keycode 35: Corresponds to the P key.
//Keycode 34: Corresponds to the I key.

//handles key events
int key_hook(int keycode, t_fractol *data)
{
    if (keycode == 53)
        exit(1);
    else if (keycode == 69)
        data->it_max += 50;
    else if (keycode == 78)
        data->it_max -= 50;
    else if (keycode == 123)
        data->x1 -= 30 / data->zoom;
    else if (keycode == 124)
        data->x1 += 30 / data->zoom;
    else if (keycode == 125)
        data->y1 += 30 / data->zoom;
    else if (keycode == 126)
        data->y1 -= 30 / data->zoom;
    else if (keycode == 49)
        fract_init(data);
    else if (keycode == 18)
        data->color = 1677216;
    key_hook2(keycode, data);
    fract_calc(data);
    return (0);
}
//Keycode 53: Exits the program.
//Keycode 69: Increases data->it_max by 50 (likely increasing the number of iterations for fractal calculation).
//Keycode 78: Decreases data->it_max by 50.
//Keycode 123: Moves the view left by adjusting data->x1.
//Keycode 124: Moves the view right by adjusting data->x1.
//Keycode 125: Moves the view down by adjusting data->y1.
//Keycode 126: Moves the view up by adjusting data->y1.
//Keycode 49: Calls fract_init(data), which likely resets or initializes the fractal.
//Keycode 18: Sets data->color to 1677216.

void	ft_zoom(int x, int y, t_fractol *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.3));
	data->zoom *= 1.3;
	data->it_max++;
}

