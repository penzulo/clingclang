CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic -g --std=c23 -Iinclude

SRC_DIR := src
TEST_DIR := tests
OBJ_DIR := obj
BIN_DIR := bin

LIB_SRCS := $(shell find $(SRC_DIR) -name '*.c')
LIB_OBJS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(LIB_SRCS)))

TEST_SRCS := $(shell find $(TEST_DIR) -name '*.c')
TEST_BINS := $(patsubst %.c, $(BIN_DIR)/%, $(notdir $(TEST_SRCS)))

SRC_SUBDIRS := $(shell find $(SRC_DIR) -type d)
TEST_SUBDIRS := $(shell find $(TEST_DIR) -type d)

vpath %.c $(SRC_SUBDIRS) $(TEST_SUBDIRS)

# Default: Build all tests
all: $(TEST_BINS)

# Turn src/%.c into obj/%.o
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/%: %.c $(LIB_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $< $(LIB_OBJS) -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

list:
	@echo "Library Sources: $(LIB_SRCS)"
	@echo "Library Objects: $(LIB_OBJS)"
	@echo "Test Sources:    $(TEST_SRCS)"
	@echo "Test Binaries:   $(TEST_BINS)"
	@echo "VPATH Paths:     $(SRC_SUBDIRS) $(TEST_SUBDIRS)"

.PHONY: all clean list
