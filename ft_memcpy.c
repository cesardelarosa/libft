/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:16:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/09/19 19:19:55 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	void	*r;

	if (dest == NULL && src == NULL)
		return (NULL);
	r = dest;
	while (n--)
		*(unsigned char *)dest++ = *(const unsigned char *)src++;
	return (r);
}
