/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 14:50:40 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 03:30:36 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = -1;
	if (!s)
		return (NULL);
	str = NULL;
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	while (++i < len)
		str[i] = s[i + start];
	str[i] = '\0';
	return (str);
}
