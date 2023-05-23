/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:53:51 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/23 16:31:19 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	generate_mandelbrot(t_data *data)
{
	int	iteration;

	while (data->x < 1000 && data->y < 700)
	{
		iteration = test_for_two(data);
		if (iteration == 80)
		{
			my_mlx_pixel_put(data, (data->x), (data->y), 0x0000FFFF);
		}
		else
		{
			my_mlx_pixel_put(data, (data->x), (data->y), iteration * 255);
		}
		data->x++;
		if (data->x == 1000)
		{
			data->y++;
			data->x = 0;
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	test_for_two(t_data *data)
{
	int		n;
	double	f_z;

	f_z = (((data->x) - 500) * 0.0035) + ((((data->y) - 350) * 0.0035) * csqrt(-1));
	data->c = f_z;
	n = 0;
	while (f_z <= 2 && n < MAX_ITER)
	{
		f_z = f_z * f_z + data->c;
		f_z = 0;
		n++;
	}
	return (n);
}