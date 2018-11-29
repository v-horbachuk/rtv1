/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:02:58 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/28 16:50:29 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	light_plane(t_all *all, t_vector dir)
{
	int i;

	i = -1;
	while (++i < all->number)
	{
		all->ray[i].point = vec_add(all->camera_tmp,
				vec_mult(dir, all->plane[all->objects.notation].inter.t));
		all->ray[i].norm = all->plane[all->objects.notation].n;
		if (vec_dot_prod(all->ray[i].norm, all->ray[i].light) < 0)
			all->ray[i].norm = vec_make_negative(all->ray[i].norm);
		all->ray[i].light = vec_diff(all->light_spot[i].l_position,
				all->ray[i].point);
		all->ray[i].light = vec_normalize(all->ray[i].light);
		all->ray[i].h = vec_diff(all->ray[i].light, dir);
		all->ray[i].h = vec_normalize(all->ray[i].h);
	}
}

double	plane_intersection(t_all *all, t_vector dir, t_vector pos, int i)
{
	double	den;
	double	ch;
	double	tmp;

	all->plane[i].inter.t = 0;
	den = vec_dot_prod(all->plane[i].n, dir);
	ch = vec_dot_prod(all->plane[i].n, vec_diff(all->plane[i].point, pos));
	tmp = ch / den;
	if (den != 0 && ch != 0 && tmp > 0)
		all->plane[i].inter.t = tmp;
	return (all->plane[i].inter.t);
}

void	draw_plane(t_all *all)
{
	all->mlx.img = mlx_new_image(all->mlx.mlx, WID, HIGH);
	all->mlx.gda = mlx_get_data_addr(all->mlx.img, &all->mlx.bpp,
									&all->mlx.size_l, &all->mlx.endian);
	all->plane = (t_plane*)malloc(sizeof(t_plane) * 1);
	get_plane_params(all);
	trace_obj(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
	free(all->plane);
}
