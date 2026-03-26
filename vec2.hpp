#if !defined (_vec2_hpp_)
# define _vec2_hpp_ 1
#
# if defined (__cplusplus)

extern "C" {

# endif
#
# include "./vec2.h"
#
# if defined (__cplusplus)

}

# endif /* __cplusplus */

typedef union u_mat2 mat2;

inline vec2 operator + (vec2, vec2);

inline vec2 operator - (vec2, vec2);

inline vec2 operator * (vec2, vec2);

inline vec2 operator / (vec2, vec2);

inline vec2 operator + (vec2, float);

inline vec2 operator - (vec2, float);

inline vec2 operator * (vec2, float);

inline vec2 operator / (vec2, float);

inline vec2 operator * (vec2, mat2);

inline bool operator == (vec2, vec2);

inline bool operator != (vec2, vec2);

inline bool operator > (vec2, vec2);

inline bool operator >= (vec2, vec2);

inline bool operator < (vec2, vec2);

inline bool operator <= (vec2, vec2);

inline vec2 &operator += (vec2 &, vec2);

inline vec2 &operator -= (vec2 &, vec2);

inline vec2 &operator *= (vec2 &, vec2);

inline vec2 &operator /= (vec2 &, vec2);

inline vec2 &operator += (vec2 &, float);

inline vec2 &operator -= (vec2 &, float);

inline vec2 &operator *= (vec2 &, float);

inline vec2 &operator /= (vec2 &, float);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include "./mat2.hpp"

inline vec2 operator + (vec2 a, vec2 b) {
    return (vec2Add(a, b));
}


inline vec2 operator - (vec2 a, vec2 b) {
    return (vec2Sub(a, b));
}


inline vec2 operator * (vec2 a, vec2 b) {
    return (vec2Mul(a, b));
}


inline vec2 operator / (vec2 a, vec2 b) {
    return (vec2Div(a, b));
}


inline vec2 operator + (vec2 v, float f) {
    return (vec2Addf(v, f));
}


inline vec2 operator - (vec2 v, float f) {
    return (vec2Subf(v, f));
}


inline vec2 operator * (vec2 v, float f) {
    return (vec2Mulf(v, f));
}


inline vec2 operator / (vec2 v, float f) {
    return (vec2Divf(v, f));
}


inline vec2 operator * (vec2 v, mat2 m) {
    return (vec2Mulm(v, m));
}


inline bool operator == (vec2 a, vec2 b) {
    return (vec2Equal(a, b));
}


inline bool operator != (vec2 a, vec2 b) {
    return (vec2NoEqual(a, b));
}


inline bool operator > (vec2 a, vec2 b) {
    return (vec2Great(a, b));
}


inline bool operator >= (vec2 a, vec2 b) {
    return (vec2GreatEqual(a, b));
}


inline bool operator < (vec2 a, vec2 b) {
    return (vec2Less(a, b));
}


inline bool operator <= (vec2 a, vec2 b) {
    return (vec2LessEqual(a, b));
}


inline vec2 &operator += (vec2 &a, vec2 b) {
    a = vec2Add(a, b);
    return (a);
}


inline vec2 &operator -= (vec2 &a, vec2 b) {
    a = vec2Sub(a, b);
    return (a);
}


inline vec2 &operator *= (vec2 &a, vec2 b) {
    a = vec2Mul(a, b);
    return (a);
}


inline vec2 &operator /= (vec2 &a, vec2 b) {
    a = vec2Div(a, b);
    return (a);
}


inline vec2 &operator += (vec2 &v, float f) {
    v = vec2Addf(v, f);
    return (v);
}


inline vec2 &operator -= (vec2 &v, float f) {
    v = vec2Subf(v, f);
    return (v);
}


inline vec2 &operator *= (vec2 &v, float f) {
    v = vec2Mulf(v, f);
    return (v);
}


inline vec2 &operator /= (vec2 &v, float f) {
    v = vec2Divf(v, f);
    return (v);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec2_hpp_ */
