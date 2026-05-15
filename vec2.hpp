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

/* Constructors */

u_vec2::u_vec2(void) : x(0.0), y(0.0) { }


u_vec2::u_vec2(float v) : x(v), y(v) { }


u_vec2::u_vec2(float x, float y) : x(x), y(y) { }


u_vec2::u_vec2(const u_vec2 &other) : x(other.x), y(other.y) { }


u_vec2 &u_vec2::operator = (const u_vec2 &other) {
    this->x = other.x;
    this->y = other.y;
    return (*this);
}

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
    return (vec2greateq(a, b));
}


inline bool operator < (vec2 a, vec2 b) {
    return (vec2less(a, b));
}


inline bool operator <= (vec2 a, vec2 b) {
    return (vec2lesseq(a, b));
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
