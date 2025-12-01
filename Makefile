CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic -g --std=c23 -Iinclude

SRC_DIR := src
TEST_DIR := tests
OBJ_DIR := obj
BIN_DIR := bin

LIB_SRCS := $(wildcard $(SRC_DIR)/*.c)
LIB_OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(LIB_SRCS))

TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)
TEST_BINS := $(patsubst $(TEST_DIR)/%.c, $(BIN_DIR)/%, $(TEST_SRCS))

# Default: Build all tests
all: $(TEST_BINS)

# Turn src/%.c into obj/%.o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Turn tests/%.c into bin/%
# NOTE: We depend on $(LIB_OBJS) so the library is compiled first!
$(BIN_DIR)/%: $(TEST_DIR)/%.c $(LIB_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $< $(LIB_OBJS) -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
