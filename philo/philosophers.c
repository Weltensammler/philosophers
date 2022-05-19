/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:47:23 by bschende          #+#    #+#             */
/*   Updated: 2022/05/19 19:00:22 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philosophers	vars;
	t_philid		*varsid;

	if (!checkinput(argc, argv))
		return (0 * printf("Error, wrong input"));
	init_vars(argc, argv, &vars);
	varsid = init_varsid(&vars, 0);
	while (vars.count < vars.phils)
		pthread_mutex_init(&varsid[vars.count++].lfork, NULL);
	pthread_mutex_init(&vars.all, NULL);
	pthread_mutex_init(&vars.check, NULL);
	init_threads(&vars, varsid);
	while (maindeath(&vars, varsid))
		;
	pthread_mutex_lock(&vars.all);
	vars.stop = 1;
	pthread_mutex_unlock(&vars.all);
	join(&vars, varsid);
	vars.count = 0;
	while (vars.count < vars.phils)
		pthread_mutex_destroy(&varsid[vars.count++].lfork);
	pthread_mutex_destroy(&vars.all);
	pthread_mutex_destroy(&vars.check);
	free(varsid);
	return (0);
}

int	init_vars(int argc, char **argv, t_philosophers *vars)
{
	vars->phils = ft_atoi(argv[1]);
	vars->ttd = ft_atoi(argv[2]);
	vars->tte = ft_atoi(argv[3]);
	vars->tts = ft_atoi(argv[4]);
	vars->count = 0;
	vars->todeath = 0;
	vars->timestart = gettime();
	vars->stop = 0;
	vars->who = 0;
	vars->allfull = 0;
	if (argc == 6)
		vars->notte = ft_atoi(argv[5]);
	else if (argc != 6)
		vars->notte = -1;
	return (1);
}

t_philid	*init_varsid(t_philosophers *vars, int i)
{
	t_philid	*varsid;

	varsid = malloc(sizeof(t_philid) * vars->phils);
	while (i < vars->phils)
	{
		varsid[i].id = i + 1;
		varsid[i].vars = vars;
		initzero(varsid, vars->phils);
		varsid[i].nulltime = vars->timestart;
		if (i - 1 >= 0)
		{
			varsid[i].rfork = &varsid[i - 1].lfork;
			varsid[i].rightf = &varsid[i - 1].leftf;
		}
		else if (i - 1 < 0)
		{
			varsid[i].rfork = &varsid[vars->phils - 1].lfork;
			varsid[i].rightf = &varsid[vars->phils - 1].leftf;
			if (vars->phils == 1)
				*varsid[i].rightf = 1;
		}
		i++;
	}
	return (varsid);
}

long int	gettime(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	init_threads(t_philosophers *vars, t_philid *varsid)
{
	int	i;

	i = 0;
	while (i < vars->phils)
	{
		pthread_create(&varsid[i].t, NULL, (void *)&cycle, (void *)&varsid[i]);
		i = i + 2;
	}
	usleep(1000);
	i = 1;
	while (i < vars->phils)
	{
		pthread_create(&varsid[i].t, NULL, (void *)&cycle, (void *)&varsid[i]);
		i = i + 2;
	}
}
