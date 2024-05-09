/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:15:24 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/17 16:43:34 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_vars *s_vars)
{
    if (s_vars->size_a < 2)
        return ;
    push_nb_on_top(s_vars->a, s_vars->a[s_vars->size_a - 1], s_vars->size_a);
    if (!add_wrap(s_vars->ops_head, RRA))
        error_exit(s_vars);
}

void    rrb(t_vars *s_vars)
{
    if (s_vars->size_b < 2)
        return ;
    push_nb_on_top(s_vars->b, s_vars->b[s_vars->size_b - 1], s_vars->size_b);
    if (!add_wrap(s_vars->ops_head, RRB))
        error_exit(s_vars);
}

void    rrr(t_vars *s_vars)
{
    if (s_vars->size_a < 2 || s_vars->size_b < 2)
        return ;
    push_nb_on_top(s_vars->a, s_vars->a[s_vars->size_a - 1], s_vars->size_a);
    push_nb_on_top(s_vars->b, s_vars->b[s_vars->size_b - 1], s_vars->size_b);
    if (!add_wrap(s_vars->ops_head, RRR))
        error_exit(s_vars);
}
