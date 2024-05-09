/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:15:24 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/17 16:43:34 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    brra(t_vars *s_vars)
{
    if (s_vars->size_a < 2)
        return ;
    push_nb_on_top(s_vars->a, s_vars->a[s_vars->size_a - 1], s_vars->size_a);
}

void    brrb(t_vars *s_vars)
{
    if (s_vars->size_b < 2)
        return ;
    push_nb_on_top(s_vars->b, s_vars->b[s_vars->size_b - 1], s_vars->size_b);
}

void    brrr(t_vars *s_vars)
{
    if (s_vars->size_a > 1)
        push_nb_on_top(s_vars->a, s_vars->a[s_vars->size_a - 1], s_vars->size_a);
    if (s_vars->size_b > 1)
        push_nb_on_top(s_vars->b, s_vars->b[s_vars->size_b - 1], s_vars->size_b);
}
