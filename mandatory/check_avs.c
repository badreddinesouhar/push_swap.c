/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:37:15 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/11 20:37:18 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_valid_input(char **av_split)
{
	int	i;

	i = 0;
	while (av_split[i])
	{
		if (!ft_isdigit_str(av_split[i]))
			return (0);
		i++;
	}
	return (1);
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

int	ft_same(const char *s1, const char *s2)
{
	int	str1;
	int	str2;

	str1 = ft_atoi(s1);
	str2 = ft_atoi(s2);
	return (str1 - str2);
}

int	is_sorted(t_node *stack)
{
	t_node	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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
