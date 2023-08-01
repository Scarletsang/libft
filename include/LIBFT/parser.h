/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:55:28 by htsang            #+#    #+#             */
/*   Updated: 2023/08/01 13:19:41 by htsang           ###   ########.fr       */
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

struct s_ft_parser_entity	ft_parser_entity(void *payload, t_ft_str input);

struct s_ft_parser_entity	ft_parser_entity_compose(\
struct s_ft_parser_entity entity, void *payload);

bool						ft_parser_entity_is_ok(\
struct s_ft_parser_entity entity);

t_ft_str					ft_parser_advance(t_ft_str input, size_t len);

char						*ft_parser_peek(t_ft_str input, size_t index)

/////////////////////////////////////
////////////   parsers   ////////////
/////////////////////////////////////

typedef struct s_ft_parser_entity	(*t_ft_parser)\
	(struct s_ft_parser_entity input, void *option);

struct s_ft_parser_entity	ft_parser_char(\
struct s_ft_parser_entity input, char *set);

struct s_ft_parser_entity	ft_parser_digit(\
struct s_ft_parser_entity input, void *option);

struct s_ft_parser_entity	ft_parser_ignore(\
struct s_ft_parser_entity input, char *set);

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