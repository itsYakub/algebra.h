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
    return (vec4add(a, b));
}


inline vec4 operator - (vec4 a, vec4 b) {
    return (vec4sub(a, b));
}


inline vec4 operator * (vec4 a, vec4 b) {
    return (vec4mul(a, b));
}


inline vec4 operator / (vec4 a, vec4 b) {
    return (vec4div(a, b));
}


inline vec4 operator + (vec4 v, float f) {
    return (vec4addf(v, f));
}


inline vec4 operator - (vec4 v, float f) {
    return (vec4subf(v, f));
}


inline vec4 operator * (vec4 v, float f) {
    return (vec4mulf(v, f));
}


inline vec4 operator / (vec4 v, float f) {
    return (vec4divf(v, f));
}


inline vec4 operator * (vec4 v, mat4 m) {
    return (vec4mulm(v, m));
}


inline bool operator == (vec4 a, vec4 b) {
    return (vec4eq(a, b));
}


inline bool operator != (vec4 a, vec4 b) {
    return (vec4noeq(a, b));
}


inline bool operator > (vec4 a, vec4 b) {
    return (vec4great(a, b));
}


inline bool operator >= (vec4 a, vec4 b) {
    return (vec4greateq(a, b));
}


inline bool operator < (vec4 a, vec4 b) {
    return (vec4less(a, b));
}


inline bool operator <= (vec4 a, vec4 b) {
    return (vec4lesseq(a, b));
}


inline vec4 &operator += (vec4 &a, vec4 b) {
    a = vec4add(a, b);
    return (a);
}


inline vec4 &operator -= (vec4 &a, vec4 b) {
    a = vec4sub(a, b);
    return (a);
}


inline vec4 &operator *= (vec4 &a, vec4 b) {
    a = vec4mul(a, b);
    return (a);
}


inline vec4 &operator /= (vec4 &a, vec4 b) {
    a = vec4div(a, b);
    return (a);
}


inline vec4 &operator += (vec4 &v, float f) {
    v = vec4addf(v, f);
    return (v);
}


inline vec4 &operator -= (vec4 &v, float f) {
    v = vec4subf(v, f);
    return (v);
}


inline vec4 &operator *= (vec4 &v, float f) {
    v = vec4mulf(v, f);
    return (v);
}


inline vec4 &operator /= (vec4 &v, float f) {
    v = vec4divf(v, f);
    return (v);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec4_hpp_ */
