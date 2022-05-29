/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdelad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:22:01 by aabdelad          #+#    #+#             */
/*   Updated: 2022/04/23 22:22:08 by aabdelad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 500
# define LEFT 123
# define RIGHT 124
# define TOP 126
# define BOTTOM 125
# define ESC 53
# define RAND 15
# define A_KEY 0

# define EXPOSE 12
# define MOTION_NOTIFY 6
# define KEYPRESS 2
# define DESTROY_NOTIFY 17

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct point
{
	double	x;
	double	y;
}	t_cord;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	double	range;
	t_img	*image;
	t_cord	*julia;
	int		animation;
	t_cord	origin;
	int		burn;
	int		color;
}	t_vars;

int		zoom(int key, int x, int y, t_vars *vars);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
double	ft_map(double n, double f2, double t2);
int		draw(t_vars *vars);
int		motion(int x, int y, t_vars *vars);
int		the_color(int x, int y, t_vars *vars);
int		key(int key, t_vars *vars);
int		keypress(int keycode, t_vars *vars);
int		destroy_window(t_vars *vars);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
void	rand_color(t_vars *vars);
#endif
