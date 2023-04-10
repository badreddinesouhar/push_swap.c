/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:28:12 by bsouhar           #+#    #+#             */
/*   Updated: 2023/03/13 09:28:14 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(struct s_node *top)
{
	while (top != NULL)
	{
		printf("%d ", top->data);
		top = top->next;
	}
	printf("\n");
}

static int	is_valid_arg(char *arg)
{
	if (!arg || !*arg)
		return (0);
	if (*arg == '+' || *arg == '-')
		++arg;
	while (*arg)
	{
		if (*arg < '0' || *arg > '9')
			return (0);
		++arg;
	}
	return (1);
}

int	has_duplicates(int arr[], int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (arr[i] == arr[j])
			{
				return (1);
			}
		}
	}
	return (0);
}

static int	check_args(int argc, char **argv, int *parsed_args)
{
	char	*trimmed_arg;
	int		arg_num;
	char	**split_args;
	int		i;

	arg_num = 0;
	while (arg_num < argc - 1)
	{
		trimmed_arg = ft_strtrim(argv[arg_num + 1], " \t\v\f\r");
		split_args = ft_split(trimmed_arg, ' ');
		if (!is_valid_arg(*split_args))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (1);
		}
		i = 0;
		while (split_args[i])
		{
			parsed_args[arg_num + i] = ft_atoi(split_args[i]);
			i++;
		}
		free(split_args);
		free(trimmed_arg);
		arg_num += i;
	}
	if (has_duplicates(parsed_args, argc - 1))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}

char	*join_args(int argc, char **argv)
{
	char	*args_str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (i < argc)
		len += ft_strlen(argv[i++]) + 1;
	args_str = (char *)malloc(sizeof(char) * len);
	if (!args_str)
		return (NULL);
	args_str[0] = '\0';
	i = 0;
	while (i < argc)
	{
		strcat(args_str, argv[i]);
		strcat(args_str, " ");
		i++;
	}
	return (args_str);
}

int	count_numbers(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				i++;
			}
			count++;
		}
		else
		{
			i++;
		}
	}
	return (count);
}

int	*parse_args(char *str, int len)
{
	int	*arr;
	int	i;
	int	j;
	int	num;
	int	sign;

	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		num = 0;
		sign = 1;
		if (str[i] == '+' || str[i] == '-')
		{
			sign = (str[i] == '-') ? -1 : 1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
			i++;
		}
		arr[j++] = num * sign;
		if (str[i] == ' ')
		{
			i++;
		}
	}
	return (arr);
}

int	main(int argc, char **argv)
{
	int				args_len;
	char			*args_str;
	int				*parsed_args;
	struct s_node	*stack_a;

	parsed_args = malloc(sizeof(int) * (argc - 1));
	if (!parsed_args)
		return (1);
	if (check_args(argc, argv, parsed_args))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		free(parsed_args);
		return (1);
	}
	args_str = join_args(argc, argv);
	if (!args_str)
	{
		free(parsed_args);
		return (1);
	}
	args_len = count_numbers(args_str);
	stack_a = NULL;
	for (int i = args_len - 1; i >= 0; i--)
		push(&stack_a, parsed_args[i]);
	print_stack(stack_a);
	free(args_str);
	free(parsed_args);
	return (0);
}
