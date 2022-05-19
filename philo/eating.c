/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:55:29 by bschende          #+#    #+#             */
/*   Updated: 2022/05/19 19:31:11 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eating(t_philosophers *vars, t_philid *varsid)
{
	take_forks(varsid);
	pthread_mutex_lock(&vars->check);
	varsid->starteat = gettime() - varsid->nulltime;
	pthread_mutex_unlock(&vars->check);
	printstate(2, varsid);
	while (gettime() - varsid->nulltime < (varsid->starteat + vars->tte))
	{
		usleep(1000);
	}
	varsid->eatcount++;
	if (varsid->eatcount == vars->notte)
	{
		pthread_mutex_lock(&varsid->vars->check);
		varsid->full = 1;
		pthread_mutex_unlock(&varsid->vars->check);
	}
	free_forks(varsid);
	return (0);
}

void	take_forks(t_philid *varsid)
{
	if (varsid->id % 2 == 0)
	{
		pthread_mutex_lock(&varsid->lfork);
		pthread_mutex_lock(varsid->rfork);
	}
	else
	{
		pthread_mutex_lock(varsid->rfork);
		pthread_mutex_lock(&varsid->lfork);
	}
	*varsid->rightf = 1;
	varsid->leftf = 1;
	printstate(1, varsid);
	printstate(1, varsid);
}

void	free_forks(t_philid *varsid)
{
	varsid->leftf = 0;
	*varsid->rightf = 0;
	pthread_mutex_unlock(&varsid->lfork);
	pthread_mutex_unlock(varsid->rfork);
}
