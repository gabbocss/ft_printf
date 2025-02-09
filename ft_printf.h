/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <inbauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:30:46 by inbauman          #+#    #+#             */
/*   Updated: 2025/02/07 12:55:39 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	control_decimales(double num);
int	numeros_dos_cifras(long long num);
int	ft_putnbr(long long num);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_puthex(unsigned long long p);
int	control(char copia, va_list args);
int	ft_printf(char const *linea, ...);
int	numero_hex(unsigned int num, char x);
int	ft_toupper(int c);
int	ft_putstr_inverso(char *s, int i);

#endif 
