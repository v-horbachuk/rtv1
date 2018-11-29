/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:08:31 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/28 18:08:33 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_prim_type_and_color(t_all *all, t_vector dir)
{
	int color;

	color = 0;
	if (ft_strcmp(all->objects.name, "Sphere") == 0)
	{
		sphere_light(all, dir);
		color = get_color(all, all->sph[all->objects.notation].col);
	}
	else if (ft_strcmp(all->objects.name, "Plane") == 0)
	{
		light_plane(all, dir);
		color = get_color(all, all->plane[all->objects.notation].col);
	}
	else if (ft_strcmp(all->objects.name, "Cylinder") == 0)
	{
		light_cylinder(all, dir);
		color = get_color(all, all->cylinder[all->objects.notation].col);
	}
	else if (ft_strcmp(all->objects.name, "Cone") == 0)
	{
		light_cone(all, dir);
		color = get_color(all, all->cone[all->objects.notation].col);
	}
	return (color);
}

void	objects_intersection(t_all *all, t_vector dir, t_vector pos)
{
	int i;

	i = -1;
	while (++i < all->objects.sph)
		sphere_intersection(all, dir, pos, i);
	i = -1;
	while (++i < all->objects.plane)
		plane_intersection(all, dir, pos, i);
	i = -1;
	while (++i < all->objects.cylinder)
		cylinder_intersection(all, dir, pos, i);
	i = -1;
	while (++i < all->objects.cone)
		cone_intersection(all, dir, pos, i);
}

void	draw_scene(t_all *all)
{
	all->mlx.img = mlx_new_image(all->mlx.mlx, WID, HIGH);
	all->mlx.gda = mlx_get_data_addr(all->mlx.img, &all->mlx.bpp,
									&all->mlx.size_l, &all->mlx.endian);
	get_scene_objects(all);
	check_all_params(all);
	trace_obj(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
	free(all->sph);
	free(all->plane);
	free(all->cylinder);
	free(all->cone);
}
