/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:48:38 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/17 16:43:41 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_vars *s_vars)
{
    if (s_vars->size_a < 2)
        return ;
    push_nb_on_bottom(s_vars->a, s_vars->a[0], s_vars->size_a);
    if (!add_wrap(s_vars->ops_head, RA))
        error_exit(s_vars);
}

void    rb(t_vars *s_vars)
{
    if (s_vars->size_b < 2)
        return ;
    push_nb_on_bottom(s_vars->b, s_vars->b[0], s_vars->size_b);
    if (!add_wrap(s_vars->ops_head, RB))
        error_exit(s_vars);
}

void    rr(t_vars *s_vars)
{
    if (s_vars->size_a < 2 || s_vars->size_b < 2)
        return ;
    push_nb_on_bottom(s_vars->a, s_vars->a[0], s_vars->size_a);
    push_nb_on_bottom(s_vars->b, s_vars->b[0], s_vars->size_b);
    if (!add_wrap(s_vars->ops_head, RR))
        error_exit(s_vars);
}
