/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_t_compare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:09:08 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/28 18:09:09 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	sphere_t_compare(t_all *all)
{
	int			i;

	i = -1;
	while (++i < all->objects.sph)
	{
		if (all->sph[i].inter.t <= all->objects.t_temp
			&& all->sph[i].inter.t != 0)
		{
			all->objects.notation = i;
			all->objects.name = "Sphere";
			all->objects.t_temp = all->sph[i].inter.t;
		}
	}
}

void	cylinder_t_compare(t_all *all)
{
	int		i;

	i = -1;
	while (++i < all->objects.cylinder)
	{
		if (all->cylinder[i].inter.t <= all->objects.t_temp &&
			all->cylinder[i].inter.t != 0)
		{
			all->objects.notation = i;
			all->objects.name = "Cylinder";
			all->objects.t_temp = all->cylinder[i].inter.t;
		}
	}
}

void	cone_t_compare(t_all *all)
{
	int		i;

	i = -1;
	while (++i < all->objects.cone)
	{
		if (all->cone[i].inter.t <= all->objects.t_temp
			&& all->cone[i].inter.t != 0)
		{
			all->objects.t_temp = all->cone[i].inter.t;
			all->objects.notation = i;
			all->objects.name = "Cone";
		}
	}
}

void	plane_t_compare(t_all *all)
{
	int		i;

	i = -1;
	while (++i < all->objects.plane)
	{
		if (all->plane[i].inter.t <= all->objects.t_temp
			&& all->plane[i].inter.t != 0)
		{
			all->objects.t_temp = all->plane[i].inter.t;
			all->objects.notation = i;
			all->objects.name = "Plane";
		}
	}
}

void	compare_primitives(t_all *all)
{
	all->objects.t_temp = 10000000000;
	sphere_t_compare(all);
	plane_t_compare(all);
	cylinder_t_compare(all);
	cone_t_compare(all);
}
