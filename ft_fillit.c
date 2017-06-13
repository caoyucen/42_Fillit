/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:52:10 by ycao              #+#    #+#             */
/*   Updated: 2017/06/06 11:52:15 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"
# include "global.h"

void init_global()
{
	int i;

	num = 0;
	i = 0;
	while (i < 26)
	{
		letter[i] = 'A' + i;
		i++;
	}
}

void	ft_putchar(char c)
{
	unsigned char a;

	a = (unsigned char)c;
	write(1, &a, 1);
}

void	ft_putstr(char const *str)
{
	int i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return ;
}

void ft_printmap(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}


void	ft_fillit(int argc, char** argv)
{
	t_list	*list;
	t_data	*data;
	char		**map;

	list = NULL;
	data = NULL;
	list = ft_init_list(list);
	data = ft_init_data(data);
	init_global();
	if (argc == 2)
	{

		if ((list = ft_pre_openfile(argv[1], list)) != NULL)
		{
			map = ft_give_me_map(list, data);
			ft_printmap(map);
			return;
		}
	}
	ft_putstr("error\n");
	return;
}
