# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
AR = ar
ARFLAGS = rcs

# Каталоги
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
LIB_DIR = lib

# Файлы
SOURCES = $(SRC_DIR)/employee.c
OBJECTS = $(BUILD_DIR)/employee.o
LIBRARY = $(LIB_DIR)/libemployee.a
TARGET = program

# Цель по умолчанию
all: $(BUILD_DIR) $(LIB_DIR) $(LIBRARY) $(TARGET)

# Создание каталогов
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

# Компиляция объектного файла
$(BUILD_DIR)/employee.o: $(SOURCES) $(INCLUDE_DIR)/employee.h
	$(CC) $(CFLAGS) -c $< -o $@

# Создание статической библиотеки
$(LIBRARY): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

# Сборка исполняемого файла
$(TARGET): main.c $(LIBRARY)
	$(CC) $(CFLAGS) main.c -L$(LIB_DIR) -lemployee -o $@

# Очистка
clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR) $(TARGET)

.PHONY: all clean