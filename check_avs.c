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

char	**check_args(char **argv)
{
	char	*str;
	char	*av;
	char	**argvs;
	int		i;

	str = 0;
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
		av = ft_strjoin(av, " ");
		str = ft_strjoin(str, av);
		free(av);
		i++;
	}
	argvs = ft_split(str, ' ');
	free(str);
	return (argvs);
}
