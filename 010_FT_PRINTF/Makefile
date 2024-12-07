NAME = libftprintf.a

MAINDIR = 000_MAIN/
UTILDIR = 100_UTILS/
WRITEDIR = 101_WRITE_FORMAT/
ARRAYDIR = 102_ARRAY_PROCESS/

MAINSRC = $(MAINDIR)ft_process.c \
	$(MAINDIR)ft_printf.c
UTILSSRC = $(UTILDIR)ft_getbase.c \
	$(UTILDIR)ft_calloc.c \
	$(UTILDIR)ft_putchar_fd.c \
	$(UTILDIR)ft_putstr_fd.c \
	$(UTILDIR)ft_strlen.c \
	$(UTILDIR)ft_itoa.c \
	$(UTILDIR)ft_strdup.c \
	$(UTILDIR)ft_pow.c
WRITESRC = $(WRITEDIR)ft_write_d.c \
	$(WRITEDIR)ft_write_s.c \
	$(WRITEDIR)ft_write_b.c \
	$(WRITEDIR)ft_write_file.c
ARRAYSRC = $(ARRAYDIR)ft_write_all.c \
	$(ARRAYDIR)ft_process_all.c

OBJDIR = 666_OBJ/
OBJ = $(patsubst %.c,$(OBJDIR)%.o,$(notdir $(MAINSRC) $(UTILSSRC) $(WRITESRC) $(ARRAYSRC)))
DEP = $(patsubst %.c,$(OBJDIR)%.d,$(notdir $(MAINSRC) $(UTILSSRC) $(WRITESRC) $(ARRAYSRC)))
GNLXIO = 010_GNLXIO/gnlxio.a

CCA = cc -Wall -Wextra -Werror -g3 -MP -MMD

TEST = ft_printf.test
TESTMAIN = main.c
TESTMAINO = $(OBJDIR)$(TESTMAIN:.c=.o)

TOTAL_FILES = $(words $(OBJ))
PROGRESS = 0
TERM_WIDTH = $(shell tput cols)
BAR_WIDTH = $(shell echo $$(( ($(TERM_WIDTH) - 30) > 60 ? 50 : ($(TERM_WIDTH) - 23) - 10 )))
COLORS = "\033[4;37m\033[4;31m\033[4;32m\033[4;33m\033[4;34m\033[4;35m\033[4;36m\033[1;37m\033[1;31m\033[1;32m\033[1;33m\033[1;34m\033[1;35m\033[1;36m\033[1;90m\033[1;91m\033[1;92m\033[1;93m\033[1;94m\033[1;95m\033[1;96m\033[1;97m"
CHARACTERS = "!?@0&:.%=+"
RESET_COLOR = "\033[0m"

PRINT_PROGRESS:=
define PRINT_PROGRESS
	$(eval PROGRESS := $(shell echo $$(( $(PROGRESS) + 1 ))))
	@BARS=$$(($(PROGRESS) * $(BAR_WIDTH) / $(TOTAL_FILES))); \
	EMPTY=$$(( $(BAR_WIDTH) - $$BARS )); \
	PERCENT=$$(($(PROGRESS) * 100 / $(TOTAL_FILES))); \
	printf "\033[1;31m\033[1mft_printf: \033[37mCompiling: \033[1;32m[+ "; \
	for i in $$(seq 1 $$BARS); do \
		COLOR=$$(echo $(COLORS) | fold -w 7 | shuf -n 1); \
		CHAR=$$(echo $(CHARACTERS) | fold -w 1 | shuf -n 1); \
		echo -n "\033[0;40m"$$COLOR$$CHAR$(RESET_COLOR); \
	done; \
	for i in $$(seq 1 $$EMPTY); do \
		echo -n " "; \
	done; \
	printf "\033[1;32m +] \033[34m$$PERCENT%%\033[0m\r"
endef

MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(OBJ)
	@ar x $(GNLXIO)
	@ar rc $(NAME) $(OBJ) *.o
	@rm -f *.o
	@printf "\n\033[31m\033[1mft_printf: \033[1;97mBuild Complete !\033[0m\n"

test: $(TESTMAINO) $(NAME)
	@$(CCA) -o $(TEST) $(TESTMAINO) $(NAME)
	@printf "\033[31m\033[1mft_printf: \033[1;37mTEST: OK !\033[0m\n"

$(GNLXIO):
	@$(MAKE) -C 010_GNLXIO/

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@printf "\033[31m\033[1mft_printf: \033[1;37m666_OBJ/ Generated !\033[0m\n"

$(OBJDIR)%.o: $(MAINDIR)%.c | $(OBJDIR) $(GNLXIO)
	@$(CCA) -o $@ -c $<
	$(PRINT_PROGRESS)

$(OBJDIR)%.o: $(UTILDIR)%.c | $(OBJDIR)
	@$(CCA) -o $@ -c $<
	$(PRINT_PROGRESS)

$(OBJDIR)%.o: $(WRITEDIR)%.c | $(OBJDIR)
	@$(CCA) -o $@ -c $<
	$(PRINT_PROGRESS)

$(OBJDIR)%.o: $(ARRAYDIR)%.c | $(OBJDIR)
	@$(CCA) -o $@ -c $<
	$(PRINT_PROGRESS)

$(TESTMAINO): $(TESTMAIN)
	@$(CCA) -o $@ -c $<

clean:
	@$(MAKE) clean -C 010_GNLXIO/
	@rm -f $(OBJ) $(TESTMAINO)
	@printf "\033[31m\033[1mft_printf: \033[1;37m666_OBJ/ Cleaned !\033[0m\n"

fclean:
	@$(MAKE) fclean -C 010_GNLXIO/
	@rm -f $(TEST) $(OBJ) $(TESMAINO) $(NAME)
	@printf "\033[31m\033[1mft_printf: \033[1;37mCleaned !\033[0m\n"

re: fclean
	@$(MAKE)

.PHONY: all clean fclean re test

-include $(DEP)
