/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:42:38 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/07 16:40:47 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		perror("Error");
		ft_printf("Error: Could not mlx_init -> Program interrupted");
		exit(EXIT_FAILURE);
	}
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fract'ol");
	if (win_ptr == NULL)
	{
		perror("Error");
		ft_printf("Error: Could not open new window -> Program interrupted");
		exit(EXIT_FAILURE);
	}
	mlx_loop(mlx_ptr);
	exit(EXIT_SUCCESS);
}
