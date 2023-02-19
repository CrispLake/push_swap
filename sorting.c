/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:53:15 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/17 17:35:22 by emajuri          ###   ########.fr       */
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

void	partitions_size(t_vars *s_vars, int size)
{
	int	median_b;
	int	max;

	create_median(s_vars, s_vars->a, s_vars->size_a);
	max = s_vars->median[size];
	median_b = s_vars->median[size / 2];
	while (size)
	{
		if (s_vars->a[0] < max)
		{
			pb(s_vars);
			if (s_vars->b[0] < median_b)
				rb(s_vars);
			else if (s_vars->b[0] < s_vars->b[1])
				sb(s_vars);
			size--;
		}
		else
			ra(s_vars);
	}
}

void	partitions_half(t_vars *s_vars)
{
	int	count;
	int	median_a;
	int	median_b;

	count = s_vars->size_a / 2;
	create_median(s_vars, s_vars->a, s_vars->size_a);
	median_a = s_vars->median[s_vars->size_median / 2];
	median_b = s_vars->median[s_vars->size_median / 4];
	while (count)
	{
		if (s_vars->a[0] < median_a)
		{
			pb(s_vars);
			if (s_vars->b[0] < median_b)
				rb(s_vars);
			else if (s_vars->b[0] < s_vars->b[1])
				sb(s_vars);
			count--;
		}
		else
			ra(s_vars);
	}
}

int	index_of_big(int nb1, int nb2, int nb3)
{
	if (nb1 > nb2)
	{
		if (nb1 > nb3)
			return (0);
	}
	else if (nb2 > nb3)
		return (1);
	return (2);
}

void	sort_a(t_vars *s_vars)
{
	int	big;

	if (s_vars->size_a == 2)
	{
		if (s_vars->a[0] > s_vars->a[1])
			sa(s_vars);
		return ;
	}
	big = index_of_big(s_vars->a[0], s_vars->a[1], s_vars->a[2]);
	if (big == 0)
		ra(s_vars);
	else if (big == 1)
		rra(s_vars);
	if (s_vars->a[0] > s_vars->a[1])
		sa(s_vars);
}
