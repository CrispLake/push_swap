/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:51:11 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/14 17:55:31 by emajuri          ###   ########.fr       */
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
	int	operations;
}	t_vars;

void	swap_stack(t_vars *s_vars, int *ptr, char stack);
void	swap_ab(t_vars *s_vars);
void	push_to_stack(t_vars *s_vars, char stack);
void	rotate_stack(t_vars *s_vars, int *ptr, int size, char stack);
void	rotate_both(t_vars *s_vars);
void	reverse_rotate_stack(t_vars *s_vars, int *ptr, int size, char stack);
void	reverse_rotate_both(t_vars *s_vars);
void	push_nb_on_top(int *ptr, int nb, int size);
void	create_stack(char **numbers, t_vars *s_vars);
int		get_next(int *ptr, int nb);
int		is_sorted(int *ptr, int ize, char stack);
int		is_small(t_vars *s_vars, int *ptr, int size, int nb);
void	sort(t_vars *s_vars);

void	print_stack(int *ptr, int size, char stack);

#endif
