/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:44:03 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/23 16:25:58 by mapfenni         ###   ########.fr       */
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
# include <math.h>
# include <complex.h>

# define UI_MAX 4294967295
# define MAX_ITER 80

typedef struct	s_data {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*win;
	int				x;
	int				y;
	int				math_x;
	int				math_y;
	int				dir;
	int				left;
	int				right;
	int				up;
	int				down;
	int				size;
	unsigned int	color;
	double			c;
}				t_data;

int				main(int ac, char **av);
int				ft_strcmp(char *str, char *str2);
int				arg_parsing(int ac, char **av);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				deal_key(t_data *params);
void			generate_mandelbrot(t_data *data);
int				key_release(int key, t_data *data);
int				key_pressed(int key, t_data *data);
int				ft_destroy_windows(t_data *data);
unsigned int	new_color(t_data *data);
int				test_for_two(t_data *data);


#endif
