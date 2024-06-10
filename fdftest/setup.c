/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:31:42 by felix             #+#    #+#             */
/*   Updated: 2024/05/27 10:30:38 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static unsigned int	get_map_size(int fd, t_terrain *terrain, char *map)
{
	unsigned int	k;
	char			*new_line;

	k = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (-1);
	}
	new_line = get_next_line(fd);
	while (new_line)
	{
		k++;
		free(new_line);
		new_line = get_next_line(fd);
	}
	free(new_line);
	terrain->height = k;
	close(fd);
	return (k);
}

static void	high_low(char **colmn, t_terrain *terrain)
{
	int	k;
	int	current;

	k = 0;
	while (colmn[k])
	{
		current = ft_atoi(colmn[k]);
		if (current < terrain->low_point)
			terrain->low_point = current;
		else if (current > terrain->high_point)
			terrain->high_point = current;
		k++;
	}
	terrain->width = k;
}

static int	fill_result(char ***result, t_terrain *terrain, int fd, char *map)
{
	char	*new_line;
	char	*trnl;
	char	**colmn;
	int		i;

	i = 0;
	colmn = NULL;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (-1);
	}
	new_line = get_next_line(fd);
	while (new_line)
	{
		trnl = ft_strtrim(new_line, "\n");
		free(new_line);
		colmn = ft_split(trnl, ' ');
		free(trnl);
		high_low(colmn, terrain);
		result[i] = colmn;
		i++;
		new_line = get_next_line(fd);
	}
	result[i] = NULL;
	close(fd);
}

int	read_terrain_map(t_terrain *terrain, char *map)
{
	char			***result;
	int				fd;

	result = (char ***)malloc(sizeof(char **)
			* (get_map_size(fd, terrain, map) + 1));
	if (!result)
		return (-1);
	fill_result(result, terrain, fd, map);
	terrain->map = result;
	return (0);
}
