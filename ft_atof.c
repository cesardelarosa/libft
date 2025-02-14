/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:27:41 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/14 11:27:45 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_atof(const char *str)
{
	double	result;
	double	frac;
	int		sign;
	double	div;

	result = 0;
	frac = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	sign = 1 - 2 * (*str == '-');
	str += 2 * (*str == '+') - sign;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if (*str++ == '.')
	{
		div = 10;
		while (*str >= '0' && *str <= '9')
		{
			frac += (*str++ - '0') / div;
			div *= 10;
		}
	}
	return ((double)sign * (result + frac));
}
