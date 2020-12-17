TARGET ?= engine
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(addsuffix .o,$(basename $(SRCS)))
LDLIBS = -lSDL2 -lSDL2_image -lSDL2_ttf

CPPFLAGS ?= -Wall -Werror -lSDL2 -lSDL2_image -lSDL2_ttf

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@ $(LOADLIBS) $(LDLIBS)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS)  */*.d */*/*.d

