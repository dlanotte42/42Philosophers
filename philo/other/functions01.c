/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:02:24 by dlanotte          #+#    #+#             */
/*   Updated: 2022/01/20 23:58:26 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

void	ft_usleep(int time, int philo_numb)
{
	int		i;

	if (time > 0)
	{
		i = ft_clock() + time;
		while (ft_clock() < i)
			usleep(philo_numb * 2);
	}
}

int	ft_clock(void)
{
	struct timeval	time;
	int				actual_time;

	gettimeofday(&time, NULL);
	actual_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (actual_time);
}
