# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    utilities.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/02 10:39:07 by ecross            #+#    #+#              #
#    Updated: 2020/04/02 10:39:10 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	section	.text
	
	default	rel
	
ft_putchar:
	xor	rax, rax
	mov	[output_buff], rdi
	mov	rax, 0x02000004         ; system call for write
	mov	rsi, output_buff	; move passed variable into rsi
	mov	rdi, 1                  ; file handle 1 is stdout
	mov	rdx, 1                  ; number of bytes
	syscall                         ; invoke operating system to do the write
	ret

ft_putstr:
	xor	rax, rax
	call _ft_strlen
	mov	rsi, rdi
	mov	rdi, 1
	mov	rdx, rax
	call _ft_write
	ret

ft_putnbr:
	xor	rax, rax
	mov	rax, rdi
	mov	r8, 10			; set 10 for divisions
	mov	r9, 0			; initialise counter

	cmp	rax, -17
	jne store
	mov	rdi, 43
	call ft_putchar
	ret

	store:
	push	rax
	inc	r9
	cmp	rax, 9
	jle write
	xor	rdx, rdx
	div	r8
	jmp store

	write:
	pop	rax
	xor	rdx, rdx
	div	r8

str:	db	"goblinsaosihaos", 10, 0

	section	.bss

output_buff	resb	4
