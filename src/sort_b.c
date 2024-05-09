/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:47:08 by emajuri           #+#    #+#             */
/*   Updated: 2024/04/12 18:38:41 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    sort_stack_b(t_vars *s_vars)
{
    int    next_i;
    int storage_size = 0;

    while (!is_sorted(s_vars->b, s_vars->size_b, 'b'))
    {
        next_i = get_next(s_vars->sorted, s_vars->a[0]);
        if (s_vars->b[0] == s_vars->sorted[next_i])
            pa(s_vars);
        else if (s_vars->b[1] == s_vars->sorted[next_i])
            sb(s_vars);
        else if (storage_size && s_vars->a[s_vars->size_a - 1] == s_vars->sorted[next_i])
        {
            rra(s_vars);
            storage_size--;
            continue;
        }
        else if (storage_size == 0 || s_vars->a[s_vars->size_a - 1] < s_vars->b[0])
        {
            pa(s_vars);
            ra(s_vars);
            storage_size++;
        }
        else
            move_next(s_vars, s_vars->sorted[next_i], s_vars->sorted[next_i - 1]);
    }
    return storage_size;
}
