/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 02:27:52 by htsang            #+#    #+#             */
/*   Updated: 2023/08/11 22:04:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

t_ft_parser_curried	ft_parser_curry(t_ft_parser parser, \
union u_ft_tobject option)
{
	return ((t_ft_parser_curried){
		.parser = parser,
		.option = option
	});
}

t_ft_parser_decorator_curried	ft_decorator_curry(\
t_ft_parser_decorator decorator, struct s_ft_parser_entity *entity, \
union u_ft_tobject option)
{
	return ((t_ft_parser_decorator_curried){
		.decorator = decorator,
		.entity = entity,
		.option = option
	});
}

t_ft_parser_combinator_curried	ft_combinator_curry(\
t_ft_parser_combinator combinator, struct s_ft_parser_entity *entities, \
size_t amount, union u_ft_tobject option)
{
	return ((t_ft_parser_combinator_curried){
		.combinator = combinator,
		.entities = entities,
		.amount = amount,
		.option = option
	});
}
