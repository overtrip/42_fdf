/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 17:59:27 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/06 19:52:13 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft.h"
# define BUFF_SIZE 8
# define WIDTH 2700
# define LENGTH 1400

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
	struct s_map	*next;
}					t_map;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

int					ft_error(int argc, char *argv);
int					ft_open(char *argv);
int					get_next_line(int const fd, char **line);
int					save_map(t_map **begin, char *line, int cmp);
int					ft_atoibis(char *line, int *x);
int					ft_sign(char c);
void				ft_aff_window(t_map *point);
void				ft_push_back(t_map **begin, t_map *new);
t_map				*ft_create_pos(int x, int y, int z);
void				ft_aff_poit(t_map *point, t_env *e);
/*static void			ft_putpxl(t_env e, int x, int y, int z);
static void			ft_aff_line1(t_env *e, t_map point1, t_map point2);
static void			ft_aff_line2(t_env *e, t_map point1, t_map point2);
*/
#endif
