/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 11:07:22 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 16:52:55 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		length;
	int		i;
	int		j;

	if (!s || !c)
		return (NULL);
	if (!(str = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
		if (s[i] == c)
			i++;
		else
		{
			length = 0;
			while (s[i + length] && (s[i + length] != c))
				length++;
			str[j++] = ft_strsub(s, i, length);
			i += length;
		}
	str[j] = NULL;
	return (str);
}
