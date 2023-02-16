/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:49:07 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/16 21:39:02 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next(int *ptr, int nb)
{
	int	i;

	i = 0;
	while (ptr[i] != nb)
		i++;
	return (i - 1);
}

int	is_sorted(int *ptr, int size, char stack)
{
	int	i;

	i = 0;
	if (stack == 'a')
	{
		while (i < size - 1)
		{
			if (ptr[i] > ptr[i + 1])
			{
				return (0);
			}
			i++;
		}
	}
	if (stack == 'b')
	{
		while (i < size - 1)
		{
			if (ptr[i] < ptr[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}

int	do_median(t_vars *s_vars, int nb)
{
	int	i;

	i = 0;
	while (i < s_vars->size_median)
	{
		if (s_vars->median[i] > nb)
		{
			push_nb_on_top(&(s_vars->median[i]), nb, s_vars->size_median - i);
			s_vars->size_median++;
			return (0);
		}
		i++;
	}
	s_vars->median[i] = nb;
	s_vars->size_median++;
	return (0);
}

int	return_median(t_vars *s_vars, int *ptr, int size)
{
	int	i;

	i = 0;
	s_vars->size_median = 0;
	while (i < size)
		do_median(s_vars, ptr[i++]);
	return (s_vars->median[s_vars->size_median / 2]);
}

int get_median_b(t_vars *s_vars, int *ptr, int size, int median)
{
	int	i;

	i = 0;
	s_vars->size_median = 0;
	while (i < size)
	{
		if (ptr[i] < median)
			do_median(s_vars, ptr[i]);
		i++;
	}
	return (s_vars->median[s_vars->size_median / 2]);
}

int	is_small(t_vars *s_vars, int *ptr, int size, int nb)
{
	int	i;

	i = 0;
	s_vars->size_median = 0;
	while (i < size)
		do_median(s_vars, ptr[i++]);
	return (nb < s_vars->median[s_vars->size_median / 2]);
}

void	print_stack(int *ptr, int size, char stack)
{
	int	i;

	i = 0;
	if (stack == 'a')
		ft_printf("stack a: %d\n", size);
	else
		ft_printf("stack b: %d\n", size);
	while (i < size)
		ft_printf("%d\n", ptr[i++]);
}

int	main(int argc, char **argv)
{
	t_vars	s_vars;
	int		partition_size = 0;

	if (argc < 2)
		return (-1);
	create_stack(argv + 1, &s_vars);
//	partition_size = decide_partitions(argc - 1);
	while (s_vars.size_a > 3)
		create_partitions(&s_vars, partition_size);
//	print_stack(s_vars.a, s_vars.size_a, 'a');
//	print_stack(s_vars.b, s_vars.size_b, 'b');
	sort_a(&s_vars);
	sort_stack_b(&s_vars);
	push_all(&s_vars);
//	print_stack(s_vars.a, s_vars.size_a, 'a');
//	print_stack(s_vars.b, s_vars.size_b, 'b');
//	sort_a(&s_vars);
//	print_stack(s_vars.a, s_vars.size_a, 'a');
	free(s_vars.data);
	return (0);
}
