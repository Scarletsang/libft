/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smartpointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 05:09:47 by htsang            #+#    #+#             */
/*   Updated: 2023/06/14 14:00:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "LIBFT/smartpointer.h"
#include "smartpointer_internal.h"

int		ft_sptr_create(t_ft_sptr *sptr, size_t allocation_size)
{
	sptr->allocation = malloc(allocation_size);
	if (!sptr->allocation)
	{
		return (EXIT_FAILURE);
	}
	sptr->owned = true;
	sptr->borrowed = false;
	sptr->mut_borrowed = false;
	return (EXIT_SUCCESS);
}

void	*ft_sptr(t_ft_sptr *sptr)
{
	return (sptr->allocation);
}

t_ft_sptr	ft_sptr_move(t_ft_sptr *sptr)
{
	t_ft_sptr	new_sptr;

	if (!sptr->owned)
	{
		ft_sptr_empty(&new_sptr);
		write(STDERR_FILENO, "Attempt to move a borrowed smart pointer\n", 41);
		return (new_sptr);
	}
	new_sptr = *sptr;
	ft_sptr_empty(sptr);
	return (new_sptr);
}

void	ft_sptr_drop(t_ft_sptr *sptr, void (*cleaner)(void *))
{
	if (!sptr->owned)
	{
		write(STDERR_FILENO, "Attempt to drop a borrowed smart pointer\n", 41);
		return ;
	}
	cleaner(sptr->allocation);
	ft_sptr_empty(sptr);
}

void	ft_sptr_empty(t_ft_sptr *sptr)
{
	sptr->allocation = NULL;
	sptr->owned = false;
	sptr->borrowed = false;
	sptr->mut_borrowed = false;
}
