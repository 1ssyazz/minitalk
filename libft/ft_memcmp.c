/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:47:01 by msukri            #+#    #+#             */
/*   Updated: 2021/05/03 15:47:01 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*bytes1;
	unsigned char	*bytes2;

	bytes1 = (unsigned char *)s1;
	bytes2 = (unsigned char *)s2;
	while (n--)
	{
		if (*bytes1 != *bytes2)
			return (*bytes1 - *bytes2);
		else
			bytes1++, bytes2++;
	}
	return (0);
}
