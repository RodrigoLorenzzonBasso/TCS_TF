
# internal flags
CCFLAGS     :=
LDFLAGS     :=

# Extra user flags
EXTRA_LDFLAGS     ?=
EXTRA_CCFLAGS     ?=

ALL_CCFLAGS :=
ALL_CCFLAGS += $(addprefix -Xcompiler ,$(CCFLAGS))
ALL_CCFLAGS += $(addprefix -Xcompiler ,$(EXTRA_CCFLAGS))

ALL_LDFLAGS :=
ALL_LDFLAGS += $(ALL_CCFLAGS)
ALL_LDFLAGS += $(addprefix -Xlinker ,$(LDFLAGS))
ALL_LDFLAGS += $(addprefix -Xlinker ,$(EXTRA_LDFLAGS))

GCCFLAGS = -g -Wall -Wfatal-errors 
GCC = gcc
SANITIZER = -fsanitize=address
CCPCHECKFLAGS = --enable=all --suppress=missingIncludeSystem
GCOVFLAGS = -fprofile-arcs -ftest-coverage

SOURCES = array.c get_opt.c main.c sort.c
TEST_SOURCES = ./test/all_tests.c ./test/TestSort.c ./test/TestSortRunner.c

EXEC = exec

UNITY_ROOT = Unity
UNITY_SRC=$(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  test/TestSort.c \
  test/TestSortRunner.c \
  test/all_tests.c \
  sort.c
UNITY_INC_DIRS = -Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
UNITY_TARGET = all_tests

INPUT1 = -a selection -n 10 -s random
INPUT2 = -a insertion -n 10 -s random
INPUT3 = -a shell -n 10 -s random
INPUT4 = -a quick -n 10 -s random
INPUT5 = -a heap -n 10 -s random
INPUT6 = -a merge -n 10 -s random

.PHONY: clean cppcheck valgrind sanitizer unity

all: clean cppcheck valgrind sanitizer unity
	
cppcheck: $(SOURCES) $(TEST_SOURCES)
	cppcheck $(CPPCHECKFLAGS) --error-exitcode=1 $^

valgrind: $(SOURCES)
	$(GCC) $(ALL_LDFLAGS) $(GCCFLAGS) -o $(EXEC) $^
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT1)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT2)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT3)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT4)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT5)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT6)

sanitizer: $(SOURCES)
	$(GCC) $(GCCFLAGS) $(ALL_LDFLAGS) $(SANITIZER) -o $(EXEC) $^
	./$(EXEC) $(INPUT1)
	./$(EXEC) $(INPUT2)
	./$(EXEC) $(INPUT3)
	./$(EXEC) $(INPUT4)
	./$(EXEC) $(INPUT5)
	./$(EXEC) $(INPUT6)

unity:
	$(GCC) $(GCCFLAGS) $(GCOVFLAGS) $(UNITY_INC_DIRS) $(UNITY_SRC) -o $(UNITY_TARGET)
	./$(UNITY_TARGET) -v
	gcov -b sort.c

app: array.c sort.c get_opt.c main.c
	gcc array.c sort.c get_opt.c main.c -o $@

clean:
	rm -fr app $(EXEC) $(UNITY_TARGET) *.o cov* *.dSYM *.gcda *.gcno *.gcov
