/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:42:38 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/07 17:46:06 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (arg_parsing(ac, av))
		exit(EXIT_FAILURE);
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		perror("Error");
		ft_printf("Error: Could not mlx_init -> Program interrupted\n");
		exit(EXIT_FAILURE);
	}
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fract'ol");
	if (win_ptr == NULL)
	{
		perror("Error");
		ft_printf("Error: Could not open new window -> Program interrupted\n");
		exit(EXIT_FAILURE);
	}
	mlx_loop(mlx_ptr);
	exit(EXIT_SUCCESS);
}
