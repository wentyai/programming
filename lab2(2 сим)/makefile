CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
AR = ar
ARFLAGS = rcs

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
LIB_DIR = lib

SOURCES = $(SRC_DIR)/employee.c
OBJECTS = $(BUILD_DIR)/employee.o
LIBRARY = $(LIB_DIR)/libemployee.a
TARGET = program

all: $(BUILD_DIR) $(LIB_DIR) $(LIBRARY) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(BUILD_DIR)/employee.o: $(SOURCES) $(INCLUDE_DIR)/employee.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBRARY): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

$(TARGET): main.c $(LIBRARY)
	$(CC) $(CFLAGS) main.c -L$(LIB_DIR) -lemployee -o $@


clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR) $(TARGET)

.PHONY: all clean