/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:04:50 by bsouhar           #+#    #+#             */
/*   Updated: 2022/10/22 13:37:53 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return NULL;
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}
int main(){
	t_list (int *)content = 5;
	t_list next = NULL;
	printf("%d - ",content->next);
}
