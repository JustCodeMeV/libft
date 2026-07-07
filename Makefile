TARGET_EXEC := libft.a

BUILD_DIR := ./build
SRC_DIRS := .
CFLAGS := -c -Wall -Wextra -Werror -g

SRCS := $(shell find $(SRC_DIRS) -name '*.c')

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

INC_DIRS := ./include
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	ar -rcs $@ $^
	mv ./build/libft.a ./libft.a

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


fclean:
	rm -r $(BUILD_DIR)
	rm ./libft.a

-include $(DEPS)

.PHONY: fclean