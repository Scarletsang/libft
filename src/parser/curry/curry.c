/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 02:27:52 by htsang            #+#    #+#             */
/*   Updated: 2023/08/04 04:11:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

t_ft_parser_curried	ft_parser_curry(t_ft_parser parser, \
union u_ft_tobject option)
{
	return ((t_ft_parser_curried){parser, option});
}

t_ft_parser_decorator_curried	ft_decorator_curry(\
t_ft_parser_decorator decorator, struct s_ft_parser_entity *entity)
{
	return ((t_ft_parser_decorator_curried){decorator, entity});
}

t_ft_parser_combinator_curried	ft_combinator_curry(\
t_ft_parser_combinator combinator, struct s_ft_parser_entity *entities, \
size_t amount)
{
	return ((t_ft_parser_combinator_curried){combinator, entities, amount});
}
