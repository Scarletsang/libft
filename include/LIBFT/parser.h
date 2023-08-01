/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:55:28 by htsang            #+#    #+#             */
/*   Updated: 2023/08/01 21:17:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "LIBFT/list.h"
# include "LIBFT/slice.h"
# include "LIBFT/vector.h"
# include <stdbool.h>

# define FT_PARSER_ENTITIES_SIZE	8

///////////////////////////////////////////
////////////   parser entity   ////////////
///////////////////////////////////////////

struct s_ft_parser_entity
{
	void		*payload;
	bool		is_owned;
	t_ft_str	input;
};

typedef struct s_ft_parser_entity	t_ft_parser_char_entity;

struct s_ft_parser_entity	ft_parser_entity(void *payload, t_ft_str input, \
bool is_owned);

struct s_ft_parser_entity	ft_parser_entity_compose(\
struct s_ft_parser_entity entity, void *payload, bool is_owned);

bool						ft_parser_entity_is_ok(\
struct s_ft_parser_entity entity);

t_ft_str					ft_parser_advance(t_ft_str input, size_t len);

char						*ft_parser_peek(t_ft_str input, size_t index);

/////////////////////////////////////////////
////////////   parser entities   ////////////
/////////////////////////////////////////////

struct s_ft_parser_entities
{
	t_ft_vector	payloads;
	t_ft_str	input;
};

int							ft_parser_entities_init(\
struct s_ft_parser_entities *entities, \
size_t item_size, t_ft_vector_item_copier copier, t_ft_str input);

void						ft_parser_entities_free(\
struct s_ft_parser_entities *entities);

bool						ft_parser_entities_is_ok(\
struct s_ft_parser_entities entities);

struct s_ft_parser_entities	ft_parser_entities_empty(void);

/////////////////////////////////////
////////////   parsers   ////////////
/////////////////////////////////////

typedef struct s_ft_parser_entity	(*t_ft_parser)\
	(struct s_ft_parser_entity input, void *option);

t_ft_parser_char_entity		ft_parser_char(\
t_ft_parser_char_entity input, char *set);

t_ft_parser_char_entity		ft_parser_digit(\
t_ft_parser_char_entity input, void *option);

struct s_ft_parser_entity	ft_parser_ignore(\
struct s_ft_parser_entity input, char *set);

///////////////////////////////////////////////
////////////   parser decorators   ////////////
///////////////////////////////////////////////

typedef struct s_ft_parser_entity	(*t_ft_parser_decorator)\
	(t_ft_parser parser, struct s_ft_parser_entity input, void *option);

struct s_ft_parser_entity	ft_parser_optional(\
t_ft_parser parser, struct s_ft_parser_entity input, void *option);

struct s_ft_parser_entities	ft_parser_some(\
t_ft_parser parser, struct s_ft_parser_entities input, void *option);

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