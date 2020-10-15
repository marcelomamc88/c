# cmake_minimum_required(VERSION <specify CMake version here>)
project(Projects C)

set(CMAKE_C_STANDARD 99)

add_executable(main main.c)
add_executable(fat_rec.c fat_rec.c)
add_executable(calc_diagonal_matriz.c calc_diagonal_matriz.c)
add_executable(ponteiro.c ponteiro.c)
add_executable(pilha_valida_parenteses.c pilha_valida_parenteses.c)
add_executable(revisao_estrutura_dados.c revisao_estrutura_dados.c)
add_executable(linked_list_struct.c linked_list_struct.c)
add_executable(linked_list_vector.c linked_list_vector.c)

