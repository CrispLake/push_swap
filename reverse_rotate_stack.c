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

void	rra(t_vars *s_vars)
{
	if (s_vars->size_a < 2)
		return ;
	ft_printf("rra\n");
	push_nb_on_top(s_vars->a, s_vars->a[s_vars->size_a - 1], s_vars->size_a);
}

void	rrb(t_vars *s_vars)
{
	if (s_vars->size_b < 2)
		return ;
	ft_printf("rrb\n");
	push_nb_on_top(s_vars->b, s_vars->b[s_vars->size_b - 1], s_vars->size_b);
}

void	rrr(t_vars *s_vars)
{
	if (s_vars->size_a < 2 || s_vars->size_b < 2)
		return ;
	ft_printf("rrr\n");
	push_nb_on_top(s_vars->a, s_vars->a[s_vars->size_a - 1], s_vars->size_a);
	push_nb_on_top(s_vars->b, s_vars->b[s_vars->size_b - 1], s_vars->size_b);
}
