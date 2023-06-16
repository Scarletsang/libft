/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smartpointer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 05:00:15 by htsang            #+#    #+#             */
/*   Updated: 2023/06/15 13:58:49 by htsang           ###   ########.fr       */
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
	void			*allocation;
	unsigned int	borrowed_count;
	bool			borrowed_is_mut : 1;
}				t_ft_sptr;

int					ft_sptr_create(t_ft_sptr *sptr, size_t allocation_size);

t_ft_sptr			ft_sptr_move(t_ft_sptr *sptr);

const void			*ft_sptr_use(t_ft_sptr *sptr);

void				*ft_sptr_use_mut(t_ft_sptr *sptr);

void				ft_sptr_drop(t_ft_sptr *sptr, void (*cleaner)(void *));

typedef struct s_ft_sptr_borrow
{
	t_ft_sptr	*owner;
	bool		is_mut;
}				t_ft_sptr_borrow;

t_ft_sptr_borrow	ft_sptr_borrow(t_ft_sptr *sptr);

t_ft_sptr_borrow	ft_sptr_borrow_mut(t_ft_sptr *sptr);

const void			*ft_sptr_borrow_use(t_ft_sptr_borrow *borrow);

void				*ft_sptr_borrow_mut_use(t_ft_sptr_borrow *borrow);

void				ft_sptr_borrow_drop(t_ft_sptr_borrow *borrow);

#endif