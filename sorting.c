/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:53:15 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/14 18:23:29 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all(t_vars *s_vars)
{
	while (s_vars->size_b > 0)
		push_to_stack(s_vars, 'a');
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
			rotate_stack(s_vars, s_vars->b, s_vars->size_b, 'b');
	else
		while (s_vars->b[0] != nb)
			reverse_rotate_stack(s_vars, s_vars->b, s_vars->size_b, 'b');
	push_to_stack(s_vars, 'a');
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
		swap_stack(s_vars, s_vars->a, 'a');
	}
}

void	sort_stack_b(t_vars *s_vars)
{
	int	i;

	while (!is_sorted(s_vars->b, s_vars->size_b, 'b'))
	{
		i = get_next(s_vars->sorted, s_vars->a[0]);
		if (s_vars->b[0] == s_vars->sorted[i])
			push_to_stack(s_vars, 'a');
		else if (s_vars->b[1] == s_vars->sorted[i])
		{
			if (is_small(s_vars, s_vars->b, s_vars->size_b, s_vars->b[0]))
				rotate_stack(s_vars, s_vars->b, s_vars->size_b, 'b');
			else
				swap_stack(s_vars, s_vars->b, 'b');
		}
		else
			move_next(s_vars, s_vars->sorted[i], s_vars->sorted[i - 1]);
	}
}

void	sort(t_vars *s_vars)
{
	while (!is_sorted(s_vars->a, s_vars->size_a, 'a') || s_vars->size_a != 2)
	{
		if (s_vars->size_a == 2)
			swap_stack(s_vars, s_vars->a, 'a');
		else if (s_vars->size_a > 2 && is_small(s_vars, s_vars->a, s_vars->size_a, s_vars->a[0]))
		{
			push_to_stack(s_vars, 'b');
			if (s_vars->size_b > 1)
			{
				if (is_small(s_vars, s_vars->b, s_vars->size_b, s_vars->b[0]))
					rotate_stack(s_vars, s_vars->b, s_vars->size_b, 'b');
				else if (s_vars->b[0] < s_vars->b[1])
					swap_stack(s_vars, s_vars->b, 'b');
			}
		}
		else
			rotate_stack(s_vars, s_vars->a, s_vars->size_a, 'a');
	}
	if (s_vars->size_b > 0)
	{
		sort_stack_b(s_vars);
		push_all(s_vars);
	}
}
