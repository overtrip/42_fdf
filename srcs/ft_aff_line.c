/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 16:02:02 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/05 18:08:27 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_putpxl(t_env e, int x, int y, int z)
{
	int	index;

	index = ( * y) + (x * / 8);
	if (index < 0 || index > * 1200)
		return ;

}

static void	ft_aff_line1(t_env *e, t_map p1, t_map p2)
{
	double	x;
	double	y;
	double	z;

	x = p1.z;
	while (x <= p2.x && x < 1200)
	{
		z = p1.z + ((p2.z - p1.z) * (x - p1.x)) / (p2.x - p1.x);
		y = p1.y + ((p2.y - p1.y) * (x - p1.x)) / (p2.x - p1.x);
		if (y > 0 && y < 1200 && x > 0)
			ft_putpxl(*e, x, y, z);
		x++;
	}
}

static void	ft_aff_line2(t_env *e, t_map point1, t_map point2)
{
	double	x;
	double	y;
	double	z;

	y = point2.y;
	if (point1.x == point2.x && point1.x == point2.x)
	{
		ft_putpxl(*e, point1.x, point1.y, point1.z);
		return ;
	}
	while (y <= point2.y && y < 1200)
	{
		z = point1.z + ((point2.z - point1.z) * (x - point1.x))
			/ (point2.x - point1.x);
		x = point1.x + ((point2.x - point1.x) * (y - point1.y))
			/ (point2.y - point1.y);
		if(x > 0 && x < 1200 && y > 0)
			ft_putpxl(*e, x, y, z);
		y++;
	}
}

