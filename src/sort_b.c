/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:47:08 by emajuri           #+#    #+#             */
/*   Updated: 2024/04/12 17:47:20 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_b(t_vars *s_vars)
{
	int	i;

	while (!is_sorted(s_vars->b, s_vars->size_b, 'b'))
	{
		i = get_next(s_vars->sorted, s_vars->a[0]);
		if (s_vars->b[0] == s_vars->sorted[i])
			pa(s_vars);
		else if (s_vars->b[1] == s_vars->sorted[i])
			sb(s_vars);
		else
			move_next(s_vars, s_vars->sorted[i], s_vars->sorted[i - 1]);
	}
}
