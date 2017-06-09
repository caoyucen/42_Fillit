/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 16:12:39 by ycao              #+#    #+#             */
/*   Updated: 2017/04/18 16:14:18 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct  s_data
{
    char            tetr[4][4];
    int             point[4]; /* min i, min j, max i, max j */
    int             n; /* NO.n data in all */
    struct  s_data  *next;
    struct  s_data  *before;
}               t_data;

typedef struct  s_list
{
    char            tetr[4][4];
    struct  s_list  *next;
}               t_list;

/* ft_pre_list.c */
t_list	*ft_init_list(t_list *list);

t_list	*ft_pre_newlist(t_list *list);

t_list	*ft_pre_buf(char* buf, t_list *list, int ret);

char	*ft_strnew(size_t size);

t_list	*ft_pre_readfile(t_list *list, int fd);

t_list	*ft_pre_openfile(char *filename, t_list *list);

/* ft_list_to_data.c */
t_data	*ft_init_data(t_data *data);

t_data	*ft_pre_newdata(t_data *data);

t_data		*ft_list_to_data_point(t_data *data, int i, int j);

t_data *ft_list_to_data(t_list *list, t_data *data, char a);

t_data	*ft_give_me_data(t_list *list, t_data *data);

/*ft_slover.c*/
int	ft_minmapsize(int num);

char **ft_init_map(int mapsize);

void ft_free_map(char **map, int mapsize);

char     ft_point_check(char a_data, char b_map);

char		**ft_map_clean(char **map, int n, int mapsize);

char	**ft_putmap_check(t_data data, char **map, int i, int j);

char		**ft_try_map(t_data data, char** map, int mapsize);

char	**ft_checkmap_samemapsize(t_data data, int mapsize);

char	**ft_give_me_map(t_list list, t_data data);

/*fillit.c*/
void init_global();

void	ft_putchar(char c);

void	ft_putstr(char const *str);

void ft_printmap(char **map);

void	fillit(int argc, char** argv);

#endif
