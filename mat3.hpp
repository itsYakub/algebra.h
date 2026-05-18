#if !defined (_mat3_hpp_)
# define _mat3_hpp_ 1
#
# if defined (__cplusplus)
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */

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
    return (mat3add(a, b));
}


inline mat3 operator - (mat3 a, mat3 b) {
    return (mat3sub(a, b));
}


inline mat3 operator * (mat3 a, mat3 b) {
    return (mat3mul(a, b));
}


inline mat3 operator * (mat3 m, float f) {
    return (mat3mulf(m, f));
}


inline vec3 operator * (mat3 m, vec3 v) {
    return (mat3mulv(m, v));
}


inline mat3 &operator += (mat3 &a, mat3 b) {
    a = mat3add(a, b);
    return (a);
}


inline mat3 &operator -= (mat3 &a, mat3 b) {
    a = mat3sub(a, b);
    return (a);
}


inline mat3 &operator *= (mat3 &a, mat3 b) {
    a = mat3mul(a, b);
    return (a);
}

# endif /* __cplusplus */
#endif /* _mat3_hpp_ */
