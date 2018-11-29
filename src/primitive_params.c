/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:23:32 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/28 16:51:48 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_sphere_params(t_all *all)
{
	all->flag.color = 1;
	all->sph[0].center_sph = vector(0, 0, -10);
	all->sph[0].radius = 6.0;
	all->sph[0].col = vector(0, 180, 0);
}

void	get_plane_params(t_all *all)
{
	all->flag.color = 1;
	all->plane[0].point = vector(0, -3, -35);
	all->plane[0].n = vec_normalize(vector(0, 1, 0));
	all->plane[0].col = vector(255, 0, 255);
}

void	get_cylinder_params(t_all *all)
{
	all->flag.color = 1;
	all->cylinder[0].radius = 4.0;
	all->cylinder[0].center_cylinder = vector(0, 0, -10);
	all->cylinder[0].dir = vec_normalize(vector(0, 1, 0));
	all->cylinder[0].col = vector(255, 255, 125);
}

void	get_cone_params(t_all *all)
{
	all->flag.color = 1;
	all->cone[0].center_cone = vector(0, 0, -10);
	all->cone[0].dir = vec_normalize(vector(0, 1, 0));
	all->cone[0].col = vector(255, 255, 0);
}

void	get_scene_objects(t_all *all)
{
	all->objects.sph = 2;
	all->objects.plane = 3;
	all->objects.cylinder = 1;
	all->objects.cone = 2;
}
