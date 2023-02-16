/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:53:15 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/16 21:37:40 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all(t_vars *s_vars)
{
	while (s_vars->size_b > 0)
		pa(s_vars);
}

int	find_next_index(int next, int *ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != next)
		i++;
	return (i);
}

int	moves_for_next(int next_i, int size)
{
	int	moves;

	moves = next_i;
	if (size - next_i < moves)
		moves = size - next_i;
	return (moves);
}

int	decide_rotate(int i, int size)
{
	if (size - i < i)
		return (0);
	return (1);
}

void	move_number(t_vars *s_vars, int nb)
{
	int i;
	
	i = find_next_index(nb, s_vars->b);
	if (decide_rotate(i, s_vars->size_b))
		while (s_vars->b[0] != nb)
			rb(s_vars);
	else
		while (s_vars->b[0] != nb)
			rrb(s_vars);
	pa(s_vars);
}

void	move_next(t_vars *s_vars, int next, int next2)
{
	int	moves1;
	int	moves2;
	int	next_i;
	int	next_i2;

	next_i = find_next_index(next, s_vars->b);
	next_i2 = find_next_index(next2, s_vars->b);
	moves1 = moves_for_next(next_i, s_vars->size_b);
	moves2 = moves_for_next(next_i2, s_vars->size_b);

	if (moves1 < moves2)
		move_number(s_vars, next);
	else
	{
		move_number(s_vars, next2);
		move_number(s_vars, next);
		sa(s_vars);
	}
}

void	sort_stack_b(t_vars *s_vars)
{
	int	i;

	while (!is_sorted(s_vars->b, s_vars->size_b, 'b'))
	{
		i = get_next(s_vars->sorted, s_vars->a[0]);
		if (s_vars->b[0] == s_vars->sorted[i])
			pa(s_vars);
		else if (s_vars->b[1] == s_vars->sorted[i])
		{
			if (is_small(s_vars, s_vars->b, s_vars->size_b, s_vars->b[0]))
				rb(s_vars);
			else
				sb(s_vars);
		}
		else
			move_next(s_vars, s_vars->sorted[i], s_vars->sorted[i - 1]);
	}
}

void	create_partitions(t_vars *s_vars, int size)
{
	int	count;
	int	median_a;
	int	median_b;
	int	i;
	(void)size;

	count = s_vars->size_a / 2;
	median_a = return_median(s_vars, s_vars->a, s_vars->size_a);
	median_b = get_median_b(s_vars, s_vars->a, s_vars->size_a, median_a);
//	ft_printf("count: %d\nmedian_a: %d\nmedian_b: %d\n", count, median_a, median_b);
	i = 0;
	while (count)
	{
//		print_stack(s_vars->a, s_vars->size_a, 'a');
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
