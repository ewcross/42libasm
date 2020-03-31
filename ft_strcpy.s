# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/30 15:10:57 by ecross            #+#    #+#              #
#    Updated: 2020/03/30 15:18:32 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	section	.text
	
	default	rel
	
	global	ft_strcpy

ft_strcpy:
	xor	rax, rax

	mov	r10, rdi		; store dst pointer
	sub	rsi, 1
	sub	rdi, 1
	loopy:
	inc	rsi
	inc	rdi
	mov	r9, [rsi]
	mov	[rdi], r9
	cmp	byte [rsi], 0
	jne	loopy

	mov	rax, r10
	ret
