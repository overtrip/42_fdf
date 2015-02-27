/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 17:14:23 by jealonso          #+#    #+#             */
/*   Updated: 2015/02/27 19:29:20 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		save_map(t_map **begin, char *line, int cmp)
{
	t_map	*current;
	int		x;

	x = 0;
	while (*line)
	{
		current = ft_create_pos(x, cmp, ft_atoibis(line));
		ft_push_back(begin, current);
		x++;
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
	get_next_line(fd, &line);
	close(fd);
	return (1);
}

int		main(int argc, char **argv)
{

	if (ft_error(argc))
		return (0);
	else
	{
		ft_open(argv[1]);
		ft_aff_window();
	}
	return (0);
}
