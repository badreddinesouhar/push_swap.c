/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:28:12 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/19 17:39:33 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(t_node **stack_a, t_node **stack_b, char *line)
{
	if (!ft_strncmp("sa\n", line, 3))
		sa(stack_a);
	else if (!ft_strncmp("pa\n", line, 3))
		pa(stack_b, stack_a);
	else if (!ft_strncmp("ra\n", line, 3))
		ra(stack_a);
	else if (!ft_strncmp("rra\n", line, 4))
		rra(stack_a);
	else if (!ft_strncmp("sb\n", line, 3))
		sb(stack_b);
	else if (!ft_strncmp("pb\n", line, 3))
		pb(stack_a, stack_b);
	else if (!ft_strncmp("rb\n", line, 3))
		rb(stack_b);
	else if (!ft_strncmp("rrb\n", line, 4))
		rrb(stack_b);
	else if (!ft_strncmp("ss\n", line, 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp("rr\n", line, 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp("rrr\n", line, 4))
		rrr(stack_a, stack_b);
	else
		return (1);
	return (0);
}

int	pedro(t_node **stack_a, t_node **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (check(stack_a, stack_b, line) == 1)
		{
			write(2, "Error\n", 6);
			free(line);
			return (1);
		}
		free(line);
	}
	return (0);
}

void	initialize_program(t_program *program, int argc, char **argv)
{
	program->stack_a = NULL;
	program->stack_b = NULL;
	program->i = 0;
	program->j = 0;
	if (argc == 1)
		exit(0);
	program->args = check_args(argv + 1);
	program->nums = no_errors(program->args);
	if (!is_valid_input(&program->nums[program->j]))
		error();
}

void	process_program(t_program *program)
{
	while (program->nums[program->i] != NULL)
	{
		push(&program->stack_a, ft_atoi(program->nums[program->i]));
		program->i++;
	}
	if (pedro(&program->stack_a, &program->stack_b) == 1)
		exit(1);
	if (is_sorted(program->stack_a) && stack_len(program->stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_arr(program->args);
	free_list(&program->stack_a);
}

int	main(int argc, char **argv)
{
	t_program	program;

	initialize_program(&program, argc, argv);
	process_program(&program);
	return (0);
}
