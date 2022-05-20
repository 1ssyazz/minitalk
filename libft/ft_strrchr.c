/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:11:04 by msukri            #+#    #+#             */
/*   Updated: 2021/05/12 12:11:04 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*to_return;

	to_return = 0;
	while (*str)
		if (*str++ == (char)c)
			to_return = (char *)str - 1;
	if (*str == (char)c)
		to_return = (char *)str;
	return (to_return);
}
