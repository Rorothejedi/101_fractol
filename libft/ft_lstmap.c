/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 19:57:44 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 18:02:11 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *begin;

	new = NULL;
	begin = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (!begin)
		{
			new = f(lst);
			begin = new;
		}
		else
		{
			new->next = f(lst);
			new = new->next;
		}
		lst = lst->next;
	}
	return (begin);
}
