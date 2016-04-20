/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:06:17 by kwiessle          #+#    #+#             */
/*   Updated: 2016/04/19 12:05:54 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int		fuck(char c)
{
	if (c > 47 && c < 59)
		return (c - 48);
	if (c == 'a' || c == 'A')
		return (10);
	if (c == 'b' || c == 'B')
		return (11);
	if (c == 'c' || c == 'C')
		return (12);
	if (c == 'd' || c == 'D')
		return (13);
	if (c == 'e' || c == 'E')
		return (14);
	if (c == 'f' || c == 'F')
		return (15);
	return (-1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		max_power(char *str, int base)
{
	int		n;
	int		result;

	n = ft_strlen(str) - 1;
	if (str[0] == '-')
		n--;
	result = 1;
	while (n > 0)
	{
		result  = result * base;
		n--;
	}
	return (result);
}

int		ft_atoi_base(char *str, int base)
{
	int		i;
	int		power;
	int		toi;
	int		verif;

	i = 0;
	toi = 0;
	verif = 1;
	if (str[i] == '-')
	{
		verif = -verif;
		i++;
	}
	power = max_power(str, base);
	while (str[i])
	{
		toi = toi + (fuck(str[i]) * power);
		power = power / base;
		i++;
	}
	return (verif *toi);
}

