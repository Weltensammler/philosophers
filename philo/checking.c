/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:09:47 by bschende          #+#    #+#             */
/*   Updated: 2022/05/19 12:48:16 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	checkifdead(t_philosophers *vars, t_philid *varsid)
// {
// 	pthread_mutex_lock(&vars->check);
// 	if ((gettime() - varsid->nulltime) - varsid->starteat > vars->ttd)
// 	{
// 		varsid->test = 1;
// 	}
// 	pthread_mutex_unlock(&vars->check);
// 	return (0);
// }

int	maindeath(t_philosophers *vars, t_philid *varsid)
{
	int	i;

	while (vars->todeath == 0)
	{
		i = 0;
		while (i < vars->phils)
		{
			pthread_mutex_lock(&vars->check);
			if (varsid[i].full == 1)
				vars->allfull = vars->allfull + 1;
			if (gettime() - vars->timestart - varsid[i].starteat > vars->ttd)
			{
				varsid->vars->todeath = 1;
				varsid->vars->who = varsid[i].id;
				printstate(5, varsid);
				pthread_mutex_unlock(&vars->check);
				return (0);
			}
			i++;
			pthread_mutex_unlock(&vars->check);
		}
		if (vars->allfull >= vars->phils)
			break ;
		vars->allfull = 0;
	}
	return (0);
}
