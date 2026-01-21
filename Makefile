NAME				= infected_prog
NAME_P				= obj/elf/injecter 

CC					= cc
CFLAGS				= 
LFLAGS				= -g3
RM					= rm -rf

OBJDIR				= obj
SOURCE_PARASITE		= srcs/injecter/elf.c srcs/injecter/elf_init.c srcs/injecter/elf_injecter.c srcs/injecter/elf_utils.c
OBJECTS_PARASITE	= $(SOURCE_PARASITE:%.c=$(OBJDIR)/%.o)
SOURCE_PROG			= srcs/infected/main.c
OBJECTS_PROG		= $(SOURCE_PROG:%.c=$(OBJDIR)/%.o)

RED=\033[0;31m
GREEN=\033[0;32m

all: $(NAME) link

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): assembly prog injecter injection

assembly:
	@mkdir -p obj/assembly 
	@nasm -f bin -o obj/assembly/handler_test.bin srcs/assembly/handler.s
	@nasm -f bin -o obj/assembly/virus_test.bin srcs/assembly/virus.s

prog: $(OBJECTS_PROG)
	@$(CC) $(LFLAGS) $(OBJECTS_PROG) -o $(NAME)

injecter: $(OBJECTS_PARASITE)
	@make --no-print-directory -C srcs/injecter/libft
	@echo "[Libft compiled ✅]\n"
	@mkdir -p obj/elf
	@$(CC) $(LFLAGS) $(OBJECTS_PARASITE) srcs/injecter/libft/libft.a -o $(NAME_P)

injection: 
	./$(NAME_P) $(NAME)
	@echo "\n[injection program executed ✅]"

test:
	$(NAME)
	@echo "$(GREEN)[OK]"

clean:
	@$(RM) $(OBJDIR)
	@make clean --no-print-directory -C srcs/injecter/libft
	@echo "\n[Object files removed ✅]"

fclean: clean
	@$(RM) $(NAME) $(NAME_P)
	@make fclean --no-print-directory -C srcs/injecter/libft
	@echo "\n[Project cleaned ✅]"

re: fclean all

.PHONY: all clean fclean re link test