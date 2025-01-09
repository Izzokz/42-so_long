NAME = so_long

INITDIR = 000_INIT/
UTILDIR = 100_UTILS/
RANDDIR = 030_FT_RANDOM/

INITSRC = main.c ft_init_imgs.c ft_map_parser.c \
	ft_loop_process.c ft_count_coins.c \
	ft_set_str.c ft_init_game.c ft_init_window.c \
	is_valid_char.c ft_flood_fill.c ft_set_entities.c \
	ft_init_ene_stats.c ft_set_rules.c ft_validate_boss.c
UTILSRC = ft_end.c ft_key_control.c ft_print_map.c \
	ft_move_plr.c ft_delta_time.c ft_super.c \
	ft_collect.c ft_exit_area.c is_complete.c \
	ft_print_stats.c ft_quit_game.c ft_restart.c \
	ft_copy_to_dmap.c ft_print_doors.c ft_unlock_player.c \
	ft_screen_form.c ft_move_enemies.c ft_paint_floor.c \
	ft_update_enemies.c ft_teleport.c ft_boss_action.c \
	ft_click.c
RANDSRC = ft_random.c

PRINTF = 010_FT_PRINTF/libftprintf.a
LIBFT = 020_LIBFT/libft.a
OBJDIR = 666_OBJ/
OBJ = $(patsubst %.c,$(OBJDIR)%.o,$(notdir $(INITSRC) $(UTILSRC) $(RANDSRC)))
DEP = $(patsubst %.c,$(OBJDIR)%.d,$(notdir $(INITSRC) $(UTILSRC) $(RANDSRC)))

MSRC = 200_MANDATORY/main.c 200_MANDATORY/ft_end.c 200_MANDATORY/ft_get_map_data.c 200_MANDATORY/ft_init_game.c 200_MANDATORY/ft_init_imgs.c \
	200_MANDATORY/ft_key_control.c 200_MANDATORY/ft_loop_process.c 200_MANDATORY/ft_set_player.c 200_MANDATORY/ft_move_plr.c \
	200_MANDATORY/ft_print_map.c 200_MANDATORY/is_complete.c 200_MANDATORY/is_valid_char.c 200_MANDATORY/ft_count_coins.c \
	200_MANDATORY/ft_exit_area.c 200_MANDATORY/ft_map_parser.c

MOBJ = $(MSRC:.c=.o)

CCA = cc -Wall -Werror -Wextra -g3 -MP -MMD

TOTAL_FILES = $(words $(OBJ))
PROGRESS = 0
TERM_WIDTH = $(shell tput cols)
BAR_WIDTH = $(shell echo $$(( ($(TERM_WIDTH) - 32) > 60 ? 50 : ($(TERM_WIDTH) - 23) - 10 )))
COLORS = "\033[4;37m\033[4;31m\033[4;32m\033[4;33m\033[4;34m\033[4;35m\033[4;36m\033[1;37m\033[1;31m\033[1;32m\033[1;33m\033[1;34m\033[1;35m\033[1;36m\033[1;90m\033[1;91m\033[1;92m\033[1;93m\033[1;94m\033[1;95m\033[1;96m\033[1;97m"
CHARACTERS = "!?@0&:.%=+"
RESET_COLOR = "\033[0m"

PRINT_PROGRESS:=
define PRINT_PROGRESS
	$(eval PROGRESS := $(shell echo $$(( $(PROGRESS) + 1 ))))
	@BARS=$$(($(PROGRESS) * $(BAR_WIDTH) / $(TOTAL_FILES))); \
	EMPTY=$$(( $(BAR_WIDTH) - $$BARS )); \
	PERCENT=$$(($(PROGRESS) * 100 / $(TOTAL_FILES))); \
	printf "\033[1;32m\033[1mso_long: \033[37mCompiling: \033[1;32m[+ "; \
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

$(NAME): $(PRINTF) $(LIBFT) $(MOBJ)
	@cc -Wall -Werror -Wextra -g3 $(MOBJ) -Lmlx_linux -lmlx_Linux -Lmlx-linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT) $(PRINTF)

bonus: $(PRINTF) $(LIBFT) $(OBJ)
	@$(CCA) $(OBJ) -Lmlx_linux -lmlx_Linux -Lmlx-linux -Imlx_linux -lXext -lX11 -lm -lz -o so_long $(LIBFT) $(PRINTF)
	@printf "\n\033[32m\033[1mso_long: \033[1;97mBuild Complete !\033[0m\n"

mlx:
	@rm -rf mlx-linux
	@git clone git@github.com:42Paris/minilibx-linux.git mlx-linux
	@chmod 0777 mlx-linux/configure
	@cd mlx-linux && ./configure
	@cd ..
	@printf "\033[32m\033[1mso_long: \033[1;37mmlx_linux Set Up !\033[0m\n"

$(PRINTF):
	@$(MAKE) -C 010_FT_PRINTF/

$(LIBFT):
	@$(MAKE) -C 020_LIBFT/

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@printf "\033[32m\033[1mso_long: \033[1;37m666_OBJ/ Generated !\033[0m\n"

$(OBJDIR)%.o: $(INITDIR)%.c | $(OBJDIR)
	@$(CCA) -o $@ -c $<
	$(PRINT_PROGRESS)

$(OBJDIR)%.o: $(UTILDIR)%.c | $(OBJDIR)
	@$(CCA) -o $@ -c $<
	$(PRINT_PROGRESS)

$(OBJDIR)%.o: $(RANDDIR)%.c | $(OBJDIR)
	@$(CCA) -o $@ -c $<
	$(PRINT_PROGRESS)

200_MANDATORY/%.o: 200_MANDATORY/%.c
	@cc -Wall -Werror -Wextra -g3 -I200_MANDATORY/ -c $< -o $@

clean:
	@$(MAKE) clean -C 010_FT_PRINTF/
	@$(MAKE) clean -C 020_LIBFT/
	@rm -f $(OBJ) $(DEP) $(MOBJ)
	@printf "\033[32m\033[1mso_long: \033[1;37m666_OBJ/ Cleaned !\033[0m\n"

fclean:
	@$(MAKE) fclean -C 010_FT_PRINTF/
	@$(MAKE) fclean -C 020_LIBFT/
	@rm -f $(NAME) $(OBJ) $(DEP) $(MOBJ)
	@printf "\033[32m\033[1mso_long: \033[1;37mCleaned !\033[0m\n"

re: fclean all

.PHONY: all clean fclean re bonus mlx

-include $(DEP)
