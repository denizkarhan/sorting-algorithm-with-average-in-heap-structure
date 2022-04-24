/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_rr_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:11:47 by dkarhan           #+#    #+#             */
/*   Updated: 2022/04/22 14:41:51 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *lsta, t_stack *lstb)
{
	write(1, "ss\n", 3);
	sa(lsta);
	sb(lstb);
}

void	rr(t_stack **lsta, t_stack **lstb)
{
	write(1, "rr\n", 3);
	ra(lsta);
	rb(lstb);
}

void	rrr(t_stack **lsta, t_stack **lstb)
{
	write(1, "rrr\n", 4);
	rra(lsta);
	rrb(lstb);
}
