NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memmove.c ft_memchr.c ft_strchr.c ft_memcmp.c ft_toupper.c ft_tolower.c ft_strrchr.c ft_strncmp.c \
	ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

CCA = cc -Werror -Wextra -Wall -g3

TOTAL_FILES = $(words $(OBJ))
PROGRESS = 0
TERM_WIDTH = $(shell tput cols)
BAR_WIDTH = $(shell echo $$(( ($(TERM_WIDTH) - 30) > 60 ? 50 : ($(TERM_WIDTH) - 19) - 10 )))
COLORS = "\033[4;30m\033[4;31m\033[4;32m\033[4;33m\033[4;34m\033[4;37m\033[4;36m\033[1;30m\033[1;31m\033[1;32m\033[1;33m\033[1;34m\033[1;37m\033[1;36m\033[1;90m\033[1;91m\033[1;92m\033[1;93m\033[1;94m\033[1;95m\033[1;96m\033[1;97m"
CHARACTERS = "!?@0&:.%=+"
RESET_COLOR = "\033[0m"

PRINT_PROGRESS:=
define PRINT_PROGRESS
	$(eval PROGRESS := $(shell echo $$(( $(PROGRESS) + 1 ))))
	@BARS=$$(($(PROGRESS) * $(BAR_WIDTH) / $(TOTAL_FILES))); \
	EMPTY=$$(( $(BAR_WIDTH) - $$BARS )); \
	PERCENT=$$(($(PROGRESS) * 100 / $(TOTAL_FILES))); \
	printf "\033[1;35m\033[1mlibft: \033[37mCompiling: \033[1;32m[+ "; \
	for i in $$(seq 1 $$BARS); do \
		COLOR=$$(echo $(COLORS) | fold -w 7 | shuf -n 1); \
		CHAR=$$(echo $(CHARACTERS) | fold -w 1 | shuf -n 1); \
		echo -n "\033[0;45m"$$COLOR$$CHAR$(RESET_COLOR); \
	done; \
	for i in $$(seq 1 $$EMPTY); do \
		echo -n " "; \
	done; \
	printf "\033[1;32m +] \033[34m$$PERCENT%%\033[0m\r"
endef

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@printf "\n\033[35m\033[1mlibft: \033[1;97mBuild Complete !\033[0m\n"

%.o: %.c
	@$(CCA) -o $@ -c $<
	$(PRINT_PROGRESS)

clean:
	@rm -f $(OBJ) $(BOBJ)
	@printf "\033[35m\033[1mlibft: \033[37mObjects Cleaned !\033[0m\n"

fclean:
	@rm -f $(OBJ) $(BOBJ) $(NAME)
	@printf "\033[35m\033[1mlibft: \033[37mCleaned !\033[0m\n"

re: fclean all

.PHONY: all clean fclean re bonus
