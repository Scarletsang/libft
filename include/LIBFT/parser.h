/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:55:28 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 14:53:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "LIBFT/list.h"
# include "LIBFT/slice.h"
# include "LIBFT/vector.h"
# include <stdbool.h>

//////////////////////////////////////////
////////////   typed object   ////////////
//////////////////////////////////////////

enum e_ft_tobject_type
{
	FT_TOBJECT_PTR,
	FT_TOBJECT_STR,
	FT_TOBJECT_VECTOR,
	FT_TOBJECT_CHAR,
	FT_TOBJECT_BOOL,
	FT_TOBJECT_INT,
	FT_TOBJECT_UINT,
	FT_TOBJECT_SIZE,
	FT_TOBJECT_FLOAT
};

/**
 * @brief Typed object
*/
union u_ft_tobject
{
	void								*as_ptr;
	t_ft_vector							*as_vector;
	char								*as_str;
	char								as_char;
	bool								as_bool;
	int									as_int;
	unsigned int						as_uint;
	size_t								as_size;
	double								as_float;
};

union u_ft_tobject				ft_tobject_empty(void);

union u_ft_tobject				ft_tobject_ptr(void *ptr);

union u_ft_tobject				ft_tobject_str(char *str);

union u_ft_tobject				ft_tobject_vector(t_ft_vector *vector);

union u_ft_tobject				ft_tobject_float(float f);

union u_ft_tobject				ft_tobject_char(char c);

union u_ft_tobject				ft_tobject_bool(bool b);

union u_ft_tobject				ft_tobject_int(int i);

union u_ft_tobject				ft_tobject_uint(unsigned int uint);

union u_ft_tobject				ft_tobject_size(size_t size);

/////////////////////////////////////////
////////////   parser atom   ////////////
/////////////////////////////////////////

struct s_ft_parser_atom
{
	union u_ft_tobject	payload;
	bool				is_valid;
	t_ft_str			string;
};

typedef struct s_ft_parser_atom	t_ft_parser_atom_char;

struct s_ft_parser_atom			ft_parser_atom(\
union u_ft_tobject payload, t_ft_str input);

struct s_ft_parser_atom			ft_parser_atom_empty(t_ft_str input, \
bool is_valid);

struct s_ft_parser_atom			ft_parser_atom_payload_set(\
struct s_ft_parser_atom entity, union u_ft_tobject payload);

struct s_ft_parser_atom			ft_parser_atom_validity_set(\
struct s_ft_parser_atom entity, bool is_valid);

bool							ft_parser_atom_is_ok(\
struct s_ft_parser_atom entity);

bool							ft_parser_atom_is_end(\
struct s_ft_parser_atom entity);

t_ft_str						ft_parser_advance(t_ft_str input, size_t len);

char							*ft_parser_peek(t_ft_str input, size_t index);

/////////////////////////////////////
////////////   parsers   ////////////
/////////////////////////////////////

struct							s_ft_parser_entity;

typedef struct s_ft_parser_atom	(*t_ft_parser)\
	(struct s_ft_parser_atom input, union u_ft_tobject option);

typedef struct s_ft_parser_atom	(*t_ft_parser_decorator)\
	(struct s_ft_parser_entity entity, struct s_ft_parser_atom input, \
	union u_ft_tobject option);

typedef struct s_ft_parser_atom	(*t_ft_parser_combinator)\
	(struct s_ft_parser_entity *entities, size_t amount, \
	struct s_ft_parser_atom input, union u_ft_tobject option);

/////////////////////////////////////////////
////////////   curried parsers   ////////////
/////////////////////////////////////////////

typedef struct s_ft_parser_curried
{
	t_ft_parser			parser;
	union u_ft_tobject	option;
}				t_ft_parser_curried;

typedef struct s_ft_parser_decorator_curried
{
	t_ft_parser_decorator		decorator;
	struct s_ft_parser_entity	*entity;
	union u_ft_tobject			option;
}				t_ft_parser_decorator_curried;

typedef struct s_ft_parser_combinator_curried
{
	t_ft_parser_combinator		combinator;
	struct s_ft_parser_entity	*entities;
	size_t						amount;
	union u_ft_tobject			option;
}				t_ft_parser_combinator_curried;

t_ft_parser_curried				ft_parser_curry(\
t_ft_parser parser, union u_ft_tobject option);

t_ft_parser_decorator_curried	ft_decorator_curry(\
t_ft_parser_decorator decorator, struct s_ft_parser_entity *entity, \
union u_ft_tobject option);

t_ft_parser_combinator_curried	ft_combinator_curry(\
t_ft_parser_combinator combinator, struct s_ft_parser_entity *entities, \
size_t amount, union u_ft_tobject option);

struct s_ft_parser_atom			ft_parser_evaluate(\
t_ft_parser_curried parser, struct s_ft_parser_atom input);

