/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:24:25 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/17 17:17:43 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(int *ptr)
{
	int	save;

	save = ptr[0];
	ptr[0] = ptr[1];
	ptr[1] = save;
}

void	bsa(t_vars *s_vars)
{
	if (s_vars->size_a < 2)
		return ;
	swap_stack(s_vars->a);
}

void	bsb(t_vars *s_vars)
{
	if (s_vars->size_b < 2)
		return ;
	swap_stack(s_vars->b);
}

void	bss(t_vars *s_vars)
{
	if (s_vars->size_a < 2 || s_vars->size_b < 2)
		return ;
	swap_stack(s_vars->a);
	swap_stack(s_vars->b);
}
