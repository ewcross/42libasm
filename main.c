/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 11:18:57 by ecross            #+#    #+#             */
/*   Updated: 2020/05/16 11:29:15 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
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
	int		n;
	int		err;
	int		ret;
	long unsigned	retlu;
	char	*str;
	char	*str2;
	char	*new;
	char	dst[10000];
	char	*normal = "goblins";
	char	*empty = "";
	char	*long_str = "gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg";
	char	*null_str = 0;

	
	printf("***FT_STRLEN***\n");
	str = empty;
	printf("testing empty string\n");
	errno = 0;
	retlu = ft_strlen(str);
	err = errno;
	printf("mine: %lu\n", retlu);
	printf("errno --> %d\n", err);
	errno = 0;
	retlu = strlen(str);
	err = errno;
	printf("real: %lu\n", retlu);
	printf("errno --> %d\n", err);
	printf("-------\n");
	
	str = long_str;
	printf("testing long str\n");
	errno = 0;
	retlu = ft_strlen(str);
	err = errno;
	printf("mine: %lu\n", retlu);
	printf("errno --> %d\n", err);
	errno = 0;
	retlu = strlen(str);
	err = errno;
	printf("real: %lu\n", retlu);
	printf("errno --> %d\n", err);
	printf("-----------------------------------------\n");
	
	printf("***FT_STRCPY***\n");
	str = empty;
	printf("testing empty string\n");
	errno = 0;
	new = ft_strcpy(dst, str);
	err = errno;
	printf("mine: %s\n", new);
	printf("errno --> %d\n", err);
	errno = 0;
	new = strcpy(dst, str);
	err = errno;
	printf("real: %s\n", new);
	printf("errno --> %d\n", err);
	printf("-------\n");
	
	str = long_str;
	printf("testing long str\n");
	errno = 0;
	new = ft_strcpy(dst, str);
	err = errno;
	printf("mine: %s\n", new);
	printf("errno --> %d\n", err);
	errno = 0;
	new = strcpy(dst, str);
	err = errno;
	printf("real: %s\n", new);
	printf("errno --> %d\n", err);
	printf("-----------------------------------------\n");
	
	printf("***FT_STRCMP***\n");
	str = empty;
	str2 = empty;
	printf("comparing empty strings\n");
	errno = 0;
	ret = ft_strcmp(str, str2);
	err = errno;
	printf("mine: %d\n", ret);
	printf("errno --> %d\n", err);
	errno = 0;
	ret = strcmp(str, str2);
	err = errno;
	printf("real: %d\n", ret);
	printf("errno --> %d\n", err);
	printf("-------\n");
	
	str = empty;
	str2 = normal;
	printf("comparing empty with normal\n");
	errno = 0;
	ret = ft_strcmp(str, str2);
	err = errno;
	printf("mine: %d\n", ret);
	printf("errno --> %d\n", err);
	errno = 0;
	ret = strcmp(str, str2);
	err = errno;
	printf("real: %d\n", ret);
	printf("errno --> %d\n", err);
	printf("-------\n");
	
	str = normal;
	str2 = empty;
	printf("comparing normal with empty\n");
	errno = 0;
	ret = ft_strcmp(str, str2);
	err = errno;
	printf("mine: %d\n", ret);
	printf("errno --> %d\n", err);
	errno = 0;
	ret = strcmp(str, str2);
	err = errno;
	printf("real: %d\n", ret);
	printf("errno --> %d\n", err);
	printf("-------\n");
	
	str = normal;
	str2 = normal;
	printf("comparing equal strings\n");
	errno = 0;
	ret = ft_strcmp(str, str2);
	err = errno;
	printf("mine: %d\n", ret);
	printf("errno --> %d\n", err);
	errno = 0;
	ret = strcmp(str, str2);
	err = errno;
	printf("real: %d\n", ret);
	printf("errno --> %d\n", err);
	printf("-------\n");
	
	str = "goblins";
	str2 = "goblinos";
	printf("comparing other strings\n");
	errno = 0;
	ret = ft_strcmp(str, str2);
	err = errno;
	printf("mine: %d\n", ret);
	printf("errno --> %d\n", err);
	errno = 0;
	ret = strcmp(str, str2);
	err = errno;
	printf("real: %d\n", ret);
	printf("errno --> %d\n", err);
	printf("-----------------------------------------\n");
	
	printf("***FT_WRITE***\n");
	str = normal;
	printf("writing string to stdout \"%s\"\n", str);
	fd = 1;
	printf("mine: \n");
	errno = 0;
	retlu = ft_write(fd, str, ft_strlen(str));
	err = errno;
	printf(" (ret = %zd)\n", retlu);
	printf("errno --> %d\n", err);
	printf("real: \n");
	errno = 0;
	retlu = write(fd, str, ft_strlen(str));
	err = errno;
	printf(" (ret = %zd)\n", retlu);
	printf("errno --> %d\n", err);
	printf("-------\n");
	
	printf("writing string to output.txt \"%s\"\n", str);
	fd = open("output.txt", O_WRONLY | O_APPEND);
	printf("mine: \n");
	errno = 0;
	retlu = ft_write(fd, str, ft_strlen(str));
	err = errno;
	printf(" (ret = %zd)\n", retlu);
	printf("errno --> %d\n", err);
	printf("real: \n");
	errno = 0;
	retlu = write(fd, str, ft_strlen(str));
	err = errno;
	printf(" (ret = %zd)\n", retlu);
	printf("errno --> %d\n", err);
	close(fd);
	printf("-------\n");
	
	printf("writing string to bad file descriptor \"%s\"\n", str);
	fd = -1;
	printf("mine: \n");
	errno = 0;
	retlu = ft_write(fd, str, ft_strlen(str));
	err = errno;
	printf(" (ret = %zd)\n", retlu);
	printf("errno --> %d\n", err);
	printf("real: \n");
	errno = 0;
	retlu = write(fd, str, ft_strlen(str));
	err = errno;
	printf(" (ret = %zd)\n", retlu);
	printf("errno --> %d\n", err);
	printf("-----------------------------------------\n");
	
	printf("***FT_READ***\n");
	n = 10;

	printf("reading from stdin\n");
	fd = 0;
	memset(dst, 0, n + 1);
	errno = 0;
	retlu = ft_read(fd, dst, n);
	err = errno;
	printf("mine: (ret = %zd) %s\n", retlu, dst);
	printf("errno --> %d\n", err);
	memset(dst, 0, n + 1);
	errno = 0;
	retlu = read(fd, dst, n);
	err = errno;
	printf("mine: (ret = %zd) %s\n", retlu, dst);
	printf("errno --> %d\n", err);
	printf("-------\n");

	printf("reading %d chars from output.txt\n", n);
	fd = open("output.txt", O_RDONLY);
	memset(dst, 0, n + 1);
	errno = 0;
	retlu = ft_read(fd, dst, n);
	err = errno;
	printf("mine: (ret = %zd) %s\n", retlu, dst);
	printf("errno --> %d\n", err);
	close(fd);
	
	fd = open("output.txt", O_RDONLY);
	memset(dst, 0, n + 1);
	errno = 0;
	retlu = read(fd, dst, n);
	err = errno;
	printf("mine: (ret = %zd) %s\n", retlu, dst);
	printf("errno --> %d\n", err);
	close(fd);
	printf("-------\n");
	
	printf("reading %d chars from bad file descriptor\n", n);
	fd = -1;
	memset(dst, 0, n + 1);
	errno = 0;
	retlu = ft_read(fd, dst, n);
	err = errno;
	printf("mine: (ret = %zd) %s\n", retlu, dst);
	printf("errno --> %d\n", err);
	memset(dst, 0, n + 1);
	errno = 0;
	retlu = read(fd, dst, n);
	err = errno;
	printf("mine: (ret = %zd) %s\n", retlu, dst);
	printf("errno --> %d\n", err);
	printf("-----------------------------------------\n");
	
	printf("***FT_STRDUP***\n");
	str = empty;
	printf("duplicating empty string\n");
	errno = 0;
	new = ft_strdup(str);
	err = errno;
	printf("mine: %s\n", new);
	printf("errno --> %d\n", err);
	free(new);
	errno = 0;
	new = strdup(str);
	err = errno;
	printf("real: %s\n", new);
	printf("errno --> %d\n", err);
	free(new);
	printf("-------\n");
	
	str = long_str;
	printf("duplicating long string\n");
	errno = 0;
	new = ft_strdup(str);
	err = errno;
	printf("mine: %s\n", new);
	printf("errno --> %d\n", err);
	free(new);
	errno = 0;
	new = strdup(str);
	err = errno;
	printf("real: %s\n", new);
	printf("errno --> %d\n", err);
	free(new);
	printf("-------\n");
}
