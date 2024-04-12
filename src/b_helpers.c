/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:09:58 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/17 17:13:15 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	i;

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
