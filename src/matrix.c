/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:02:15 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/27 10:37:37 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		matr_mult(t_all *all, t_matrix_prim m1, t_matrix_prim m2)
{
	int		i;
	int		j;
	int		k;
	double	sum;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = 0;
			sum = 0;
			while (k++ < 4)
			{
				sum += m1.matr[i][k - 1] * m2.matr[k - 1][j];
				all->matrix.m_result.matr[i][j] = sum;
			}
		}
	}
}

void		trans_init(double x, double y, double z, t_all *all)
{
	all->matrix.m_trans.matr[0][0] = 1;
	all->matrix.m_trans.matr[1][1] = 1;
	all->matrix.m_trans.matr[2][2] = 1;
	all->matrix.m_trans.matr[3][3] = 1;
	all->matrix.m_trans.matr[0][3] = x;
	all->matrix.m_trans.matr[1][3] = y;
	all->matrix.m_trans.matr[2][3] = z;
}

void		rot_x_init(double deg, t_all *all)
{
	double	rad;

	rad = M_PI * deg / 180;
	all->matrix.m_x.matr[0][0] = 1;
	all->matrix.m_x.matr[1][1] = cos(rad);
	all->matrix.m_x.matr[1][2] = -sin(rad);
	all->matrix.m_x.matr[2][1] = sin(rad);
	all->matrix.m_x.matr[2][2] = cos(rad);
	all->matrix.m_x.matr[3][3] = 1;
}

void		rot_y_init(double deg, t_all *all)
{
	double	rad;

	rad = M_PI * deg / 180;
	all->matrix.m_y.matr[0][0] = cos(rad);
	all->matrix.m_y.matr[0][2] = sin(rad);
	all->matrix.m_y.matr[1][1] = 1;
	all->matrix.m_y.matr[2][0] = -sin(rad);
	all->matrix.m_y.matr[2][2] = cos(rad);
	all->matrix.m_y.matr[3][3] = 1;
}

void		rot_z_init(double deg, t_all *all)
{
	double	rad;

	rad = M_PI * deg / 180;
	all->matrix.m_z.matr[0][0] = cos(rad);
	all->matrix.m_z.matr[0][1] = -sin(rad);
	all->matrix.m_z.matr[1][0] = sin(rad);
	all->matrix.m_z.matr[1][1] = cos(rad);
	all->matrix.m_z.matr[2][2] = 1;
	all->matrix.m_z.matr[3][3] = 1;
}
