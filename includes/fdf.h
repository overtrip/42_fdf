/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 17:59:27 by jealonso          #+#    #+#             */
/*   Updated: 2015/02/27 19:29:18 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <mlx.h>
# include "libft.h"
# define BUFF_SIZE 8

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
	struct s_map	*next;
}					t_map;

int					ft_error(int argc);
int					ft_open(char *argv);
int					get_next_line(int const fd, char **line);
int					save_map(t_map **begin, char *line, int cmp);
int					ft_atoibis(char *line);
int					ft_sign(char c);
void				ft_push_back(t_map **begin, t_map *new);
t_map				*ft_create_pos(int x, int y, int z);
void				ft_aff_window(t_map *map);

#endif
