/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:28:12 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/11 16:03:26 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	struct s_node	*stack_a;
	struct s_node	*stack_b;
	int				i;
	char			**args;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (argc == 1)
		return (1);
	args = check_args(argv + 1);
	while (args[i] != NULL)
	{
		push(&stack_a, ft_atoi(args[i]));
		i++;
	}
	display(stack_a);
	return (0);
}
