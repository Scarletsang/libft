/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_sequence.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:49:15 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:49:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_SEQUENCE_H
# define FTPRINTF_SEQUENCE_H

# include "../parsers/ftprintf_parsers.h"
# include "../printers/ftprintf_printers.h"

int	ftprintf_str_sub(char format, struct s_ftprintf_parser *states, \
va_list *subs);

int	ftprintf_num_sub(char format, char write_zero, va_list *subs);

int	ftprintf_prefix(char format, struct s_ftprintf_parser *states, \
va_list *subs);

///////////////////////
////// private ////////
///////////////////////

int	ftprintf_sequence_num_with_precision(char format, \
struct s_ftprintf_parser *states, va_list *subs);

#endif