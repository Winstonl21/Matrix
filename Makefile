NAME := s21_matrix.a
HEADER := s21_matrix.h
HEADER_TEST := tests/tests_suite.h #нужен отдельно main и все фаилы со стрингов
SRC_TEST := main.c \
			create_tests_matrix.c \
			eq_tests.c \
			sum_tests.c \
			sub_tests.c \
			mult_number_tests.c \
			mult_matrix_tests.c \
			transpose_tests.c \
			determinant_tests.c \
			calc_tests.c \
			inverse_tests.c

SRC_TEST := $(addprefix tests/, $(SRC_TEST))
REPORT := GcovReport

CC := gcc
GCOVFLAGS := -fprofile-arcs -ftest-coverage
CFLAGS := -std=c11 -Wall -Werror -Wextra -g #-fsanitize=leak -fsanitize=address
TEST := test 

OS = $(shell uname) #команда для определения типо операционной системы
ifeq ($(OS),Darwin) #нужно провериь на мак, как подставляются флаги
	CHECK_FLAGS := -lcheck
else
	CHECK_FLAGS := -lcheck -lpthread -lrt -lm -lsubunit
endif

ifeq ($(OS),Linux)
    LEAKS := valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
endif
ifeq ($(OS),Darwin)
    LEAKS := leaks --atExit -- ./test
endif

SRCS := s21_matrix.c
		
OBJS := $(SRCS:.c=.o)

.PHONY: clean gcov_report test

all: s21_matrix.a

s21_matrix.a: $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

test: clean $(NAME) $(SRC_TEST)
	echo $(OS)
	$(CC) $(CFLAGS) $(SRC_TEST) $(NAME) $(CHECK_FLAGS) -o $(TEST)
	./$(TEST)

lint: $(SRC_TEST) $(SRCS) $(HEADER) $(HEADER_TEST) 
	clang-format -i $^

check: clean $(NAME) $(SRC_TEST)
	clang-format -n *.c *.h */*.h */*.c
	cppcheck --enable=all --force --suppress=missingIncludeSystem *.h *.c */*.c */*.h
	$(CC) $(CFLAGS) $(SRC_TEST) $(NAME) $(CHECK_FLAGS) -o $(TEST)
	$(LEAKS)

gcov_report: $(SRC_TEST) $(SRCS)
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(SRC_TEST) $(SRCS) $(CHECK_FLAGS) -o $(REPORT)
	chmod +x *
	./GcovReport
	lcov -t "$(REPORT)" -o $(REPORT).info -c -d .
	genhtml -o report $(REPORT).info
	rm -rf ./*.gcno ./*.gcda ./$(REPORT).*s
ifeq ($(OS),Darwin)
 	open ./report/index.html
else
	xdg-open ./report/index.html
endif

rebuild: clean all

clean: 
	rm -rf report GcovReport GcovReport.info *.o *.a *.gcno *.gcda test
