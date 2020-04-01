# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/31 10:43:22 by ecross            #+#    #+#              #
#    Updated: 2020/04/01 12:32:56 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	section	.text
	
	default	rel
	
	global	_ft_strcmp
	
_ft_strcmp:
	xor	rax, rax
	mov	r8b, [rdi]		; store first byte of str1
	
	loop:
	cmp	r8b, [rsi]		; if *str1 != *str2
	jne	outy			; return
	cmp	r8b, 0			; if either str is finished
	je	outy			; return
	inc	rsi
	inc	rdi
	mov	r8b, [rdi]
	jmp	loop

	outy:
	sub	r8b, [rsi]		; *str1 - *str2
	movsx	rax, r8b		; move result into first byte of rax
	ret
