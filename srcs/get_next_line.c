/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 10:57:13 by jealonso          #+#    #+#             */
/*   Updated: 2015/02/27 18:43:37 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_get_join(char *s1, char *s2)
{
	char	*final;

	if (!(s1))
		return (ft_strdup(s2));
	if ((final = (ft_strnew((ft_strlen(s1)) + (ft_strlen(s2))))))
	{
		ft_strcpy(final, (char *)s1);
		free(s1);
		ft_strcat(final, (char *)s2);
		return (final);
	}
	return (NULL);
}

static int	ft_find(char *pos_line, char **line)
{
	char	*save;

	save = pos_line;
	while (*pos_line)
	{
		if (*pos_line == '\n')
		{
			if (!(*line = ft_strnew(pos_line - save)))
				return (-1);
			*line = ft_strncpy(*line, save, pos_line - save);
			ft_strcpy(save, pos_line + 1);
			return (1);
		}
		pos_line++;
	}
	return (0);
}

static int	ft_test(char *pos_line, char **line, int i)
{
	if (pos_line != NULL && *pos_line != '\0')
	{
		*line = ft_strdup(pos_line);
		ft_strdel(&pos_line);
		return (1);
	}
	if (i == 0 || i == -1)
		return (i);
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	int			i;
	int			size;
	static char	*pos_line = NULL;
	char		shovel[BUFF_SIZE + 1];

	if (fd == -1 || !(line))
		return (-1);
	if (pos_line)
	{
		size = ft_find(pos_line, line);
		if (size > 0)
			return (1);
	}
	while ((i = read(fd, shovel, BUFF_SIZE)))
	{
		shovel[i] = '\0';
		pos_line = ft_get_join(pos_line, shovel);
		if ((size = ft_find(pos_line, line)) > 0)
			return (1);
	}
	return (ft_test(pos_line, line, i));
}
