/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:11:41 by dkarhan           #+#    #+#             */
/*   Updated: 2022/04/22 16:12:51 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b2(t_stack **stack_a, t_stack **stack_b, int ort)
{
	int	index;
	int	size;

	while (min(*stack_a) != ort)
	{
		size = ft_lstsize(*stack_a);
		index = find_index(*stack_a, ort);
		if (index <= size / 2 && index != 0)
			ra(stack_a);
		else if (index >= size / 2 && index != 0)
			rra(stack_a);
		else
			pb(stack_a, stack_b);
		if (min(*stack_a) == ort && !is_sorted(*stack_a) && size <= 5)
			five_sort(stack_a, stack_b);
	}
}

void	push_b(t_stack **stack_a, t_stack **stack_b, int *dizi, int boyut)
{
	t_stack	*temp;
	int		ort;
	int		index;
	int		minn;

	index = -1;
	while (++index < boyut)
	{
		temp = *stack_a;
		minn = 2147483647;
		while (temp)
		{
			if (minn > temp -> content
				&& ctrl_dizi(dizi, temp -> content, boyut))
				minn = temp -> content;
			temp = temp -> next;
		}
		dizi[index] = minn;
	}
	ort = dizi[boyut - 1];
	push_b2(stack_a, stack_b, ort);
}

void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		boyut;
	int		dizi[50];
	int		a;

	stack_b = NULL;
	if (is_sorted(*stack_a))
		return ;
	while (!is_sorted(*stack_a))
	{
		if (ft_lstsize(*stack_a) >= 40)
			boyut = 40;
		else
		{
			a = ft_lstsize(*stack_a);
			while (a--)
				pb(stack_a, &stack_b);
			break ;
		}
		push_b(stack_a, &stack_b, dizi, boyut);
	}
	if (stack_b)
		give_back(stack_a, &stack_b);
	free(stack_b);
}

t_stack	*push_swap(char **str, int len)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = to_int(str, len);
	if (!is_uniq(stack_a))
	{
		write(2, "Error\n", 6);
		free(stack_a);
		exit(EXIT_FAILURE);
	}
	if (ft_lstsize(stack_a) <= 3 && !is_sorted(stack_a))
		three_sort(&stack_a);
	else if (ft_lstsize(stack_a) <= 5 && !is_sorted(stack_a))
		five_sort(&stack_a, &stack_b);
	sort(&stack_a);
	free(stack_b);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (!is_number(argv, argc))
	{
		write(2, "Error\n", 6);
		free(stack);
		exit(EXIT_FAILURE);
	}
	else if (argc > 1)
	{
		stack = push_swap(argv, argc);
		free(stack);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
