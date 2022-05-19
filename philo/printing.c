/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:41:56 by bschende          #+#    #+#             */
/*   Updated: 2022/05/19 18:51:58 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	checkinput(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_strchr("0123456789", argv[i][j]))
				return (0);
			j++;
		}
		if (ft_atoi(argv[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	printstate(int what, t_philid *varsid)
{
	pthread_mutex_lock(&varsid->vars->all);
	if (varsid->vars->stop != 1)
	{
		if (what == 1)
			printf("%li	%i	has taken a fork\n",
				gettime() - varsid->nulltime, varsid->id);
		else if (what == 2)
			printf("%li	%i	is eating\n", varsid->starteat, varsid->id);
		else if (what == 3)
			printf("%li	%i	is sleeping\n", varsid->startsleep, varsid->id);
		else if (what == 4)
			printf("%li	%i	is thinking\n", varsid->startthink, varsid->id);
		else if (what == 5)
		{
			printf("%li	%i	died\n", gettime() - varsid->nulltime,
				varsid->vars->who);
			pthread_mutex_unlock(&varsid->vars->all);
			return (0);
		}
	}
	pthread_mutex_unlock(&varsid->vars->all);
	return (0);
}
