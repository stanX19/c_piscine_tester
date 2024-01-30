SRCDIR		= srcs
SRCS		= $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(SRCDIR)/*/*.cpp)
HEADER_DIR	= headers
HEADERS		= $(wildcard $(HEADER_DIR)/*.hpp)
OBJDIR		= objs
OBJDIRS		= $(sort $(dir $(OBJS)))
OBJS		= $(subst $(SRCDIR),$(OBJDIR),$(subst .cpp,.o,$(SRCS)))

UNITTEST_DIR	= ../CUnitTest
UNITTEST_LIB	= $(UNITTEST_DIR)/unittest.a

NAME		= C07tester
IFLAGS		= -I. -I$(HEADER_DIR) -I$(UNITTEST_DIR)/headers
CC			= g++
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3 -std=c++17

UP			= \033[1A
FLUSH		= \033[2K
RM			= rm -rf

ARGV		= C07 -fd

all: $(UNITTEST_LIB) $(NAME)
#	./$(NAME) $(ARGV)

$(NAME): $(UNITTEST_LIB) $(OBJDIRS) $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(UNITTEST_LIB) -o $(NAME)
	@echo "$(UP)$(FLUSH)$(UP)"

$(UNITTEST_LIB):
	@make --directory=$(UNITTEST_DIR) all
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"

$(OBJDIRS):
	mkdir -p $@
	@echo "$(UP)$(FLUSH)$(UP)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)"

clean:
	@find . -name "temp*" -type f -delete
	@$(RM) $(OBJDIR)

fclean: clean
	@make --directory=$(UNITTEST_DIR) fclean
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"
	@$(RM) $(NAME)
	@$(RM) ./a.out

re: fclean all

.PHONY: all clean fclean re $(UNITTEST_LIB)
