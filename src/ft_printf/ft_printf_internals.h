/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internals.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:24 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:58:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNALS_H
# define FT_PRINTF_INTERNALS_H

# include "parsers/ftprintf_parsers.h"
# include "printers/ftprintf_printers.h"

//////////////////////////////
//////    Core logic    //////
//////////////////////////////

int	ftprintf_control(const char *str, va_list *subs);

//////////////////////////////
//////    Sequencers    //////
//////////////////////////////

int	ftprintf_sequence_num(char format, struct s_ftprintf_parser *states, \
va_list *subs);

int	ftprintf_sequence_str(char format, struct s_ftprintf_parser *states, \
va_list *subs);

#endif