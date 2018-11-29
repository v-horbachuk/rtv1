/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:09:19 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/28 18:09:20 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	find_shadow_min_t(t_all *all, int n, int len)
{
	double	t;
	int		i;

	i = 0;
	t = 0;
	while (i < len)
	{
		if (all->light_spot[n].t_shadow[i] > t)
			t = all->light_spot[n].t_shadow[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (all->light_spot[n].t_shadow[i] < t &&
				all->light_spot[n].t_shadow[i] != 0)
			t = all->light_spot[n].t_shadow[i];
		i++;
	}
	return (t);
}

double	check_shadow(t_all *all, int k)
{
	int		i;
	int		j;
	int		len;
	double	t;

	i = -1;
	j = 0;
	len = all->objects.sph + all->objects.plane + all->objects.cylinder +
			all->objects.cone;
	all->light_spot[k].t_shadow = (double*)malloc(sizeof(double) * len);
	while (++i < all->objects.sph)
		all->light_spot[k].t_shadow[j++] = all->sph[i].inter.t;
	i = -1;
	while (++i < all->objects.plane)
		all->light_spot[k].t_shadow[j++] = all->plane[i].inter.t;
	i = -1;
	while (++i < all->objects.cylinder)
		all->light_spot[k].t_shadow[j++] = all->cylinder[i].inter.t;
	i = -1;
	while (++i < all->objects.cone)
		all->light_spot[k].t_shadow[j++] = all->cone[i].inter.t;
	t = find_shadow_min_t(all, k, len);
	free(all->light_spot[k].t_shadow);
	return (t);
}

void	count_shadow(t_all *all)
{
	int			i;
	t_vector	light;
	double		t;

	i = -1;
	while (++i < all->number)
	{
		all->ray[i].point = vec_add(all->ray[i].point,
			vec_mult(all->ray[i].norm, 0.001));
		all->ray[i].light = vec_normalize(vec_diff(
			all->light_spot[i].l_position, all->ray[i].point));
		objects_intersection(all, all->ray[i].light, all->ray[i].point);
		light = vec_diff(all->light_spot[i].l_position, all->ray[i].point);
		t = check_shadow(all, i);
		if (t != 0 && t < vec_len(light))
			get_pixel_shadow(all);
	}
}

int		get_shadow(t_all *all)
{
	int		total;

	if (!all->flag.color)
		count_shadow(all);
	total = ((int)fmin(255, all->rgb.r) << 16) + ((int)fmin(255,
		all->rgb.g) << 8) + ((int)fmin(255, all->rgb.b));
	return (total);
}
