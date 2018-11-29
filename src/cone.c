/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:00:05 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/28 14:10:19 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	cone_intersection(t_all *all, t_vector dir, t_vector pos, int i)
{
	t_polinome		coef;
	t_vector		a;
	t_vector		c;

	dir = vec_normalize(dir);
	all->cone[i].inter.diff = vec_diff(pos, all->cone[i].center_cone);
	a = vec_diff(dir, vec_mult(all->cone[i].dir,
				vec_dot_prod(dir, all->cone[i].dir)));
	coef.a = pow(cos(20 * M_PI / 180), 2) * vec_dot_prod(a, a) -
		pow(sin(20 * M_PI / 180), 2) * pow(vec_dot_prod(dir,
				all->cone[i].dir), 2);
	c = vec_diff(all->cone[i].inter.diff, vec_mult(all->cone[i].dir,
		vec_dot_prod(all->cone[i].inter.diff, all->cone[i].dir)));
	coef.c = pow(cos(20 * M_PI / 180), 2) * vec_dot_prod(c, c) -
		pow(sin(20 * M_PI / 180), 2) *
			pow(vec_dot_prod(all->cone[i].inter.diff, all->cone[i].dir), 2);
	coef.b = 2 * (pow(cos(20 * M_PI / 180), 2) * vec_dot_prod(a, c) -
			pow(sin(20 * M_PI / 180), 2) * vec_dot_prod(dir, all->cone[i].dir)
			* vec_dot_prod(all->cone[i].inter.diff, all->cone[i].dir));
	all->cone[i].inter.t = polinomial_solver(coef);
	return (all->cone[i].inter.t);
}

void	light_cone(t_all *all, t_vector dir)
{
	double		t;
	t_vector	vec_temp;
	t_vector	b;
	int			i;

	i = -1;
	while (++i < all->number)
	{
		all->ray[i].point = vec_add(all->camera_tmp,
			vec_mult(dir, all->cone[all->objects.notation].inter.t));
		vec_temp = vec_diff(all->ray[i].point,
			all->cone[all->objects.notation].center_cone);
		t = vec_dot_prod(vec_normalize(vec_temp),
			all->cone[all->objects.notation].dir);
		b = vec_mult(all->cone[all->objects.notation].dir,
			sqrt(vec_dot_prod(vec_temp, vec_temp)) / t);
		all->ray[i].norm = vec_normalize(vec_diff(vec_temp, b));
		all->ray[i].light = vec_diff(all->light_spot[i].l_position,
			all->ray[i].point);
		all->ray[i].light = vec_normalize(all->ray[i].light);
		all->ray[i].h = vec_diff(all->ray[i].light, dir);
		all->ray[i].h = vec_normalize(all->ray[i].h);
	}
}

void	draw_cone(t_all *all)
{
	all->mlx.img = mlx_new_image(all->mlx.mlx, WID, HIGH);
	all->mlx.gda = mlx_get_data_addr(all->mlx.img, &all->mlx.bpp,
			&all->mlx.size_l, &all->mlx.endian);
	all->cone = (t_cone*)malloc(sizeof(t_cone) * 1);
	get_cone_params(all);
	trace_obj(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
	free(all->cone);
}
