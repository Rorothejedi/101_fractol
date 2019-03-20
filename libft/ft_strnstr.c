/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:07:55 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 13:05:13 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t i;
	size_t j;

	j = 0;
	while (big[j])
	{
		i = 0;
		while (big[i + j] == lit[i] && lit[i] && j + i < len)
			i++;
		if (!lit[i])
			return ((char *)big + j);
		j++;
	}
	return (0);
}
