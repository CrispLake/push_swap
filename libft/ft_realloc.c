/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:34:15 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/16 16:34:23 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size, size_t len)
{
	char	*new;
	char	*tmp;
	size_t	i;

	tmp = (char *)ptr;
	i = 0;
	if (!size)
		return (NULL);
	if (!tmp)
	{
		tmp = ft_calloc(size, 1);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	new = ft_calloc(size, 1);
	if (!new)
		return (NULL);
	while (len--)
	{
		new[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (new);
}
