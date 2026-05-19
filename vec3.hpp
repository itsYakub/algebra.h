#if !defined (_vec3_hpp_)
# define _vec3_hpp_ 1
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */
#
# if defined (__cplusplus)

extern "C" {

# endif
#
# include "./vec3.h"
#
# if defined (__cplusplus)

}

# endif /* __cplusplus */

typedef union u_mat3 mat3;

inline vec3 operator + (vec3, vec3);

inline vec3 operator - (vec3, vec3);

inline vec3 operator * (vec3, vec3);

inline vec3 operator / (vec3, vec3);

inline vec3 operator + (vec3, float);

inline vec3 operator - (vec3, float);

inline vec3 operator * (vec3, float);

inline vec3 operator / (vec3, float);

inline vec3 operator * (vec3, mat3);

inline bool operator == (vec3, vec3);

inline bool operator != (vec3, vec3);

inline bool operator > (vec3, vec3);

inline bool operator >= (vec3, vec3);

inline bool operator < (vec3, vec3);

inline bool operator <= (vec3, vec3);

inline vec3 &operator += (vec3 &, vec3);

inline vec3 &operator -= (vec3 &, vec3);

inline vec3 &operator *= (vec3 &, vec3);

inline vec3 &operator /= (vec3 &, vec3);

inline vec3 &operator += (vec3 &, float);

inline vec3 &operator -= (vec3 &, float);

inline vec3 &operator *= (vec3 &, float);

inline vec3 &operator /= (vec3 &, float);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include "./mat3.hpp"

inline vec3 operator + (vec3 a, vec3 b) {
    return (vec3add(a, b));
}


inline vec3 operator - (vec3 a, vec3 b) {
    return (vec3sub(a, b));
}


inline vec3 operator * (vec3 a, vec3 b) {
    return (vec3mul(a, b));
}


inline vec3 operator / (vec3 a, vec3 b) {
    return (vec3div(a, b));
}


inline vec3 operator + (vec3 v, float f) {
    return (vec3addf(v, f));
}


inline vec3 operator - (vec3 v, float f) {
    return (vec3subf(v, f));
}


inline vec3 operator * (vec3 v, float f) {
    return (vec3mulf(v, f));
}


inline vec3 operator / (vec3 v, float f) {
    return (vec3divf(v, f));
}


inline vec3 operator * (vec3 v, mat3 m) {
    return (vec3mulm(v, m));
}


inline bool operator == (vec3 a, vec3 b) {
    return (vec3eq(a, b));
}


inline bool operator != (vec3 a, vec3 b) {
    return (vec3noeq(a, b));
}


inline bool operator > (vec3 a, vec3 b) {
    return (vec3great(a, b));
}


inline bool operator >= (vec3 a, vec3 b) {
    return (vec3greq(a, b));
}


inline bool operator < (vec3 a, vec3 b) {
    return (vec3less(a, b));
}


inline bool operator <= (vec3 a, vec3 b) {
    return (vec3lseq(a, b));
}


inline vec3 &operator += (vec3 &a, vec3 b) {
    a = vec3add(a, b);
    return (a);
}


inline vec3 &operator -= (vec3 &a, vec3 b) {
    a = vec3sub(a, b);
    return (a);
}


inline vec3 &operator *= (vec3 &a, vec3 b) {
    a = vec3mul(a, b);
    return (a);
}


inline vec3 &operator /= (vec3 &a, vec3 b) {
    a = vec3div(a, b);
    return (a);
}


inline vec3 &operator += (vec3 &v, float f) {
    v = vec3addf(v, f);
    return (v);
}


inline vec3 &operator -= (vec3 &v, float f) {
    v = vec3subf(v, f);
    return (v);
}


inline vec3 &operator *= (vec3 &v, float f) {
    v = vec3mulf(v, f);
    return (v);
}


inline vec3 &operator /= (vec3 &v, float f) {
    v = vec3divf(v, f);
    return (v);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec3_hpp_ */
