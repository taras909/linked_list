
CC=gcc

CUR_PATH := $(shell pwd)
SRC_DIR:= $(CUR_PATH)/src
BUILD_DIR:= $(CUR_PATH)/build

all: $(SRC_DIR)/main.c $(SRC_DIR)/list.c
	@mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/app $(SRC_DIR)/main.c $(SRC_DIR)/list.c

clean: 
	@rm -rf $(BUILD_DIR)
