###############################################################################
#############################   Makefile Options   ############################
###############################################################################

################################   Variables   ################################
CC				= g++
EXT				= .exe

RM				= del
RMDIR			= rd /s /q
MD				= md

INCLUDE			= 
LIB				= 

FLAGS			= -g -Wall
LD				= -lsfml-graphics -lsfml-window -lsfml-system

#############################   Executable List   #############################
#                              Without Extension                              #
EXECS			= test

#############################   Dependency List   #############################
#       Use Format: {filename}.deps = {List of all files it depends on}       #
test.exe.deps = main.o
main.deps = main.cpp


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
	$(CC) -c -o $@ $(include) $($*.deps) $(FLAGS)