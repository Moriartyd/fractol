/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 20:09:03 by cpollich          #+#    #+#             */
/*   Updated: 2019/08/30 20:09:20 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (s1[++i])
		;
	j = -1;
	while (s2[++j] && n > 0)
	{
		s1[i] = s2[j];
		i++;
		n--;
	}
	s1[i] = '\0';
	return (s1);
}
