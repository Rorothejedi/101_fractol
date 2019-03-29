/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   thread.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 14:42:45 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 18:43:38 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Initialisation des threads
*/

int		thread_init(t_mlx *ptr)
{
	pthread_t	*thread;
	int			i;

	if (!(thread = (pthread_t*)ft_memalloc(sizeof(pthread_t))))
		return (0);
	i = -1;
	while (++i < THREADS)
	{
		if (pthread_create(&(thread[i]), NULL, thread_compute,
					(void*)ptr->thr[i]))
		{
			perror("pthread_create failure");
			return (EXIT_FAILURE);
		}
	}
	i = -1;
	while (++i < THREADS)
	{
		if (pthread_join(thread[i], NULL))
		{
			perror("pthread_join failure");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

void	*thread_compute(void *param)
{
	int		x;
	int		y;
	t_thr	*thr;
	t_mlx	*ptr;

	thr = (void*)param;
	ptr = thr->ptr_add;
	x = thr->id_thread * W_WIDTH / THREADS - 1;
	while (++x < (thr->id_thread + 1) * W_WIDTH / THREADS)
	{
		y = -1;
		while (++y < W_HEIGHT)
		{
			if (ft_strcmp(ptr->fr->name, "Mandelbrot") == 0)
				mandel_create(ptr, thr, x, y);
			else if (ft_strcmp(ptr->fr->name, "Julia") == 0)
				julia_create(ptr, thr, x, y);
			else if (ft_strcmp(ptr->fr->name, "Burning_Ship") == 0)
				bship_create(ptr, thr, x, y);
			else if (ft_strcmp(ptr->fr->name, "Multibrot") == 0)
				multi_create(ptr, thr, x, y);
		}
	}
	pthread_exit(NULL);
}
