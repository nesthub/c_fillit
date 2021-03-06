/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 07:44:30 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/16 18:53:44 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_stralloc(const char *s)
{
	return ((char *)malloc(sizeof(char) * (ft_strlen(s) + 1)));
}
