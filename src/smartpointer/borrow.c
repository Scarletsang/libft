/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borrow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 05:27:04 by htsang            #+#    #+#             */
/*   Updated: 2023/06/15 13:58:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "LIBFT/smartpointer.h"

t_ft_sptr_borrow	ft_sptr_borrow(t_ft_sptr *sptr)
{
	if (sptr->allocation == NULL)
	{
		write(STDERR_FILENO, "Dropped smart pointer cannot be used\n", 37);
		return ((t_ft_sptr_borrow){NULL, false});
	}
	if (sptr->borrowed_count && sptr->borrowed_is_mut)
	{
		write(STDERR_FILENO, \
			"Cannot borrow while there is another mutably borrow\n", 52);
		return ((t_ft_sptr_borrow){NULL, false});
	}
	sptr->borrowed_count += 1;
	sptr->borrowed_is_mut = false;
	return ((t_ft_sptr_borrow){sptr, false});
}

t_ft_sptr_borrow	ft_sptr_borrow_mut(t_ft_sptr *sptr)
{
	if (sptr->allocation == NULL)
	{
		write(STDERR_FILENO, "Dropped smart pointer cannot be used\n", 37);
		return ((t_ft_sptr_borrow){NULL, false});
	}
	if (sptr->borrowed_count)
	{
		if (sptr->borrowed_is_mut)
			write(STDERR_FILENO, \
			"Cannot mutably borrow while there is another mutably borrow\n", 60);
		else
			write(STDERR_FILENO, \
				"Cannot mutably borrow while there is another borrow\n", 52);
		return ((t_ft_sptr_borrow){NULL, true});
	}
	sptr->borrowed_count = 1;
	sptr->borrowed_is_mut = true;
	return ((t_ft_sptr_borrow){sptr, true});
}

const void	*ft_sptr_borrow_use(t_ft_sptr_borrow *borrow)
{
	if (!borrow->owner)
	{
		write(STDERR_FILENO, "Attempt to use a empty borrow\n", 30);
		return (NULL);
	}
	if (borrow->owner->allocation == NULL)
	{
		write(STDERR_FILENO, "Dropped smart pointer cannot be used\n", 37);
	}
	return (borrow->owner->allocation);
}

void	*ft_sptr_borrow_mut_use(t_ft_sptr_borrow *borrow)
{
	if (!borrow->owner)
	{
		write(STDERR_FILENO, "Attempt to mutably use a empty borrow\n", 38);
		return (NULL);
	}
	if (!borrow->owner->borrowed_is_mut)
	{
		write(STDERR_FILENO, \
			"Attempt to mutably use a readonly borrow\n", 41);
		return (NULL);
	}
	if (borrow->owner->allocation == NULL)
	{
		write(STDERR_FILENO, "Dropped smart pointer cannot be used\n", 37);
	}
	return (borrow->owner->allocation);
}

void	ft_sptr_borrow_drop(t_ft_sptr_borrow *borrow)
{
	if (!borrow->owner)
	{
		write(STDERR_FILENO, "Attempt to drop an empty borrow\n", 32);
		return ;
	}
	if (borrow->is_mut)
		borrow->owner->borrowed_count = 0;
	else
		borrow->owner->borrowed_count -= 1;
	borrow->owner = NULL;
}
