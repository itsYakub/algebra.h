<div align="center">

# algebra.h - header-only linear algebra library for C/C++

</div>

`algebra.h` is a header-only linear algebra library written for C/C++.
It collects common algebraic data types with friendly and easy-to-use interface.
`algebra.h` target specification versions are C99 and C++98.

## Usage

`algebra.h` can be included to the project either by cloning this repository or by using an installed intance of the library.
To start working with `algebra.h` clone this repository to your project:
```tty
$ cd /path/to/your/project/
$ git clone https://github.com/itsYakub/algebra.h.git algebra
```

That's it, you can now start working with all the `algebra.h` provides!

*NOTE: all the components of the library are position-dependent; all the components must be present in the root of the library.*

To compile the program with the library include `algebra.h` with the `ALGEBRA_IMPLEMENTATION` macro:
```c
/* ... */

#define ALGEBRA_IMPLEMENTATION
#include "algebra/algebra.h"

/* ... */
```

...accordingly, for C++ implementation:
```cpp
/* ... */

#define ALGEBRA_IMPLEMENTATION
#include "algebra/algebra.hpp"

/* ... */
```

...or if you want to copile just the specific parts of the library:
```c
/* ... */

#define ALGEBRA_IMPLEMENTATION
#include "algebra/vec2.h" /* include vec2's declarations and definitions... */
#include "algebra/mat3.h" /* include mat3's declarations and definitions... */

/* ... */
```

Lastly, you can install the library simply by running:
```
$ cd /path/to/your/project/algebra

# install the library on the root-level at '/usr/local/include/algebra'
$ sudo make install
```

## Licence

This project is licenced under [LGPL-3 Licence](./LICENCE).
