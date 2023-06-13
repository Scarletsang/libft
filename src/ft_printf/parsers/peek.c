/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:15:07 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:46:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_parsers.h"

int	ftprintf_va_peek(va_list *subs, t_ftprintf_peek_func getter)
{
	va_list		copy;
	long long	result;

	va_copy(copy, *subs);
	result = getter(&copy);
	va_end(copy);
	return (result);
}

long long	ftprintf_va_is_minus(va_list *subs)
{
	return ((int) va_arg(*subs, int) < 0);
}

long long	ftprintf_va_is_zero(va_list *subs)
{
	return ((int) va_arg(*subs, long long) == 0);
}

long long	ftprintf_va_ptr_is_zero(va_list *subs)
{
	return ((size_t) va_arg(*subs, size_t) == 0);
}

int	ftprintf_sub_is_zero(char format, va_list *subs)
{
	if (format == 'p')
	{
		return (ftprintf_va_peek(subs, ftprintf_va_ptr_is_zero));
	}
	return (ftprintf_va_peek(subs, ftprintf_va_is_zero));
}
