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
#include <unistd.h>
#include <stdlib.h>

typedef struct  s_data
{
    char            tetr[4][4];
    int             point[4]; /* min i, min j, max i, max j */
		int							n; /* NO.n data in all */
    struct  s_data  *next;
		struct  s_data  *before;
}               t_data;

typedef struct  s_list
{
    char            tetr[4][4];
    struct  s_list  *next;
}               t_list;

#endif
