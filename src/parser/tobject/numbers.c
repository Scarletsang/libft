/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 01:41:25 by htsang            #+#    #+#             */
/*   Updated: 2023/08/04 01:48:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

union u_ft_tobject	ft_tobject_int(int i)
{
	return ((union u_ft_tobject){.as_int = i});
}

union u_ft_tobject	ft_tobject_uint(unsigned int uint)
{
	return ((union u_ft_tobject){.as_uint = uint});
}

union u_ft_tobject	ft_tobject_size(size_t size)
{
	return ((union u_ft_tobject){.as_size = size});
}

union u_ft_tobject	ft_tobject_float(float f)
{
	return ((union u_ft_tobject){.as_float = f});
}

union u_ft_tobject	ft_tobject_double(double d)
{
	return ((union u_ft_tobject){.as_double = d});
}
