# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/31 10:45:08 by ecross            #+#    #+#              #
#    Updated: 2020/03/31 10:46:17 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	section	.text
	
	default	rel
	
	global	_ft_read

_ft_read:
	xor	rax, rax
	mov	rax, 0x02000003		; system call for read
	syscall
	ret
