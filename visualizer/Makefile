# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/17 19:16:02 by bbeldame          #+#    #+#              #
#    Updated: 2017/07/01 17:57:46 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./visualiser
FLAGS = -Wall -Wextra # -Werror TODO: UNCOMMENT THIS
LIBFTA = libft.a
LIBFTDIR = ./libft
OBJDIR = ./obj/
INCDIR = ./includes
SRCDIR = ./srcs/
SRCS_NAME = main.c
OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))
LIBFT = $(addprefix $(LIBFTDIR)/,$(LIBFTA))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

SRCS = $(addprefix $(SRCDIR),$(SRCS_NAME))

all: $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@gcc $(FLAGS) -I $(INCDIR) -I $(LIBFTDIR) -o $@ -c $<

$(LIBFT):
	@make -C $(LIBFTDIR)

$(NAME): $(LIBFT) obj $(OBJS)
	@gcc $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)--------Visualiser compiled-------$(NC)"

norme:
	@norminette includes srcs

clean:
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFTDIR)

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)
	@echo "$(GREEN)---Visualiser removed completely--$(NC)"

re: fclean all
