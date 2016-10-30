/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.C                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz	  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/15 13:22:34 by vruiz	           #+#    #+#             */
/*   Updated: 2014/08/16 11:25:03 by vruiz	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strrev(char *str)
{
	int		i;
	int		size_str;
	char	temp;

	i = 0;
	size_str = 0;
	while (str[size_str])
		size_str++;
	size_str -= 1;
	while (i < size_str)
	{
		temp = str[size_str];
		str[size_str] = str[i];
		str[i] = temp;
		i++;
		size_str--;
	}
	return (str);
}
