/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:49:07 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/10 18:06:06 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *ptr, int size, char stack)
{
	int	i;

	i = 0;
	if (stack == 'a')
	{
		while (i < size)
		{
			if (ptr[i] > ptr[i + 1])
				return (0);
			i++;
		}
	}
	if (stack == 'b')
	{
		while (i < size)
		{
			if (ptr[i] < ptr[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}

int	is_small(int *ptr, int size)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < size)
		sum += ptr[i++];
	if (ptr[0] < sum / size)
		return (1);
	return (0);
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

#include <unistd.h>
void	test_operations(t_vars *s_vars)
{
	int		readval;
	char	buf[1];

	readval = 1;
	while(readval)	
	{
		print_stack(s_vars->a, s_vars->size_a, 'a');
		ft_printf("\n");
		print_stack(s_vars->b, s_vars->size_b, 'b');
		ft_printf("--%d--\n\n", s_vars->operations);
		readval = read(0, buf, 2);
		if (buf[0] == '1')
			swap_stack(s_vars, s_vars->a, 'a');
		else if (buf[0] == '2')
			swap_stack(s_vars, s_vars->b, 'b');
		else if (buf[0] == '3')
			swap_ab(s_vars);
		else if (buf[0] == '4')
			push_to_stack(s_vars, 'a');
		else if (buf[0] == '5')
			push_to_stack(s_vars, 'b');
		else if (buf[0] == '6')
			rotate_stack(s_vars, s_vars->a, s_vars->size_a, 'a');
		else if (buf[0] == '7')
			rotate_stack(s_vars, s_vars->b, s_vars->size_b, 'b');
		else if (buf[0] == '8')
			rotate_both(s_vars);
		else if (buf[0] == '9')
			reverse_rotate_stack(s_vars, s_vars->a, s_vars->size_a, 'a');
		else if (buf[0] == '0')
			reverse_rotate_stack(s_vars, s_vars->b, s_vars->size_b, 'b');
		else if (buf[0] == 'a')
			reverse_rotate_both(s_vars);
	}
}

int	main(int argc, char **argv)
{
	t_vars	s_vars;

	if (argc < 2)
		return (-1);
	create_stack(argv + 1, &s_vars);
	test_operations(&s_vars);
	return (0);
}
