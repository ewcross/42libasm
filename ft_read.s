# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/31 10:45:08 by ecross            #+#    #+#              #
#    Updated: 2020/05/17 14:49:47 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	section	.text
	
	default	rel
	
	global	_ft_read
	
	extern	___error

set_errno:
	mov	r8, rax			; get error code from syscall
	push rbp
	call	___error		; returns address of errno in rax
	pop rbp
	mov	dword [rax], r8d	; put error code from syscall into errno
	mov	rax, -1			; set return value to -1
	ret

_ft_read:
	xor	rax, rax
	mov	rax, 0x02000003		; system call for read
	syscall
	jc	error			; check if carry flag set (syscall error)
	ret
	error:
	call	set_errno
	ret
