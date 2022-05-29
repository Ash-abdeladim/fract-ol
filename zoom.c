/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdelad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:23:19 by aabdelad          #+#    #+#             */
/*   Updated: 2022/04/23 22:23:22 by aabdelad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void	zoom_in(t_vars *vars)
{
	vars->range -= vars->range * .1;
}

void	zoom_out(t_vars *vars)
{
	vars->range += vars->range * .1;
}

int	zoom(int key, int x, int y, t_vars *vars)
{
	x = y;
	if (key == 5)
		zoom_in(vars);
	else if (key == 4)
		zoom_out(vars);
	draw(vars);
	return (1);
}
