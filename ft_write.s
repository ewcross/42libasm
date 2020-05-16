# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/31 10:44:33 by ecross            #+#    #+#              #
#    Updated: 2020/05/16 12:31:30 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	section	.text
	
	default	rel
	
	global	_ft_write

	extern	___error
	
_ft_write:
	xor	rax, rax
	mov	rax, 0x02000004         ; system call for write
	syscall                         ; invoke operating system to do the write
	test	rax, rax
	js	error
	;call	___error
	ret
	error:
	mov	rax, -1
	ret
