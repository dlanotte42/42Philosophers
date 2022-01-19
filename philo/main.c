/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:47:54 by dlanotte          #+#    #+#             */
/*   Updated: 2022/01/19 19:30:30 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	ft_philo_cyclo(t_settings *philo, int *eaten_numbers, int id)
{
	pthread_mutex_lock(&philo->forks[id]);
	ft_print_status(0, philo, id);
	pthread_mutex_lock(&philo->forks[(id + 1) % philo->number_philos]);
	ft_print_status(0, philo, id);
	ft_print_status(1, philo, id);
	philo->last_philo_eat_time[id] = ft_clock() - philo->start_time;
	ft_usleep(philo->time_to_eat, philo->number_philos);
	pthread_mutex_unlock(&philo->forks[id]);
	pthread_mutex_unlock(&philo->forks[(id + 1) % philo->number_philos]);
	ft_print_status(2, philo, id);
	*eaten_numbers = *eaten_numbers + 1;
	if (*eaten_numbers == philo->num_times_philo_eat)
	{
		pthread_mutex_lock(&philo->sss);
		philo->eating_number++;
		pthread_mutex_unlock(&philo->sss);
	}
	ft_usleep(philo->time_to_eat, philo->number_philos);
	ft_print_status(3, philo, id);
}

void	ft_check_is_dead(t_settings *philo)
{
	int	i;

	while (philo->eating_number < philo->number_philos)
	{
		i = -1;
		while (++i < philo->number_philos)
		{
			if ((ft_clock() - philo->start_time) \
			- (philo->last_philo_eat_time[i] >= philo->time_to_die))
			{
				ft_dead(philo, i);
				return ;
			}
		}
		ft_usleep(1, philo->number_philos);
	}
	pthread_mutex_lock(&philo->ss);
	printf("The eating cycle are terminated");
}

void	ft_philo_life(t_settings *philo)
{
	int		id;
	int		eaten_number;

	eaten_number = 0;
	id = philo->i;
	pthread_mutex_unlock(&philo->s);
	if (id % 2)
		ft_usleep(1, philo->number_philos);
	while (1)
		ft_philo_cyclo(philo, &eaten_number, id);
}

int	ft_start(t_settings settings)
{
	int		i;

	i = -1;
	settings.start_time = ft_clock();
	while (++i < settings.number_philos)
	{
		pthread_mutex_lock(&settings.s);
		settings.i = i;
		pthread_create(&settings.philo[settings.i], \
			NULL, (void *)ft_philo_life, &settings);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_settings	settings;

	if (argc < 5 || argc > 6)
		return (printf("[Error] Wrong number of argments\n"));
	if (!ft_init_settings(argv, &settings))
		return (printf("[Error] Wrong argments\n"));
	ft_start(settings);
	ft_check_is_dead(&settings);
	ft_usleep(100, settings.number_philos);
	smart_free(&settings);
	return (0);
}
