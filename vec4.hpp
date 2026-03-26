#if !defined (_vec4_hpp_)
# define _vec4_hpp_ 1
#
# if defined (__cplusplus)

extern "C" {

# endif
#
# include "./vec4.h"
#
# if defined (__cplusplus)

}

# endif /* __cplusplus */

typedef union u_mat4 mat4;

inline vec4 operator + (vec4, vec4);

inline vec4 operator - (vec4, vec4);

inline vec4 operator * (vec4, vec4);

inline vec4 operator / (vec4, vec4);

inline vec4 operator + (vec4, float);

inline vec4 operator - (vec4, float);

inline vec4 operator * (vec4, float);

inline vec4 operator / (vec4, float);

inline vec4 operator * (vec4, mat4);

inline bool operator == (vec4, vec4);

inline bool operator != (vec4, vec4);

inline bool operator > (vec4, vec4);

inline bool operator >= (vec4, vec4);

inline bool operator < (vec4, vec4);

inline bool operator <= (vec4, vec4);

inline vec4 &operator += (vec4 &, vec4);

inline vec4 &operator -= (vec4 &, vec4);

inline vec4 &operator *= (vec4 &, vec4);

inline vec4 &operator /= (vec4 &, vec4);

inline vec4 &operator += (vec4 &, float);

inline vec4 &operator -= (vec4 &, float);

inline vec4 &operator *= (vec4 &, float);

inline vec4 &operator /= (vec4 &, float);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include "./mat4.hpp"

inline vec4 operator + (vec4 a, vec4 b) {
    return (vec4Add(a, b));
}


inline vec4 operator - (vec4 a, vec4 b) {
    return (vec4Sub(a, b));
}


inline vec4 operator * (vec4 a, vec4 b) {
    return (vec4Mul(a, b));
}


inline vec4 operator / (vec4 a, vec4 b) {
    return (vec4Div(a, b));
}


inline vec4 operator + (vec4 v, float f) {
    return (vec4Addf(v, f));
}


inline vec4 operator - (vec4 v, float f) {
    return (vec4Subf(v, f));
}


inline vec4 operator * (vec4 v, float f) {
    return (vec4Mulf(v, f));
}


inline vec4 operator / (vec4 v, float f) {
    return (vec4Divf(v, f));
}


inline vec4 operator * (vec4 v, mat4 m) {
    return (vec4Mulm(v, m));
}


inline bool operator == (vec4 a, vec4 b) {
    return (vec4Equal(a, b));
}


inline bool operator != (vec4 a, vec4 b) {
    return (vec4NoEqual(a, b));
}


inline bool operator > (vec4 a, vec4 b) {
    return (vec4Great(a, b));
}


inline bool operator >= (vec4 a, vec4 b) {
    return (vec4GreatEqual(a, b));
}


inline bool operator < (vec4 a, vec4 b) {
    return (vec4Less(a, b));
}


inline bool operator <= (vec4 a, vec4 b) {
    return (vec4LessEqual(a, b));
}


inline vec4 &operator += (vec4 &a, vec4 b) {
    a = vec4Add(a, b);
    return (a);
}


inline vec4 &operator -= (vec4 &a, vec4 b) {
    a = vec4Sub(a, b);
    return (a);
}


inline vec4 &operator *= (vec4 &a, vec4 b) {
    a = vec4Mul(a, b);
    return (a);
}


inline vec4 &operator /= (vec4 &a, vec4 b) {
    a = vec4Div(a, b);
    return (a);
}


inline vec4 &operator += (vec4 &v, float f) {
    v = vec4Addf(v, f);
    return (v);
}


inline vec4 &operator -= (vec4 &v, float f) {
    v = vec4Subf(v, f);
    return (v);
}


inline vec4 &operator *= (vec4 &v, float f) {
    v = vec4Mulf(v, f);
    return (v);
}


inline vec4 &operator /= (vec4 &v, float f) {
    v = vec4Divf(v, f);
    return (v);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec4_hpp_ */
