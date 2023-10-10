/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:01:48 by vvu               #+#    #+#             */
/*   Updated: 2023/10/09 19:01:48 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*currentelement;

	currentelement = lst;
	if (currentelement == NULL)
		return (NULL);
	while (currentelement ->next != NULL)
		currentelement = currentelement->next;
	return (currentelement);
}
