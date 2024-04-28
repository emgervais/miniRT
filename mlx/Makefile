# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eboyce-n <eboyce-n@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 21:32:49 by W2Wizard          #+#    #+#              #
#    Updated: 2023/02/08 20:57:00 by eboyce-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libmlx42.a
LIB_DIR		:= lib
SRC_DIR		:= src
SHADER_DIR	:= shaders
INCLUDE_DIR	:= include

override HEADERS += -I $(INCLUDE_DIR)

CFLAGS :=	-Wextra -Wall -Werror -Wunreachable-code -Wno-char-subscripts -Wno-sign-compare \
			-DLODEPNG_NO_COMPILE_ANCILLARY_CHUNKS -DLODEPNG_NO_COMPILE_ENCODER
ifdef DEBUG
	CFLAGS += -g
else
	CFLAGS	+= -Ofast -D NDEBUG
endif

# Recursive wildcard/find function, the subst is to guarantee unix file paths
rwildcard = $(subst \,/,$(sort $(foreach d,$(wildcard $1/*),$(call rwildcard,$d,$2) $(wildcard $1/$2))))

SHDR	:= $(call rwildcard,$(SHADER_DIR),default.*)
SHDR	:= $(SHDR:$(SHADER_DIR)/default.%=$(SRC_DIR)/mlx_%_shader.c)
LIB		:= $(call rwildcard,$(LIB_DIR),*.c)
SRCS	:= $(call rwildcard,$(SRC_DIR),*.c)
OBJS	:= $(sort $(patsubst %.c,%.o,$(SRCS) $(LIB) $(SHDR)))
HDRS	:= $(call rwildcard,$(INCLUDE_DIR),*.h)

#//= Make Rules =//#
$(NAME): $(OBJS)
	@ar rc $@ $^

%.o: %.c $(HDRS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

# Convert shaders to .c files
$(SRC_DIR)/mlx_%_shader.c: $(SHADER_DIR)/default.%
	@bash tools/compile_shader.sh $< > $@

clean:
	@rm -f $(OBJS) $(SHDR)

fclean: clean
	@rm -f $(NAME)

#//= Make Rules =//#
all: $(SHDR) $(NAME)

# Run make as part of the recipe to allow for multi-threading to be used (-j)
re: fclean
	@$(MAKE) -e

#//= Misc =//#
.DEFAULT_GOAL := all
.PHONY: all clean fclean re
