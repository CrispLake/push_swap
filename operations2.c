/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:00:16 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/13 18:56:16 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_nb_on_bottom(int *ptr, int nb, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		ptr[i] = ptr[i + 1];
		i++;
	}
	ptr[i] = nb;
}

void	rotate_stack(t_vars *s_vars, int *ptr, int size, char stack)
{
	s_vars->operations++;
	if (stack == 'a')
		ft_printf("ra\n");
	else if (stack == 'b')
		ft_printf("rb\n");
	push_nb_on_bottom(ptr, ptr[0], size);
}

void	rotate_both(t_vars *s_vars)
{
	s_vars->operations--;
	ft_printf("rr\n");
	rotate_stack(s_vars, s_vars->a, s_vars->size_a, 0);
	rotate_stack(s_vars, s_vars->b, s_vars->size_b, 0);
}

void	reverse_rotate_stack(t_vars *s_vars, int *ptr, int size, char stack)
{
	if (stack == 'a')
	{
		if (size < 2)
		{
			ft_printf("reverse_rotate_a error\n");
			return ;
		}
	}
	if (stack == 'b')
	{
		if (size < 2)
		{
			ft_printf("reverse_rotate_b error\n");
			return ;
		}
	}
	s_vars->operations++;
	if (stack == 'a')
		ft_printf("rra\n");
	else if (stack == 'b')
		ft_printf("rrb\n");
	push_nb_on_top(ptr, ptr[size - 1], size);
}

void	reverse_rotate_both(t_vars *s_vars)
{
	if (s_vars->size_a < 2 || s_vars->size_b < 2)
	{
		ft_printf("rrr error\n");
		return ;
	}
	s_vars->operations--;
	ft_printf("rrr\n");
	reverse_rotate_stack(s_vars, s_vars->a, s_vars->size_a, 0);
	reverse_rotate_stack(s_vars, s_vars->b, s_vars->size_b, 0);
}
