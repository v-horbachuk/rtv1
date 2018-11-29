/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:00:29 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/28 13:53:10 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	light_cylinder(t_all *all, t_vector dir)
{
	double		t;
	t_vector	tmp;
	int			i;

	i = -1;
	while (++i < all->number)
	{
		all->ray[i].point = vec_add(all->camera_tmp,
				vec_mult(dir, all->cylinder[all->objects.notation].inter.t));
		t = vec_dot_prod(vec_diff(all->ray[i].point,
				all->cylinder[all->objects.notation].center_cylinder),
						all->cylinder[all->objects.notation].dir);
		tmp = vec_add(all->cylinder[all->objects.notation].center_cylinder,
				vec_mult(all->cylinder[all->objects.notation].dir, t));
		all->ray[i].norm = vec_diff(all->ray[i].point, tmp);
		all->ray[i].norm = vec_normalize(all->ray[i].norm);
		all->ray[i].light = vec_diff(all->light_spot[i].l_position,
				all->ray[i].point);
		all->ray[i].light = vec_normalize(all->ray[i].light);
		all->ray[i].h = vec_diff(all->ray[i].light, dir);
		all->ray[i].h = vec_normalize(all->ray[i].h);
	}
}

double	cylinder_intersection(t_all *all, t_vector dir, t_vector pos, int i)
{
	t_polinome		coef;
	t_vector		a;
	t_vector		c;

	a = vec_diff(dir, vec_mult(all->cylinder[i].dir,
		vec_dot_prod(dir, all->cylinder[i].dir)));
	all->cylinder[i].inter.diff = vec_diff(pos,
		all->cylinder[i].center_cylinder);
	coef.a = vec_dot_prod(a, a);
	c = vec_diff(all->cylinder[i].inter.diff, vec_mult(all->cylinder[i].dir,
			vec_dot_prod(all->cylinder[i].inter.diff, all->cylinder[i].dir)));
	coef.c = vec_dot_prod(c, c) - pow(all->cylinder[i].radius, 2);
	coef.b = 2 * vec_dot_prod(a, c);
	all->cylinder[i].inter.t = polinomial_solver(coef);
	return (all->cylinder[i].inter.t);
}

void	draw_cylinder(t_all *all)
{
	all->mlx.img = mlx_new_image(all->mlx.mlx, WID, HIGH);
	all->mlx.gda = mlx_get_data_addr(all->mlx.img, &all->mlx.bpp,
									&all->mlx.size_l, &all->mlx.endian);
	all->cylinder = (t_cylinder*)malloc(sizeof(t_cylinder) * 1);
	get_cylinder_params(all);
	trace_obj(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
	free(all->cylinder);
}
