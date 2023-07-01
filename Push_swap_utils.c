/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:58:46 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/29 18:57:41 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(l_list *current)
{
	ft_lstclearer(&current);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	repeat_or_digit(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
				return (-1);
		}
		k = -1;
		while (argv[i][++k])
		{
			if (ft_isdigit(argv[i][k]) ==  0
				&& (argv[i][k] != '+' && argv[i][k] != '-'))
				return (-1);
		}
	}
	return (0);
}

long	ft_long_atoi(const char *nptr)
{
	long	i;
	long	neg;

	i = 0;
	neg = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg *= (-1);
		nptr++;
	}
	if (*nptr >= '0' && *nptr <= '9')
	{
		while (*nptr >= '0' && *nptr <= '9')
		{
			i = i * 10 + (*nptr - 48);
			nptr++;
		}
	}
	else
		return (-2147483649);
	return (i * neg);
}

int	is_sorted(l_list *list)
{
	l_list	*first;

	first = list;
	while (list->next)
	{
		if (list->data > list->next->data)
			return (-1);
		list = list->next;
	}
	ft_lstclearer(&first);
	return (1);
}

l_list	*find_highest(l_list *stack_a)
{
	l_list	*highest;

	highest = NULL;
	while (stack_a)
	{
		if (stack_a->data > highest->data)
			highest = stack_a;
		stack_a = stack_a->next;
	}
	return (highest);
}

/*void	small_sort(l_list **stack)
{
	l_list	*highest;

	highest = find_highest(*stack);
	if (*stack == )
}*/

void	push_swap(l_list **stack_a, l_list **stack_b)
{
	(void)stack_b;
	if (list_size(*stack_a) == 2)
		rrotate(stack_a, "rra");
		//swap(stack_a, "sa");
	//if (list_size(*stack_a) == 3)
	//	small_sort(stack_a);
}