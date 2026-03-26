#if !defined (_mat2_hpp_)
# define _mat2_hpp_ 1
#
# if defined (__cplusplus)

extern "C" {

# endif
#
# include "./mat2.h"
#
# if defined (__cplusplus)

}

inline mat2 operator + (mat2 a, mat2 b) {
    return (mat2Add(a, b));
}


inline mat2 operator - (mat2 a, mat2 b) {
    return (mat2Sub(a, b));
}


inline mat2 operator * (mat2 a, mat2 b) {
    return (mat2Mul(a, b));
}


inline mat2 operator * (mat2 m, float f) {
    return (mat2Mulf(m, f));
}


inline vec2 operator * (mat2 m, vec2 v) {
    return (mat2Mulv(m, v));
}


inline mat2 &operator += (mat2 &a, mat2 b) {
    a = mat2Add(a, b);
    return (a);
}


inline mat2 &operator -= (mat2 &a, mat2 b) {
    a = mat2Sub(a, b);
    return (a);
}


inline mat2 &operator *= (mat2 &a, mat2 b) {
    a = mat2Mul(a, b);
    return (a);
}

# endif /* __cplusplus */
#endif /* _mat2_hpp_ */
