/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:51:11 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/10 18:06:00 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_vars
{
	int	*data;
	int	*a;
	int	*b;
	int	*sorted;
	int	size_a;
	int	size_b;
	int	size_sorted;
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

#endif
