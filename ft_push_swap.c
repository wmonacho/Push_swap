/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:05:08 by wmonacho          #+#    #+#             */
/*   Updated: 2022/02/23 11:47:00 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_list		*tab_a;
	t_list		*tab_b;
	int			*tmp;
	char		**tab;

	tab = ft_check(&argc, argv);
	if (tab == NULL)
		return (0);
	tmp = ft_index(argc, tab);
	tab_a = ft_list_a(argc - 1, tmp);
	tab_b = ft_list_b();
	if (argc < 7)
	{
		ft_tri_under_5(tab_a, tab_b, argc);
		return (0);
	}
	ft_setradix(tab_a, tab_b, argc - 1);
	return (0);
}

/*
il faut que j'envoie tab_a et tab_b a setradix.
pour ca je dois creer la list b et recuperer la list a
pour creer tab_b je dois//
*/
