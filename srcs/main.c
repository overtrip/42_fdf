/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 17:14:23 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/06 19:57:04 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		save_map(t_map **begin, char *line, int cmp)
{
	t_map	*current;
	int		x;
	int		inc;

	inc = 0;
	x = -1;
	while (inc < (int)ft_strlen(line) && (line[inc + 1]))
	{
		current = ft_create_pos(++x, cmp, ft_atoibis(line + inc, &inc));
		ft_push_back(begin, current);
		line++;
	}
	return (0);
}

int		ft_open(char *argv)
{
	int		fd;
	char	*line;
	int		cmp;
	t_map	*begin;

	cmp = 0;
	line = NULL;
	begin = NULL;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		save_map(&begin, line, cmp);
		free(line);
		cmp++;
	}
	ft_aff_window(begin);
	close(fd);
	return (1);
}

int		main(int argc, char **argv)
{
	if (ft_error(argc, argv[1]))
		return (0);
	else
		ft_open(argv[1]);
	return (0);
}
