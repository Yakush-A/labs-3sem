# Компилятор и флаги
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -g

# Имя исполняемого файла
TARGET = main

# Исходные файлы
SRCS = main.cpp matrix.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = matrix.h

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Компиляция main.cpp
main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c main.cpp

# Компиляция matrix.cpp
matrix.o: matrix.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c matrix.cpp

# Очистка
clean:
	rm -f $(TARGET) $(OBJS)

# Пересборка
rebuild: clean all

# Файлы для пересборки при изменении заголовков
$(OBJS): $(HEADERS)

.PHONY: all clean rebuild