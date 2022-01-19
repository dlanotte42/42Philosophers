/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 00:18:24 by dlanotte          #+#    #+#             */
/*   Updated: 2022/01/19 19:27:23 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_dead(t_settings *philo, int id)
{
	philo->is_dead = 1;
	pthread_mutex_lock(&philo->ss);
	printf("[%d][%d] has died\n", (ft_clock()) - philo->start_time, id +1);
}

void	ft_print_status(int print_action, t_settings *philo, int id)
{
	pthread_mutex_lock(&philo->ss);
	if (print_action == 0)
		printf("[%d][%d] has taken fork\n", (ft_clock()) - philo->start_time,
			id + 1);
	else if (print_action == 1)
		printf("[%d][%d] is eating\n", (ft_clock()) - philo->start_time, id + 1);
	else if (print_action == 2)
		printf("[%d][%d] is sleeping\n", (ft_clock()) - philo->start_time,
			id + 1);
	else if (print_action == 3)
		printf("[%d][%d] is thinking\n", (ft_clock()) - philo->start_time,
			id + 1);
	pthread_mutex_unlock(&philo->ss);
}