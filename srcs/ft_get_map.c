/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 17:16:38 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/06 19:51:16 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_create_pos(int x, int y, int z)
{
	t_map	*new;

	new = NULL;
	if ((new = (t_map *)malloc(sizeof(t_map))))
	{
		new->x = x;
		new->y = y;
		new->z = z;
		new->next = NULL;
	}
	return (new);
}

void	ft_push_back(t_map **begin, t_map *new)
{
	t_map	*cursor;

	cursor = *begin;
	if (begin)
	{
		if (*begin && new)
		{
			while (cursor->next)
				cursor = cursor->next;
			cursor->next = new;
		}
		else
			*begin = new;
	}
}

int		ft_sign(char c)
{
	if ((c == '-' || c == '+') && c != '\0')
	{
		if (c == '-')
			return (-1);
	}
	return (1);
}

int		ft_atoibis(char *line, int *x)
{
	int	cmp;
	int	sign;
	int	nb;

	cmp = -1;
	nb = 0;
	while ((line[++cmp] && line[cmp] != '-' && line[cmp] != '+'
			&& !(line[cmp] >= '0' && line[cmp] <= '9')))
		(*x)++;
	if ((sign = ft_sign(line[cmp])) == -1)
		(*x)++;
	while (line[cmp] && (line[cmp] >= '0' && line[cmp] <= '9'))
	{
		nb = nb * 10 + (line[cmp++] - '0');
		(*x)++;
	}
	return (sign * nb);
}
