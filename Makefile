CC = gcc
CFLAGS = -g -Wall -std=c11

all: lisp
lisp: lisp.c main.c
	$(CC) $(CFLAGS) -o lisp lisp.c main.c

.PHONY: clean
clean:
	rm -f lisp test_lisp *~ core

.PHONY: format
format:
	clang-format -i -style=Google *.c *.h

CHECK_MAJOR = 0.14
CHECK_MINOR = 0
CHECK_INCLUDE = /usr/local/include
CHECK_LIB_DIR = /usr/local/lib
CHECK_CFLAGS = -I$(CHECK_INCLUDE)

.PHONY: test
test: test_lisp.c lisp.c
	$(CC) $(CFLAGS) $(CHECK_CFLAGS) -o test_lisp test_lisp.c lisp.c -L$(CHECK_LIB_DIR) -lcheck -DCHECK_MAJOR_VERSION=$(CHECK_MAJOR) -DCHECK_MINOR_VERSION=$(CHECK_MINOR)
	export LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):/usr/local/lib && ./test_lisp
