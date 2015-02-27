/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 17:17:33 by jealonso          #+#    #+#             */
/*   Updated: 2015/02/27 17:21:13 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(int argc)
{
	if (argc <= 1)
	{
		ft_putstr("\nrespect my autority please and add a file directory\n\n");
		return (1);
	}
	return (0);
}
