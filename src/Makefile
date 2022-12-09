CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
LDFLAGS=
PROFILE_FLAGS=-fprofile-arcs -ftest-coverage
LIBSOURCES=s21_string.c s21_sscanf.c s21_sprintf.c
LIBOBJECTS=$(LIBSOURCES:.c=.o)
OS:=$(shell uname)

ifeq ($(OS), Linux)
	CHECKFLAGS=-lcheck -lm -lpthread -lrt -lsubunit
else
	CHECKFLAGS=-lcheck -lm -lpthread
endif

# get example from: https://www.ccs.neu.edu/home/skotthe/classes/cs5600/fall/2015/labs/intro-check.html

all: s21_string.a gcov_report

s21_string.a: $(LIBOBJECTS)
	ar -crs s21_string.a $(LIBOBJECTS)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

test_telega: s21_string.a
	gcc -std=c11 $(CHECKFLAGS) sscanf_tests.c s21_string.a -o unit-test
	./unit-test

test: s21_string.a
	$(CC) $(CFLAGS) $(CHECKFLAGS) $(LDFLAGS) s21_string.a tests.c -o run
	./run

gcov_report:
	gcc --coverage -lcheck $(LIBSOURCES) tests.c -o ./gcov
	./gcov
	lcov -t "./gcov" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html

valgrind:
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBSOURCES) tests_valgrind.c -o vtests_run
	sh valgrind.sh ./vtests_run

docker_test:
	sh ./run.sh

rebuild: clean all

clean:
	rm -rf *.o \
		*.a \
		*.so \
		*.gcno \
		*gcda \
		*.gcov \
		gcov_report.* \
		*.dSYM \
        RESULT_VALGRIND.txt \
        unit-test \
        vtests_run \
		run \
		gcov \
		report/ \
		report.info
