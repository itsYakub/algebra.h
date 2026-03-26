#if !defined (_mat4_hpp_)
# define _mat4_hpp_ 1
#
# if defined (__cplusplus)

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
    return (mat4Add(a, b));
}


inline mat4 operator - (mat4 a, mat4 b) {
    return (mat4Sub(a, b));
}


inline mat4 operator * (mat4 a, mat4 b) {
    return (mat4Mul(a, b));
}


inline mat4 operator * (mat4 m, float f) {
    return (mat4Mulf(m, f));
}


inline vec4 operator * (mat4 m, vec4 v) {
    return (mat4Mulv(m, v));
}


inline mat4 &operator += (mat4 &a, mat4 b) {
    a = mat4Add(a, b);
    return (a);
}


inline mat4 &operator -= (mat4 &a, mat4 b) {
    a = mat4Sub(a, b);
    return (a);
}


inline mat4 &operator *= (mat4 &a, mat4 b) {
    a = mat4Mul(a, b);
    return (a);
}

# endif /* __cplusplus */
#endif /* _mat4_hpp_ */
