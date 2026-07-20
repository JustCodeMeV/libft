NAME        := libft.a

BUILD_DIR   := build
SRC_DIRS    := .
CC          := cc
CFLAGS      := -Wall -Wextra -Werror

SRCS        := $(wildcard $(SRC_DIRS)/*.c)
OBJS        := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re