/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smartpointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 05:09:47 by htsang            #+#    #+#             */
/*   Updated: 2023/06/15 13:34:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "LIBFT/smartpointer.h"

int	ft_sptr_create(t_ft_sptr *sptr, size_t allocation_size)
{
	sptr->allocation = malloc(allocation_size);
	if (!sptr->allocation)
	{
		return (EXIT_FAILURE);
	}
	sptr->borrowed_count = 0;
	sptr->borrowed_is_mut = false;
	return (EXIT_SUCCESS);
}

const void	*ft_sptr_use(t_ft_sptr *sptr)
{
	if (sptr->borrowed_count && sptr->borrowed_is_mut)
	{
		write(STDERR_FILENO, \
			"Another mutably borrow is using the snart pointer\n", 50);
		return (NULL);
	}
	if (sptr->allocation == NULL)
	{
		write(STDERR_FILENO, "Dropped smart pointer cannot be used\n", 37);
	}
	return (sptr->allocation);
}

void	*ft_sptr_use_mut(t_ft_sptr *sptr)
{
	if (sptr->borrowed_count)
	{
		write(STDERR_FILENO, \
			"Attempt to mutate the smart pointer while it is borrowed\n", 57);
		return (NULL);
	}
	if (sptr->allocation == NULL)
	{
		write(STDERR_FILENO, "Dropped smart pointer cannot be used\n", 37);
	}
	return (sptr->allocation);
}

t_ft_sptr	ft_sptr_move(t_ft_sptr *sptr)
{
	t_ft_sptr	new_sptr;

	if (sptr->allocation == NULL)
	{
		write(STDERR_FILENO, "Dropped smart pointer cannot be moved\n", 38);
		return (*sptr);
	}
	new_sptr = *sptr;
	sptr->allocation = NULL;
	sptr->borrowed_count = 0;
	sptr->borrowed_is_mut = false;
	return (new_sptr);
}

void	ft_sptr_drop(t_ft_sptr *sptr, void (*cleaner)(void *))
{
	if (sptr->allocation == NULL)
	{
		write(STDERR_FILENO, "Dropped smart pointer cannot be dropped\n", 40);
		return ;
	}
	cleaner(sptr->allocation);
	sptr->allocation = NULL;
	sptr->borrowed_count = 0;
	sptr->borrowed_is_mut = false;
}
