/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_parsers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:47:34 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 15:01:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_PARSERS_H
# define FTPRINTF_PARSERS_H

# include <stdarg.h>
# include <stdlib.h>
# include "LIBFT/ctype.h"
# include "LIBFT/string.h"

/**
 * @brief A strict to be constructed by parsers, and passed
 * to printers to print out the substitution with the correct
 * format.
 * 
 * @details during the initial parsing, the struct wouuld be used
 * to store values collected by the parsers. After that, calculators
 * would perform calculations on the struct itself, and they have
 * slightly different meaning in string(cs%) and number(diuxXp)
 * substitution:
 * 
 * @param flags_end: The end of an array of flags, array always started
 * with a '%'.
 * @param width: length of filler chars (in cs%), 
 * length of spaces (with .) or filler chars (in diuxXp).
 * @param precision: unused (in cs%), length of zeros (in diuxXp)
 * @param strlen: characters to print of the substitution string
*/
struct s_ftprintf_parser
{
	char	*flags_end;
	int		width;
	int		precision;
	int		strlen;
};

typedef char		(*t_ftprintf_parser_func)(const char *, \
struct s_ftprintf_parser *);

typedef long long	(*t_ftprintf_peek_func)(va_list *);

///////////////////////////
//////    Parsers    //////
///////////////////////////

void		ftprintf_parser_init(struct s_ftprintf_parser *parser);

void		ftprintf_parser_run(char **str, struct s_ftprintf_parser *states, \
t_ftprintf_parser_func parser);

char		ftprintf_parse_flags(const char *str, \
struct s_ftprintf_parser *states);

char		ftprintf_parse_width(const char *str, \
struct s_ftprintf_parser *states);

char		ftprintf_parse_precision(const char *str, \
struct s_ftprintf_parser *states);

///////////////////////////////
//////    Calculators    //////
///////////////////////////////

int			ftprintf_calc_numlen(va_list *subs, char format);

int			ftprintf_calc_strlen(va_list *subs);

void		ftprintf_calc_states_str(char format, \
struct s_ftprintf_parser *states, va_list *subs);

void		ftprintf_calc_states_num(char format, \
struct s_ftprintf_parser *states, va_list *subs);

/////////////////////////////
//////     Private     //////
/////////////////////////////

char		ftprintf_has_flag(struct s_ftprintf_parser *states, char flag);

char		ftprintf_has_flags(struct s_ftprintf_parser *states, char *flags);

char		ftprintf_has_precision(struct s_ftprintf_parser *states);

size_t		ftprintf_get_numlen(long n, int base);

size_t		ftprintf_get_ptrlen(size_t n);

int			ftprintf_sub_is_zero(char format, va_list *subs);

/////////////////////////////////////////////
//////     Peek and peek functions     //////
/////////////////////////////////////////////

int			ftprintf_va_peek(va_list *subs, t_ftprintf_peek_func getter);

long long	ftprintf_va_is_minus(va_list *subs);

long long	ftprintf_va_is_zero(va_list *subs);

long long	ftprintf_va_ptr_is_zero(va_list *subs);

#endif