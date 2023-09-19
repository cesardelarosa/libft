/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:48:59 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/09/19 15:54:08 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list = NULL;
    t_list *new_tail = NULL;

    while (lst)
    {
        void *content = f(lst->content);
        if (!content)
        {
            // Si la función f devuelve NULL, considera liberar recursos si es necesario
            if (del)
                del(content);
        }
        else
        {
            // Crea un nuevo nodo para la nueva lista
            t_list *new_node = ft_lstnew(content);
            if (!new_node)
            {
                // Considera liberar recursos si no se pudo crear un nuevo nodo
                if (del)
                    del(content);
            }
            else
            {
                // Agrega el nuevo nodo a la nueva lista
                if (!new_list)
                    new_list = new_node;
                else
                    new_tail->next = new_node;
                new_tail = new_node;
            }
        }

        lst = lst->next;
    }
	return new_list;
}

