TARGET ?= engine
SRC_DIRS ?= ./src ./example
CXX=clang++

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(addsuffix .o,$(basename $(SRCS)))

LDLIBS = -lSDL2 -lSDL2_image -lSDL2_ttf

CPPFLAGS ?= -Wall -Werror -Iinclude/

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@ $(LOADLIBS) $(LDLIBS)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS)

