/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 12:16:59 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 17:24:47 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	temp;

	i = -1;
	length = ft_strlen(str);
	while (++i < --length)
	{
		temp = str[i];
		str[i] = str[length];
		str[length] = temp;
	}
	return (str);
}
