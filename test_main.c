/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 11:18:57 by ecross            #+#    #+#             */
/*   Updated: 2020/03/31 13:33:33 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

extern	size_t	ft_strlen(const char *str);
extern	char	*ft_strcpy(char *dst, const char *src);
extern	int		ft_strcmp(const char *s1, const char *s2);
extern	ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
extern	ssize_t	ft_read(int fd, void *buf, size_t nbyte);
extern	char	*ft_strdup(char const *s1);

int	main(void)
{
	char	*str;
	char	*str2;
	char	*s1 = "poopoo";
	char	*s2 = "";
	char	*s3 = 0;
	char	*s4 = "";
	char	dst[100];

	printf("***FT_STRLEN***\n");
	str = s2;
	printf("testing string: \"%s\"\n", str);
	printf("mine: %lu\n", ft_strlen(str));
	printf("real: %lu\n", strlen(str));
	
	printf("***FT_STRCPY***\n");
	str = s1;
	printf("copying string: \"%s\"\n", str);
	printf("mine: %s\n", ft_strcpy(dst, str));
	printf("real: %s\n", strcpy(dst, str));
	str = s2;
	printf("copying string: \"%s\"\n", str);
	printf("mine: %s\n", ft_strcpy(dst, str));
	printf("real: %s\n", strcpy(dst, str));
	str = s3;
	printf("copying string: \"%s\"\n", str);
	printf("mine: %s\n", ft_strcpy(dst, str));
	//printf("real: %s\n", strcpy(dst, str));
	printf("***FT_STRCMP***\n");
	str = s2;
	str2 = s4;
	printf("comparing strings: \"%s\" and \"%s\"\n", str, str2);
	printf("mine: %d\n", ft_strcmp(str, str2));
	printf("real: %d\n", strcmp(str, str2));
	printf("***FT_WRITE***\n");
	str = s1;
	printf("writing string: \"%s\"\n", str);
	printf("mine: %zd\n", ft_write(1, str, ft_strlen(str)));
	printf("real: %zd\n", write(1, str, strlen(str)));
	printf("***FT_READ***\n");
	printf("reading from file\n");
	int fd = open("text", O_RDONLY);
	printf("mine: %zd -> %s\n", ft_read(fd, dst, 10), dst);
	printf("real: %zd -> %s\n", read(fd, dst, 10), dst);
	printf("***FT_STRDUP***\n");
	str = s1;
	printf("duplicating string \"%s\"\n", str);
	printf("mine: %s\n", ft_strdup(str));
	printf("real: %s\n", strdup(str));
}
