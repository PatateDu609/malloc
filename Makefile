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

CFLAGS				:=	-Wall -Werror -Wextra $(PATH_INC) -g
LDFLAGS				:=	-shared -fPIC -g

BASENAME			:=	main.c

SRC 				:=	$(addprefix $(PATH_SRC)/, $(BASENAME))
OBJS 				:=	$(addprefix $(PATH_OBJS)/, $(BASENAME:%.c=%.o))
DEP 				:=	$(addprefix $(PATH_OBJS)/, $(BASENAME:%.c=%.d))

$(PATH_OBJS)/%.o:	$(PATH_SRC)/%.c
					@echo "Compiling $(subst objs/,,$@)..."
					$(MKDIR) $(dir $@)
					$(CC) $(CFLAGS) -MMD -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJS)
					@echo "Creating shared library"
					$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

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
