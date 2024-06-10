/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:28:07 by felix             #+#    #+#             */
/*   Updated: 2024/05/27 10:10:24 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	free_map(t_terrain *terrain)
{
	int	i;
	int	k;

	i = 0;
	while (terrain->map[i])
	{
		k = 0;
		while (terrain->map[i][k])
		{
			free(terrain->map[i][k]);
			k++;
		}
		free(terrain->map[i]);
		i++;
	}
	free(terrain->map);
}

void	end_window(t_terrain *terrain)
{
	free_map(terrain);
}
