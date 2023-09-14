/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:22:14 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/09/14 20:31:00 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*count;

	size = 0;
	count = lst;
	while (count)
	{
		count = count->next;
		size++;
	}
	return (size);
}
