#if !defined (_vec2_hpp_)
# define _vec2_hpp_ 1
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */
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

/* Operator - overloading */

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
    return (vec2add(a, b));
}


inline vec2 operator - (vec2 a, vec2 b) {
    return (vec2sub(a, b));
}


inline vec2 operator * (vec2 a, vec2 b) {
    return (vec2mul(a, b));
}


inline vec2 operator / (vec2 a, vec2 b) {
    return (vec2div(a, b));
}


inline vec2 operator + (vec2 v, float f) {
    return (vec2addf(v, f));
}


inline vec2 operator - (vec2 v, float f) {
    return (vec2subf(v, f));
}


inline vec2 operator * (vec2 v, float f) {
    return (vec2mulf(v, f));
}


inline vec2 operator / (vec2 v, float f) {
    return (vec2divf(v, f));
}


inline vec2 operator * (vec2 v, mat2 m) {
    return (vec2mulm(v, m));
}


inline bool operator == (vec2 a, vec2 b) {
    return (vec2eq(a, b));
}


inline bool operator != (vec2 a, vec2 b) {
    return (vec2noeq(a, b));
}


inline bool operator > (vec2 a, vec2 b) {
    return (vec2great(a, b));
}


inline bool operator >= (vec2 a, vec2 b) {
    return (vec2greq(a, b));
}


inline bool operator < (vec2 a, vec2 b) {
    return (vec2less(a, b));
}


inline bool operator <= (vec2 a, vec2 b) {
    return (vec2lseq(a, b));
}


inline vec2 &operator += (vec2 &a, vec2 b) {
    a = vec2add(a, b);
    return (a);
}


inline vec2 &operator -= (vec2 &a, vec2 b) {
    a = vec2sub(a, b);
    return (a);
}


inline vec2 &operator *= (vec2 &a, vec2 b) {
    a = vec2mul(a, b);
    return (a);
}


inline vec2 &operator /= (vec2 &a, vec2 b) {
    a = vec2div(a, b);
    return (a);
}


inline vec2 &operator += (vec2 &v, float f) {
    v = vec2addf(v, f);
    return (v);
}


inline vec2 &operator -= (vec2 &v, float f) {
    v = vec2subf(v, f);
    return (v);
}


inline vec2 &operator *= (vec2 &v, float f) {
    v = vec2mulf(v, f);
    return (v);
}


inline vec2 &operator /= (vec2 &v, float f) {
    v = vec2divf(v, f);
    return (v);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec2_hpp_ */
