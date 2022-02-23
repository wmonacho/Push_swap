/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_under_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:48:29 by wmonacho          #+#    #+#             */
/*   Updated: 2022/02/23 17:57:59 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_tri_3(t_list **tab_a)
{
	int	nb0;
	int	nb1;
	int	nb2;

	nb0 = *(int *)((*tab_a)->content);
	nb1 = *(int *)((*tab_a)->next->content);
	nb2 = *(int *)((*tab_a)->next->next->content);
	if (nb0 > nb1 && nb1 < nb2 && nb0 > nb2)
		ft_rotate_a(tab_a);
	if (nb0 < nb1 && nb1 > nb2 && nb0 > nb2)
		ft_reverserotate_a(tab_a);
	if (nb0 > nb1 && nb1 > nb2 && nb0 > nb2)
	{
		ft_swap_a(tab_a);
		ft_reverserotate_a(tab_a);
	}
	if (nb0 > nb1 && nb1 < nb2 && nb0 < nb2)
		ft_swap_a(tab_a);
	if (nb0 < nb1 && nb1 > nb2 && nb0 < nb2)
	{
		ft_reverserotate_a(tab_a);
		ft_swap_a(tab_a);
	}
}

void	ft_tri_4(t_list **tab_a, t_list **tab_b)
{
	int	nb3;
	int	nb2;
	int	nb1;
	int	nb0;

	nb3 = *(int *)((*tab_a)->content);
	nb0 = *(int *)((*tab_a)->next->content);
	nb1 = *(int *)((*tab_a)->next->next->content);
	nb2 = *(int *)((*tab_a)->next->next->next->content);
	ft_push_b(tab_a, tab_b);
	ft_tri_3(&(*tab_a)->next);
	ft_push_b(tab_a, tab_b);
	if (nb3 == 1)
		ft_swap_a(tab_a);
	if (nb3 == 2 || (nb3 == 3 && (nb2 == 4 || nb1 == 4 || nb0 == 4)))
		write(1, "rra\nsa\nra\nra", 12);
	if (nb3 >= 4)
		ft_rotate_a(tab_a);
}

void	ft_tri_5(t_list **tab_a, t_list **tab_b)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *tab_a;
	print_stack(tab_a);
	while (temp->content != 0)
	{
		temp = temp->next;
		i++;
	}
	ft_push_me(tab_a, tab_b, i, 1);
	temp = *tab_a;
	i = 0;
	while ((int)(temp->content) != 1)
	{
		temp = temp->next;
		i++;
	}
	ft_push_me(tab_a, tab_b, i, 2);
	ft_tri_3(tab_a);
	ft_push_a(tab_a, tab_b);
	ft_push_a(tab_a, tab_b);
}

int	ft_tri_under_5(t_list *tab_a, t_list *tab_b, int size)
{
	if (size == 2)
		return (0);
	if (size == 3)
		ft_tri_2(&tab_a);
	if (size == 4)
		ft_tri_3(&tab_a);
	if (size == 5)
		ft_tri_4(&tab_a, &tab_b);
	if (size == 6)
		ft_tri_5(&tab_a, &tab_b);
	return (0);
}
