/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:28:12 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/14 17:47:00 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize(int argc, char **argv, t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->i = 0;
	data->j = 0;
	if (argc == 1)
		exit(0);
	data->args = check_args(argv + 1);
	data->nums = no_errors(data->args);
	if (!is_valid_input(&data->nums[data->j]))
		error();
	while (data->nums[data->i] != NULL)
	{
		push(&data->stack_a, ft_atoi(data->nums[data->i]));
		data->i++;
	}
	if (is_sorted(data->stack_a))
	{
		free_list(&data->stack_a);
		exit(0);
	}
	data->sorted_arr = sorting_arr(data->nums, stack_len(data->stack_a));
	free_arr(data->args);
}

void	execute(t_data *data)
{
	sort(&data->stack_a, &data->stack_b, data->sorted_arr);
	free_list(&data->stack_a);
	free(data->sorted_arr);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	initialize(argc, argv, &data);
	execute(&data);
	return (0);
}
