/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:55:28 by htsang            #+#    #+#             */
/*   Updated: 2023/07/31 13:11:17 by htsang           ###   ########.fr       */
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
	(struct s_ft_parser_entity input);

///////////////////////////////////////////////
////////////   parser decorators   ////////////
///////////////////////////////////////////////

typedef struct s_ft_parser_entity	(*t_ft_parser_decorator)\
	(struct s_ft_parser_entity input, t_ft_parser parser);

struct s_ft_parser_entity	ft_parser_optional(\
struct s_ft_parser_entity input, t_ft_parser parser);

struct s_ft_parser_entity	ft_parser_some(\
struct s_ft_parser_entity input, t_ft_parser parser);

////////////////////////////////////////////////
////////////   parser combinators   ////////////
////////////////////////////////////////////////

typedef struct s_ft_parser_entity	(*t_ft_parser_combinator)\
	(struct s_ft_parser_entity input, t_ft_parser *parsers, size_t amount);

struct s_ft_parser_entity	ft_parser_and(struct s_ft_parser_entity input, \
t_ft_parser *parsers, size_t amount);

struct s_ft_parser_entity	ft_parser_or(struct s_ft_parser_entity input, \
t_ft_parser *parsers, size_t amount);

#endif