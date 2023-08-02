/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:55:28 by htsang            #+#    #+#             */
/*   Updated: 2023/08/02 18:20:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "LIBFT/list.h"
# include "LIBFT/slice.h"
# include "LIBFT/vector.h"
# include <stdbool.h>

# define FT_PARSER_ENTITIES_SIZE	8

////////////////////////////////////////////
////////////   parser payload   ////////////
////////////////////////////////////////////

/**
 * @brief Typed object
*/
union u_ft_tobject
{
	void			*as_ptr;
	char			*as_str;
	char			as_char;
	bool			as_bool;
	int				as_int;
	unsigned int	as_uint;
	size_t			as_size;
	float			as_float;
	double			as_double;
};

union u_ft_tobject			ft_parser_tobject_ptr(void *ptr);

union u_ft_tobject			ft_parser_tobject_str(char *str);

union u_ft_tobject			ft_parser_tobject_char(char c);

union u_ft_tobject			ft_parser_tobject_bool(bool b);

union u_ft_tobject			ft_parser_tobject_int(int i);

union u_ft_tobject			ft_parser_tobject_uint(unsigned int uint);

union u_ft_tobject			ft_parser_tobject_size(size_t size);

union u_ft_tobject			ft_parser_tobject_float(float f);

union u_ft_tobject			ft_parser_tobject_double(double d);

///////////////////////////////////////////
////////////   parser entity   ////////////
///////////////////////////////////////////

struct s_ft_parser_entity
{
	union u_ft_tobject	payload;
	bool				is_valid;
	t_ft_str			input;
};

typedef struct s_ft_parser_entity	t_ft_parser_char_entity;

struct s_ft_parser_entity	ft_parser_entity(\
union u_ft_tobject payload, t_ft_str input);

struct s_ft_parser_entity	ft_parser_entity_empty(t_ft_str input, \
bool is_valid);

struct s_ft_parser_entity	ft_parser_entity_payload_set(\
struct s_ft_parser_entity entity, union u_ft_tobject payload);

struct s_ft_parser_entity	ft_parser_entity_validity_set(\
struct s_ft_parser_entity entity, bool is_valid);

bool						ft_parser_entity_is_ok(\
struct s_ft_parser_entity entity);


bool						ft_parser_entity_is_end(\
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
	(struct s_ft_parser_entity input, union u_ft_tobject option);

typedef struct s_ft_parser_curried
{
	t_ft_parser			parser;
	union u_ft_tobject	option;
}				t_ft_parser_curried;

t_ft_parser_curried			ft_parser_curry(\
t_ft_parser parser, union u_ft_tobject option);

t_ft_parser_char_entity		ft_parser_char(\
t_ft_parser_char_entity input, union u_ft_tobject set);

t_ft_parser_char_entity		ft_parser_digit(\
t_ft_parser_char_entity input, union u_ft_tobject option);

struct s_ft_parser_entity	ft_parser_ignore(\
struct s_ft_parser_entity input, union u_ft_tobject set);

///////////////////////////////////////////////
////////////   parser decorators   ////////////
///////////////////////////////////////////////

typedef struct s_ft_parser_entity	(*t_ft_parser_decorator)\
	(t_ft_parser_curried curried_parser, struct s_ft_parser_entity input);

struct s_ft_parser_entity	ft_parser_optional(t_ft_parser_curried curried, \
struct s_ft_parser_entity input);

struct s_ft_parser_entity	ft_parser_accumulate(t_ft_parser_curried curried, \
struct s_ft_parser_entity input);

struct s_ft_parser_entities	ft_parser_some(t_ft_parser_curried curried, \
struct s_ft_parser_entities input);

////////////////////////////////////////////////
////////////   parser combinators   ////////////
////////////////////////////////////////////////

typedef struct s_ft_parser_entity	(*t_ft_parser_combinator)\
	(t_ft_parser_curried *curried_parsers, size_t amount, \
	struct s_ft_parser_entity input);

struct s_ft_parser_entity	ft_parser_and(t_ft_parser_curried *curried_parsers, \
size_t amount, struct s_ft_parser_entity input);

struct s_ft_parser_entity	ft_parser_or(t_ft_parser_curried *curried_parsers, \
size_t amount, struct s_ft_parser_entity input);

#endif