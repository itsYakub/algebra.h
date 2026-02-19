# ========

MK_ROOT		= $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
MK_NAME		= algebra

# ========

MODULES		= $(MK_ROOT)algebra.h 	\
			  $(MK_ROOT)algebra.hpp \
			  $(MK_ROOT)vec2.h 		\
			  $(MK_ROOT)vec2.hpp 	\

# ========

.PHONY : all

all : install

.PHONY : install

install :
	mkdir -p /usr/local/include/$(MK_NAME)/
	cp -f $(MODULES) /usr/local/include/$(MK_NAME)/

.PHONY : remove

remove :
	rm -rf /usr/local/include/$(MK_NAME)

# ========
