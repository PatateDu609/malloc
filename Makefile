ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME				:=	libft_malloc_$(HOSTTYPE).so

CC					:=	@gcc
RM					:=	@rm -f
MKDIR				:=	@mkdir -p

PATH_INC			:=	-I./include
PATH_SRC			:=	./src
PATH_OBJS			:=	./objs

CFLAGS				:=	-Wall -Werror -Wextra $(PATH_INC) -g3 -gdwarf-2 -fPIC
LDFLAGS				:=	-shared -fPIC -g

BASENAME			:=	malloc.c					\
						realloc_utils.c				\
						logger/logger.c				\
						logger/log_funcs.c			\
						logger/utils.c				\
						zone/alloc_zone.c			\
						zone/utils.c				\
						zone/show_alloc_mem.c		\
						zone/block/reserve_block.c	\
						zone/block/split_block.c	\
						zone/block/free_block.c		\
						zone/block/resize_block.c	\
						zone/get_block.c			\
						zone/free_zone.c			\
						utils/ft_memset.c			\
						utils/ft_memcpy.c			\
						utils/ft_max.c				\

SRC 				:=	$(addprefix $(PATH_SRC)/, $(BASENAME))
OBJS 				:=	$(addprefix $(PATH_OBJS)/, $(BASENAME:%.c=%.o))
DEP 				:=	$(addprefix $(PATH_OBJS)/, $(BASENAME:%.c=%.d))

MAIN				:=	main.c

$(PATH_OBJS)/%.o:	$(PATH_SRC)/%.c
					@echo "Compiling $(subst objs/,,$@)..."
					$(MKDIR) $(dir $@)
					$(CC) $(CFLAGS) -MMD -c $< -o $@

main:				$(NAME)
					$(CC) -g $(PATH_INC) -o test -L.  $(MAIN) -lft_malloc_$(HOSTTYPE)
					@LD_LIBRARY_PATH=. ./test

all:				$(NAME)

$(NAME):			$(OBJS)
					@echo "Creating shared library"
					$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)
					@echo -n "\n"

-include $(DEP)

clean:
					$(RM) $(OBJS)

echo:
					@echo "srcs : $(SRC)"
					@echo "objs : $(OBJS)"
					@echo "deps : $(DEP)"

fclean:				clean
					$(RM) $(NAME)

re:					fclean all


.PHONY: all clean fclean re
