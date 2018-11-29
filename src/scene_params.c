/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:08:53 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/28 18:08:55 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	sphere_params(t_all *all)
{
	all->sph[0].center_sph = vector(-7, -2, 25);
	all->sph[0].radius = 3;
	all->sph[0].col = vector(255, 0, 0);
	all->sph[1].center_sph = vector(7, 0, -3);
	all->sph[1].radius = 5;
	all->sph[1].col = vector(255, 100, 0);
}

void	plane_params(t_all *all)
{
	all->plane[0].point = vector(0, -5, -16);
	all->plane[0].n = vec_normalize(vector(0, -1, 0));
	all->plane[0].col = vector(100, 100, 100);
	all->plane[1].point = vector(0, -1, -16);
	all->plane[1].n = vec_normalize(vector(0, 0, 1));
	all->plane[1].col = vector(100, 100, 100);
	all->plane[2].point = vector(-10, 10, -16);
	all->plane[2].n = vec_normalize(vector(1, 0, 0));
	all->plane[2].col = vector(1, 150, 100);
}

void	cylinder_params(t_all *all)
{
	all->cylinder[0].radius = 1.0;
	all->cylinder[0].center_cylinder = vector(15, 0, 10);
	all->cylinder[0].dir = vec_normalize(vector(1, -2, 3));
	all->cylinder[0].col = vector(0, 100, 100);
}

void	cone_params(t_all *all)
{
	all->cone[0].center_cone = vector(7, 0, -3);
	all->cone[0].dir = vec_normalize(vector(-1, 1, 0));
	all->cone[0].col = vector(255, 255, 0);
	all->cone[1].center_cone = vector(7, 0, -3);
	all->cone[1].dir = vec_normalize(vector(1, 1, 0));
	all->cone[1].col = vector(165, 30, 255);
}

void	check_all_params(t_all *all)
{
	all->sph = (t_sphere*)malloc(sizeof(t_sphere) * all->objects.sph);
	all->plane = (t_plane*)malloc(sizeof(t_plane) * all->objects.plane);
	all->cylinder = (t_cylinder*)malloc(sizeof(t_cylinder) *
			all->objects.cylinder);
	all->cone = (t_cone*)malloc(sizeof(t_cone) * all->objects.cone);
	sphere_params(all);
	plane_params(all);
	cylinder_params(all);
	cone_params(all);
}
