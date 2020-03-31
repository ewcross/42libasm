# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hello.s                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/27 14:46:35 by ecross            #+#    #+#              #
#    Updated: 2020/03/30 15:33:02 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; to do
; stop using registers for storing things - this may disrupt a called function
; better to just push and pop stored values
; find out problem with malloc

	section	.text
	
	default	rel
	
	global	_main
	
	extern	_malloc
	extern	_ft_strlen
	extern	_ft_strcpy

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
	; try using movsx to move 1 byte into entire rax
	; e.g. movsx	rax, r12b
	; instead of having to go via another register
	xor	rax, rax
	xor	r10, r10
	xor	r11, r11
	mov	r10b, r12b
	mov	r11b, r13b
	mov	rax, r10
	sub	rax, r11
	ret

ft_write:
	xor	rax, rax
	mov	rax, 0x02000004         ; system call for write
	syscall                         ; invoke operating system to do the write
	ret

ft_read:
	xor	rax, rax
	mov	rax, 0x02000003		; system call for read
	syscall
	ret

ft_strdup:
	xor	rax, rax
	push	rdi			; push src pointer
	call _ft_strlen			; get length of string to copy

	sub	rsp, 8			; align stack
	mov	rdi, rax		; using retrun value of strlen
	inc	rdi			; add 1 byte to len for null byte
	call _malloc			; malloc len + 1 bytes
	add	rsp, 8			; clean up stack
	
	cmp	rax, 0			; check malloc did not fail
	je	outout

	mov	rdi, rax		; pass malloced dst to strcpy
	pop	rsi			; get src pointer from stack
	call	ft_strcpy		; ft_strcpy returns pointer to dst in rax

	outout:
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
	xor	rax, rax
	call _ft_strlen
	mov	rsi, rdi
	mov	rdi, 1
	mov	rdx, rax
	call ft_write
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
	mov	rdi, rdx
	add	rdi, 48
	call ft_putchar
	sub	r9, 1
	cmp	r9, 0
	jg write
	ret

_main:
	; to test _ft_strlen
	;mov	rdi, str
	;call _ft_strlen
	;mov	rdi, rax
	;call ft_putnbr

	; to test ft_strcpy
	;mov	rdi, dst
	;mov	rsi, str
	;call ft_strcpy
	;mov	rdi, rax
	;mov	r10, rax
	;call _ft_strlen
	;mov	rdi, 1
	;mov	rsi, r10
	;mov	rdx, rax
	;call ft_write

	; to test ft_strcmp
	;mov	rdi, str
	;mov	rsi, str2
	;call ft_strcmp
	;mov	rdi, rax
	;call	ft_putnbr

	; to test ft_write
	;mov	rdi, str
	;call _ft_strlen
	;mov	rdx, rax
	;mov	rdi, 1
	;mov	rsi, str
	;call ft_write

	; to test ft_read
	;mov	rdi, 0
	;mov	rsi, dst
	;mov	rdx, 9
	;call ft_read
	;mov	rdi, dst
	;call _ft_strlen
	;mov	rdi, 1
	;mov	rsi, dst
	;mov	rdx, rax
	;call ft_write

	; to test ft_strdup
	mov	rdi, str
	call ft_strdup
	mov	rdi, rax
	call ft_putstr

	mov	rax, 0x02000001         ; system call for exit
	xor	rdi, rdi                ; exit code 0
	syscall                         ; invoke operating system to exit

	section	.data

str:	db	"goblins", 10, 0
str2:	db	"xob", 0

	section	.bss

output_buff	resb	4
dst		resb	20
