/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:40:36 by kasen             #+#    #+#             */
/*   Updated: 2026/11/03 15:40:40 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sift_down(int *values, int root, int end)
{
	int	child;
	int	tmp;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		if (child + 1 <= end && values[child] < values[child + 1])
			child++;
		if (values[root] >= values[child])
			return ;
		tmp = values[root];
		values[root] = values[child];
		values[child] = tmp;
		root = child;
	}
}

static void	heap_sort(int *values, int size)
{
	int	end;
	int	root;
	int	tmp;

	root = size / 2 - 1;
	while (root >= 0)
	{
		sift_down(values, root, size - 1);
		root--;
	}
	end = size - 1;
	while (end > 0)
	{
		tmp = values[0];
		values[0] = values[end];
		values[end] = tmp;
		sift_down(values, 0, --end);
	}
}

static int	find_rank(int *values, int size, int value)
{
	int	high;
	int	low;
	int	middle;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		middle = low + (high - low) / 2;
		if (values[middle] == value)
			return (middle);
		if (values[middle] < value)
			low = middle + 1;
		else
			high = middle - 1;
	}
	return (-1);
}

static void	copy_values(t_stack *stack, int *values)
{
	int	position;

	position = 0;
	while (stack)
	{
		values[position++] = stack->value;
		stack = stack->next;
	}
}

int	rank_stack(t_stack *stack)
{
	t_stack	*current;
	int		*values;
	int		size;

	size = stack_size(stack);
	values = malloc(sizeof(int) * size);
	if (!values)
		return (0);
	copy_values(stack, values);
	heap_sort(values, size);
	current = stack;
	while (current)
	{
		current->index = find_rank(values, size, current->value);
		current = current->next;
	}
	free(values);
	return (1);
}
