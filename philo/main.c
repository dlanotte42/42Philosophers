/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:47:54 by dlanotte          #+#    #+#             */
/*   Updated: 2022/01/19 02:14:02 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	ft_philo_cyclo()
{
	
}

void	ft_philo_life(t_settings *philo)
{
	int		id;

	id = philo->i;
	pthread_mutex_unlock(&philo->s);
	if (id % 2)
		ft_usleep(1, philo->number_philos);
	while (1)
		ft_philo_cyclo();
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
	smart_free(&settings);
	return (0);
}
