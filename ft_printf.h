/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoca <akoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:50:24 by akoca             #+#    #+#             */
/*   Updated: 2026/05/07 11:50:45 by akoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define UP_HEXA "0123456789ABCDEF"
# define LOW_HEXA "0123456789abcdef"
# define DECIMAL "0123456789"

int	ft_printf(const char *s, ...);
int	ft_strlen(const char *s);
int	ft_putchar_s(char c);
int	ft_putstr_s(char *s);
int	ft_putnbr_s(int nbr, char *base);
int	ft_puthexa_uint(unsigned int nbr, char *base);
int	ft_put_addr(void *ptr);
int	ft_putaddr_long(long unsigned int nbr, char *base);

#endif