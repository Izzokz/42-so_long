NAME = gnlxio.a

MAINDIR = 000_MAIN/
UTILDIR = 100_UTILS/

MAINSRC = $(MAINDIR)get_next_line.c \
	$(MAINDIR)ft_readlines.c \
	$(MAINDIR)ft_deline.c \
	$(MAINDIR)ft_rewrite_file.c \
	$(MAINDIR)ft_get_line.c \
	$(MAINDIR)ft_readfile.c \
	$(MAINDIR)ft_replace.c \
	$(MAINDIR)ft_input.c \
	$(MAINDIR)ft_gen_file.c \
	$(MAINDIR)ft_add_line.c \
	$(MAINDIR)ft_split_file.c
UTILSSRC = $(UTILDIR)gnlxio_ft_strdup.c \
	$(UTILDIR)gnlxio_ft_putstr_fd.c \
	$(UTILDIR)get_next_line_utils.c \
	$(UTILDIR)ft_free_rlines.c \
	$(UTILDIR)ft_len.c \
	$(UTILDIR)ft_fix_lineno.c \
	$(UTILDIR)gnlxio_ft_strnstr.c \
	$(UTILDIR)gnlxio_ft_strcmp.c \
	$(UTILDIR)ft_rlines_dup.c \
	$(UTILDIR)ft_rlines_cutendl.c \
	$(UTILDIR)invalid_rlines.c \
	$(UTILDIR)invalid_slines.c \
	$(UTILDIR)ft_trunc.c \
	$(UTILDIR)ft_realloc_rlines.c \
	$(UTILDIR)ft_split_rlines.c \
	$(UTILDIR)gnlxio_ft_split.c

OBJDIR = 666_OBJ/
OBJ = $(patsubst %.c,$(OBJDIR)%.o,$(notdir $(MAINSRC) $(UTILSSRC)))
DEP = $(patsubst %.c,$(OBJDIR)%.d,$(notdir $(MAINSRC) $(UTILSSRC)))

CCA = cc -Wall -Wextra -Werror -g3 -MP -MMD

TOTAL_FILES = $(words $(OBJ))
PROGRESS = 0
TERM_WIDTH = $(shell tput cols)
BAR_WIDTH = $(shell echo $$(( ($(TERM_WIDTH) - 30) > 60 ? 50 : ($(TERM_WIDTH) - 20) - 10 )))
COLORS = "\033[4;30m\033[4;31m\033[4;32m\033[4;33m\033[4;34m\033[4;35m\033[4;36m\033[1;30m\033[1;31m\033[1;32m\033[1;33m\033[1;34m\033[1;35m\033[1;36m\033[1;90m\033[1;91m\033[1;92m\033[1;93m\033[1;94m\033[1;95m\033[1;96m\033[1;97m"
CHARACTERS = "!?@0&:.%=+"
RESET_COLOR = "\033[0m"

PRINT_PROGRESS:=
define PRINT_PROGRESS
	$(eval PROGRESS := $(shell echo $$(( $(PROGRESS) + 1 ))))
	@BARS=$$(($(PROGRESS) * $(BAR_WIDTH) / $(TOTAL_FILES))); \
	EMPTY=$$(( $(BAR_WIDTH) - $$BARS )); \
	PERCENT=$$(($(PROGRESS) * 100 / $(TOTAL_FILES))); \
	printf "\033[1;36m\033[1mGNLXIO: \033[37mCompiling: \033[1;32m[+ "; \
	for i in $$(seq 1 $$BARS); do \
		COLOR=$$(echo $(COLORS) | fold -w 7 | shuf -n 1); \
		CHAR=$$(echo $(CHARACTERS) | fold -w 1 | shuf -n 1); \
		echo -n "\033[0;47m"$$COLOR$$CHAR$(RESET_COLOR); \
	done; \
	for i in $$(seq 1 $$EMPTY); do \
		echo -n " "; \
	done; \
	printf "\033[1;32m +] \033[34m$$PERCENT%%\033[0m\r"
endef

MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(OBJ)
	$(eval PROGRESS := 0)
	@ar -rc $(NAME) $(OBJ)
	@printf "\n\033[36m\033[1mGNLXIO: \033[1;97mBuild Complete !\033[0m\n"

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@printf "\033[36m\033[1mGNLXIO: \033[1;37m666_OBJ/ Generated !\033[0m\n"

$(OBJDIR)%.o: $(MAINDIR)%.c | $(OBJDIR)
	@$(CCA) -o $@ -c $<
	$(PRINT_PROGRESS)

$(OBJDIR)%.o: $(UTILDIR)%.c | $(OBJDIR)
	@$(CCA) -o $@ -c $<
	$(PRINT_PROGRESS)

clean:
	@rm -f $(OBJ)
	@printf "\033[36m\033[1mGNLXIO: \033[37m666_OBJ/ Cleaned !\033[0m\n"

fclean:
	@rm -f $(OBJ) $(NAME)
	@printf "\033[36m\033[1mGNLXIO: \033[37mCleaned !\033[0m\n"

re: fclean
	@$(MAKE)

.PHONY: all clean fclean re

-include $(DEP)
