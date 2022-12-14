rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

NAME	:= B2

PWD		:= $(CURDIR)
SRC		:= $(PWD)/src
BIN		:= $(PWD)/bin

OUTPUT	:= $(PWD)/$(NAME)
CLEAR	:=

CC		:= gcc
CFLG	:=	-g				\
			-isystem ./src	\
			-Wattributes

CSRC	:= $(call rwildcard,$(SRC),*.c)
CTAR	:= $(patsubst $(SRC)/%,$(BIN)/%,$(patsubst %.c,%.out,$(CSRC)))
# CIDR	:= $(shell dirname $(shell echo $(CSRC) | tr ' ' '\n' | sort -u | xargs))
CINC	:= $(addprefix -I ,$(CSRC))

export

ifeq ($(OS),Windows_NT)
	## Windows Logic
	OUTPUT := $(OUTPUT).exe
	CLEAR += cls
else
	UNAME=$(shell uname -s)
	ifeq ($(UNAME),Linux)
		## Linux logic
		CLEAR+=clear
	endif
	ifeq ($(UNAME),Darwin)
		## OSX logic
	endif
endif

all: build run

build:
	@$(CLEAR)
	@$(CC) $(CFLG) $(CSRC) -o $(OUTPUT) $(CINC)

run:
	@$(CLEAR)
	@$(OUTPUT)
