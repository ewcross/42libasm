# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/31 10:47:28 by ecross            #+#    #+#              #
#    Updated: 2020/04/01 12:25:37 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	section	.text
	
	default	rel
	
	global	_ft_strdup
	
	extern	_malloc

len:
	xor	rax, rax
	mov	r8, -1
	cmp	rdi, 0			; if pointer is null
	je	outout			; return len = 0

	loop_strlen:
	inc	r8
	cmp	byte [rdi + r8], 0
	jne	loop_strlen

	outout:
	mov	rax, r8
	ret

cpy:
	xor	rax, rax

	push	rdi			; push dst pointer
	sub	rsi, 1
	sub	rdi, 1
	loopy:
	inc	rsi
	inc	rdi
	mov	r9, [rsi]		; move byte from src
	mov	[rdi], r9		; to dst
	cmp	byte [rsi], 0
	jne	loopy

	pop	rax			; get dst pointer
	ret

_ft_strdup:
	xor	rax, rax
	cmp	rdi, 0			; if src pointer is NULL
	je	out			; return NULL (rax = 0)

	push	rdi			; push src pointer
	call len			; get length of string to copy
	
	mov	rdi, rax		; using return value of strlen
	inc	rdi			; add 1 byte to len for null byte
	call _malloc

	pop	rsi			; clean stack and get src pointer for str cpy call
	cmp	rax, 0			; check malloc did not fail
	jz	out

	mov	rdi, rax		; pass malloced dst to strcpy
	call cpy			; ft_strcpy returns pointer to dst in rax

	out:
	ret
