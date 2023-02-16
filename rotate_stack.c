/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:48:38 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/16 19:58:20 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_vars *s_vars)
{
	ft_printf("ra\n");
	push_nb_on_bottom(s_vars->a, s_vars->a[0], s_vars->size_a);
}

void	rb(t_vars *s_vars)
{
	ft_printf("rb\n");
	push_nb_on_bottom(s_vars->b, s_vars->b[0], s_vars->size_b);
}

void	rr(t_vars *s_vars)
{
	ft_printf("rr\n");
	push_nb_on_bottom(s_vars->a, s_vars->a[0], s_vars->size_a);
	push_nb_on_bottom(s_vars->b, s_vars->b[0], s_vars->size_b);
}
