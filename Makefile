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

.PHONY : test

test :
	# ensure that all the necessary compilers are installed
	gcc --version
	g++ --version
	clang --version
	clang++ --version
	# Test no.0: compilation status 
	gcc   -Wall -Wextra -Werror $(MK_ROOT)tests/00-compile.c -lm && ./a.out ; rm -f a.out
	clang -Wall -Wextra -Werror $(MK_ROOT)tests/00-compile.c -lm && ./a.out ; rm -f a.out

	g++     -Wall -Wextra -Werror $(MK_ROOT)tests/00-compile.cc && ./a.out ; rm -f a.out
	clang++ -Wall -Wextra -Werror $(MK_ROOT)tests/00-compile.cc && ./a.out ; rm -f a.out
	
	# Test no.1: vec2 module
	g++ -Wall -Wextra -Werror $(MK_ROOT)tests/01-vec2.cc -lgtest && ./a.out ; rm -f a.out
	
	# Test no.2: vec3 module
	g++ -Wall -Wextra -Werror $(MK_ROOT)tests/02-vec3.cc -lgtest && ./a.out ; rm -f a.out
	
	# Test no.3: vec4 module
	g++ -Wall -Wextra -Werror $(MK_ROOT)tests/03-vec4.cc -lgtest && ./a.out ; rm -f a.out
	
	# Test no.4: mat2 module
	g++ -Wall -Wextra -Werror $(MK_ROOT)tests/04-mat2.cc -lgtest && ./a.out ; rm -f a.out
	
	# Test no.5: mat3 module
	g++ -Wall -Wextra -Werror $(MK_ROOT)tests/05-mat3.cc -lgtest && ./a.out ; rm -f a.out
	
	# Test no.6: mat4 module
	g++ -Wall -Wextra -Werror $(MK_ROOT)tests/06-mat4.cc -lgtest && ./a.out ; rm -f a.out

# ========
