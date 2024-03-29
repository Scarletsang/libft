/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 01:40:25 by htsang            #+#    #+#             */
/*   Updated: 2023/08/04 14:49:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

union u_ft_tobject	ft_tobject_empty(void)
{
	return ((union u_ft_tobject){});
}

union u_ft_tobject	ft_tobject_char(char c)
{
	return ((union u_ft_tobject){.as_char = c});
}

union u_ft_tobject	ft_tobject_bool(bool b)
{
	return ((union u_ft_tobject){.as_bool = b});
}
