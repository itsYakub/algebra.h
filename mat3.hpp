#if !defined (_mat3_hpp_)
# define _mat3_hpp_ 1
#
# if defined (__cplusplus)

extern "C" {

# endif
#
# include "./mat3.h"
#
# if defined (__cplusplus)

}

# endif /* __cplusplus */

typedef union u_vec3 vec3;

inline mat3 operator + (mat3, mat3);

inline mat3 operator - (mat3, mat3);

inline mat3 operator * (mat3, mat3);

inline mat3 operator * (mat3, float);

inline vec3 operator * (mat3, vec3);

inline mat3 &operator += (mat3 &, mat3);

inline mat3 &operator -= (mat3 &, mat3);

inline mat3 &operator *= (mat3 &, mat3);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include "./vec3.hpp"

inline mat3 operator + (mat3 a, mat3 b) {
    return (mat3Add(a, b));
}


inline mat3 operator - (mat3 a, mat3 b) {
    return (mat3Sub(a, b));
}


inline mat3 operator * (mat3 a, mat3 b) {
    return (mat3Mul(a, b));
}


inline mat3 operator * (mat3 m, float f) {
    return (mat3Mulf(m, f));
}


inline vec3 operator * (mat3 m, vec3 v) {
    return (mat3Mulv(m, v));
}


inline mat3 &operator += (mat3 &a, mat3 b) {
    a = mat3Add(a, b);
    return (a);
}


inline mat3 &operator -= (mat3 &a, mat3 b) {
    a = mat3Sub(a, b);
    return (a);
}


inline mat3 &operator *= (mat3 &a, mat3 b) {
    a = mat3Mul(a, b);
    return (a);
}

# endif /* __cplusplus */
#endif /* _mat3_hpp_ */
