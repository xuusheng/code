# 程序相关部分

OUTPUT	:= mytest
SRCS	:= mytest.cpp tinyxml.cpp tinyxmlparser.cpp tinyxmlerror.cpp tinystr.cpp
DEBUG	:= NO
PROFILE	:= NO
LIBS	:=
INCS	:=
TINYXML_USE_STL := YES

ifeq (YES, ${TINYXML_USE_STL})
  DEFS := -DTIXML_USE_STL
else
  DEFS :=
endif

# 平台相关部分

CC	:= gcc
CXX	:= g++
LD	:= g++
AR	:= ar rc
RANLIB	:= ranlib

# 公共部分

DEBUG_CFLAGS	:= -Wall -Wno-format -g -DDEBUG
RELEASE_CFLAGS	:= -Wall -Wno-unknown-pragmas -Wno-format -O3

DEBUG_CXXFLAGS	:= ${DEBUG_CFLAGS}
RELEASE_CXXFLAGS:= ${RELEASE_CFLAGS}

DEBUG_LDFLAGS	:= -g
RELEASE_LDFLAGS :=

ifeq (YES, ${DEBUG})
	CFLAGS	:= ${DEBUG_CFLAGS}
	CXXFLAGS:= ${DEBUG_CXXFLAGS}
	LDFLAGS	:= ${DEBUG_LDFLAGS}
else
	CFLAGS	:= ${RELEASE_CFLAGS}
	CXXFLAGS:= ${RELEASE_CXXFLAGS}
	LDFLAGS	:= ${RELEASE_LDFLAGS}
endif

ifeq (YES, ${PROFILE})
	CFLAGS	:= ${CFLAGS} -pg -O3
	CXXFLAGS:= ${CXXFLAGS} -pg -O3
	LDFLAGS	:= ${LDFLAGS} -pg
endif

CFLAGS   := ${CFLAGS}   ${DEFS}
CXXFLAGS := ${CXXFLAGS} ${DEFS}

all: ${OUTPUT}

OBJS := $(addsuffix .o,$(basename ${SRCS}))

${OUTPUT}: ${OBJS}
	${LD} -o $@ ${LDFLAGS} ${OBJS} ${LIBS}

%.o : %.cpp
	${CXX} -c ${CXXFLAGS} ${INCS} $< -o $@

%.o : %.c
	${CC} -c ${CFLAGS} ${INCS} $< -o $@

clean:
	-rm -f ${OBJS} ${OUTPUT}
