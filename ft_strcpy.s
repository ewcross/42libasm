# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/30 15:10:57 by ecross            #+#    #+#              #
#    Updated: 2020/04/01 12:28:32 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	section	.text
	
	default	rel
	
	global	_ft_strcpy

_ft_strcpy:
	xor	rax, rax

	cmp	rsi, 0			; if src pointer is NULL
	je	out			; return NULL (ret = 0)

	push	rdi			; push dst pointer to stack
	sub	rsi, 1
	sub	rdi, 1
	loopy:
	inc	rsi
	inc	rdi
	mov	r8, [rsi]
	mov	[rdi], r8
	cmp	byte [rsi], 0
	jne	loopy

	pop	rax			; get dst pointer from stack
	out:
	ret
