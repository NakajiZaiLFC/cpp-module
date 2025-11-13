NAME := account
CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98 -pedantic
FILE :=	tests.cpp \
		Account.cpp
OBJDIR := obj

OBJ := $(addprefix $(OBJDIR)/, $(FILE:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run:
	$(MAKE) re
	./$(NAME)

.PHONY: re clean fclean all run
