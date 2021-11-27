/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:02:24 by dlanotte          #+#    #+#             */
/*   Updated: 2021/11/27 18:47:53 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_s_atoi(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '1' || str[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (ft_s_atoi(str) == -1)
		return (-1);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	res = res * sign;
	return (res);
}
