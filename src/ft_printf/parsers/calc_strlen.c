/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:18:47 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:43:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_parsers.h"

static long long	va_strlen(va_list *subs)
{
	char	*str;
	int		len;

	str = va_arg(*subs, char *);
	len = 6;
	if (str)
	{
		len = (int) ft_strlen(str);
	}
	return (len);
}

int	ftprintf_calc_strlen(va_list *subs)
{
	return (ftprintf_va_peek(subs, &va_strlen));
}
