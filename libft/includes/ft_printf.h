/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:11:53 by katakada          #+#    #+#             */
/*   Updated: 2024/12/02 00:02:49 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <errno.h>
# include <stdarg.h>
# define DEC "0123456789"
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"
# define HEX_SIGN_UPPER "0X"
# define HEX_SIGN_LOWER "0x"

typedef struct s_flags
{
	int	is_minus;
	int	is_zero;
	int	is_sharp;
	int	is_space;
	int	is_plus;
	int	blank_size;
	int	precision;
	int	charactors;
	int	sign;
	int	type;
}		t_flags;

int		ft_printf(const char *format, ...);
int		ft_vdprintf(int fd, const char *format, va_list args);
int		ft_vprintf(const char *format, va_list args);
int		ft_dprintf(int fd, const char *format, ...);

int		print_format(const char **format, t_flags *flags, va_list *args,
			int fd);

int		print_invalid_char_start_case(const char **format, int fd);
int		print_over_flow_case(void);
int		print_invalid_order_case(const char **format, t_flags *flags,
			va_list *args, int fd);

int		print_char(int c, t_flags *flags, int fd);
int		print_str(const char *str, t_flags *flags, int fd);
int		print_int(int n, t_flags *flags, int fd);
int		print_hex_base(unsigned int hex, t_flags *flags, char *base, int fd);
int		print_prefix_hex(t_flags *flags, int fd, char *base);
int		print_ptr(unsigned long long ptr, t_flags *flags, int fd);
int		print_percent(t_flags *flags, int fd);
int		print_u_int(unsigned int n, t_flags *flags, int fd);

int		print_zero_loop(int loop_times, int fd);
int		print_space_loop(int loop_times, int fd);

int		print_blank_space_nbr(t_flags *flags, int fd);
int		print_flag_zero_hex(t_flags *flags, int fd);
int		print_flag_zero_int(t_flags *flags, int fd);
int		print_core_int(int fd, t_flags *flags, long output_nbr);
int		print_suffix_nbr_str(t_flags *flags, int fd);

int		force_print_flags(t_flags *flags, int fd);
int		force_print_number(int fd, int number);
int		force_print_precision(t_flags *flags, int fd);

int		ft_putnbr_hex_base(unsigned long long n, char *base, int fd);
int		ft_putnbr_ptr_base(unsigned long long n, char *base, int fd);

int		is_format_flag_after_dot(const char **format, char valid_type);
int		is_invalid_order_case(const char **format, char valid_type);

int		is_format_flag(int c);
int		is_not_zero_format_flag(int c);
int		is_field_digit(int c);
int		is_precision_dot(int c);
int		is_number_type(int c);
int		is_format_type(int c);

void	set_format_type(const char **format, t_flags *flags);
void	set_format_flags_loop(const char **format, t_flags *flags,
			va_list *args);

int		ascii_to_field_size(const char *str_pos);
void	set_precision_number(const char **format, t_flags *flags,
			va_list *args);
int		can_use_precision_number(const char **format, t_flags *flags);

void	force_set_format_flags(const char **format, t_flags *flags);
void	force_set_field_size(const char **format, t_flags *flags,
			va_list *args);
int		force_set_precision(const char **format, t_flags *flags, va_list *args);

void	set_char_print_conf(t_flags *flags);
void	set_str_print_conf(t_flags *flags, const char *str);
void	set_ptr_print_conf(t_flags *flags, unsigned long long output_ptr);
void	set_int_print_conf(t_flags *flags, long *output_nbr);
void	set_hex_print_conf(t_flags *flags, unsigned int output_hex, char *base);
void	set_u_int_print_conf(t_flags *flags, unsigned int output_nbr);

void	set_print_conf_precision(t_flags *flags);
void	set_print_conf_counted_digits(t_flags *flags, unsigned long long number,
			char *base);
void	set_print_conf_nbr_digits(t_flags *flags, long output_nbr, char *base);
void	set_print_conf_blank_size_int(t_flags *flags, long output_nbr);
void	set_print_conf_precision_int(t_flags *flags);

long	get_abs(long n);

#endif