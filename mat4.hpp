#if !defined (_mat4_hpp_)
# define _mat4_hpp_ 1
#
# if defined (__cplusplus)
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */

extern "C" {

# endif
#
# include "./mat4.h"
#
# if defined (__cplusplus)

}

# endif /* __cplusplus */

typedef union u_vec4 vec4;

inline mat4 operator + (mat4, mat4);

inline mat4 operator - (mat4, mat4);

inline mat4 operator * (mat4, mat4);

inline mat4 operator * (mat4, float);

inline vec4 operator * (mat4, vec4);

inline mat4 &operator += (mat4 &, mat4);

inline mat4 &operator -= (mat4 &, mat4);

inline mat4 &operator *= (mat4 &, mat4);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include "./vec4.hpp"

inline mat4 operator + (mat4 a, mat4 b) {
    return (mat4add(a, b));
}


inline mat4 operator - (mat4 a, mat4 b) {
    return (mat4sub(a, b));
}


inline mat4 operator * (mat4 a, mat4 b) {
    return (mat4mul(a, b));
}


inline mat4 operator * (mat4 m, float f) {
    return (mat4mulf(m, f));
}


inline vec4 operator * (mat4 m, vec4 v) {
    return (mat4mulv(m, v));
}


inline mat4 &operator += (mat4 &a, mat4 b) {
    a = mat4add(a, b);
    return (a);
}


inline mat4 &operator -= (mat4 &a, mat4 b) {
    a = mat4sub(a, b);
    return (a);
}


inline mat4 &operator *= (mat4 &a, mat4 b) {
    a = mat4mul(a, b);
    return (a);
}

# endif /* __cplusplus */
#endif /* _mat4_hpp_ */
