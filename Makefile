# ========

MK_ROOT		= $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
MK_NAME		= algebra

# ========

MODULES		= $(MK_ROOT)algebra.h 	\
			  $(MK_ROOT)algebra.hpp \
			  $(MK_ROOT)vec2.h 		\
			  $(MK_ROOT)vec2.hpp 	\
			  $(MK_ROOT)vec3.h 		\
			  $(MK_ROOT)vec3.hpp 	\
			  $(MK_ROOT)vec4.h 		\
			  $(MK_ROOT)vec4.hpp	\
			  $(MK_ROOT)mat2.h 		\
			  $(MK_ROOT)mat2.hpp 	\
			  $(MK_ROOT)mat3.h 		\
			  $(MK_ROOT)mat3.hpp 	\
			  $(MK_ROOT)mat4.h 		\
			  $(MK_ROOT)mat4.hpp	\
			  $(MK_ROOT)utils.h 	\
			  $(MK_ROOT)utils.hpp

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
