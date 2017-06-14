/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slover.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:56:02 by ycao              #+#    #+#             */
/*   Updated: 2017/05/01 14:56:25 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"
# include "global.h"

int	ft_minmapsize(int num)
{
	if (num == 1)
		return (2);
	if (num == 2)
		return (3);
	if (num == 4)
		return (4);
	if (num == 6)
		return (5);
	if (num == 9)
		return (6);
	if (num == 12)
		return (7);
	if (num <= 16)
		return (8);
	if (num <= 20)
		return (9);
	if (num <= 25)
		return (10);
	return (11); /* how to calculate: int(sqrt(num * 4)), if it more than 25, just let it go  */
}

char **ft_init_map(int mapsize)
{
	char **map;
	int		i;
	int		j;

	i = -1;
	map = (char**)malloc(sizeof(char*) * mapsize + 1);
	map[mapsize] = NULL;
	while(++i < mapsize)
	{
		j = -1;
		map[i] = (char*)malloc(sizeof(char) * (mapsize + 1));
		while(++j < mapsize)
			map[i][j] = '.';
		map[i][mapsize] = '\0';
	}
	return (map);
}

void ft_free_map(char **map, int mapsize)
{
	int		i;

	i = -1;

	while(++i < mapsize)
		free(map[i]);
		/*mark */
	ft_putstr(" something is wrong here, free map here we go\n");
		/*mark */
	free(map);
}

char     ft_point_check(char a_data, char b_map)
{

	if(b_map != '.' && a_data != '.')
		return (0); /* then clean data */
	if(b_map != '.' && a_data == '.')
		return (b_map);
	else
	return (a_data);
}

char		**ft_map_clean(char **map, int n, int mapsize)/*clean in every layer */
{
	/*when can not put data in the map, clean it */
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < mapsize)
	{
		while (++j < mapsize)
		{
			if (map[i][j] == letter[n])
				map[i][j] = '.';
		}
	}
	return (map);
}

char	**ft_putmap_check(t_data *data, char **map, int i, int j, int mapsize)
{
	/*put data in the map, from point [i, j] */
	int a;
	int b;
	char temp;

	int n = 0;
	a = -1;
	while (++a <= (data->point[2] - data->point[0]))
	{
		b = -1;
		/*mark */
		// char s = 48 + a;
		// ft_putchar(s);
		  //ft_putstr("next\n");
		/*mark */
		while (++b <= (data->point[3] - data->point[1]))
		{
			/*mark */
			char s = 48 + n;
			ft_putchar(s);
			 ft_putstr(" mark\n");
			 n++;
			/*mark */
			temp = ft_point_check(data->tetr[data->point[0] + a][data->point[1] + b], map[i + a][j + b]); /* can put it or not */

			if (temp)
				map[a + i][b + j] = temp;
			if (!temp)
			{
				/*mark */
				  ft_putchar('W');
					ft_putchar('\n');
				/*mark */
				ft_map_clean(map, data->n, mapsize);
				/*mark */
				  ft_putchar('Q');
					ft_putchar('\n');
					return (NULL);
			}
		}
	}
	//ft_printmap(map);
	return (map);
}

char		**ft_try_map(t_data *data, char** map, int mapsize)
{
	/* in this mapsize, try to find if all the data can be put in it */
	int i;
	int j;

	i = -1;
	while (++i < mapsize)
	{
		j = -1;
		while (++j < mapsize)
		{
			/*mark */
			 //ft_putstr("1 mark here we go\n");
			/*mark */
			if(((i + (data->point[2] - data->point[0])) > mapsize) || ((j + (data->point[3] - data->point[1])) > mapsize))
			{
				continue;/* I have question here, have to ask zhuzhu ^-^ */
			}
			/*mark */
			// char d = 48 + j;
			//  ft_putchar(d);
			/*mark */
			if ((ft_putmap_check(data, map, i, j, mapsize)) == NULL)
			{
				if (!data->next)
				{
					ft_putstr("!data return NULL here\n");
					return (NULL);
				}
				else
					continue;
			}

			ft_printmap(map);

			/*mark */
			ft_putstr("putmap check here we go\n");
			/*mark */
			if (!data->next)
				return (map);
			if (ft_try_map(data->next, map, mapsize)) /*data->next ?? what is it? */
			{
						/*mark */
						 //ft_putstr("mark continue here we go\n");
						/*mark */
						return (map);
			}
			if (!ft_try_map(data->next, map, mapsize) && !data->next)
			{
				return (NULL);
			}
		}
	}
	ft_map_clean(map, data->n, mapsize);
	return (NULL);
}

char	**ft_give_me_map(t_list *list, t_data *data)
{
	int		mapsize;
	char	**map;

	mapsize = ft_minmapsize(num); /* min mapsize, then add it one by one */
	data = ft_give_me_data(list, data);
	map = ft_init_map(mapsize);

 	while ((ft_try_map(data, map, mapsize)) == NULL)
	{
		/*mark */
		char c = 48 + mapsize;
		ft_putstr("this is important important important,mapsize is : ");
		ft_putchar(c);
		/*mark */
		ft_free_map(map, mapsize);
		mapsize++;
		map = ft_init_map(mapsize);

	}
	return (map);
}


// char	**ft_checkmap_samemapsize(t_data *data, int mapsize)
// {
// 	char	**map;
//
// 	/*mark */
// 	char s = 48 + mapsize;
// 	ft_putstr("mapsize = ");
// 	ft_putchar(s);
// 	ft_putchar('\n');
//
// 	map = ft_init_map(mapsize);
// 	if (ft_try_map(data, map, mapsize) == NULL)
// 	{
// 		return (NULL);
// 	}
//
// 	return (map);
// }

// char	**ft_give_me_map(t_list *list, t_data *data)
// {
// 	int		mapsize;
// 	char	**map;
//
// 	mapsize = ft_minmapsize(num); /* min mapsize, then add it one by one */
// 	data = ft_give_me_data(list, data);
//
//  	while ((map = ft_checkmap_samemapsize(data, mapsize)) == NULL)
// 	{
// 		ft_free_map(map, mapsize);
// 		mapsize++;
// 		/*mark */
// 		char c = 48 + mapsize;
// 		ft_putchar(c);
// 		/*mark */
// 	}
// 	return (map);
// }
