/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:47:54 by dlanotte          #+#    #+#             */
/*   Updated: 2021/11/27 20:12:32 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	ft_check_args(char **argv, t_settings *settings)
{
	settings->num_times_philo_eat = -2;
	settings->number_philos = ft_atoi(argv[1]);
	settings->time_to_die = ft_atoi(argv[2]);
	settings->time_to_eat = ft_atoi(argv[3]);
	settings->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		settings->num_times_philo_eat = ft_atoi(argv[5]);
	if (settings->number_philos == -1)
		return (0);
	if (settings->time_to_die == -1)
		return (0);
	if (settings->time_to_eat == -1)
		return (0);
	if (settings->time_to_sleep == -1)
		return (0);
	if (settings->num_times_philo_eat == -1)
		return (0);
	return (1);
}

int	ft_start(t_settings settings)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	settings.start_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (1);
}

int	ft_init_settings(char **argv, t_settings *settings)
{
	int			errorn;

	errorn = ft_check_args(argv, settings);
	if (!errorn)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_settings	settings;

	if (argc < 5 || argc > 6)
		return (printf("Error: Wrong number of argments\n"));
	if (!ft_init_settings(argv, &settings))
		return (printf("Error: Wrong argments\n"));
	ft_start(settings);
	return (0);
}
