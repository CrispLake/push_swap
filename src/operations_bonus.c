/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:42:32 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/17 17:14:35 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_nb_on_top(int *ptr, int nb, int size)
{
    while (size)
    {
        ptr[size] = ptr[size - 1];
        size--;
    }
    ptr[size] = nb;
}

void    remove_nb_on_top(int *ptr, int size)
{
    int    i;

    i = 0;
    while (i < size - 1)
    {
        ptr[i] = ptr[i + 1];
        i++;
    }
}

void    push_nb_on_bottom(int *ptr, int nb, int size)
{
    int    i;

    i = 0;
    while (i < size - 1)
    {
        ptr[i] = ptr[i + 1];
        i++;
    }
    ptr[i] = nb;
}
