/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:24:48 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/23 14:12:55 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_pressed(int key, t_data *data)
{
	if (key == 12)
		generate_mandelbrot(data);
	if (key == 124)
	{
		data->x++;
		my_mlx_pixel_put(data, data->x, data->y, new_color(data));
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	if (key == 123)
	{
		data->x--;
		my_mlx_pixel_put(data, data->x, data->y, new_color(data));
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	if (key == 126)
	{
		data->y--;
		my_mlx_pixel_put(data, data->x, data->y, new_color(data));
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	if (key == 125)
	{
		data->y++;
		my_mlx_pixel_put(data, data->x, data->y, new_color(data));
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	if (key == 53)
	{
		ft_printf("Exiting...\n");
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_SUCCESS);
	}
	// if (key == 17)
	// 	ft_destroy_windows(data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	return (0);
}

int	ft_destroy_windows(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("Exiting...\n");
	exit(EXIT_SUCCESS);
	return (0);
}

unsigned int	new_color(t_data *data)
{
	if (data->color < UI_MAX)
		data->color = data->color + 1000;
	else
		data->color = 0;
	return (data->color);
}
