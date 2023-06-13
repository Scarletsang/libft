/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:13:10 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:48:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_parsers.h"

static int	ftprintf_minus_without_neg(int a, int b)
{
	if (a > b)
	{
		return (a - b);
	}
	return (0);
}

static int	ftprintf_prefixlen(char format, \
struct s_ftprintf_parser *states, va_list *subs, int is_zero)
{
	char	has_plus_or_space;

	has_plus_or_space = ftprintf_has_flags(states, "+ ");
	if (format == 'u' && has_plus_or_space)
	{
		return (1);
	}
	if (ft_strchr("di", format) && \
	(ftprintf_va_peek(subs, &ftprintf_va_is_minus) || has_plus_or_space))
	{
		return (1);
	}
	if (format == 'p' || \
	(ft_strchr("xX", format) && ftprintf_has_flag(states, '#') && !is_zero))
	{
		return (2);
	}
	return (0);
}

static void	ftprintf_calc_states_num_with_precision(int prefixlen, \
struct s_ftprintf_parser *states)
{
	int	space_len;
	int	zero_len;

	space_len = 0;
	zero_len = 0;
	if (states->precision >= states->width)
		zero_len = ftprintf_minus_without_neg(states->precision, \
			states->strlen);
	else
	{
		if (states->strlen < states->precision)
		{
			zero_len = states->precision - states->strlen;
			space_len = ftprintf_minus_without_neg(states->width, \
			states->precision + prefixlen);
		}
		else if (states->strlen + prefixlen < states->width)
		{
			space_len = states->width - states->strlen - prefixlen;
		}
	}
	states->width = space_len;
	states->precision = zero_len;
}

void	ftprintf_calc_states_num(char format, struct s_ftprintf_parser *states, \
va_list *subs)
{
	int	is_zero;
	int	prefix_len;

	is_zero = ftprintf_sub_is_zero(format, subs);
	prefix_len = ftprintf_prefixlen(format, states, subs, is_zero);
	if (is_zero)
	{
		states->strlen = !(states->precision == 0);
	}
	else
	{
		states->strlen = ftprintf_calc_numlen(subs, format);
	}
	if (ftprintf_has_precision(states))
	{
		ftprintf_calc_states_num_with_precision(prefix_len, states);
	}
	else
	{
		states->width = ftprintf_minus_without_neg(states->width, \
		states->strlen + prefix_len);
	}
}

void	ftprintf_calc_states_str(char format, struct s_ftprintf_parser *states, \
va_list *subs)
{
	states->strlen = 1;
	if (format == 's')
	{
		states->strlen = ftprintf_calc_strlen(subs);
		if (ftprintf_has_precision(states) && \
			states->precision < states->strlen)
		{
			states->strlen = states->precision;
		}
	}
	states->width = ftprintf_minus_without_neg(states->width, states->strlen);
}
