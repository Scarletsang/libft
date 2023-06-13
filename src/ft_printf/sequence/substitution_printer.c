/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution_printer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:51:51 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:49:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_sequence.h"

static int	ftprintf_maybe_s(struct s_ftprintf_parser *states, va_list *subs)
{
	char	*str;

	str = va_arg(*subs, char *);
	if (str)
	{
		return (ftprintf_s(str, states->strlen));
	}
	else
	{
		return (ftprintf_null(states->strlen));
	}
}

int	ftprintf_str_sub(char format, struct s_ftprintf_parser *states, \
va_list *subs)
{
	if (format == 'c')
	{
		return (ftprintf_c(va_arg(*subs, int)));
	}
	else if (format == '%')
	{
		return (ftprintf_c('%'));
	}
	else
	{
		return (ftprintf_maybe_s(states, subs));
	}
}

int	ftprintf_num_sub(char format, char write_zero, va_list *subs)
{
	if (write_zero <= 0)
	{
		va_arg(*subs, int);
		return (0);
	}
	if (ft_strchr("di", format))
	{
		return (ftprintf_di(va_arg(*subs, int)));
	}
	else if (format == 'u')
	{
		return (ftprintf_u(va_arg(*subs, unsigned int)));
	}
	else if (format == 'X')
	{
		return (ftprintf_x_upper(va_arg(*subs, unsigned int)));
	}
	else if (format == 'x')
	{
		return (ftprintf_x(va_arg(*subs, unsigned int)));
	}
	else
	{
		return (ftprintf_p(va_arg(*subs, size_t)));
	}
}

int	ftprintf_prefix(char format, struct s_ftprintf_parser *states, \
va_list *subs)
{
	if (format == 'p' || (ft_strchr("xX", format) && \
		ftprintf_has_flag(states, '#') && !ftprintf_sub_is_zero(format, subs)))
	{
		return (ftprintf_0x((format > 64) && (format < 91)));
	}
	else if (ft_strchr("di", format) && \
		ftprintf_va_peek(subs, &ftprintf_va_is_minus))
	{
		return (ftprintf_minus());
	}
	else if (ftprintf_has_flag(states, '+'))
	{
		return (ftprintf_plus());
	}
	else if (ftprintf_has_flag(states, ' '))
	{
		return (ftprintf_spaces(1));
	}
	return (0);
}
