#Colors------------------------------------------------------------
#\033[38;2;255;0;0m 38;2 indicates 24-bit color mode.
#                   255;0;0 amount of red, green, and blue
CYAN = \033[0;96m
ORANGE = \033[38;2;255;146;3m
RED = \033[38;2;255;0;0m
GREEN = \033[38;2;0;255;0m
RESET = \033[0m
#------------------------------------------------------------------

#Emojis-------------------------
EMOJI_HAPPY := \xF0\x9F\x98\x83
EMOJI_SAD := \xF0\x9F\x98\xA2
EMOJI_CELEBRATE := \xF0\x9F\x8E\x89
EMOJI_CLOCK := \xE2\x8F\xB0
CLEANING_TOOL := \xF0\x9F\xA7\xBD
#--------------------------------


# Binary name
NAME = cub3d

# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -I includes/ -I libft/includes/ #-I./mlx
# MLX_FLAGS :=  -L./mlx -lmlx -framework OpenGL -framework AppKit

# Folders & files
HEADER = cub3d.h
FILES = map_parse map_parse2 textures_parse structures_management main#add more files here 
LIBFT = -L libft -lft

#timing
TIMER = sleep 0.5

# Source files
SRC = $(addsuffix .c, $(addprefix srcs/, $(FILES)))

# Object files
OBJ = $(SRC:c=o)

all: $(NAME)
                                                                                                                                                            
$(NAME): $(OBJ)
	@echo "$(EMOJI_CLOCK)$(ORANGE)Compiling libft...$(RESET)"
	@make -C libft/
	@echo "$(EMOJI_CLOCK)$(ORANGE)Compiling cub3d...$(RESET)"
	@$(TIMER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(GNL)
	@echo "$(EMOJI_HAPPY)$(GREEN)DONE ✓✓$(RESET)"
	@echo "$(CYAN)$$HEADER$(RESET)"
	@echo "\n"

%.o: %.c
	@echo "$(ORANGE)Generating cub3d objects... $@$(RESET)"
	@$(TIMER)
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "$(RESET)$(ORANGE)Cleaning libft...$(RESET)"
	@make clean -C libft/
	@echo "$(RESET)$(ORANGE)$(CLEANING_TOOL)Cleaning binaries...$(RESET)"
	@rm -f $(OBJ)
	@echo "$(RESET)$(GREEN)CLEANED ✓✓$(RESET)"

fclean:
	@echo "$(RESET)$(ORANGE)$(CLEANING_TOOL)Cleaning object files from libft...$(RESET)"
	@make fclean -C libft/
	@echo "$(RESET)$(ORANGE)$(CLEANING_TOOL)Cleaning object files...$(RESET)"
	@$(TIMER)
	@rm -f $(OBJ)
	@echo "$(RESET)$(ORANGE)$(CLEANING_TOOL)Cleaning executable...$(RESET)"
	@$(TIMER)
	@rm -f $(NAME)
	@$(TIMER)
	@echo "$(RESET)$(GREEN)ALL CLEANED ✓✓$(RESET)"

re: fclean all

norm:
	@echo "$(CYAN)\nChecking norm for $(NAME)...$(RESET)\n"
	@norminette $(SRC) includes/ && echo "$(EMOJI_HAPPY)$(GREEN)Norm check passed!$(RESET)$(EMOJI_CELEBRATE)" || echo "$(EMOJI_SAD)$(RED)Norm check failed!$(RESET)$(EMOJI_SAD)"
	@echo "$(CYAN)\nChecking norm for LIBFT...$(RESET)\n"
	@norminette libft/ && echo "$(EMOJI_HAPPY)$(GREEN)Norm check passed!$(RESET)$(EMOJI_CELEBRATE)" || echo "$(EMOJI_SAD)$(RED)Norm check failed!$(RESET)$(EMOJI_SAD)"

.PHONY: clean fclean re test norm


define HEADER
                                                               
	                                    .--,-``-.                  
	  ,----..                          /   /     '.      ,---,     
	 /   /   \                ,---,   / ../        ;   .'  .' `\   
	|   :     :         ,--,,---.'|   \ ``\  .`-    ',---.'     \  
	.   |  ;. /       ,'_ /||   | :    \___\/   \   :|   |  .`\  | 
	.   ; /--`   .--. |  | ::   : :         \   :   |:   : |  '  | 
	;   | ;    ,'_ /| :  . |:     |,-.      /  /   / |   ' '  ;  : 
	|   : |    |  ' | |  . .|   : '  |      \  \   \ '   | ;  .  | 
	.   | '___ |  | ' |  | ||   |  / :  ___ /   :   ||   | :  |  ' 
	'   ; : .'|:  | : ;  ; |'   : |: | /   /\   /   :'   : | /  ;  
	'   | '/  :'  :  `--'   \   | '/ :/ ,,/  ',-    .|   | '` ,/   
	|   :    / :  ,      .-./   :    |\ ''\        ; ;   :  .'     
	 \   \ .'   `--`----'   /    \  /  \   \     .'  |   ,.'       
	  `---`                 `-'----'    `--`-,,-'    '---'      

endef
export HEADER
