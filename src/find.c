/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:11:56 by dkarhan           #+#    #+#             */
/*   Updated: 2022/04/22 14:41:53 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	min_index(t_stack *stack)
{
	int		i;
	int		data;
	t_stack	*temp;

	temp = stack;
	data = temp->content;
	i = 0;
	while (stack != NULL)
	{
		if (data <= stack->content && stack != NULL)
			stack = stack->next;
		else
		{
			temp = temp->next;
			data = temp->content;
			i++;
		}
	}
	return (i);
}

int	min(t_stack *stack)
{
	int		data;
	t_stack	*temp;

	temp = stack;
	data = temp->content;
	while (stack != NULL)
	{
		if (data <= stack->content && stack != NULL)
			stack = stack->next;
		else
		{
			temp = temp->next;
			data = temp->content;
		}
	}
	return (data);
}

int	big_index(t_stack *stack)
{
	int		i;
	int		data;
	t_stack	*temp;

	temp = stack;
	data = temp->content;
	i = 0;
	while (stack != NULL)
	{
		if (data >= stack->content && stack != NULL)
			stack = stack->next;
		else
		{
			temp = temp->next;
			data = temp->content;
			i++;
		}
	}
	return (i);
}

int	find_index(t_stack *stack, int data)
{
	int		first;
	int		last;
	int		j;
	int		size;

	first = 0;
	size = ft_lstsize(stack);
	while (stack && data <= stack->content)
	{
		stack = stack->next;
		first++;
	}
	j = first;
	while (stack)
	{
		if (data > stack->content)
			last = j;
		stack = stack->next;
		j++;
	}
	if (first > (size - last))
		return (last);
	return (first);
}

int	ctrl_dizi(int *dizi, int min, int boyut)
{
	int	i;

	i = -1;
	while (++i < boyut)
		if (dizi[i] == min)
			return (0);
	return (1);
}
