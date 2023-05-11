/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:19:38 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/11 12:25:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int		ft_isalnum(int c);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memset(void *r, int c, size_t len);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void    *memmove(void *dst, const void *src, size_t n);

#endif
