/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nojia <nojia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:16:41 by nojia             #+#    #+#             */
/*   Updated: 2025/02/09 18:18:55 by nojia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	cam_look_leftright(t_minirt *minirt, double angle)
{
	double	x;
	double	z;

	x = minirt->camera->tuple_xyz.coor[0];
	z = minirt->camera->tuple_xyz.coor[2];
	minirt->camera->tuple_xyz.coor[0] = x * cos(angle) + z * sin(angle);
	minirt->camera->tuple_xyz.coor[2] = -x * sin(angle) + z * cos(angle);
	clean_window(minirt);
	display_precision(minirt);
}

void	cam_look_updown(t_minirt *minirt, double angle)
{
	t_tuple	old_cam;
	t_tuple	up;

	if ((minirt->camera->tuple_xyz.coor[1] >= 0.9 && angle < 0)
		|| (minirt->camera->tuple_xyz.coor[1] <= -0.9 && angle > 0))
		return ;
	old_cam = vec_normalization2(minirt->camera->tuple_xyz);
	if (double_abs(old_cam.coor[0]) == 0 && double_abs(old_cam.coor[1]) == 1
		&& double_abs(old_cam.coor[2]) == 0)
		up = create_tuple2(-1, 0, 0, 0);
	else
		up = create_tuple2(0, 1, 0, 0);
	up = vec_cross(vec_cross(up, old_cam), old_cam);
	up = vec_normalization2(up);
	minirt->camera->tuple_xyz.coor[0] = old_cam.coor[0] * cos(angle)
		+ up.coor[0] * sin(angle);
	minirt->camera->tuple_xyz.coor[1] = old_cam.coor[1] * cos(angle)
		+ up.coor[1] * sin(angle);
	minirt->camera->tuple_xyz.coor[2] = old_cam.coor[2] * cos(angle)
		+ up.coor[2] * sin(angle);
	minirt->camera->tuple_xyz = vec_normalization2(minirt->camera->tuple_xyz);
	clean_window(minirt);
	display_precision(minirt);
}

void	cam_go_frontback(t_minirt *minirt, int dir)
{
	minirt->camera->xyz = apply_vec_to_nbr(vec_multiplication2(
				vec_normalization2(minirt->camera->tuple_xyz), 5 * dir),
			minirt->camera->xyz);
	clean_window(minirt);
	display_precision(minirt);
}

void	cam_go_leftright(t_minirt *minirt, int left_right)
{
	t_tuple	right;
	t_tuple	up;

	if (double_abs(minirt->camera->tuple_xyz.coor[0] == 0
			&& double_abs(minirt->camera->tuple_xyz.coor[1] == 1
				&& double_abs(minirt->camera->tuple_xyz.coor[2] == 0))))
		up = create_tuple2(-1, 0, 0, 0);
	else
		up = create_tuple2(0, -1, 0, 0);
	up = vec_cross(vec_cross(up, minirt->camera->tuple_xyz),
			minirt->camera->tuple_xyz);
	right = vec_cross(up, minirt->camera->tuple_xyz);
	right = vec_multiplication2(right, left_right * 5);
	minirt->camera->xyz = apply_vec_to_nbr(right, minirt->camera->xyz);
	clean_window(minirt);
	display_precision(minirt);
}

void	cam_go_updown(t_minirt *minirt, int up_down)
{
	t_tuple	up;

	up.coor[0] = 0;
	up.coor[1] = 5;
	up.coor[2] = 0;
	minirt->camera->xyz = apply_vec_to_nbr(vec_multiplication2(up, up_down),
			minirt->camera->xyz);
	clean_window(minirt);
	display_precision(minirt);
}
