
//calls the function for the right calculation for fractal depending on the input Data
void fract_select(t_fractol *data)
{
	if (*data->it_max < 0)
		data->it_max = 0;
	if (data->fract == 0)
		mandelbrot_pthread(data);
	else if (data->fract == 1)
		julia_pthread(data);
	if (data->show_text)
		put_text(data);	
}

//calls initialization for fractal settings
void fract_init(t_fractol *data)
{
    if (data->fract == 0)
        mandelbrot_init(data);
    else if (data->fract == 1)
        julia_init(data);
    fract_calc(data);
}

//initializes window and image
void mlx_win_init(t_fractol *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WIDTH, WIDTH, "Fractol");
    data->img = mlx_new_image(data->mlx, WIDTH, WIDTH);
    data->img_ptr = mlx_get_data_addr(data->img, &data->bpp, &data->sl, &data->endian);
}
