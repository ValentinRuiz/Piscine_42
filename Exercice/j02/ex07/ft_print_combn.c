/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combnb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz	  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/14 12:33:14 by vruiz	           #+#    #+#             */
/*   Updated: 2014/08/15 10:51:23 by vruiz	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	init_tab(char *tab, int n)
{
	int i;

	i = 0;
	while (i != n)
	{
		tab[i] = '0';
		i++;
	}
	tab[n] = '\n';
}

int		incr(char *str, int n)
{
	int i;
	int j;

	i = n - 1;
	j = n - 1;
	if (str[i] == '9')
	{
		while (i >= 0 && str[i] == '9')
			i--;
		if (i >= 0)
		{
			while (j != i && str[j] == '9') 
			{
				str[j] = '0';
				j--;
			}
			str[i]++;
			return (1);
		}
		return (0);
	}
	else
		str[i]++;
	return (1);
}

int		good(char *str, int n)
{
	int i;
	int n;
	int var_de_test;
	
	var_de_test = 0;
	n = 1;
	i = 0;
	while (1) 
	{
		if (str[i] >= str[i + n] && (i + n) < n)
			return (0);
		else if ((i + n + 1) <= (n - 1))
			n++;
		else if ((i + n) == (n - 1) && i != (n - 1))
		{
			i++;
			n = 1;
		}
		else if (i == (n - 1))
			return (1);
	}
}
void	ft_print_combn(int n)
{
	char str[n];
	int i;
	int j;

	j = 0;
	i = 1;
	init_tab(str, n);
	while (i)
	{
		i = incr(str, n);
		if (good(str, n))
		{
			ft_putstr(str);
			if (i)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			else
				ft_putchar('\n');
		}
	}
}

int main(int argc, const char *argv[])
{
	int n;

	n = 5;

	ft_print_combn(n);
	return 0;
}