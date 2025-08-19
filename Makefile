CXX      := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -pedantic -MMD -MP
LDFLAGS  := 
TARGET   := program
SRC      := main.cc solver.cc
OBJ      := $(SRC:.cc=.o)
DEP      := $(OBJ:.o=.d)

.PHONY: all clean run debug release

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

debug: CXXFLAGS := -std=c++17 -g -O0 -Wall -Wextra -pedantic -MMD -MP
debug: clean all

release: CXXFLAGS := -std=c++17 -O3 -DNDEBUG -Wall -Wextra -pedantic -MMD -MP
release: clean all

clean:
	$(RM) $(OBJ) $(DEP) $(TARGET)

-include $(DEP)
