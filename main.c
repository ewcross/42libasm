/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 11:18:57 by ecross            #+#    #+#             */
/*   Updated: 2020/05/15 19:14:29 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

extern	size_t	ft_strlen(const char *str);
extern	char	*ft_strcpy(char *dst, const char *src);
extern	int		ft_strcmp(const char *s1, const char *s2);
extern	ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
extern	ssize_t	ft_read(int fd, void *buf, size_t nbyte);
extern	char	*ft_strdup(char const *s1);

int	main(void)
{
	int		fd;
	int		ret;
	char	*str;
	char	*str2;
	char	dst[10000];
	char	*normal = "goblins";
	char	*empty = "";
	char	*long_str = "gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg";
	char	*null_str = 0;

	
	printf("***FT_STRLEN***\n");
	str = empty;
	printf("testing empty string\n");
	printf("mine: %lu\n", ft_strlen(str));
	printf("errno --> %d\n", errno);
	printf("real: %lu\n", strlen(str));
	printf("errno --> %d\n", errno);
	printf("-------\n");
	str = long_str;
	printf("testing long str\n");
	printf("mine: %lu\n", ft_strlen(str));
	printf("errno --> %d\n", errno);
	printf("real: %lu\n", strlen(str));
	printf("errno --> %d\n", errno);
	printf("-----------------------------------------\n");
	printf("***FT_STRCPY***\n");
	str = empty;
	printf("testing empty string\n");
	printf("mine: %s\n", ft_strcpy(dst, str));
	printf("errno --> %d\n", errno);
	printf("real: %s\n", strcpy(dst, str));
	printf("errno --> %d\n", errno);
	printf("-------\n");
	str = long_str;
	printf("testing long str\n");
	printf("mine: %s\n", ft_strcpy(dst, str));
	printf("errno --> %d\n", errno);
	printf("real: %s\n", strcpy(dst, str));
	printf("errno --> %d\n", errno);
	printf("-----------------------------------------\n");
	printf("***FT_STRCMP***\n");
	str = empty;
	str2 = empty;
	printf("comparing empty strings\n");
	printf("mine: %d\n", ft_strcmp(str, str2));
	printf("errno --> %d\n", errno);
	printf("real: %d\n", strcmp(str, str2));
	printf("errno --> %d\n", errno);
	printf("-------\n");
	str = empty;
	str2 = normal;
	printf("comparing empty with normal\n");
	printf("mine: %d\n", ft_strcmp(str, str2));
	printf("errno --> %d\n", errno);
	printf("real: %d\n", strcmp(str, str2));
	printf("errno --> %d\n", errno);
	printf("-------\n");
	str = normal;
	str2 = empty;
	printf("comparing normal with empty\n");
	printf("mine: %d\n", ft_strcmp(str, str2));
	printf("errno --> %d\n", errno);
	printf("real: %d\n", strcmp(str, str2));
	printf("errno --> %d\n", errno);
	printf("-------\n");
	str = normal;
	str2 = normal;
	printf("comparing equal strings\n");
	printf("mine: %d\n", ft_strcmp(str, str2));
	printf("errno --> %d\n", errno);
	printf("real: %d\n", strcmp(str, str2));
	printf("errno --> %d\n", errno);
	printf("-------\n");
	str = "goblins";
	str2 = "goblinos";
	printf("comparing other strings\n");
	printf("mine: %d\n", ft_strcmp(str, str2));
	printf("errno --> %d\n", errno);
	printf("real: %d\n", strcmp(str, str2));
	printf("errno --> %d\n", errno);
	printf("-----------------------------------------\n");
	printf("***FT_WRITE***\n");
	str = normal;
	fd = 1;
	printf("writing string to stdout \"%s\"\n", str);
	ret = ft_write(fd, str, ft_strlen(str));
	printf("mine: %d\n", ret);
	printf("errno --> %d\n", errno);
	ret = write(fd, str, ft_strlen(str));
	printf("real: %d\n", ret);
	printf("errno --> %d\n", errno);
	printf("-------\n");
	printf("writing string to output.txt \"%s\"\n", str);
	fd = open("output.txt", O_WRONLY | O_APPEND);
	ret = ft_write(fd, str, ft_strlen(str));
	printf("mine: %d\n", ret);
	printf("errno --> %d\n", errno);
	ret = write(fd, str, ft_strlen(str));
	printf("real: %d\n", ret);
	printf("errno --> %d\n", errno);
	close(fd);
	printf("-------\n");
	fd = -1;
	printf("writing string to bad file descriptor \"%s\"\n", str);
	ret = ft_write(fd, str, ft_strlen(str));
	printf("mine: %d\n", ret);
	printf("errno --> %d\n", errno);
	ret = write(fd, str, ft_strlen(str));
	printf("real: %d\n", ret);
	printf("errno --> %d\n", errno);
	printf("-----------------------------------------\n");
	printf("***FT_READ***\n");
	printf("reading from stdin\n");
	fd = 0;
	dst[10] = 0;
	printf("mine: %zd -> %s\n", ft_read(fd, dst, 10), dst);
	printf("real: %zd -> %s\n", read(fd, dst, 10), dst);
	printf("-------\n");
	printf("reading from output.txt\n");
	fd = open("output.txt", O_RDONLY);
	printf("mine: %zd -> %s\n", ft_read(fd, dst, 10), dst);
	close(fd);
	fd = open("output.txt", O_RDONLY);
	printf("real: %zd -> %s\n", read(fd, dst, 10), dst);
	close(fd);

	/*
	printf("***FT_READ***\n");
	printf("reading from file\n");
	fd = open("text", O_RDONLY);
	printf("mine: %zd -> %s\n", ft_read(fd, dst, 10), dst);
	close(fd);
	fd = open("text", O_RDONLY);
	printf("real: %zd -> %s\n", read(fd, dst, 10), dst);
	close(fd);

	printf("***FT_STRDUP***\n");
	str = s1;
	printf("duplicating string \"%s\"\n", str);
	printf("mine: %s\n", ft_strdup(str));
	printf("real: %s\n", strdup(str));
	*/
}
