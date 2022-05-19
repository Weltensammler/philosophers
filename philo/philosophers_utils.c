/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:47:54 by bschende          #+#    #+#             */
/*   Updated: 2022/05/18 23:13:24 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	ft_atoi(const char *str)
{
	int			i;
	long int	value;
	int			sign;

	i = 0;
	value = 0;
	sign = 1;
	while (*(str + i) == ' ' || (*(str + i) >= 9 && *(str + i) <= 13))
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
		sign = 1 - 2 * (str[i++] == '-');
	else if (*str == '\0')
		return (0);
	while (ft_isdigit(*(str + i)))
		value = value * 10 + *(str + i++) - '0';
	return (sign * value);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	*temp;

	temp = (unsigned char *)str;
	i = 0;
	while (*(temp + i))
	{
		if (*(temp + i) == (unsigned char)c)
			return (1);
		i++;
	}
	if (*(temp + i) == (unsigned char)c)
		return (1);
	return (0);
}
