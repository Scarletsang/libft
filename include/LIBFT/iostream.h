/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iostream.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:56:31 by htsang            #+#    #+#             */
/*   Updated: 2023/07/04 17:32:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOSTREAM_H
# define IOSTREAM_H

# include <unistd.h>
# include "LIBFT/slice.h"
# include "LIBFT/stringbuilder.h"
# include "LIBFT/stringbuilder/sb_iterator.h"

# ifndef IOSTREAM_BUFFER_SIZE
#  define IOSTREAM_BUFFER_SIZE 20
# endif

struct s_ft_iostream
{
	t_ft_sb				sb;
	t_ft_sb_iterator	iterator;
	size_t				delimiter_size;
	ssize_t				read_size;
};

int			ft_iostream_init(struct s_ft_iostream *iostream);

void		ft_iostream_reset(struct s_ft_iostream *iostream);

ssize_t		ft_iostream_read(struct s_ft_iostream *iostream, int fd);

int			ft_iostream_read_until(struct s_ft_iostream *iostream, \
int fd, t_ft_str match);

int			ft_iostream_read_until_delimiter(\
struct s_ft_iostream *iostream, int fd, t_ft_str delimiter);

t_ft_str	ft_iostream_to_slice(struct s_ft_iostream *iostream);

void		ft_iostream_free(struct s_ft_iostream *iostream);

#endif