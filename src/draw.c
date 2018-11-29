/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:06:51 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/28 18:06:56 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_pixel_color(t_all *all, int x, int y, int color)
{
	*((int *)(all->mlx.gda + x * all->mlx.bpp /
		8 + y * all->mlx.size_l)) = color;
}

void	get_pixel_shadow(t_all *all)
{
	all->rgb.r *= 0.5;
	all->rgb.g *= 0.5;
	all->rgb.b *= 0.5;
}

int		get_color(t_all *all, t_vector col)
{
	int	i;

	i = 0;
	all->rgb.r = 0.0;
	all->rgb.g = 0.0;
	all->rgb.b = 0.0;
	while (i < all->number)
	{
		all->rgb.r += (col.x * (AMB + DIFF * vec_dot_prod(all->ray[i].norm,
			all->ray[i].light)) + all->light_spot[i].l_color.x * SPEC *
				pow(vec_dot_prod(all->ray[i].norm, all->ray[i].h), POW));
		all->rgb.g += (col.y * (AMB + DIFF * vec_dot_prod(all->ray[i].norm,
			all->ray[i].light)) + all->light_spot[i].l_color.y * SPEC *
				pow(vec_dot_prod(all->ray[i].norm, all->ray[i].h), POW));
		all->rgb.b += (col.z * (AMB + DIFF * vec_dot_prod(all->ray[i].norm,
			all->ray[i].light)) + all->light_spot[i].l_color.z * SPEC *
				pow(vec_dot_prod(all->ray[i].norm, all->ray[i].h), POW));
		i++;
	}
	return (get_shadow(all));
}

void	trace_obj(t_all *all)
{
	t_vector	pix;
	t_vector	dir;
	int			x;
	int			y;

	y = 0;
	while (y < HIGH)
	{
		x = 0;
		while (x < WID)
		{
			pix.x = (2 * ((x + 0.5) / WID) - 1) * (WID / HIGH) * tan(FOV / 2);
			pix.y = (1 - 2 * ((y + 0.5) / HIGH)) * tan(FOV / 2);
			pix.z = all->camera.position.z - 1;
			dir = vec_diff(pix, all->camera.position);
			dir = vec_matrix_mult(all, vec_normalize(dir));
			get_object_1(all, dir, x, y);
			x++;
		}
		y++;
	}
}
