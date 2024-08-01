OS = $(shell uname -o)
FLAGS = -Wall -Wextra -Werror -std=c++11
FLAGS_FOR_GCOV = -fprofile-arcs -ftest-coverage
FILES_CPP = s21_matrix.cpp
GTEST_LIBS = -lgtest -pthread
GTEST_DIR = /path/to/gtest
TESTS = s21_tests.cpp

ifeq ($(OS), GNU/Linux)
	TEST_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
	TEST_FLAGS = -lcheck -lm -lpthread
endif

all: s21_matrix_oop.a test

clean:
	@rm -rf s21_tests *.gcda *.gcno *.o *.info *.a report gcov valgrind.log

rebuild: clean all

test: s21_matrix_oop.a
	g++ $(FLAGS) $(FLAGS_FOR_GCOV) $(TESTS) -I$(GTEST_DIR)/include -L$(GTEST_DIR)/lib --coverage s21_matrix_oop.a $(GTEST_LIBS) -o s21_tests
	./s21_tests

s21_matrix_oop.a: $(FILES_CPP:.cpp=.o)
	ar rc $@ $^
	ranlib $@

%.o: %.cpp
	g++ $(FLAGS) $(FLAGS_FOR_GCOV) -I$(GTEST_DIR)/include -c $< -o $@

gcov_report: s21_matrix_oop.a
	mkdir -p gcov
	mv s21_*.gcda ./gcov
	mv s21_*.gcno ./gcov
	lcov --ignore-errors usage --ignore-errors inconsistent -t "s21_matrix" -o s21_matrix.info -c -d ./gcov/.
	genhtml -o report ./s21_matrix.info
	rm -rf ./gcov

cl_fri:
	@clang-format -i -style=google *.hpp *.cpp

cl_fr:
	clang-format -n -style=google *.hpp *.cpp

valgrind_check: test
	@CK_FORK=no valgrind --vgdb=no --leak-check=full \
	--show-leak-kinds=all --track-origins=yes --verbose --log-file="valgrind.log" -v --verbose -q --quiet -s ./s21_tests

valgrind: test
	@CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --verbose --read-var-info=yes ./s21_tests

git:
	git add *.c *.h Makefile
	git commit -m "new"
	git push origin develop
