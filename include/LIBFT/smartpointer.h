/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smartpointer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 05:00:15 by htsang            #+#    #+#             */
/*   Updated: 2023/06/14 13:56:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMARTPOINTER_H
# define SMARTPOINTER_H

# include <stddef.h>
# include <stdbool.h>

/**
 * @brief A smart pointer 
*/
typedef struct s_ft_sptr
{
	void	*allocation;
	bool	owned : 1;
	bool	borrowed : 1;
	bool	mut_borrowed : 1;
}				t_ft_sptr;

int				ft_sptr_create(t_ft_sptr *sptr, size_t allocation_size);

t_ft_sptr		ft_sptr_move(t_ft_sptr *sptr);

t_ft_sptr		ft_sptr_borrow(t_ft_sptr *sptr);

t_ft_sptr		ft_sptr_mut_borrow(t_ft_sptr *sptr);

void			*ft_sptr(t_ft_sptr *sptr);

void			ft_sptr_drop(t_ft_sptr *sptr, void (*cleaner)(void *));


#endif