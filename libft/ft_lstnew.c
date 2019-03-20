/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:09:51 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 16:51:57 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *temp;

	temp = NULL;
	if (!(temp = malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(temp->content = malloc(content_size)))
			return (NULL);
		temp->content_size = content_size;
		ft_memcpy(temp->content, content, content_size);
	}
	else
	{
		temp->content = (char *)NULL;
		temp->content_size = 0;
	}
	temp->next = NULL;
	return (temp);
}
