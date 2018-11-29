/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:00:47 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/27 10:31:25 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

int		get_window_name(char *av, t_all *all)
{
	if (ft_strcmp(av, "Sphere") == 0 || ft_strcmp(av, "Plane") == 0 ||
			ft_strcmp(av, "Cylinder") == 0 || ft_strcmp(av, "Cone") == 0 ||
			ft_strcmp(av, "Scene") == 0)
		all->mlx.name = av;
	else
		return (0);
	return (1);
}

int		exit_rtv1(t_all *all)
{
	if (all)
		all = NULL;
	exit(0);
}

int		key_rotation(int keycode, t_all *all)
{
	if (keycode == 0)
		rot_xyz(all, 10);
	else if (keycode == 12)
		rot_xyz(all, -10);
	else if (keycode == 1)
		rot_xyz(all, 20);
	else if (keycode == 13)
		rot_xyz(all, -20);
	else if (keycode == 2)
		rot_xyz(all, 30);
	else if (keycode == 14)
		rot_xyz(all, -30);
	return (0);
}

int		key_hook(int keycode, t_all *all)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		move_xyz(all, 1);
	else if (keycode == 124)
		move_xyz(all, -1);
	else if (keycode == 126)
		move_xyz(all, -2);
	else if (keycode == 125)
		move_xyz(all, 2);
	else if (keycode == 116)
		move_xyz(all, -3);
	else if (keycode == 121)
		move_xyz(all, 3);
	key_rotation(keycode, all);
	return (0);
}
