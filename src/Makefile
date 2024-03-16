NAME := s21_matrix.a
HEADER := s21_matrix.h
HEADER_TEST := tests/tests_suite.h
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
CFLAGS := -std=c11 -Wall -Werror -Wextra -g 
TEST := test 

CHECK_FLAGS := -lcheck #-lpthread -lrt -lm -lsubunit
LEAKS := leaks --atExit -- ./test

SRCS := s21_matrix.c
		
OBJS := $(SRCS:.c=.o)

.PHONY: clean gcov_report test

all: s21_matrix.a

s21_matrix.a: $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

test: clean $(NAME) $(SRC_TEST)
	$(CC) $(CFLAGS) $(SRC_TEST) $(NAME) $(CHECK_FLAGS) -o $(TEST)
	./$(TEST)

lint: $(SRC_TEST) $(SRCS) $(HEADER) $(HEADER_TEST) 
	clang-format -i $^

check: clean $(NAME) $(SRC_TEST)
	clang-format -n *.c *.h */*.h */*.c
	cppcheck --enable=all --force --suppress=missingIncludeSystem *.h *.c */*.c */*.h
	$(CC) $(CFLAGS) $(SRC_TEST) $(NAME) $(CHECK_FLAGS) -o $(TEST)
	$(shell $(LEAKS))

gcov_report: $(SRC_TEST) $(SRCS)
	$(CC) $(CFLAGS) $(SRC_TEST) $(GCOVFLAGS) $(SRCS) $(CHECK_FLAGS) -o $(REPORT)
	chmod +x *
	./GcovReport
	lcov -t "$(REPORT)" -o $(REPORT).info -c -d .
	genhtml -o report $(REPORT).info
	rm -rf ./*.gcno ./*.gcda ./$(REPORT).*s

open_report: 
	open ./report/index.html

rebuild: 
	$(MAKE) clean
	$(MAKE) all

clean: 
	rm -rf report GcovReport GcovReport.info *.o *.a *.gcno *.gcda test
