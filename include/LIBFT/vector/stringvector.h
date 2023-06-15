/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringvector.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:14:45 by htsang            #+#    #+#             */
/*   Updated: 2023/06/15 19:04:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGVECTOR_H
# define STRINGVECTOR_H

# include "LIBFT/vector.h"

///////////////////////////////////////////////////////////
////////////     stringvector interface     ///////////////
///////////////////////////////////////////////////////////

typedef t_ft_vector	t_ft_stringvector;

int		ft_stringvector_init(t_ft_stringvector *stringv, size_t capacity);

char	*ft_stringvector_get(const t_ft_stringvector *stringv, size_t index);

char	*ft_stringvector_set(t_ft_stringvector *stringv, size_t index, \
char *string);

int		ft_stringvector_resize(t_ft_stringvector *stringv);

void	ft_stringvector_free(t_ft_stringvector *stringv);

/**
 * @brief Addiitonal interface
*/

char	*ft_stringvector_append(t_ft_vector *vector, char *data);

char	*ft_stringvector_insert(t_ft_vector *vector, char *data, size_t index);

int		ft_stringvector_remove(t_ft_vector *vector, size_t index);

#endif