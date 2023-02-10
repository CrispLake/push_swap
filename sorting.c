/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:53:15 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/10 18:05:53 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_vars *s_vars)
{
	while (!is_sorted(s_vars->a, s_vars->size_a, 'a' && s_vars->size_b == 0))
	{
		if (is_sorted(s_vars->a, s_vars->size_a, 'a'))
		{
			sort_stack(s_vars, 'b');
			push_all(s_vars);
		}
		if (s_vars->size_a > 1 && is_small(s_vars->a, s_vars->size_a))
		{
			
		}
	}
}
