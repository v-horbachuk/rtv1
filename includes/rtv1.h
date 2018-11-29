/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:11:59 by vhorbach          #+#    #+#             */
/*   Updated: 2018/11/28 17:38:39 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "../libft/libft.h"
# define FOV 45 * M_PI / 180
# define HIGH 800
# define WID 1200.
# define AMB 0.195
# define DIFF 0.5
# define SPEC 0.4
# define POW  100

typedef struct		s_matrix_prim
{
	double			matr[4][4];
}					t_matrix_prim;

typedef struct		s_matrix
{
	t_matrix_prim	m_x;
	t_matrix_prim	m_y;
	t_matrix_prim	m_z;
	t_matrix_prim	m_result;
	t_matrix_prim	m_trans;
}					t_matrix;

typedef struct		s_objects
{
	int				sph;
	int				plane;
	int				cylinder;
	int				cone;
	int				notation;
	double			t_temp;
	char			*name;
}					t_objects;

typedef struct		s_polinome
{
	double			a;
	double			b;
	double			c;
}					t_polinome;

typedef struct		s_flag
{
	int				color;
}					t_flag;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_intersect
{
	double			t;
	t_vector		diff;
}					t_intersect;

typedef struct		s_camera
{
	t_vector		position;
}					t_camera;

typedef struct		s_ray
{
	t_vector		point;
	t_vector		light;
	t_vector		norm;
	t_vector		h;
}					t_ray;

typedef struct		s_light_spot
{
	t_vector		l_position;
	t_vector		l_color;
	double			*t_shadow;
}					t_light_spot;

typedef struct		s_plane
{
	t_vector		n;
	t_vector		point;
	t_vector		col;
	t_intersect		inter;
}					t_plane;

typedef struct		s_sphere
{
	t_vector		center_sph;
	t_vector		col;
	double			radius;
	t_intersect		inter;
}					t_sphere;

typedef struct		s_cylinder
{
	t_vector		center_cylinder;
	t_vector		dir;
	double			radius;
	t_vector		col;
	t_intersect		inter;
}					t_cylinder;

typedef struct		s_cone
{
	t_vector		center_cone;
	t_vector		dir;
	t_vector		col;
	t_intersect		inter;
}					t_cone;

typedef struct		s_spectre
{
	double			r;
	double			g;
	double			b;
}					t_spectre;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*gda;
	char			*name;
	int				bpp;
	int				size_l;
	int				endian;
}					t_mlx;

typedef struct		s_all
{
	t_sphere		*sph;
	t_plane			*plane;
	t_cylinder		*cylinder;
	t_cone			*cone;
	t_mlx			mlx;
	t_camera		camera;
	t_light_spot	*light_spot;
	t_ray			*ray;
	t_objects		objects;
	t_flag			flag;
	t_matrix		matrix;
	t_vector		camera_tmp;
	t_spectre		rgb;
	int				number;
}					t_all;

/*
** vector_1.c and vector_2.c
*/

t_vector			vector(double a, double b, double c);
double				vec_dot_prod(t_vector vec, t_vector vec1);
t_vector			vec_diff(t_vector vec, t_vector vec1);
t_vector			vec_make_negative(t_vector vec);
t_vector			vec_normalize(t_vector vec);
double				vec_len(t_vector vec);
t_vector			vec_mult(t_vector vec, double a);
t_vector			vec_add(t_vector vec, t_vector vec1);
t_vector			vec_matrix_mult(t_all *all, t_vector vec);

/*
** keycodes.c
*/

int					exit_rtv1(t_all *all);
int					key_hook(int keycode, t_all *all);
int					key_rotation(int keycode, t_all *all);
int					get_window_name(char *av, t_all *all);

/*
** main.c
*/

void				mlx_define(t_all *all);
int					recalculate_object(t_all *all);
void				first_ray_trace(t_all *all, int number);
void				draw_primitives(t_all *all);

/*
** matrix.c
*/

void				rot_x_init(double deg, t_all *all);
void				rot_y_init(double deg, t_all *all);
void				rot_z_init(double deg, t_all *all);
void				matr_mult(t_all *all, t_matrix_prim m1, t_matrix_prim m2);
void				trans_init(double x, double y, double z, t_all *all);

/*
** params.c
*/

void				check_all_params(t_all *all);
void				cone_params(t_all *all);
void				cylinder_params(t_all *all);
void				plane_params(t_all *all);
void				sphere_params(t_all *all);

/*
** scene.c
*/

void				draw_scene(t_all *all);
int					get_prim_type_and_color(t_all *all, t_vector dir);
void				objects_intersection(t_all *all, t_vector dir,
						t_vector pos);

/*
** sphere.c
*/

void				draw_sphere(t_all *all);
double				sphere_intersection(t_all *all, t_vector dir,
						t_vector pos, int i);
void				sphere_light(t_all *all, t_vector dir);

/*
** plane.c
*/

void				draw_plane(t_all *all);
double				plane_intersection(t_all *all, t_vector dir,
						t_vector pos, int i);
void				light_plane(t_all *all, t_vector dir);

/*
** cylinder.c
*/

void				draw_cylinder(t_all *all);
double				cylinder_intersection(t_all *all, t_vector dir,
						t_vector pos, int i);
void				light_cylinder(t_all *all, t_vector dir);

/*
** cone.c
*/

void				draw_cone(t_all *all);
double				cone_intersection(t_all *all, t_vector dir,
						t_vector pos, int i);
void				light_cone(t_all *all, t_vector dir);

/*
** shadows.c
*/

int					get_shadow(t_all *all);
double				find_shadow_min_t(t_all *all, int k, int len);
double				check_shadow(t_all *all, int k);
void				count_shadow(t_all *all);

/*
** scene_t_compare.c
*/

void				compare_primitives(t_all *all);
void				cone_t_compare(t_all *all);
void				cylinder_t_compare(t_all *all);
void				plane_t_compare(t_all *all);
void				sphere_t_compare(t_all *all);

/*
** change_units.c
*/

void				move_xyz(t_all *all, double param);
void				rot_xyz(t_all *all, double param);
double				polinomial_solver(t_polinome polinome);
void				get_object_1(t_all *all, t_vector dir, int x, int y);
void				get_object_2(t_all *all, t_vector dir, int x, int y);

/*
** primitive_params.c
*/

void				get_sphere_params(t_all *all);
void				get_plane_params(t_all *all);
void				get_cylinder_params(t_all *all);
void				get_cone_params(t_all *all);
void				get_scene_objects(t_all *all);

/*
** draw.c
*/

void				trace_obj(t_all *all);
void				get_pixel_shadow(t_all *all);
int					get_color(t_all *all, t_vector col);
void				get_pixel_color(t_all *all, int x, int y, int color);

#endif
