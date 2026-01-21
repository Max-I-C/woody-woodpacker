SRC			= ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp ft_strlen ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_striteri ft_strlcat ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd

SRC_B		= ft_lstlast_bonus ft_lstnew_bonus ft_lstiter_bonus ft_lstadd_front_bonus ft_lstdelone_bonus ft_lstclear_bonus ft_lstadd_back_bonus ft_lstsize_bonus ft_lstmap_bonus 

SRCS		= $(addsuffix .c, ${SRC})

SRCS_B		= $(addsuffix .c, ${SRC_B})

HEAD		= ./includes/ 

OBJS		= ${SRCS:.c=.o}

OBJS_B		= ${SRCS_B:.c=.o}

NAME		= libft.a

CC			= gcc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} $(NAME)


re:			fclean all

bonus:		${OBJS_B}
			${AR} ${NAME} ${OBJS_B}
			${RN} ${NAME}

