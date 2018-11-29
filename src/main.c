/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:01:12 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/28 18:55:58 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw_primitives(t_all *all)
{
	if (ft_strcmp(all->mlx.name, "Sphere") == 0)
		draw_sphere(all);
	else if (ft_strcmp(all->mlx.name, "Plane") == 0)
		draw_plane(all);
	else if (ft_strcmp(all->mlx.name, "Cylinder") == 0)
		draw_cylinder(all);
	else if (ft_strcmp(all->mlx.name, "Cone") == 0)
		draw_cone(all);
	else if (ft_strcmp(all->mlx.name, "Scene") == 0)
		draw_scene(all);
}

void	first_ray_trace(t_all *all, int number)
{
	all->number = number;
	all->light_spot = (t_light_spot*)malloc(sizeof(t_light_spot) * all->number);
	all->ray = (t_ray*)malloc(sizeof(t_ray) * number);
	all->camera.position = vector(0, 0, 50);
	all->camera_tmp = all->camera.position;
	rot_x_init(0, all);
	rot_y_init(0, all);
	rot_z_init(0, all);
	matr_mult(all, all->matrix.m_x, all->matrix.m_y);
	matr_mult(all, all->matrix.m_result, all->matrix.m_z);
	all->camera_tmp = vec_matrix_mult(all, all->camera_tmp);
	all->light_spot[0].l_position = vector(10, 0, 50);
	all->light_spot[0].l_color = vector(100, 100, 100);
	draw_primitives(all);
}

int		recalculate_object(t_all *all)
{
	mlx_destroy_image(all->mlx.mlx, all->mlx.img);
	mlx_clear_window(all->mlx.mlx, all->mlx.win);
	all->camera_tmp = all->camera.position;
	all->camera_tmp = vec_matrix_mult(all, all->camera_tmp);
	all->mlx.img = mlx_new_image(all->mlx.mlx, WID, HIGH);
	all->mlx.gda = mlx_get_data_addr(all->mlx.img, &all->mlx.bpp,
		&all->mlx.size_l, &all->mlx.endian);
	draw_primitives(all);
	return (0);
}

void	mlx_define(t_all *all)
{
	all->mlx.mlx = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.mlx, WID, HIGH, all->mlx.name);
	first_ray_trace(all, 1);
	mlx_expose_hook(all->mlx.win, recalculate_object, all);
	mlx_hook(all->mlx.win, 2, 3, key_hook, all);
	mlx_hook(all->mlx.win, 17, 1L << 17, exit_rtv1, &all);
	mlx_loop(all->mlx.mlx);
}

int		main(int ac, char **av)
{
	t_all	all;

	if (ac != 2 || !(av[0]) || get_window_name(av[1], &all) == 0)
	{
		ft_putstr("usage:\n");
		ft_putstr("       Do ./RTv1 <primitive name>\n");
		ft_putstr("           Primitive names:\n");
		ft_putstr("           Sphere\n");
		ft_putstr("           Plane\n");
		ft_putstr("           Cylinder\n");
		ft_putstr("           Cone\n");
		ft_putstr("           Scene\n");
		exit(0);
	}
	mlx_define(&all);
	return (0);
}
