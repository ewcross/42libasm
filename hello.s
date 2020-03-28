# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hello.s                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/27 14:46:35 by ecross            #+#    #+#              #
#    Updated: 2020/03/28 18:59:49 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_main
	default	rel

	section	.text

ft_strlen:
	xor	rax, rax
	mov	r8, -1

	loop_strlen:
	inc	r8
	cmp	byte [rdi + r8], 0
	jne	loop_strlen

	mov	rax, r8
	ret

ft_strcpy:
	xor	rax, rax

	;loop_strcpy:
	;cmp	byte [rsi], 0
	;je	out
	;mov	r9, [rsi]
	;mov	[rdi], r9
	;inc	rdi
	;inc	rsi
	;jmp	loop_strcpy

	;out:
	;mov	r9, [rsi]
	;mov	[rdi], r9
	;ret

	sub	rsi, 1
	sub	rdi, 1
	loopy:
	inc	rsi
	inc	rdi
	mov	r9, [rsi]
	mov	[rdi], r9
	cmp	byte [rsi], 0
	jne	loopy
	ret

ft_strcmp:
	mov	r10, rdi
	mov	r11, rsi
	mov	r12b, [r10]
	mov	r13b, [r11]
	
	loop_strcmp:
	cmp	r12b, r13b
	jne	outy
	cmp	r12b, 0
	je	outy
	inc	rsi
	inc	rdi
	mov	r12b, [rdi]
	mov	r13b, [rsi]
	jmp	loop_strcmp

	outy:
	xor	rax, rax
	xor	r10, r10
	xor	r11, r11
	mov	r10b, r12b
	mov	r11b, r13b
	mov	rax, r10
	sub	rax, r11
	ret

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
	; in (rdi = fd)(rsi = buff)(rdx = count)
	xor	rax, rax
	mov	rax, 0x02000004         ; system call for write
	mov	rdi, rdx
	mov	rdx, rsi 
	mov	rsi, rdi
	syscall                         ; invoke operating system to do the write
	ret

ft_write:
	xor	rax, rax
	mov	rax, 0x02000004         ; system call for write
	syscall                         ; invoke operating system to do the write
	ret

ft_putnbr:
	xor	rax, rax
	mov	rax, rdi
	mov	r8, 10		; set 10 for divisions
	mov	r9, 0		; initialise counter

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
	mov	rdi, rdx
	add	rdi, 48
	call ft_putchar
	sub	r9, 1
	cmp	r9, 0
	jg write
	ret

_main:
	; to test ft_strlen
	;mov	rdi, str
	;call ft_strlen
	;mov	rdi, rax
	;call ft_putnbr

	; to test ft_strcpy
	;mov	rdi, dst
	;mov	rsi, str
	;call ft_strcpy
	;mov	rdi, dst
	;call ft_strlen
	;mov	rsi, rax
	;mov	rdi, dst
	;call ft_putstr

	; to test ft_strcmp
	mov	rdi, str
	mov	rsi, str2
	call ft_strcmp
	mov	rdi, rax
	call	ft_putnbr

	; to test ft_write
	mov	rdi, str
	call ft_strlen
	mov	rdx, rax
	mov	rdi, 1
	mov	rsi, str
	call ft_write

	mov	rax, 0x02000001         ; system call for exit
	xor	rdi, rdi                ; exit code 0
	syscall                         ; invoke operating system to exit

	section	.data

str:	db	"goblin", 0
str2:	db	"xob", 0

	section	.bss

output_buff	resb	4
dst		resb	10
