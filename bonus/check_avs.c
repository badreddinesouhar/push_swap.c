/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_avs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:37:15 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/19 15:51:25 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

char	**check_args(char **argv)
{
	char	*str;
	char	*av;
	char	**argvs;
	int		i;

	str = malloc(1);
	str[0] = '\0';
	i = 0;
	while (argv[i] != NULL)
	{
		av = ft_strtrim(argv[i], " ");
		if (*av == '\0')
		{
			free(str);
			free(av);
			error();
		}
		str = ft_strjoin(str, av);
		str = ft_strjoin(str, " ");
		free(av);
		i++;
	}
	argvs = ft_split(str, ' ');
	free(str);
	return (argvs);
}

char	**no_errors(char **args)
{
	char	**numbers;
	int		i;
	int		j;

	numbers = args;
	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_same(numbers[i], numbers[j]) == 0)
				error();
			j++;
		}
		i++;
	}
	return (numbers);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_list(t_node **stack)
{
	t_node	*current;
	t_node	*tmp;

	if (*stack)
	{
		current = *stack;
		while (current)
		{
			tmp = current->next;
			free(current);
			current = tmp;
		}
		*stack = NULL;
	}
}
