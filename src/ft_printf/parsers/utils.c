/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:01:42 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:46:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_parsers.h"

char	ftprintf_has_flag(struct s_ftprintf_parser *states, char flag)
{
	int	i;

	if (!states->flags_end)
	{
		return (0);
	}
	i = 0;
	while (*(states->flags_end - i) != '%')
	{
		if (*(states->flags_end - i) == flag)
		{
			return (flag);
		}
		i++;
	}
	return (0);
}

char	ftprintf_has_flags(struct s_ftprintf_parser *states, char *flags)
{
	int		i;

	if (!states->flags_end)
	{
		return (0);
	}
	i = 0;
	while (*(states->flags_end - i) != '%')
	{
		if (ft_strchr(flags, *(states->flags_end - i)))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	ftprintf_has_precision(struct s_ftprintf_parser *states)
{
	return (states->precision > -1);
}

/**
** @param n: a long number
** @param base: the base to interpret the number in
** @return the length of the given number when printed out
*/
size_t	ftprintf_get_numlen(long n, int base)
{
	size_t	len;
	int		sign;

	len = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
	}
	while (n * sign > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

/**
** @param n: a pointer
** @return the length of the given pointer address if printed out.
*/
size_t	ftprintf_get_ptrlen(size_t n)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}
