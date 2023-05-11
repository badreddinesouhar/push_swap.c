/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:07:04 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/11 23:07:26 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	quicksort(int *arr, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		quicksort(arr, low, pivot_index - 1);
		quicksort(arr, pivot_index + 1, high);
	}
}

int	*sorting_arr(char **argv, int size)
{
	int	i;
	int	*tab;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	i = 0;
	while (i < size)
	{
		tab[i] = ft_atoi(argv[i]);
		i++;
	}
	quicksort(tab, 0, size - 1);
	return (tab);
}
