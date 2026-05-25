<div align="center">

# algebra.h - header-only linear algebra library for C/C++

</div>

`algebra.h` is a header-only linear algebra library written for C/C++.

`algebra.h` aggregates common linear algebra data types and operations.

`algebra.h` target specification versions are C99 and C++11.

## Usage

`algebra.h` can be included to the project either by cloning this repository or by using an installed intance of the library.


To start working with `algebra.h` clone this repository:

```tty
$ git clone https://github.com/itsYakub/algebra.h.git algebra
```


Structure of library is as follows:

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
├── vec4.hpp
└── Makefile
```

Core library elements are placed in the root directory.

Data types are defined in the `type/` directory.

Library comes with `Makefile` file for working with library:
- building.
- installing system-wide.
- removing system-wide.

Library is conducted of both `.h` and `.hpp` files:
- `.h` - C language modules.
- `.hpp` - C++ language modules.

The aim of this project is to provide both C and C++ interface that does not require any linking between them.

## Configuration

**Header-only** nature of `algebra.h` allows user to configure it using compile-time preprocessor definitions:

- `#define ALGEBRA_IMPLEMENTATION`:
Mandatory definition used to include function definitions of the library.
It must be defined only once before the header file inclusion:

```c
#define ALGEBRA_IMPLEMENTATION
#include "algebra/vec2.h"       /* include module directly... */
#include "algebra/algebra.h"    /* or include the whole library... */
```

*Note:
If you declare ALGEBRA_IMPLEMENTATION more than once, it can cause multiple-definitions compilation error.*


## Resources

Resources used in this project:
- [Nvidia Developer Docs: stdlib index](https://developer.nvidia.com/w/cg/index_stdlib.html)

## Licence

This project is licenced under [LGPL-3 Licence](./LICENCE).
