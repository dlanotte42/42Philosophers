/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:48:12 by dlanotte          #+#    #+#             */
/*   Updated: 2022/01/19 02:15:30 by dlanotte         ###   ########.fr       */
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

typedef struct s_settings
{
	int					i;
	int					number_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_times_philo_eat;
	int					start_time;
	int					eating_number;
	int					*last_philo_eat_time;
	pthread_t			*philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*write;
	pthread_mutex_t		*die;
	pthread_mutex_t		s;
	pthread_mutex_t		ss;
	pthread_mutex_t		sss;
}	t_settings;

void	smart_free(t_settings *settings);
void	ft_usleep(int time, int philo_numb);
void	ft_print_status(int print_action, t_settings *philo, int id);
int		ft_check_args(char **argv, t_settings *settings);
int		ft_clock(void);
int		ft_init_settings(char **argv, t_settings *settings);
int		ft_atoi(const char *str);

#endif