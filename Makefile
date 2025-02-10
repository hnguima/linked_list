PROJECT_DIR := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
BUILD_DIR := $(PROJECT_DIR)/build
TEST_DIR := $(PROJECT_DIR)/test

clean: 
	rm -rf build

clean_test:
	rm -rf test/build

build: clean
	mkdir build
	cd build && gcc -Wall -Wconversion -Werror -Wpedantic -fsanitize=address $(PROJECT_DIR)/*.c -o linkedList -I$(PROJECT_DIR)/*
	$(PROJECT_DIR)/build/linkedList


test: clean_test $(TEST_DIR)/test_linkedList.c linkedList.c
	mkdir test/build
	$(CC) -Wall -Wconversion -Werror -Wpedantic -fsanitize=address -I$(TEST_DIR) -o $(TEST_DIR)/build/linkedList $(TEST_DIR)/test_linkedList.c $(PROJECT_DIR)/linkedList.c $(TEST_DIR)/unity.c 
	$(TEST_DIR)/build/linkedList