<div align="center">

# algebra.h - header-only linear algebra library for C/C++

</div>

`algebra.h` is a header-only linear algebra library written for C/C++.
It collects common algebraic data types with friendly and easy-to-use interface.
`algebra.h` target specification versions are C99 and C++11.

## Usage

`algebra.h` can be included to the project either by cloning this repository or by using an installed intance of the library.
To start working with `algebra.h` clone this repository to your project:
```tty
$ cd /path/to/your/project/
$ git clone https://github.com/itsYakub/algebra.h.git algebra
```

Library is constructed in the following way:
```
algebra.h/
├── type/
│   ├── mat2.h
│   ├── mat2.hpp
│   ├── mat3.h
│   ├── mat3.hpp
│   ├── mat4.h
│   ├── mat4.hpp
│   ├── vec2.h
│   ├── vec2.hpp
│   ├── vec3.h
│   ├── vec3.hpp
│   ├── vec4.h
│   └── vec4.hpp
│
├── algebra-fwd.hpp
├── algebra.h
├── algebra.hpp
├── utils.h
├── utils.hpp
├── mat2.h
├── mat2.hpp
├── mat3.h
├── mat3.hpp
├── mat4.h
├── mat4.hpp
├── vec2.h
├── vec2.hpp
├── vec3.h
├── vec3.hpp
├── vec4.h
└── vec4.hpp
```
`type/` directory contains all the type definitions available in `algebra.h`. They're just bare-bones definitions, without any functions, constructors, methods etc.
By that you should be able to just copy-and-paste `type/` directory into your project and provide your own implementations, API etc.
But if you'd like to use standard-defined functions, you should look into repo's root directory.

For C modules, you should look for the `.h` header files.
Correspondingly, `.hpp` header files are reserved for C++.

By design you should be able to use C modules without C++ and vice versa, C++ modules without C.
Only difference is for the `utils` module which is actually commedy gold.

Header-only design forces us to work with macro-definitions to provide implementation for each module.
To do that, you should provide `ALGEBRA_IMPLEMENTATION` definition:
```
#define ALGEBRA_IMPLEMENTATION
#include "algebra/algebra.h"

/* ... */
```

*NOTE:
This can be defined only once. Otherwise, multiple definition to the same function can cause complation errors*

Lastly, you can install the library globally onto your system.
`Makefile` provide several rules for handling such cases:
```tty
# install library globally...
# this installs algebra.h into /usr/local/include ...
$ sudo make install

# and to remove the library...
$ sudo make remove
```

## Resources

Resources used in this project:
- [Nvidia Developer Docs: stdlib index](https://developer.nvidia.com/w/cg/index_stdlib.html)

## Licence

This project is licenced under [LGPL-3 Licence](./LICENCE).
