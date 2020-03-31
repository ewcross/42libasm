# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/30 15:05:06 by ecross            #+#    #+#              #
#    Updated: 2020/03/30 15:09:58 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	section	.text
	
	default	rel

	global	_ft_strlen

ft_strlen:
	xor	rax, rax
	mov	r8, -1

	loop_strlen:
	inc	r8
	cmp	byte [rdi + r8], 0
	jne	loop_strlen

	mov	rax, r8
	ret
