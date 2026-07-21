/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutorrez <dutorrez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 12:35:05 by dutorrez          #+#    #+#             */
/*   Updated: 2026/07/21 19:52:40 by dutorrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s1);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s1, len + 1);
	return (copy);
}