struct s_ft_parser_atom			ft_decorator_evaluate(\
t_ft_parser_decorator_curried decorator, struct s_ft_parser_atom input);

struct s_ft_parser_atom			ft_combinator_evaluate(\
t_ft_parser_combinator_curried combinator, struct s_ft_parser_atom input);

///////////////////////////////////////////
////////////   parser entity   ////////////
///////////////////////////////////////////

enum e_ft_parser_type
{
	FT_PARSER,
	FT_PARSER_DECORATOR,
	FT_PARSER_COMBINATOR
};

union u_ft_parser_construct
{
	t_ft_parser_curried				as_parser;
	t_ft_parser_decorator_curried	as_decorator;
	t_ft_parser_combinator_curried	as_combinator;
};

struct s_ft_parser_entity
{
	enum e_ft_parser_type			type;
	union u_ft_parser_construct		construct;
};

struct s_ft_parser_entity		ft_parser_entity(t_ft_parser parser, \
union u_ft_tobject option);

struct s_ft_parser_entity		ft_decorator_entity(\
t_ft_parser_decorator decorator, struct s_ft_parser_entity *entity, \
union u_ft_tobject option);

struct s_ft_parser_entity		ft_combinator_entity(\
t_ft_parser_combinator combinator, struct s_ft_parser_entity *entities, \
size_t amount, union u_ft_tobject option);

struct s_ft_parser_atom			ft_parser_entity_evaluate(\
struct s_ft_parser_entity *entity, struct s_ft_parser_atom input);

/////////////////////////////////////////////
////////////   builtin parsers   ////////////
/////////////////////////////////////////////

struct s_ft_parser_float_payload
{
	double	maximum;
	double	minumum;
	double	number;
	double	power;
};

t_ft_parser_atom_char			ft_parser_char(\
t_ft_parser_atom_char input, union u_ft_tobject set);

struct s_ft_parser_atom			ft_parser_digit_int(\
struct s_ft_parser_atom input, union u_ft_tobject is_negative);

struct s_ft_parser_atom			ft_parser_int(\
struct s_ft_parser_atom input, union u_ft_tobject option);

struct s_ft_parser_atom			ft_parser_uint(\
struct s_ft_parser_atom input, union u_ft_tobject option);

struct s_ft_parser_atom			ft_parser_size(\
struct s_ft_parser_atom input, union u_ft_tobject option);

struct s_ft_parser_atom			ft_parser_float(\
struct s_ft_parser_atom input, union u_ft_tobject option);

struct s_ft_parser_atom			ft_parser_digit_uint(\
struct s_ft_parser_atom input, union u_ft_tobject option);

struct s_ft_parser_atom			ft_parser_digit_size(\
struct s_ft_parser_atom input, union u_ft_tobject option);

struct s_ft_parser_atom			ft_parser_digit_float(\
struct s_ft_parser_atom input, union u_ft_tobject is_negative);

struct s_ft_parser_atom			ft_parser_digit_float_decimal(\
struct s_ft_parser_atom input, union u_ft_tobject is_negative);

struct s_ft_parser_atom			ft_parser_ignore(\
struct s_ft_parser_atom input, union u_ft_tobject set);

struct s_ft_parser_atom			ft_parser_ignore_not(\
struct s_ft_parser_atom input, union u_ft_tobject set);

struct s_ft_parser_atom			ft_parser_ignore_string(\
struct s_ft_parser_atom input, union u_ft_tobject string);

struct s_ft_parser_atom			ft_parser_ignore_multiple(\
struct s_ft_parser_atom input, union u_ft_tobject set);

struct s_ft_parser_atom			ft_parser_expect(\
struct s_ft_parser_atom input, union u_ft_tobject set);

struct s_ft_parser_atom			ft_parser_expect_not(\
struct s_ft_parser_atom input, union u_ft_tobject set);

////////////////////////////////////////////////
////////////   builtin decorators   ////////////
////////////////////////////////////////////////

struct s_ft_parser_atom			ft_parser_optional(\
struct s_ft_parser_entity entity, struct s_ft_parser_atom input, \
union u_ft_tobject option);

struct s_ft_parser_atom			ft_parser_accumulate(\
struct s_ft_parser_entity entity, struct s_ft_parser_atom input, \
union u_ft_tobject option);

struct s_ft_parser_atom			ft_parser_some(\
struct s_ft_parser_entity entity, struct s_ft_parser_atom input, \
union u_ft_tobject option);

////////////////////////////////////////////////
////////////   builtin combinators   ///////////
////////////////////////////////////////////////

struct s_ft_parser_atom			ft_parser_and(\
struct s_ft_parser_entity *entities, size_t amount, \
struct s_ft_parser_atom input, union u_ft_tobject option);

struct s_ft_parser_atom			ft_parser_or(\
struct s_ft_parser_entity *entities, size_t amount, \
struct s_ft_parser_atom input, union u_ft_tobject option);

#endif