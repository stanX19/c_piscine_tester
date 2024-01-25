
UNITTEST_DIR	= ../CUnitTest
UNITTEST_LIB	= $(UNITTEST_DIR)/unittest.a

NAME		= C04tester
IFLAGS		= -I. -I$(UNITTEST_DIR)/headers

CC			= g++
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3 -std=c++17

shell_fmt: $(UNITTEST_LIB)
	$(CC) $(CFLAGS) $(IFLAGS) findShellFormat.cpp $(UNITTEST_LIB) && ./a.out && rm a.out

$(UNITTEST_LIB):
	@make --directory=$(UNITTEST_DIR) all
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"