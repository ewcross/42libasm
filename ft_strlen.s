# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/30 15:05:06 by ecross            #+#    #+#              #
#    Updated: 2020/04/01 12:27:25 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	section	.text
	
	default	rel

	global	_ft_strlen

_ft_strlen:
	xor	rax, rax
	cmp	rdi, 0			; if str pointer is NULL
	je	out			; return 0 (rax = 0)
	mov	r8, -1
	loop:
	inc	r8
	cmp	byte [rdi + r8], 0
	jne	loop
	mov	rax, r8
	out:
	ret
