/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:47:24 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:47:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_parsers.h"

void	ftprintf_parser_init(struct s_ftprintf_parser *parser)
{
	parser->flags_end = NULL;
	parser->width = 0;
	parser->precision = -1;
	parser->strlen = 0;
}

void	ftprintf_parser_run(char **str, struct s_ftprintf_parser *states, \
t_ftprintf_parser_func parser)
{
	while (*str)
	{
		if (parser(*str, states))
		{
			return ;
		}
		else
		{
			(*str)++;
		}
	}
}

char	ftprintf_parse_flags(const char *str, struct s_ftprintf_parser *states)
{
	char	check_failed;

	check_failed = 1;
	if (ft_strchr("+ #0-", *str))
	{
		states->flags_end = (char *) str;
		check_failed = 0;
	}
	return (check_failed);
}

char	ftprintf_parse_width(const char *str, struct s_ftprintf_parser *states)
{
	char	check_failed;

	check_failed = 1;
	if (ft_isdigit(*str))
	{
		states->width = states->width * 10 + (*str - '0');
		check_failed = 0;
	}
	return (check_failed);
}

char	ftprintf_parse_precision(const char *str, \
struct s_ftprintf_parser *states)
{
	char	check_failed;

	check_failed = 1;
	if (ft_isdigit(*str))
	{
		states->precision = states->precision * 10 + (*str - '0');
		check_failed = 0;
	}
	return (check_failed);
}
