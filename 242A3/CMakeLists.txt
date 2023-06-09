cmake_minimum_required(VERSION 3.24)
project(FinalGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(FinalGame main.cpp Board.cpp Board.h Pieces.cpp Pieces.h Knight.cpp Knight.h Meele.cpp Melee.h Ranged.cpp Ranged.h Spearman.cpp Spearman.h Ranger.cpp Ranger.h Swordsman.cpp Swordsman.h Bowman.cpp Bowman.h Elf.cpp Elf.h Mage.cpp Mage.h)
