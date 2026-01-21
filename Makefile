NAME				= infected_prog
NAME_P				= obj/elf/injecter 

CC					= cc
CFLAGS				= 
LFLAGS				= -g3
RM					= rm -rf

OBJDIR				= obj
SOURCE_PARASITE		= srcs/injecter/elf.c
OBJECTS_PARASITE	= $(SOURCE_PARASITE:%.c=$(OBJDIR)/%.o)
SOURCE_PROG			= srcs/infected/main.c
OBJECTS_PROG		= $(SOURCE_PROG:%.c=$(OBJDIR)/%.o)

RED=\033[0;31m
GREEN=\033[0;32m

all: $(NAME) link

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

$(NAME): assembly prog injecter injection

assembly:
	mkdir -p obj/assembly 
	nasm -f bin -o obj/assembly/handler_test.bin srcs/assembly/handler.s
	nasm -f bin -o obj/assembly/virus_test.bin srcs/assembly/virus.s

prog: $(OBJECTS_PROG)
	@$(CC) $(LFLAGS) $(OBJECTS_PROG) -o $(NAME)

injecter: $(OBJECTS_PARASITE)
	cd srcs/injecter/libft && make
	mkdir -p obj/elf
	@$(CC) $(LFLAGS) $(OBJECTS_PARASITE) srcs/injecter/libft/libft.a -o $(NAME_P)

injection: 
	./$(NAME_P) $(NAME)
	@echo "infected_prog"

test:
	$(NAME)
	@echo "$(GREEN)[OK]"

clean:
	@$(RM) $(OBJDIR)
	@cd srcs/injecter/libft && make clean
	@echo "Object files removed"

fclean: clean
	@$(RM) $(NAME) $(NAME_P)
	@cd srcs/injecter/libft && make fclean
	@echo "DELETED"

re: fclean all

.PHONY: all clean fclean re link test