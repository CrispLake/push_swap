/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:49:07 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/17 17:14:42 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"
#include <unistd.h>

void	exit_on_error(t_vars *s_vars, char *operations)
{
	ft_printf_fd(2, "Error\n");
	free(s_vars->data);
	free(operations);
	exit(-1);
}

int	check_rotate(char *line)
{
	if (line[2] == '\n')
	{
		if (line[1] == 'a')
			return (RA);
		if (line[1] == 'b')
			return (RB);
		if (line[1] == 'r')
			return (RR);
	}
	else if (line[3] == '\n')
	{
		if (line[1] == 'r' && line[2] == 'a')
			return (RRA);
		if (line[1] == 'r' && line[2] == 'b')
			return (RRB);
		if (line[1] == 'r' && line[2] == 'r')
			return (RRR);
	}
	return (0);
}

int	check_operation(char *line)
{
	if (line[0] == 's')
	{
		if (line[1] == 'a' && line[2] == '\n')
			return (SA);
		if (line[1] == 'b' && line[2] == '\n')
			return (SB);
		if (line[1] == 's' && line[2] == '\n')
			return (SS);
	}
	else if (line[0] == 'p')
	{
		if (line[1] == 'a' && line[2] == '\n')
			return (PA);
		if (line[1] == 'b' && line[2] == '\n')
			return (PB);
	}
	else if (line[0] == 'r')
		return (check_rotate(line));
	return (0);
}

void	add_operation(t_vars *s_vars, t_vec *vec, int operation)
{
	if (!vec->len)
		vec->len = 1;
	if (vec->len <= vec->count + 1)
	{
		vec->len *= 2;
		ft_realloc(vec->operations, vec->len * sizeof(char), vec->count);
		if (!vec->operations)
			exit_on_error(s_vars, vec->operations);
	}
	vec->operations[vec->count] = operation;
	vec->count++;
}

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
	while(i < vec->count)
	{
		command(s_vars, vec->operations[i]);
		i++;
	}
	free(vec->operations);
}

void	read_and_execute(t_vars *s_vars)
{
	char	*line;
	int		x;
	int		operation;
	t_vec	vec;

	x = 1;
	ft_bzero(&vec, sizeof(t_vec));
	while (line || x)
	{
		x = 0;
		line = ft_get_next_line(0);
		if (line)
		{
			operation = check_operation(line);
			free(line);
			if (!operation)
				exit_on_error(s_vars, vec.operations);
			add_operation(s_vars, &vec, operation);
		}
		else
			execute(s_vars, &vec);
	}
}

int	is_sorted_bonus(int *ptr, int size)
{
	int i;

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
