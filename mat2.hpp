#if !defined (_mat2_hpp_)
# define _mat2_hpp_ 1
#
# if defined (__cplusplus)
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */

extern "C" {

# endif
#
# include "./mat2.h"
#
# if defined (__cplusplus)

}

# endif /* __cplusplus */

typedef union u_vec2 vec2;

inline mat2 operator + (mat2, mat2);

inline mat2 operator - (mat2, mat2);

inline mat2 operator * (mat2, mat2);

inline mat2 operator * (mat2, float);

inline vec2 operator * (mat2, vec2);

inline mat2 &operator += (mat2 &, mat2);

inline mat2 &operator -= (mat2 &, mat2);

inline mat2 &operator *= (mat2 &, mat2);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include "./vec2.hpp"

inline mat2 operator + (mat2 a, mat2 b) {
    return (mat2add(a, b));
}


inline mat2 operator - (mat2 a, mat2 b) {
    return (mat2sub(a, b));
}


inline mat2 operator * (mat2 a, mat2 b) {
    return (mat2mul(a, b));
}


inline mat2 operator * (mat2 m, float f) {
    return (mat2mulf(m, f));
}


inline vec2 operator * (mat2 m, vec2 v) {
    return (mat2mulv(m, v));
}


inline mat2 &operator += (mat2 &a, mat2 b) {
    a = mat2add(a, b);
    return (a);
}


inline mat2 &operator -= (mat2 &a, mat2 b) {
    a = mat2sub(a, b);
    return (a);
}


inline mat2 &operator *= (mat2 &a, mat2 b) {
    a = mat2mul(a, b);
    return (a);
}

# endif /* __cplusplus */
#endif /* _mat2_hpp_ */
