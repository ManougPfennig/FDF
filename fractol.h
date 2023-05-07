/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:44:03 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/07 18:53:27 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <mlx.h>
# include "ft_printf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct pos {
	int	x;
	int	y;
}				pos;

int		main(int ac, char **av);
int		ft_strcmp(char *str, char *str2);
int		arg_parsing(int ac, char **av);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);


#endif
