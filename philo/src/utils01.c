/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:07:43 by dlanotte          #+#    #+#             */
/*   Updated: 2022/01/21 00:01:16 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	smart_free(t_settings *settings)
{
	int	i;

	i = 0;
	free(settings->last_philo_eat_time);
	pthread_mutex_destroy(&settings->s);
	free(settings->forks);
	while (++i < settings->number_philos)
		pthread_detach(settings->philo[i]);
	pthread_mutex_destroy(&settings->ss);
	pthread_mutex_destroy(&settings->sss);
	free(settings->philo);
}

int	ft_check_args(char **argv, t_settings *settings)
{
	settings->num_times_philo_eat = -2;
	settings->number_philos = ft_atoi(argv[1]);
	settings->time_to_die = ft_atoi(argv[2]);
	settings->time_to_eat = ft_atoi(argv[3]);
	settings->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		settings->num_times_philo_eat = ft_atoi(argv[5]);
	if (settings->number_philos <= 0)
		return (0);
	if (settings->time_to_die <= 0)
		return (0);
	if (settings->time_to_eat <= 0)
		return (0);
	if (settings->time_to_sleep <= 0)
		return (0);
	if (settings->num_times_philo_eat <= 0 && argv[5])
		return (0);
	return (1);
}

int	ft_init_settings(char **argv, t_settings *settings)
{
	int			errorn;
	int			i;

	i = 0;
	errorn = ft_check_args(argv, settings);
	if (!errorn)
		return (0);
	settings->eating_number = 0;
	settings->is_dead = 0;
	settings->forks = malloc(sizeof(pthread_mutex_t) * settings->number_philos);
	settings->philo = malloc(sizeof(pthread_t) * settings->number_philos);
	settings->last_philo_eat_time = malloc(sizeof(int) * \
		settings->number_philos);
	pthread_mutex_init(&settings->s, NULL);
	pthread_mutex_init(&settings->ss, NULL);
	pthread_mutex_init(&settings->sss, NULL);
	while (i < settings->number_philos)
	{
		settings->last_philo_eat_time[i] = 0;
		pthread_mutex_init(&settings->forks[i], NULL);
		i++;
	}
	return (1);
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
