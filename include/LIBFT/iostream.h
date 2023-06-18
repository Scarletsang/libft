/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iostream.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:56:31 by htsang            #+#    #+#             */
/*   Updated: 2023/06/18 00:29:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOSTREAM_H
# define IOSTREAM_H

# include <unistd.h>
# include "LIBFT/slice.h"
# include "LIBFT/stringbuilder.h"
# include "LIBFT/stringbuilder/clipper.h"

# ifndef IOSTREAM_BUFFER_SIZE
#  define IOSTREAM_BUFFER_SIZE 20
# endif

struct s_ft_iostream
{
	t_ft_sb					sb;
	struct s_ft_sb_clipper	clipper;
	bool					no_selection;
	ssize_t					read_size;
};

int					ft_iostream_init(struct s_ft_iostream *iostream);

int					ft_iostream_read(struct s_ft_iostream *iostream, int fd);

int					ft_iostream_read_until(struct s_ft_iostream *iostream, \
int fd, const char *end_match);

t_ft_string_slice	ft_iostream_to_slice(struct s_ft_iostream *iostream);

void				ft_iostream_free(struct s_ft_iostream *iostream);

#endif