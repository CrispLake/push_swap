/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:49:07 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/20 14:35:34 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	command(t_vars *s_vars, int operation)
{
	if (operation == SA)
		bsa(s_vars);
	else if (operation == SB)
		bsb(s_vars);
	else if (operation == PA)
		bpa(s_vars);
	else if (operation == PB)
		bpb(s_vars);
	else if (operation == RA)
		bra(s_vars);
	else if (operation == RB)
		brb(s_vars);
	else if (operation == RR)
		brr(s_vars);
	else if (operation == RRA)
		brra(s_vars);
	else if (operation == RRB)
		brrb(s_vars);
	else if (operation == RRR)
		brrr(s_vars);
}

void	execute(t_vars *s_vars, t_vec *vec)
{
	int	i;

	i = 0;
	while (i < vec->count)
	{
		command(s_vars, vec->operations[i]);
		i++;
	}
	free(vec->operations);
}

void	read_and_execute(t_vars *s_vars)
{
	char	*line;
	int		operation;
	t_vec	vec;

	ft_bzero(&vec, sizeof(t_vec));
	line = ft_get_next_line(0);
	while (line)
	{
		operation = check_operation(line);
		free(line);
		if (!operation)
			exit_on_error(s_vars, vec.operations);
		add_operation(s_vars, &vec, operation);
		line = ft_get_next_line(0);
	}
	execute(s_vars, &vec);
}

int	is_sorted_bonus(int *ptr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (ptr[i] > ptr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	s_vars;

	if (argc < 2)
		return (0);
	ft_bzero(&s_vars, sizeof(t_vars));
	if (argc == 2)
	{
		s_vars.numbers = ft_split_one_malloc(argv[1], ' ');
		create_stack_bonus(s_vars.numbers, &s_vars);
		free(s_vars.numbers);
	}
	else
		create_stack_bonus(argv + 1, &s_vars);
	read_and_execute(&s_vars);
	if (s_vars.size_b == 0 && is_sorted_bonus(s_vars.a, s_vars.size_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(s_vars.data);
	return (0);
}
