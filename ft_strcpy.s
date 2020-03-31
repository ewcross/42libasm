# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/30 15:10:57 by ecross            #+#    #+#              #
#    Updated: 2020/03/31 13:19:52 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	section	.text
	
	default	rel
	
	global	_ft_strcpy

_ft_strcpy:
	xor	rax, rax

	cmp	rsi, 0			; do nothing if null pointer
	je	out			; this is safer than strcpy

	push	rdi
	sub	rsi, 1
	sub	rdi, 1
	loopy:
	inc	rsi
	inc	rdi
	mov	r8, [rsi]
	mov	[rdi], r8
	cmp	byte [rsi], 0
	jne	loopy

	pop	rax
	out:
	ret
