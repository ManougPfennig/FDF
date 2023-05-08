/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:24:48 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/08 19:14:04 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_pressed(int key, t_data *data)
{
	if (key == 12)
		generate_triangle(data);
	if (key == 124)
		data->x++;
	if (key == 123)
		data->x--;
	if (key == 126)
		data->y--;
	if (key == 125)
		data->y++;
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