/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 18:49:15 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/04 17:35:23 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_aff_point(t_map *point, void *mlx, void *win)
{
	mlx_pixel_put(mlx, win, point->x * 15 + 15,  point->y * 15 + 15, 0xFF0000);
}

int		key_hook(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

int		expose_hook(t_env *e)
{
	e->win = e->win;
	return (0);
}

void	ft_aff_window(t_map *point)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, LENGTH, "fdf");
	mlx_key_hook(e.win, key_hook, &e);
	while (point->next)
	{
		if (!point->z)
			ft_aff_point(point, e.mlx, e.win);
		point = point->next;
	}
			ft_aff_point(point, e.mlx, e.win);
	mlx_loop(e.mlx);
	return ;
}
