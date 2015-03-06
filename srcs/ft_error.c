/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 17:17:33 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/06 19:56:42 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(int argc, char *argv)
{
	int fd;
	if (argc <= 1)
	{
		ft_putstr("\n\trespect my autority please and add a file directory\n\n");
		return (1);
	}

	if ((fd = open(argv, O_RDONLY)) == -1)
	{
		ft_putstr("\n\trespect my autority please, this file doesn't exist\n\n");
		return (1);
	}

	return (0);
}
