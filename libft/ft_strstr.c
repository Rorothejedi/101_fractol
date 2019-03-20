/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 10:15:33 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 19:00:31 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[j])
	{
		i = 0;
		while (big[i + j] == little[i] && little[i])
			i++;
		if (!little[i])
			return ((char *)big + j);
		j++;
	}
	return (0);
}
