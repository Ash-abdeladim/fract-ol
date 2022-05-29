/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdelad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:22:56 by aabdelad          #+#    #+#             */
/*   Updated: 2022/04/23 22:23:00 by aabdelad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw(t_vars *vars)
{
	int		x;
	int		y;
	int		color;
	int		n;
	int		maxiteration;

	y = 0;
	maxiteration = 100;
	color = 0;
	while (y++ < WIDTH)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			n = the_color(x, y, vars);
			if (n == maxiteration)
				color = 0;
			else
				color = (vars->color * n);
			my_mlx_pixel_put(vars->image, x, y, color);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image->img, 0, 0);
	return (0);
}

void	pick_fract(t_vars *vars, char fract)
{
	if (fract != 'b')
		vars->julia = NULL;
	if (fract != 'c')
		vars->burn = 0;
}

void	ft_init(t_vars *vars, t_cord *julia)
{
	vars->origin.x = 0;
	vars->origin.y = 0;
	vars->burn = 1;
	vars->julia = julia;
	vars->color = 0x124500;
}

void	setup(char fract)
{
	t_vars	vars;
	t_img	image;
	t_cord	julia;

	julia.x = 0.7;
	julia.y = 0.4;
	ft_init(&vars, &julia);
	pick_fract(&vars, fract);
	vars.range = 2;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, WIDTH, "fractol");
	vars.image = &image;
	vars.image->img = mlx_new_image(vars.mlx, WIDTH, WIDTH);
	vars.image->addr = mlx_get_data_addr(vars.image->img,
			&vars.image->bits_per_pixel,
			&vars.image->line_length, &vars.image->endian);
	mlx_hook(vars.win, EXPOSE, 0, draw, &vars);
	mlx_hook(vars.win, MOTION_NOTIFY, 0, motion, &vars);
	mlx_hook(vars.win, KEYPRESS, 0, keypress, &vars);
	mlx_hook(vars.win, DESTROY_NOTIFY, 0, destroy_window, &vars);
	mlx_mouse_hook(vars.win, zoom, &vars);
	mlx_key_hook(vars.win, key, &vars);
	mlx_loop(vars.mlx);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putstr("fractol a -> Mandelbrot\nfractol b -> Julia\n");
		ft_putstr("fractol c -> burningship\n");
		return (0);
	}
	else if (ac == 2)
	{
		if (av[1][1] == 0 && av[1][0] >= 'a' && av[1][0] < 'd')
			setup(av[1][0]);
		else
		{
			ft_putstr("fractol a -> Mandelbrot\nfractol b -> Julia\n");
			ft_putstr("fractol c -> burningship\n");
			return (0);
		}
	}
	else
	{
		ft_putstr("fractol a -> Mandelbrot\n");
		ft_putstr("fractol b -> Julia\n");
		ft_putstr("fractol c -> burningship\n");
		return (0);
	}
	return (0);
}
