#  targets all, clean, test, s21_matrix.a, gcov_report

CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11

BUILD_NAME = s21_matrix.a
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)


TEST = test
TEST_SRC = $(wildcard test_src/*.c) 
ifeq ($(shell uname),Linux)
    LINUX_TEST = -lcheck -lsubunit -lm
else
    LINUX_TEST = # macOS
endif

GCOV = -fprofile-arcs -ftest-coverage
# FVALGRING = -s --tool=memcheck  --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes
FVALGRIND = -s --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=definite --errors-for-leak-kinds=definite --summary-only=yes

FSANITIZE = -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=unreachable

all: rebuild

$(BUILD_NAME): $(OBJECTS)
	@ar rcs $(BUILD_NAME) $(OBJECTS)
	@ranlib $@

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf *.o *.a *.gcno *.gcda *.gcov *.out *.info $(BUILD_NAME) $(TEST) matrix
	@rm -rf report *.txt

rebuild: clean style $(BUILD_NAME)

test: rebuild
	@$(CC) $(FLAGS) $(TEST_SRC) $(BUILD_NAME) $(LINUX_TEST) -o $(TEST)
	@./$(TEST)
	@make clean 

gcov_report: rebuild
	@$(CC) $(FLAGS) $(GCOV) $(SOURCES) $(TEST_SRC) $(LINUX_TEST) -o $(TEST)
	@./$(TEST)
	@lcov -t "s21_matrix" -o s21_matrix.info -c -d .
	@genhtml -o report s21_matrix.info

	# ----------------------------- #
	
open_report:
	firefox report/index.html

style_check:
	clang-format -style=Google -n *.h $(SOURCES) $(TEST_SRC) test_src/*.h for_fun/*.c

style:
	@clang-format -style=Google -i *.h $(SOURCES) $(TEST_SRC) test_src/*.h for_fun/*.c

valgrind: rebuild
	$(CC) -g $(FLAGS) $(TEST_SRC) $(BUILD_NAME) $(LINUX_TEST) -o $(TEST)
	valgrind $(FVALGRING) ./$(TEST) > valgrind_output.txt 2>&1

sanitize: rebuild
	$(CC) -g $(FLAGS) $(TEST_SRC) $(BUILD_NAME) $(LINUX_TEST) $(FSANITIZE) -o $(TEST)
	./$(TEST) > sanitize_output.txt 2> sanitize_error.txt


fun: for_fun/matrix.c
	$(CC) -o matrix for_fun/matrix.c -lrt
	./matrix