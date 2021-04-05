TARGET ?= engine
SRC_DIRS ?= ./src ./example

CXX=clang++
LD=ld.lld
ROOT=sudo
SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(addsuffix .o,$(basename $(SRCS)))

LIB_FILES := $(shell find src -name *.cpp)
LIB_OBJS := $(addsuffix .o,$(basename $(LIB_FILES)))

LDLIBS = -lSDL2 -lSDL2_image -lSDL2_ttf

CPPFLAGS ?= -std=c++17 -Wall -Werror -Iinclude/ -fPIC

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@ $(LOADLIBS) $(LDLIBS)

libpear.so: $(LIB_OBJS)	
	 $(CXX) $(LDFLAGS) $(LIB_OBJS) -shared -o $@ $(LOADLIBS) $(LDLIBS)

install: libpear.so
	$(ROOT) cp libpear.so /usr/lib64/
	$(ROOT) mkdir /usr/include/Pear
	$(ROOT) cp -r include/* /usr/include/Pear
uninstall:
	$(ROOT) rm -rf /usr/lib64/libpear.so
	$(ROOT) rm -rf /usr/include/Pear
.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS)

