/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 18:49:15 by jealonso          #+#    #+#             */
/*   Updated: 2015/02/27 19:29:16 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_aff_window(t_map *point)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 2700, 1400, "fdf");
	while (point->next)
	{
		mlx_pixel_put(mlx, win, 15, 15, 0xFF0000);
		point->next = next;
	}
	sleep(5);
}
