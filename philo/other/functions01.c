/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:02:24 by dlanotte          #+#    #+#             */
/*   Updated: 2022/01/19 01:28:30 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int						is_negative;
	unsigned long long		result;

	result = 0;
	is_negative = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || \
			*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		is_negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return ((int)result * is_negative);
}