
########################
# Initialize directory constants
########################

INCLUDE=-Iinclude
SRC_DIR=src

TEST_DIR=test

BIN=bin

DEPS_DIR = depend

########################
# Find source files
########################

HEADERS := $(shell find . -type f -name "*.h" )

#SRCS := $(shell find $(SRC_DIR) -type f -name "*.cpp" )
SRCS :=
OBJS := $(addprefix $(BIN)/,$(SRCS:.cpp=.o))
DEPS := $(addprefix $(DEPS_DIR)/,$(SRCS:.cpp=.d))


########################
# Test settings
########################

#find the src files in the test directory
TEST_SRCS := $(shell find $(TEST_DIR) -type f -name "*.cpp")
#$(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS=$(addprefix $(BIN)/,$(TEST_SRCS:.cpp=.o))

TEST_MAIN=$(TEST_DIR)run_tests.cpp
TEST_EXE=$(BIN)/run_test.out

DEPS += $(addprefix $(DEPS_DIR)/,$(TEST_SRCS:.cpp=.d))

########################
# Compiler settings
########################
CXX=g++
CXXFLAGS= -Wall -Wextra -pthread -std=c++14 -O3 
CXXFLAGS += $(INCLUDE)

LDFLAGS := -lblas -lgtest

#INCL_GTEST= $(foreach incl,$(GTEST_INCLUDE),-I$(incl))

########################
# Build targets
########################

.PHONY: test runtest clean $(DEPS_DIR)

test: $(TEST_EXE)

runtest: $(TEST_EXE)
	./$(TEST_EXE)

clean:
	rm -r -f $(BIN)
	rm -r -f $(DEPS_DIR)

$(TEST_EXE): $(OBJS) $(TEST_OBJS) $(GTEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $(TEST_EXE)

$(BIN)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DEPS_DIR)/%.d: %.cpp
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -MF $@ -MT"$@" -MT"$(BIN)/$(<:.cpp=.o)" -MP -MM $<


$(DEPS_DIR): $(DEPS)
	@:

sinclude $(DEPS)

#depend: .depend

#.depend: $(TEST_SRCS)
#	rm -f ./.depend
#	$(CXX) $(INCL) $(INCL_GTEST) -MM $^ > ./.depend

#sinclude .depend
