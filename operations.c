/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:42:32 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/13 18:56:19 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_nb_on_top(int *ptr, int nb, int size)
{
	while (size)
	{
		ptr[size] = ptr[size - 1];
		size--;
	}
	ptr[size] = nb;
}

void	remove_nb_on_top(int *ptr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		ptr[i] = ptr[i + 1];
		i++;
	}
}

void	push_to_stack(t_vars *s_vars, char stack)
{
	if (stack == 'a')
	{
		ft_printf("pa\n");
		push_nb_on_top(s_vars->a, s_vars->b[0], s_vars->size_a);
		remove_nb_on_top(s_vars->b, s_vars->size_b);
		s_vars->size_a++;
		s_vars->size_b--;
	}	
	else
	{
		ft_printf("pb\n");
		push_nb_on_top(s_vars->b, s_vars->a[0], s_vars->size_b);
		remove_nb_on_top(s_vars->a, s_vars->size_a);
		s_vars->size_b++;
		s_vars->size_a--;
	}
	s_vars->operations++;
}

void	swap_stack(t_vars *s_vars, int *ptr, char stack)
{
	int	save;

	if (stack == 'a')
		ft_printf("sa\n");
	else if (stack == 'b')
		ft_printf("sb\n");
	s_vars->operations++;
	save = ptr[0];
	ptr[0] = ptr[1];
	ptr[1] = save;
}

void	swap_ab(t_vars *s_vars)
{
	if (s_vars->size_a >= 2 && s_vars->size_b >= 2)
	{
		s_vars->operations--;
		swap_stack(s_vars, s_vars->a, 0);
		swap_stack(s_vars, s_vars->b, 0);
		ft_printf("ss\n");
	}
	else
		ft_printf("swap_ab error\n");
}
