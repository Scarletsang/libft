/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borrow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 05:27:04 by htsang            #+#    #+#             */
/*   Updated: 2023/06/14 13:57:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "LIBFT/smartpointer.h"
#include "smartpointer_internal.h"

t_ft_sptr	ft_sptr_borrow(t_ft_sptr *sptr)
{
	t_ft_sptr	borrowed_sptr;

	if (sptr->mut_borrowed)
	{
		ft_sptr_empty(&borrowed_sptr);
		write(STDERR_FILENO, \
			"Attempt to borrow a mutably borrowed smart pointer\n", 51);
		return (borrowed_sptr);
	}
	sptr->borrowed = true;
	borrowed_sptr.allocation = sptr->allocation;
	borrowed_sptr.owned = false;
	borrowed_sptr.borrowed = true;
	borrowed_sptr.mut_borrowed = false;
	return (borrowed_sptr);
}

t_ft_sptr	ft_sptr_mut_borrow(t_ft_sptr *sptr)
{
	t_ft_sptr	borrowed_sptr;

	if (sptr->mut_borrowed || sptr->borrowed)
	{
		ft_sptr_empty(&borrowed_sptr);
		if (sptr->mut_borrowed)
			write(STDERR_FILENO, \
				"Only one mutably borrowed smart pointer can exists\n", 51);
		else
			write(STDERR_FILENO, \
				"No mixing mutable and immutable borrowing\n", 42);
		return (borrowed_sptr);
	}
	sptr->mut_borrowed = true;
	borrowed_sptr.allocation = sptr->allocation;
	borrowed_sptr.owned = false;
	borrowed_sptr.borrowed = true;
	borrowed_sptr.mut_borrowed = true;
	return (borrowed_sptr);
}
