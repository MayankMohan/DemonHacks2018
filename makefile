###############################################################################
#############################   Makefile Options   ############################
###############################################################################

################################   Variables   ################################
CC				= g++
EXT				= .exe
FEXT			= .cpp

RM				= del
RMDIR			= rd /s /q
MD				= md

INCLUDE			= C:/lib/SFML/include
LIB				= C:/lib/SFML/lib

FLAGS			= -g -std=c++11
LD				= -lsfml-graphics -lsfml-window -lsfml-system

#############################   Executable List   #############################
#                              Without Extension                              #
EXECS			= test game

#############################   Dependency List   #############################
#       Use Format: {filename}.deps = {List of all files it depends on}       #
test.exe.deps = test.o
test.deps = test.cpp

game.exe.deps = main.o menu.o game.o
main.deps = main.cpp game.h
game.deps = game.cpp game.h
menu.deps = Menu.cpp menu.h


###############################################################################
###########################   End Makefile Options   ##########################
###############################################################################

.PHONY:all clean 
.SUFFIXES:
.SECONDARY:

include = $(foreach dir, $(INCLUDE), -I$(dir))
lib = $(foreach library, $(LIB), -L$(library))
execpaths = $(foreach name, $(EXECS), bin/$(name)$(EXT))

#################################   Recipes   #################################
all:bin obj $(execpaths)

clean:
	$(RM) bin\*$(EXT)
	$(RM) obj\*.o

bin:
	$(MD) bin

obj:
	$(MD) obj

.SECONDEXPANSION:
bin/%$(EXT):$$(foreach object, $$($$*$(EXT).deps), obj/$$(object))
	$(CC) -o $@ $(foreach object, $($*$(EXT).deps), obj/$(object)) $(lib) $(LD)

obj/%.o:$$($$*.deps)
	$(CC) -c -o $@ $(include) $(filter %$(FEXT), $($*.deps)) $(FLAGS)