/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:42:32 by emajuri           #+#    #+#             */
/*   Updated: 2024/04/12 18:42:14 by emajuri          ###   ########.fr       */
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

void	push_all(t_vars *s_vars, int storage_size)
{
	while (s_vars->size_b > 0)
	{
		if (storage_size && s_vars->a[s_vars->size_a - 1] > s_vars->b[0])
		{
			rra(s_vars);
			storage_size--;
		}
		else
			pa(s_vars);
	}
	while (storage_size--)
		rra(s_vars);
}
