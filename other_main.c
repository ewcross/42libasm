/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 11:18:57 by ecross            #+#    #+#             */
/*   Updated: 2020/05/16 12:19:12 by ecross           ###   ########.fr       */
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

	str = "123456789";
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
}
