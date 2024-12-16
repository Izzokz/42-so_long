NAME = so_long

INITDIR = 000_INIT/
UTILDIR = 100_UTILS/
RANDDIR = 030_FT_RANDOM/

INITSRC = main.c ft_init_imgs.c ft_map_parser.c \
	ft_loop_process.c ft_count_coins.c \
	ft_set_str.c ft_init_game.c ft_init_window.c \
	is_valid_char.c ft_flood_fill.c ft_set_entities.c
UTILSRC = ft_end.c ft_key_control.c ft_print_map.c \
	ft_move_plr.c ft_delta_time.c ft_super.c \
	ft_collect.c ft_exit_area.c is_complete.c \
	ft_print_stats.c ft_quit_game.c ft_restart.c \
	ft_copy_to_dmap.c ft_print_doors.c ft_unlock_player.c \
	ft_screen_form.c ft_move_enemies.c ft_paint_floor.c
RANDSRC = ft_random.c

LIB = 010_FT_PRINTF/libftprintf.a 020_LIBFT/libft.a
OBJDIR = 666_OBJ/
OBJ = $(patsubst %.c,$(OBJDIR)%.o,$(notdir $(INITSRC) $(UTILSRC) $(RANDSRC)))
DEP = $(patsubst %.c,$(OBJDIR)%.d,$(notdir $(INITSRC) $(UTILSRC) $(RANDSRC)))

CCA = cc -Wall -Werror -Wextra -g3 -MP -MMD -g

MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C 010_FT_PRINTF/
	$(MAKE) -C 020_LIBFT/
	$(CCA) $(OBJ) -Lmlx_linux -lmlx_Linux -Lmlx-linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIB)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(INITDIR)%.c | $(OBJDIR)
	@$(CCA) -o $@ -c $<

$(OBJDIR)%.o: $(UTILDIR)%.c | $(OBJDIR)
	@$(CCA) -o $@ -c $<

$(OBJDIR)%.o: $(RANDDIR)%.c | $(OBJDIR)
	@$(CCA) -o $@ -c $<

%.o: %.c
	$(CCA) -Imlx_linux -O3 -o $@ -c $<

clean:
	$(MAKE) clean -C 010_FT_PRINTF/
	$(MAKE) clean -C 020_LIBFT/
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C 010_FT_PRINTF/
	$(MAKE) fclean -C 020_LIBFT/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
