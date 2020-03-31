# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/31 10:43:22 by ecross            #+#    #+#              #
#    Updated: 2020/03/31 13:18:21 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	section	.text
	
	default	rel
	
	global	_ft_strcmp
	
_ft_strcmp:
	mov	r8b, [rdi]
	
	loop:
	cmp	r8b, [rsi]
	jne	outy
	cmp	r8b, 0
	je	outy
	inc	rsi
	inc	rdi
	mov	r8b, [rdi]
	jmp	loop

	outy:
	xor	rax, rax
	sub	r8b, [rsi]
	movsx	rax, r8b
	ret
