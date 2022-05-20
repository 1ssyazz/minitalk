/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:56:23 by msukri            #+#    #+#             */
/*   Updated: 2021/05/18 19:56:23 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_estim(long n)
{
	size_t	estim;
	int		isneg;

	estim = 0;
	isneg = 0;
	if (n < 0)
	{
		estim++;
		isneg++;
		n = -n;
	}
	while (n >= 1)
	{
		estim++;
		n /= 10;
	}
	return (estim);
}

static char	*ft_gen(char *ret, long nbr, int len, int isneg)
{
	if (nbr != 0)
		ret = malloc(sizeof(char) * (len + 1));
	else
		return (ret = ft_strdup("0"));
	if (!ret)
		return (NULL);
	isneg = 0;
	if (nbr < 0)
	{
		isneg++;
		nbr = -nbr;
	}
	ret[len] = '\0';
	while (--len)
	{
		ret[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (isneg == 1)
		ret[0] = '-';
	else
		ret[0] = (nbr % 10) + '0';
	return (ret);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;
	long	nbr;
	int		isneg;

	nbr = n;
	len = ft_estim(nbr);
	ret = 0;
	isneg = 0;
	ret = ft_gen(ret, nbr, len, isneg);
	if (!ret)
		return (0);
	return (ret);
}
