CC = g++
CPPFLAGS = -lgtest -lgtest_main -std=c++17 -pthread
CHECKFLAGS = -Wall -Werror -Wextra

all: clean test

test: clean
	@$(CC) $(CHECKFLAGS) tests/tests.cc modules/*.cc -o $@ $(CPPFLAGS) && ./test

clean:
	@rm -f */*.o
	@rm -f *.gc*
	@rm -f ./test
	@rm -f .DS_Store
	@rm -f *.a
	@rm -rf test.dSYM
	@rm -rf ../archive_calc/
	@rm -rf ../build/
	@rm -f *.info
	@rm -f *.filtered
	@rm -rf out

	@rm -rf ./gcov_report
style:
	@clang-format -style=Google -n controllers/*.h modules/*.h modules/*.cc view/*.h view/*.cc

clang:
	@clang-format -style=Google -i controllers/*.h modules/*.h modules/*.cc view/*.h view/*.cc

install: uninstall
	@cd ../ && mkdir -p build
	@cd ../src/view && qmake && make && make clean && rm -rf Makefile  && mv view.app ../../build
	@cp -R ../build/view.app ~/Desktop/view.app

uninstall:
	@rm -rf ../build
	@rm -rf ~/Desktop/view.app

dvi:
	@open description.html

dist: 
	@rm -rf ../archive_calc/
	@mkdir ../archive_calc/
	@mkdir ../archive_calc/src/
	@mv ../build/view.app ../archive_calc/src/
	@tar cvzf ../archive_calc.tgz -C ../archive_calc/ .
	@rm -rf ../archive_calc/
	
gcov_report: clean
	@$(CC) --coverage tests/tests.cc modules/modelcalculator.cc ${CPPFLAGS} ${CHECKFLAGS} ${LIBS} -o gcov_report
	@./gcov_report
	@lcov -c -d . -o coverage.info --rc lcov_branch_coverage=1 --ignore-errors mismatch -t "all_check"
	@lcov --rc lcov_branch_coverage=1 -e coverage.info 'tests/tests.cc' 'modules/modelcalculator.cc' -o coverage.info.filtered
	@genhtml coverage.info.filtered --output-directory out

ifeq ($(shell uname), Linux)
	@xdg-open out/index.html
else ifeq ($(shell uname), Darwin)
	@open out/index.html
endif
leaks: clean
	@$(CC) $(CHECKFLAGS) tests/tests.cc modules/*.cc -o test $(CPPFLAGS)
	@leaks -atExit -- ./test

valgrind: 
	@$(CC) $(CHECKFLAGS) tests/tests.cc modules/*.cc -o test $(CPPFLAGS)
	@CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test

docker:
	@docker build . -t set:1.1 -f ./Dockerfile
	@docker run --rm -it --name set_test set:1.1

.PHONY: all clang leaks install gcov_report valgrind docker clean uninstall
