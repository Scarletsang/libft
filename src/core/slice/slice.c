/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:06:07 by htsang            #+#    #+#             */
/*   Updated: 2023/08/01 13:17:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/slice.h"
#include <stdbool.h>

t_ft_slice	ft_slice(void *content, size_t size)
{
	return ((t_ft_slice){
		.content = content,
		.size = size});
}

t_ft_slice	ft_slice_empty(void)
{
	return ((t_ft_slice){
		.content = NULL,
		.size = 0});
}

bool	ft_slice_is_ok(t_ft_slice slice)
{
	return (slice.content != NULL);
}

bool	ft_slice_is_empty(t_ft_slice slice)
{
	return ((slice.size == 0) || (slice.content == NULL));
}
