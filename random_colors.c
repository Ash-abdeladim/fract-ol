/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdelad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:22:19 by aabdelad          #+#    #+#             */
/*   Updated: 2022/04/23 22:22:27 by aabdelad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	rand_color(t_vars *vars)
{
	if (vars->color == 0x124500)
		vars->color = 0xff0600;
	else if (vars->color == 0xff0600)
		vars->color = 0x050000;
	else if (vars->color == 0x050000)
		vars->color = 0xcbcfd3;
	else if (vars->color == 0xcbcfd3)
		vars->color = 0xf9fbff;
	else if (vars->color == 0xf9fbff)
		vars->color = 0x85143;
	else if (vars->color == 0x85143)
		vars->color = 0x124500;
	else if (vars->color == 0x124500)
		vars->color = 0x40916c;
}
