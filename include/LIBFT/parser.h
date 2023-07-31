/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:55:28 by htsang            #+#    #+#             */
/*   Updated: 2023/07/31 21:59:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "LIBFT/list.h"
# include "LIBFT/slice.h"
# include <stdbool.h>

///////////////////////////////////////////
////////////   parser entity   ////////////
///////////////////////////////////////////

struct s_ft_parser_entity
{
	void		*payload;
	t_ft_str	input;
};

bool						ft_parser_entity_is_ok(\
struct s_ft_parser_entity entity);

/////////////////////////////////////
////////////   parsers   ////////////
/////////////////////////////////////

typedef struct s_ft_parser_entity	(*t_ft_parser)\
	(struct s_ft_parser_entity input, void *option);

///////////////////////////////////////////////
////////////   parser decorators   ////////////
///////////////////////////////////////////////

typedef struct s_ft_parser_entity	(*t_ft_parser_decorator)\
	(t_ft_parser parser, struct s_ft_parser_entity input, void *option);

struct s_ft_parser_entity	ft_parser_optional(\
t_ft_parser parser, struct s_ft_parser_entity input, void *option);

struct s_ft_parser_entity	ft_parser_some(\
t_ft_parser parser, struct s_ft_parser_entity input, void *option);

////////////////////////////////////////////////
////////////   parser combinators   ////////////
////////////////////////////////////////////////

typedef struct s_ft_parser_entity	(*t_ft_parser_combinator)\
	(t_ft_parser *parsers, size_t amount, \
	struct s_ft_parser_entity input, void *option);

struct s_ft_parser_entity	ft_parser_and(t_ft_parser *parsers, size_t amount, \
struct s_ft_parser_entity input, void *option);

struct s_ft_parser_entity	ft_parser_or(t_ft_parser *parsers, size_t amount, \
struct s_ft_parser_entity input, void *option);

#endif