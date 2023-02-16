/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:51:11 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/16 19:56:25 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_vars
{
	int	*data;
	int	*a;
	int	*b;
	int	*sorted;
	int	*median;
	int	size_a;
	int	size_b;
	int	size_sorted;
	int	size_median;
}	t_vars;

void	sa(t_vars *s_vars);
void	sb(t_vars *s_vars);
void	ss(t_vars *s_vars);
void	pa(t_vars *s_vars);
void	pb(t_vars *s_vars);
void	ra(t_vars *s_vars);
void	rb(t_vars *s_vars);
void	rr(t_vars *s_vars);
void	rra(t_vars *s_vars);
void	rrb(t_vars *s_vars);
void	rrr(t_vars *s_vars);
void	sort_stack_b(t_vars *s_vars);
void	push_all(t_vars *s_vars);
void	push_nb_on_top(int *ptr, int nb, int size);
void	push_nb_on_bottom(int *ptr, int nb, int size);
void	push_nb_on_top(int *ptr, int nb, int size);
void	remove_nb_on_top(int *ptr, int size);
void	create_stack(char **numbers, t_vars *s_vars);
int		get_next(int *ptr, int nb);
int		is_sorted(int *ptr, int ize, char stack);
int		is_small(t_vars *s_vars, int *ptr, int size, int nb);
void	sort_a(t_vars *s_vars);
int		return_median(t_vars *s_vars, int *ptr, int size);
int		get_median_b(t_vars *s_vars, int *ptr, int size, int median);
void	create_partitions(t_vars *s_vars, int amount);

void	print_stack(int *ptr, int size, char stack);

#endif
