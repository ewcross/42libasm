# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    nasm.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/27 12:54:30 by ecross            #+#    #+#              #
#    Updated: 2020/03/31 10:56:34 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import os

if len(sys.argv) != 2:
    print('Wrong args.')
    exit()

if not sys.argv[1] == 'all':
    asm_file = sys.argv[1]
    obj_file = asm_file.replace('.s', '.o')
    os.system('nasm -f macho64 ' + asm_file + ' && ld ' + obj_file + ' -lSystem && rm ' + obj_file)
else:
    for f in os.listdir('.'):
        if '.s' in f:
            os.system('nasm -f macho64 ' + f)
