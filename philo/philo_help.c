/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:34:47 by bschende          #+#    #+#             */
/*   Updated: 2022/05/19 18:56:48 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	join(t_philosophers *vars, t_philid *varsid)
{
	int	i;

	i = 0;
	while (i < vars->phils)
	{
		pthread_join(varsid[i].t, NULL);
		i++;
	}
}

void	initzero(t_philid *varsid, int phil)
{
	int	i;

	i = 0;
	while (i < phil)
	{
		varsid[i].full = 0;
		varsid[i].leftf = 0;
		varsid[i].starteat = 0;
		varsid[i].eatcount = 0;
		i++;
	}
}

void	setvarcheck(t_philosophers *vars, t_philid *varsid, int i)
{
	vars->todeath = 1;
	varsid->vars->who = varsid[i].id;
}
