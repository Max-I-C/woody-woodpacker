NAME	= infected_prog
NAME_P  = obj/elf/injecter 

CC		= cc
CFLAGS	= 
LFLAGS	= -g3
OBJDIR				= obj
SOURCE_PARASITE		= srcs/injecter/elf.c
OBJECTS_PARASITE	= $(SOURCE_PARASITE:%.c=$(OBJDIR)/%.o)
SOURCE_PROG			= srcs/infected/main.c
OBJECTS_PROG		= $(SOURCE_PROG:%.c=$(OBJDIR)/%.o)

RM		= rm -rf


RED=\033[0;31m
GREEN=\033[0;32m

all: $(NAME) link

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

$(NAME): assembly prog injecter injection

injection: 
	./$(NAME_P) $(NAME)
	@echo "infected_prog"

prog: $(OBJECTS_PROG)
	@$(CC) $(LFLAGS) $(OBJECTS_PROG) -o $(NAME)

injecter: $(OBJECTS_PARASITE)
	mkdir -p obj/elf
	@$(CC) $(LFLAGS) $(OBJECTS_PARASITE) -o $(NAME_P)

assembly:
	mkdir -p obj/assembly 
	nasm -f bin -o obj/assembly/handler_test.bin srcs/assembly/handler.s
	nasm -f bin -o obj/assembly/virus_test.bin srcs/assembly/virus.s

clean:
	@$(RM) $(OBJDIR)
	@echo "Object files removed"

fclean: clean
	@$(RM) $(NAME) $(NAME_P)
	@echo "DELETED"

test:
	$(NAME)
	@echo "$(GREEN)[OK]"

re: fclean all

.PHONY: all clean fclean re link test