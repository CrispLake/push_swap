/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:32:20 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/16 21:23:21 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack(t_vars *s_vars, char stack)
{
	if (stack == 'a')
	{
		push_nb_on_top(s_vars->a, s_vars->b[0], s_vars->size_a);
		remove_nb_on_top(s_vars->b, s_vars->size_b);
		s_vars->size_a++;
		s_vars->size_b--;
	}
	else
	{
		push_nb_on_top(s_vars->b, s_vars->a[0], s_vars->size_b);
		remove_nb_on_top(s_vars->a, s_vars->size_a);
		s_vars->size_b++;
		s_vars->size_a--;
	}
}

void	bpa(t_vars *s_vars)
{
	push_to_stack(s_vars, 'a');
}

void	bpb(t_vars *s_vars)
{
	push_to_stack(s_vars, 'b');
}
