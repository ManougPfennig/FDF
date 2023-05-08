/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:43:57 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/08 19:26:34 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	arg_parsing(int ac, char **av)
{
	if (ac > 2)
	{
		ft_printf("Please start program with only one argument :\n");
		ft_printf("- 'Julia' for Julia set\n");
		ft_printf("- 'Mandelbrot' for Mandelbrot set\n");
		ft_printf("- 'Bonus' for Bonus set\n");
		return (1);
	}
	if (ac != 1 && (ft_strcmp(av[1], "Mandelbrot") || ft_strcmp(av[1], "Julia") \
	|| ft_strcmp(av[1], "Bonus")))
	{
		ft_printf("Starting %s set !\n", av[1]);
		return (0);
	}
	else if (ac != 1)
		ft_printf("Error: '%s' Invalid argument !\n", av[1]);
	ft_printf("Please start program with one of those argument :\n");
	ft_printf("- 'Julia' for Julia set\n");
	ft_printf("- 'Mandelbrot' for Mandelbrot set\n");
	ft_printf("- 'Bonus' for Bonus set\n");
	return (1);
}

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] && str2[i])
	{
		if (str[i] != str2[i])
			return (0);
		i++;
	}
	if (str[i] != str2[i])
		return (0);
	return (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	deal_key(t_data *data)
{
	my_mlx_pixel_put(data, data->x, data->y, 0x00FF0000);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void	generate_triangle(t_data *data)
{
	int length;

	length = 10 * data->size;
	while (length-- && length > -1)
	{
		my_mlx_pixel_put(data, (data->x)++, (data->y)--, 0x00FF0000);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	length = 10 * data->size;
	while (length-- && length > -1)
	{
		my_mlx_pixel_put(data, (data->x)++, (data->y)++, 0x00FF0000);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	length = 20 * data->size;
	while (length-- && length > -1)
	{
		my_mlx_pixel_put(data, (data->x)--, (data->y), 0x00FF0000);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	length = 10 * data->size;
	while (length-- && length > -1)
		data->x++;
	data->size = (data->size / 2) + (data->size / 4);
}