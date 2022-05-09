/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:21:27 by htsang            #+#    #+#             */
/*   Updated: 2022/05/09 22:09:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

int		ft_isalnum(int c);

int		ft_tolower(int c);

int		ft_toupper(int c);

size_t	ft_strlen(const char *str);

int		ft_strcmp(const char *s1, const char *s2);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strcpy(char *dest, const char *src);

char	*ft_strncpy(char *dest, const char *src, size_t n);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

char	*ft_strcat(char *dest, const char *src);

char	*ft_strncat(char *dest, const char *src, size_t n);

size_t	ft_strlcat(char *dest, const char *src, size_t size);

char	*ft_strstr(const char *str, const char *to_find);

char	*ft_strnstr(const char *str, const char *to_find, size_t n);

char	*ft_strchr(const char *str, int c);

char	*ft_strrchr(const char *str, int c);

char	*ft_strdup(const char *str);

void	ft_bzero(void *str, size_t n);

int		ft_atoi(const char *str);

#endif