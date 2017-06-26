/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slover_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:56:02 by ycao              #+#    #+#             */
/*   Updated: 2017/06/24 18:21:18 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "global.h"

char	**ft_putmap_check(t_data *data, char **map, int *i, int mapsize)
{
	int		a;
	int		b;
	char	temp;

	a = -1;
	while (++a <= (data->point[2] - data->point[0]))
	{
		b = -1;
		while (++b <= (data->point[3] - data->point[1]))
		{
			temp = ft_point_check(
				data->tetr[data->point[0] + a][data->point[1] + b],
				map[i[0] + a][i[1] + b]);
			if (temp)
				map[a + i[0]][b + i[1]] = temp;
			if (!temp)
			{
				ft_map_clean(map, data->n, mapsize);
				return (NULL);
			}
		}
	}
	return (map);
}

char	**ft_try_map(t_data *data, char **map, int mapsize, int *i)
{
	int a[2];

	if (((i[0] + (data->point[2] - data->point[0])) >= mapsize)
			|| ((i[1] + (data->point[3] - data->point[1])) >= mapsize))
		return (NULL);
	if ((ft_putmap_check(data, map, i, mapsize)))
	{
		if (!data->next)
			return (map);
		a[0] = -1;
		while (++a[0] < mapsize)
		{
			a[1] = -1;
			while (++a[1] < mapsize)
			{
				if (ft_try_map(data->next, map, mapsize, a))
					return (map);
			}
		}
	}
	ft_map_clean(map, data->n, mapsize);
	return (NULL);
}

char	**ft_checkmap_samemapsize(t_data *data, int mapsize, char **map)
{
	int i[2];

	i[0] = -1;
	while (++i[0] < mapsize)
	{
		i[1] = -1;
		while (++i[1] < mapsize)
		{
			if (ft_try_map(data, map, mapsize, i))
				return (map);
		}
	}
	return (NULL);
}

char	**ft_give_me_map(t_list *list, t_data *data)
{
	int		mapsize;
	char	**map;

	mapsize = ft_minmapsize(g_num);
	data = ft_give_me_data(list, data);
	map = ft_init_map(mapsize);
	while ((ft_checkmap_samemapsize(data, mapsize, map)) == NULL)
	{
		ft_free_map(map, mapsize);
		mapsize++;
		map = ft_init_map(mapsize);
	}
	return (map);
}
