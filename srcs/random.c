/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:45:57 by jleem             #+#    #+#             */
/*   Updated: 2021/02/02 10:36:29 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"
#include <fcntl.h>
#include <unistd.h>

unsigned int	ft_rand(void)
{
	static unsigned short	lfsr = 0xACE1u;
	static unsigned int		bit;

	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
	return (lfsr = (lfsr >> 1) | (bit << 15));
}

unsigned int	ft_urand(void)
{
	int const		fd = open("/dev/urandom", O_RDONLY);
	unsigned int	rand;

	if (fd != -1)
	{
		read(fd, &rand, 4);
		close(fd);
		return (rand);
	}
	return (0);
}
