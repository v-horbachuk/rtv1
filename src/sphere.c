/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:05:09 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/28 16:57:46 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	sphere_intersection(t_all *all, t_vector dir, t_vector pos, int i)
{
	t_polinome		coef;
	t_vector		tmp;

	tmp = pos;
	all->sph[i].inter.diff = vec_diff(tmp, all->sph[i].center_sph);
	coef.a = vec_dot_prod(dir, dir);
	coef.b = 2 * vec_dot_prod(dir, all->sph[i].inter.diff);
	coef.c = vec_dot_prod(all->sph[i].inter.diff,
			all->sph[i].inter.diff) - all->sph[i].radius * all->sph[i].radius;
	all->sph[i].inter.t = polinomial_solver(coef);
	return (all->sph[i].inter.t);
}

void	sphere_light(t_all *all, t_vector dir)
{
	int i;

	i = -1;
	while (++i < all->number)
	{
		all->ray[i].point = vec_add(all->camera_tmp, vec_mult(dir,
				all->sph[all->objects.notation].inter.t));
		all->ray[i].norm = vec_diff(all->ray[i].point,
				all->sph[all->objects.notation].center_sph);
		all->ray[i].norm = vec_normalize(all->ray[i].norm);
		all->ray[i].light = vec_diff(all->light_spot[i].l_position,
				all->ray[i].point);
		all->ray[i].light = vec_normalize(all->ray[i].light);
		all->ray[i].h = vec_diff(all->ray[i].light, dir);
		all->ray[i].h = vec_normalize(all->ray[i].h);
	}
}

void	draw_sphere(t_all *all)
{
	all->mlx.img = mlx_new_image(all->mlx.mlx, WID, HIGH);
	all->mlx.gda = mlx_get_data_addr(all->mlx.img, &all->mlx.bpp,
									&all->mlx.size_l, &all->mlx.endian);
	all->sph = (t_sphere*)malloc(sizeof(t_sphere) * 1);
	get_sphere_params(all);
	trace_obj(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
	free(all->sph);
}
