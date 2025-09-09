# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: 42 Student <student@42.fr>                +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2024/01/01 00:00:00 by student          #+#    #+#             #
#    Updated: 2024/01/01 00:00:00 by student         ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

# Compiler and flags for strict C++89 compliance
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME		= cpp_module_demo

# Source files
SRCDIR		= .
SOURCES		= main.cpp SampleClass.cpp
OBJECTS		= $(SOURCES:.cpp=.o)

# Header files
HEADERS		= SampleClass.hpp

# Default target
all: $(NAME)

# Compile the program
$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

# Compile object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJECTS)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Test the program
test: $(NAME)
	./$(NAME)

# Check for C++89 compliance issues
check: $(SOURCES) $(HEADERS)
	@echo "Checking for C++89 compliance..."
	@echo "Checking for prohibited C++11+ features..."
	@! grep -n "auto " $(SOURCES) $(HEADERS) || (echo "ERROR: 'auto' keyword found (C++11+)" && exit 1)
	@! grep -n "for.*:" $(SOURCES) $(HEADERS) || (echo "ERROR: Range-based for loop found (C++11+)" && exit 1)
	@! grep -n "lambda" $(SOURCES) $(HEADERS) || (echo "ERROR: Lambda expression found (C++11+)" && exit 1)
	@! grep -n "using namespace" $(SOURCES) $(HEADERS) || (echo "ERROR: 'using namespace' directive found" && exit 1)
	@! grep -n "friend " $(SOURCES) $(HEADERS) || (echo "ERROR: 'friend' keyword found" && exit 1)
	@! grep -n "printf\|malloc\|calloc\|realloc\|free" $(SOURCES) $(HEADERS) || (echo "ERROR: Prohibited C functions found" && exit 1)
	@! grep -n "std::vector\|std::map\|std::list\|std::set" $(SOURCES) $(HEADERS) || (echo "ERROR: STL containers found" && exit 1)
	@echo "✓ C++89 compliance check passed!"

# Phony targets
.PHONY: all clean fclean re test check