/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:39:39 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:58:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internals.h"

int	ft_printf(const char *str, ...)
{
	va_list	subs;
	int		size;

	va_start(subs, str);
	size = ftprintf_control(str, &subs);
	va_end(subs);
	return (size);
}
