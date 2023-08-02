/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 01:40:25 by htsang            #+#    #+#             */
/*   Updated: 2023/08/02 13:48:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

union u_ft_parser_payload	ft_parser_payload_ptr(void *ptr)
{
	return ((union u_ft_parser_payload){.as_ptr = ptr});
}

union u_ft_parser_payload	ft_parser_payload_str(char *str)
{
	return ((union u_ft_parser_payload){.as_str = str});
}

union u_ft_parser_payload	ft_parser_payload_char(char c)
{
	return ((union u_ft_parser_payload){.as_char = c});
}

union u_ft_parser_payload	ft_parser_payload_bool(bool b)
{
	return ((union u_ft_parser_payload){.as_bool = b});
}
