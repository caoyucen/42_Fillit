/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:52:28 by ycao              #+#    #+#             */
/*   Updated: 2017/06/06 11:52:32 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* this part is to make t_list to t_data */

#include "fillit.h"
#include "global.h"

t_data	*ft_init_data(t_data *data)
{

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	/*init data->point[]  --> min i, min j, max i, max j */
	data->point[0] = 9;
	data->point[0] = 9;
	data->point[0] = 0;
	data->point[0] = 0;
	data->next = NULL;
	return (data);
}

t_data	*ft_pre_newdata(t_data *data)
{
	t_data	*newdata;

	newdata = (t_data*)malloc(sizeof(t_data));
	if (!newdata)
		return (NULL);
	data->point[0] = 9;
	data->point[0] = 9;
	data->point[0] = 0;
	data->point[0] = 0;
	newdata->next = NULL;
	data->next = newdata;
	data = newdata; /* I have problem here */
	return (data);
}

int		*ft_list_to_data_point(t_data data, int i, int j)
{
	if(data->point[0] > i)
		data->point[0] = i;
	if(data->point[1] > j)
		data->point[1] = j;
	if(data->point[2] < i)
		data->point[2] = i;
	if(data->point[3] < j)
		data->point[3] = j;
	return(data);
}

t_data *ft_list_to_data(t_list list, t_data data, char a)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		while (++j < 4)
		{
			data->tetr[i][j] = list->tetr[i][j];
			if (data->tetr[i][j] == '#')
			{
				data = ft_list_to_data_point(data, i, j);
				data->tetr[i][j] = a;
			}
		}
	}
}

t_data	*ft_give_me_data(t_list list, t_data data)
{
	int		i;
	t_data	start;

	i = 0;
	while (i < num)
	{
		data = ft_list_to_data(list, data, letter[i]);
		i++;
		if (i < num)
			data = ft_pre_newdata(t_data *data);
	}
	return (start);
}
