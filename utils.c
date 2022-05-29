/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdelad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:23:08 by aabdelad          #+#    #+#             */
/*   Updated: 2022/04/23 22:23:13 by aabdelad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	ft_map(double n, double f2, double t2)
{
	return (f2 + (n - 0) * ((t2 - f2) / (WIDTH - 0)));
}

void	check(t_vars *vars, t_cord cord, t_cord *c)
{
	if (vars->julia)
	{
		c->x = vars->julia->x;
		c->y = vars->julia->y;
	}
	else
	{
		c->x = cord.x;
		c->y = cord.y;
	}
}

int	iterations(t_vars *vars, t_cord *cord, t_cord *dos, t_cord *c)
{
	int	n;

	n = 0;
	while (n < 100)
	{
		dos->x = cord->x * cord->x - cord->y * cord->y;
		if (vars->burn == 1)
			dos->y = fabs(2 * cord->x * cord->y);
		else
			dos->y = 2 * cord->x * cord->y;
		cord->x = dos->x + c->x;
		cord->y = dos->y + c->y;
		if (cord->x * cord->x + cord->y * cord->y > 4)
		{
			return (n);
		}
		n++;
	}
	return (n);
}

int	the_color(int x, int y, t_vars *vars)
{
	int		n;
	t_cord	c;
	t_cord	dos;
	t_cord	cord;

	cord.x = ft_map (vars->origin.x + x, -vars->range, vars->range);
	cord.y = ft_map (vars->origin.y + y, -vars->range, vars->range);
	check(vars, cord, &c);
	n = iterations(vars, &cord, &dos, &c);
	return (n);
}
