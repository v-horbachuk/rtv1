/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:09:41 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/28 18:09:43 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		vec_dot_prod(t_vector vec, t_vector vec1)
{
	double result;

	result = vec.x * vec1.x + vec.y * vec1.y + vec.z * vec1.z;
	return (result);
}

t_vector	vec_diff(t_vector vec, t_vector vec1)
{
	t_vector result;

	result.x = vec.x - vec1.x;
	result.y = vec.y - vec1.y;
	result.z = vec.z - vec1.z;
	return (result);
}

t_vector	vec_mult(t_vector vec, double a)
{
	t_vector result;

	result.x = vec.x * a;
	result.y = vec.y * a;
	result.z = vec.z * a;
	return (result);
}

t_vector	vec_add(t_vector vec, t_vector vec1)
{
	t_vector result;

	result.x = vec.x + vec1.x;
	result.y = vec.y + vec1.y;
	result.z = vec.z + vec1.z;
	return (result);
}
