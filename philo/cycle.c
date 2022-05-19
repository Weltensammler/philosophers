/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:06:26 by bschende          #+#    #+#             */
/*   Updated: 2022/05/19 19:13:28 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*cycle(t_philid *varsid)
{
	while ((gettime() - varsid->nulltime) - varsid->starteat
		< varsid->vars->ttd && varsid->vars->stop != 1)
	{
		if (varsid->vars->phils == 1)
			return (0);
		eating(varsid->vars, varsid);
		sleeping(varsid->vars, varsid);
		thinking(varsid);
		pthread_mutex_lock(&varsid->vars->all);
		if (varsid->vars->stop == 1)
		{
			pthread_mutex_unlock(&varsid->vars->all);
			break ;
		}
		pthread_mutex_unlock(&varsid->vars->all);
	}
	return (NULL);
}

int	sleeping(t_philosophers *vars, t_philid *varsid)
{
	varsid->startsleep = gettime() - varsid->nulltime;
	printstate(3, varsid);
	while (gettime() - varsid->nulltime < (varsid->startsleep + vars->tts))
	{
		usleep(1000);
	}
	return (0);
}

int	thinking(t_philid *varsid)
{
	varsid->startthink = gettime() - varsid->nulltime;
	printstate(4, varsid);
	usleep(2000);
	return (0);
}
