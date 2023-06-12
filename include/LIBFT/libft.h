/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:21:27 by htsang            #+#    #+#             */
/*   Updated: 2023/06/12 13:08:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# ifdef __linux__
#  include <stdint.h>
# endif
# include <limits.h>

///////////////////////////
//// basic functions //////
///////////////////////////

int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

///////////////////////////
//// string functions /////
///////////////////////////

size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t max_len);
char	*ft_strncpy(char *dest, const char *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t max_len);
size_t	ft_strlcat(char *dest, const char *src, size_t max_len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
int		ft_atoi(const char *str);

////////////////////////////////////////
//// string functions with malloc //////
////////////////////////////////////////

char	*ft_strdup(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t max_len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strljoin(char *dest, char const *src, size_t len);
char	*ft_strtrim(char const *str, char const *set);
char	**ft_split(char const *str, char c);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
char	*ft_itoa(int n);

////////////////////////////
//// memory functions //////
////////////////////////////

void	ft_bzero(void *mem, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *mem, int val, size_t max_size);
void	*ft_memset(void *mem, int val, size_t size);
int		ft_memcmp(const void *m1, const void *m2, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);

///////////////////////////
////// IO functions ///////
///////////////////////////

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif