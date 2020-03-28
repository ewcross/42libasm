# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    nasm.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/27 12:54:30 by ecross            #+#    #+#              #
#    Updated: 2020/03/27 15:48:20 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import os

if len(sys.argv) != 2 or not '.s' in sys.argv[1]:
    print('Wrong args.')
    exit()
asm_file = sys.argv[1]
obj_file = asm_file.replace('.s', '.o')
os.system('nasm -f macho64 ' + asm_file + ' && ld ' + obj_file + ' -lSystem && rm ' + obj_file)
