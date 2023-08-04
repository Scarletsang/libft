/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 01:40:25 by htsang            #+#    #+#             */
/*   Updated: 2023/08/04 01:47:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

union u_ft_tobject	ft_tobject_ptr(void *ptr)
{
	return ((union u_ft_tobject){.as_ptr = ptr});
}

union u_ft_tobject	ft_tobject_str(char *str)
{
	return ((union u_ft_tobject){.as_str = str});
}

union u_ft_tobject	ft_tobject_vector(t_ft_vector *vector)
{
	return ((union u_ft_tobject){.as_vector = vector});
}

union u_ft_tobject	ft_tobject_char(char c)
{
	return ((union u_ft_tobject){.as_char = c});
}

union u_ft_tobject	ft_tobject_bool(bool b)
{
	return ((union u_ft_tobject){.as_bool = b});
}
