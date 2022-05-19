/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:51:15 by bschende          #+#    #+#             */
/*   Updated: 2022/05/19 11:25:15 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philosophers
{
	pthread_t		dead;
	int				phils;
	int				ttd;
	int				tte;
	int				tts;
	int				notte;
	int				todeath;
	int				who;
	int				allfull;
	int				stop;
	pthread_mutex_t	death;
	pthread_mutex_t	all;
	pthread_mutex_t	check;
	long int		timestart;
	long int		runtime;
}	t_philosophers;

typedef struct s_philid
{
	int				id;
	int				test;
	long int		nulltime;
	long int		starteat;
	long int		startsleep;
	long int		startthink;
	long int		time;
	int				eatcount;
	int				full;
	int				leftf;
	int				*rightf;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	lfork;
	pthread_t		t;
	t_philosophers	*vars;
}	t_philid;

long int	ft_atoi(const char *str);
int			ft_isdigit(int c);
int			init_vars(int argc, char **argv, t_philosophers *vars);
t_philid	*init_varsid(t_philosophers *vars, int i);
long int	gettime(void);
int			eating(t_philosophers *vars, t_philid *varsid);
int			sleeping(t_philosophers *vars, t_philid *varsid);
int			thinking(t_philid *varsid);
int			checkifdead(t_philosophers *vars, t_philid *varsid);
void		*cycle(t_philid *varsid);
void		take_forks(t_philid *varsid);
void		free_forks(t_philid *varsid);
int			checkinput(int argc, char **argv);
int			ft_strchr(const char *str, int c);
int			printstate(int what, t_philid *philid);
void		init_threads(t_philosophers *vars, t_philid *varsid);
int			maindeath(t_philosophers *vars, t_philid *varsid);
void		detach(t_philosophers *vars, t_philid *varsid);
void		join(t_philosophers *vars, t_philid *varsid);
void		detachorjoin(t_philosophers *vars, t_philid *varsid);
void		initzero(t_philid *varsid, int phil);

#endif
