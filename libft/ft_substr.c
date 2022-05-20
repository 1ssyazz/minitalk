/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:14:44 by msukri            #+#    #+#             */
/*   Updated: 2021/07/18 22:14:44 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if ((start >= ft_strlen(s)) || (len == 0))
		return (ft_calloc(1, sizeof(char)));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(*s) * (len + 1));
	if (!ret)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			ret [j] = s[i];
			j++;
		}
		i++;
	}
	ret[j] = 0;
	return (ret);
}
