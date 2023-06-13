/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:08:36 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 15:04:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

#endif