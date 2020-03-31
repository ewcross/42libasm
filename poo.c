/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 11:18:57 by ecross            #+#    #+#             */
/*   Updated: 2020/03/31 11:44:42 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

extern	size_t	ft_strlen(const char *str);

int	main(void)
{
	char	*str;
	char	*s1 = "hello there sir";

	printf("\n***FT_STRLEN***\n");
	str = s1;
	printf("testing: \"%s\"\n", str);
	printf("ft_strlen: %lu\n", ft_strlen(str));
	printf("   strlen: %lu\n", strlen(str));
}
