/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_units.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:05:40 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/28 18:05:53 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rot_xyz(t_all *all, double param)
{
	if (param == 10 || param == -10)
	{
		rot_x_init(param, all);
		matr_mult(all, all->matrix.m_result, all->matrix.m_x);
	}
	else if (param == 20 || param == -20)
	{
		rot_y_init(param / 2, all);
		matr_mult(all, all->matrix.m_result, all->matrix.m_y);
	}
	else if (param == 30 || param == -30)
	{
		rot_z_init(param / 3, all);
		matr_mult(all, all->matrix.m_result, all->matrix.m_z);
	}
	recalculate_object(all);
}

void	move_xyz(t_all *all, double param)
{
	if (param == 1 || param == -1)
	{
		trans_init(param / 500, 0, 0, all);
		matr_mult(all, all->matrix.m_result, all->matrix.m_trans);
	}
	else if (param == 2 || param == -2)
	{
		trans_init(0, param / 1000, 0, all);
		matr_mult(all, all->matrix.m_result, all->matrix.m_trans);
	}
	else if (param == 3 || param == -3)
	{
		trans_init(0, 0, param / 1500, all);
		matr_mult(all, all->matrix.m_result, all->matrix.m_trans);
	}
	recalculate_object(all);
}

double	polinomial_solver(t_polinome coef)
{
	double	disc;
	double	t1;
	double	t2;
	double	result;

	result = 0;
	disc = pow(coef.b, 2) - 4 * coef.a * coef.c;
	if (disc >= 0)
	{
		t1 = (-coef.b + sqrt(disc)) / (2. * coef.a);
		t2 = (-coef.b - sqrt(disc)) / (2. * coef.a);
		if (t1 > 0 || t2 > 0)
		{
			if (t1 < 0 || t2 < 0)
				result = fmax(t1, t2);
			else
				result = fmin(t1, t2);
			return (result);
		}
	}
	return (result);
}

void	get_object_2(t_all *all, t_vector dir, int x, int y)
{
	if (ft_strcmp(all->mlx.name, "Cone") == 0)
	{
		if (cone_intersection(all, dir, all->camera_tmp, 0) != 0)
		{
			light_cone(all, dir);
			get_pixel_color(all, x, y, get_color(all, all->cone[0].col));
		}
	}
	else if (ft_strcmp(all->mlx.name, "Cylinder") == 0)
	{
		if (cylinder_intersection(all, dir, all->camera_tmp, 0) != 0)
		{
			light_cylinder(all, dir);
			get_pixel_color(all, x, y, get_color(all,
				all->cylinder[0].col));
		}
	}
	else if (ft_strcmp(all->mlx.name, "Scene") == 0)
	{
		objects_intersection(all, dir, all->camera_tmp);
		compare_primitives(all);
		get_pixel_color(all, x, y, get_prim_type_and_color(all, dir));
	}
}

void	get_object_1(t_all *all, t_vector dir, int x, int y)
{
	if (ft_strcmp(all->mlx.name, "Sphere") == 0)
	{
		if (sphere_intersection(all, dir, all->camera_tmp, 0) != 0)
		{
			sphere_light(all, dir);
			get_pixel_color(all, x, y, get_color(all, all->sph[0].col));
		}
	}
	else if (ft_strcmp(all->mlx.name, "Plane") == 0)
	{
		if (plane_intersection(all, dir, all->camera_tmp, 0) != 0)
		{
			light_plane(all, dir);
			get_pixel_color(all, x, y, get_color(all, all->plane[0].col));
		}
	}
	get_object_2(all, dir, x, y);
}
