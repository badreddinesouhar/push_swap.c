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
	struct s_node *stack_a;
	struct s_node *stack_b;
	int i;
	int j;
	char **args;
	char **nums;
	int *sorted_arr;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	j = 0;
	if (argc == 1)
		return (1);
	args = check_args(argv + 1);
	nums = no_errors(args);
	if (!is_valid_input(&nums[j]))
	{
		error();
	}
	while (nums[i] != NULL)
	{
		push(&stack_a, ft_atoi(nums[i]));
		i++;
	}
	if (is_sorted(stack_a))
	{
		free_list(&stack_a);
		return (0);
	}
	sorted_arr = sorting_arr(argv + 1, argc - 1);
	sort(stack_a, stack_b, sorted_arr);
	display(stack_a);
	free_list(&stack_a);
}