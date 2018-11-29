/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:09:52 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/28 18:09:54 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	vector(double a, double b, double c)
{
	t_vector result;

	result.x = a;
	result.y = b;
	result.z = c;
	return (result);
}

t_vector	vec_normalize(t_vector vec)
{
	t_vector	result;
	double		len;

	len = vec_len(vec);
	result.x = vec.x / len;
	result.y = vec.y / len;
	result.z = vec.z / len;
	return (result);
}

double		vec_len(t_vector vec)
{
	double len;

	len = sqrt(vec_dot_prod(vec, vec));
	return (len);
}

t_vector	vec_make_negative(t_vector vec)
{
	t_vector result;

	result.x = -vec.x;
	result.y = -vec.y;
	result.z = -vec.z;
	return (result);
}

t_vector	vec_matrix_mult(t_all *all, t_vector vec)
{
	t_vector result;

	result.x = all->matrix.m_result.matr[0][0] * vec.x +
			all->matrix.m_result.matr[0][1] * vec.y +
			all->matrix.m_result.matr[0][2] * vec.z +
			all->matrix.m_result.matr[0][3];
	result.y = all->matrix.m_result.matr[1][0] * vec.x +
			all->matrix.m_result.matr[1][1] * vec.y +
			all->matrix.m_result.matr[1][2] * vec.z +
			all->matrix.m_result.matr[1][3];
	result.z = all->matrix.m_result.matr[2][0] * vec.x +
			all->matrix.m_result.matr[2][1] * vec.y +
			all->matrix.m_result.matr[2][2] * vec.z +
			all->matrix.m_result.matr[2][3];
	return (result);
}
