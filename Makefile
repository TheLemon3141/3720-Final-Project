CXX=g++
CXXFLAGS= -std=c++17 -g -fprofile-arcs -ftest-coverage

OATPP_INCLUDE_LIB = /usr/local/include/oatpp-1.3.0/oatpp
OATPP_INCLUDE = -I src -I $(OATPP_INCLUDE_LIB)

LINKFLAGS_LOCAL = -L /usr/local/lib/oatpp-1.3.0
LINKFLAGS_APP =  $(LINKFLAGS_LOCAL) -loatpp
LINKFLAGS_TEST = $(LINKFLAGS_APP) -loatpp-test

# Added include directory variables
INC_DIR_MODEL = include/model
INC_DIR_CONTROLLER = include/controller
INC_DIR_VIEW = include/view

SRC_DIR = src
SRC_DIR_SERVER = src/server
SRC_DIR_DTO = src/dto
SRC_DIR_CONTROLLER = src/controller
SRC_DIR_MODEL = src/model
SRC_DIR_VIEW = src/view

SRC_DIR_TESTS = test
SRC_DIR_TESTS_ENDPOINT = test/endpoint

GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage

STATIC_ANALYSIS = cppcheck

STYLE_CHECK = cpplint

PROGRAM_SERVER = gameServer
TEST_SERVER = testServer

.PHONY: all
all: $(PROGRAM_SERVER) coverage docs style #static

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean-gcov
clean-gov:
	rm -rf *.gcov *.gcda *.gcno

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o $(TEST_SRC)/*.o *.gcov *.gcda *.gcno \
	$(COVERAGE_RESULTS) \
	$(PROGRAM_SERVER) \
	$(TEST_SERVER) \
	$(COVERAGE_DIR) \
	doxygen/html \
	obj bin \

# Replaced SRC_DIR_SERVICE with MODEL and VIEW, added INC directory vars
$(PROGRAM_SERVER): $(SRC_DIR_SERVER) $(SRC_DIR_MODEL) $(SRC_DIR_VIEW) $(SRC_DIR_CONTROLLER)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_SERVER) $(OATPP_INCLUDE) \
	$(SRC_DIR_SERVER)/*.cpp \
	$(SRC_DIR_DTO)/*.hpp \
	$(SRC_DIR_CONTROLLER)/* \
	$(INC_DIR_CONTROLLER)/*.hpp \
	src/model/*.cpp \
	src/view/*.cpp \
	$(INC_DIR_MODEL)/*.hpp \
	$(INC_DIR_VIEW)/*.hpp \
	$(LINKFLAGS_APP)

# Deleted SRC_DIR_SERVICE CIRCLE,
$(TEST_SERVER): $(SRC_DIR_TESTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OATPP_INCLUDE) \
	$(SRC_DIR_TESTS_ENDPOINT)/*.cpp \
	$(SRC_DIR_CONTROLLER)/* \
	$(INC_DIR_CONTROLLER)/*.hpp \
	$(SRC_DIR_TESTS)/app/* \
	src/model/*.cpp \
	src/view/*.cpp \
	$(INC_DIR_MODEL)/*.hpp \
	$(INC_DIR_VIEW)/*.hpp \
	$(LINKFLAGS_TEST)

# This will need to modified from "shaperest" to whatever our docker is called
docker:
	docker build --pull --rm -f "Dockerfile" -t shaperest:latest "."

start:
	docker compose -f "compose.yml" up -d --build

stop:
	docker compose -f "compose.yml" down

# I have no idea what "SRC_INCLUDE" is. It's not set up earlier in file.
style: ${SRC_DIR_SERVICE} ${SRC_INCLUDE}
	${STYLE_CHECK} src/controller/* src/dto/* src/server/* src/service/*/* src/test/*/* src/test/*.cpp

# static doesn't exist yet

# To perform the code coverage checks
.PHONY: coverage
coverage: ${TEST_SERVER}
	./${TEST_SERVER}
	# Determine code coverage
	${LCOV} --capture --gcov-tool ${GCOV} --directory . --output-file \
	${COVERAGE_RESULTS} --rc lcov_branch_coverage=1
# Only show code coverage for the source code files (not library files)
	${LCOV} --extract ${COVERAGE_RESULTS} */${SRC_DIR}/* -o ${COVERAGE_RESULTS}
	#Generate the HTML reports
	genhtml ${COVERAGE_RESULTS} --output-directory ${COVERAGE_DIR}
	#Remove all of the generated files from gcov
	make clean-gcov
