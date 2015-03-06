/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 16:01:30 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/06 19:51:11 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_aff_point(t_map *point, t_env e)
{
/*	if ((ABS(point->x - point->next->x) > ABS(point->y - point->next->y)))
	{
		if (point->x < point->next->x)
			ft_aff_line1(e, point, point->next);
		else
			ft_aff_lin1(e, point->next, point);
	}
	else
	{
		if (point->y < point->next->y)
			ft_aff_line2(e, *point, *point->next);
		else
			ft_aff_line2(e, *point->next, *point);
	}*/
	mlx_pixel_put(e.mlx, e.win, point->x * 15 + 15, point->y * 15 + 15, 0xFFFFFF);
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
			ft_aff_point(point, e);
		point = point->next;
	}
			ft_aff_point(point, e);
	mlx_loop(e.mlx);
	return ;
}
