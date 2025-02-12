/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:01:09 by nadjemia          #+#    #+#             */
/*   Updated: 2025/01/22 13:02:31 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	secured_free(void **data)
{
	if (*data)
	{
		free(*data);
		*data = NULL;
	}
}

void	free_minirt(t_minirt *minirt)
{
	if (minirt->addr_img)
		mlx_destroy_image(minirt->mlx, minirt->addr_img);
	if (minirt->win)
		mlx_destroy_window(minirt->mlx, minirt->win);
	if (minirt->mlx)
		mlx_destroy_display(minirt->mlx);
	secured_free(&minirt->mlx);
	secured_free((void **)&minirt->ambient);
	secured_free((void **)&minirt->camera);
	secured_free((void **)&minirt->light);
	free_list_shape(&minirt->cylinder);
	secured_free((void **)&minirt->cylinder);
	free_list_shape(&minirt->plan);
	secured_free((void **)&minirt->plan);
	free_list_shape(&minirt->sphere);
	secured_free((void **)&minirt->sphere);
}
