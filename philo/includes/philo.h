/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:48:12 by dlanotte          #+#    #+#             */
/*   Updated: 2021/11/27 20:39:35 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				philo_id;
	int				left_fork_id;
	int				right_fork_id;
	int				tot_meals;
	int				last_meal;
}	t_philo;

typedef struct s_settings
{
	int					number_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_times_philo_eat;
	int					start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*write;
	pthread_mutex_t		*die;
}	t_settings;

int		ft_atoi(const char *str);
void	smart_free(t_settings *settings);

#endif