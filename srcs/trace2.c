/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 23:06:52 by jleem             #+#    #+#             */
/*   Updated: 2021/01/26 23:21:32 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include <stdlib.h>

t_trace			*init_trace(void)
{
	t_trace	*trace;

	if (!(trace = malloc(sizeof(t_trace))) ||
		!(trace->ray = malloc(sizeof(t_ray))))
	{
		free_trace(trace);
		return (NULL);
	}
	return (trace);
}

t_trace			**init_traces(int thread_count)
{
	t_trace	**traces;
	int		i;

	if (!(traces = malloc(sizeof(t_trace *) * thread_count)))
		return (NULL);
	i = 0;
	while (i < thread_count)
	{
		if (!(traces[i] = init_trace()))
			free_traces(traces, i - 1);
		i++;
	}
	return (traces);
}

void			free_trace(t_trace *trace)
{
	if (trace)
	{
		free(trace->ray);
		free(trace);
	}
}

void			free_traces(t_trace **traces, int index)
{
	int i;

	if (!traces)
		return ;
	i = index;
	while (i > -1)
		free_trace(traces[i--]);
	free(traces);
}
