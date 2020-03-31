# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/31 10:47:28 by ecross            #+#    #+#              #
#    Updated: 2020/03/31 10:49:51 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	section	.text
	
	default	rel
	
	global	_ft_strdup
	
	extern	_malloc

len:
	xor	rax, rax
	mov	r8, -1

	loop_strlen:
	inc	r8
	cmp	byte [rdi + r8], 0
	jne	loop_strlen

	mov	rax, r8
	ret

cpy:
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

_ft_strdup:
	xor	rax, rax
	push	rdi			; push src pointer
	call len			; get length of string to copy

	sub	rsp, 8			; align stack
	mov	rdi, rax		; using retrun value of strlen
	inc	rdi			; add 1 byte to len for null byte
	call _malloc			; malloc len + 1 bytes
	add	rsp, 8			; clean up stack
	
	cmp	rax, 0			; check malloc did not fail
	je	outout

	mov	rdi, rax		; pass malloced dst to strcpy
	pop	rsi			; get src pointer from stack
	call	cpy			; ft_strcpy returns pointer to dst in rax

	outout:
	ret
