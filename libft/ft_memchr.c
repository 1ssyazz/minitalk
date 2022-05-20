/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:31:40 by msukri            #+#    #+#             */
/*   Updated: 2021/07/18 20:31:40 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ac;

	str = (unsigned char *)s;
	ac = (unsigned char)c;
	while (n)
	{
		if (*str == ac)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
