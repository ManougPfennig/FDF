/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:42:38 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/07 19:02:25 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_data	img;
	pos		pos;

	if (arg_parsing(ac, av))
		exit(EXIT_FAILURE);
	mlx = mlx_init();
	if (mlx == NULL)
	{
		ft_printf("Error: Could not mlx_init -> Program interrupted\n");
		exit(EXIT_FAILURE);
	}
	win = mlx_new_window(mlx, 1000, 700, av[1]);
	if (win == NULL)
	{
		ft_printf("Error: Could not mlx_new_window -> Program interrupted\n");
		exit(EXIT_FAILURE);
	}
	pos.x = 1;
	pos.y = 1;
	img.img = mlx_new_image(mlx, 1000, 700);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, \
	&img.endian);
	while (pos.x < 700 && pos.y < 700)
	{
		my_mlx_pixel_put(&img, pos.x, pos.y, 0x00FF0000);
		mlx_put_image_to_window(mlx, win, img.img, 0, 0);
		// my_mlx_pixel_put(&img, pos.x, pos.y, 0x00000000);
		// mlx_put_image_to_window(mlx, win, img.img, 0, 0);
		// mlx_destroy_image(mlx, img.img);
		// img.img = mlx_new_image(mlx, 1000, 700);
		pos.x++;
		pos.y++;
	}
	mlx_loop(mlx);
	exit(EXIT_SUCCESS);
}
