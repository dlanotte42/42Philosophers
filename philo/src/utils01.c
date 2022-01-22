/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:07:43 by dlanotte          #+#    #+#             */
/*   Updated: 2022/01/22 04:17:34 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	smart_free(t_settings *philo)
{
	int	i;

	free(philo->last_philo_eat_time);
	pthread_mutex_destroy(&philo->s);
	i = -1;
	while (++i < philo->number_philos)
		pthread_mutex_destroy(&philo->forks[i]);
	free(philo->forks);
	i = -1;
	while (++i < philo->number_philos)
		pthread_detach(philo->philo[i]);
	pthread_mutex_destroy(&philo->ss);
	pthread_mutex_destroy(&philo->sss);
	free(philo->philo);
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

	i = -1;
	errorn = ft_check_args(argv, settings);
	if (!errorn)
		return (0);
	settings->eating_number = 0;
	settings->is_dead = 0;
	settings->i = 0;
	settings->forks = malloc(sizeof(pthread_mutex_t) * settings->number_philos);
	settings->philo = malloc(sizeof(pthread_t) * settings->number_philos);
	settings->last_philo_eat_time = malloc(sizeof(int) * \
		settings->number_philos);
	pthread_mutex_init(&settings->s, NULL);
	pthread_mutex_init(&settings->ss, NULL);
	pthread_mutex_init(&settings->sss, NULL);
	while (++i < settings->number_philos)
	{
		settings->last_philo_eat_time[i] = 0;
		pthread_mutex_init(&settings->forks[i], NULL);
	}
	return (1);
}

void	ft_print_status(int mode, t_settings *philo, int id)
{
	pthread_mutex_lock(&philo->ss);
	if (mode == 0)
		printf("%d %d, has taken a fork\n",
			(ft_clock()) - philo->start_time, id + 1);
	else if (mode == 1)
		printf("%d %d, is eating\n", (ft_clock()) - philo->start_time, id + 1);
	else if (mode == 2)
		printf("%d %d, is sleeping\n", (ft_clock()) - philo->start_time, id + 1);
	else if (mode == 3)
		printf("%d %d, is thinking\n", (ft_clock()) - philo->start_time, id + 1);
	pthread_mutex_unlock(&philo->ss);
}
