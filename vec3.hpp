#if !defined (_vec3_hpp_)
# define _vec3_hpp_ 1
#
# if defined (__cplusplus)

extern "C" {

# endif
#
# include "./vec3.h"
#
# if defined (__cplusplus)

}

inline vec3 operator + (vec3 a, vec3 b) {
    return (vec3Add(a, b));
}


inline vec3 operator - (vec3 a, vec3 b) {
    return (vec3Sub(a, b));
}


inline vec3 operator * (vec3 a, vec3 b) {
    return (vec3Mul(a, b));
}


inline vec3 operator / (vec3 a, vec3 b) {
    return (vec3Div(a, b));
}


inline vec3 operator + (vec3 v, float f) {
    return (vec3Addf(v, f));
}


inline vec3 operator - (vec3 v, float f) {
    return (vec3Subf(v, f));
}


inline vec3 operator * (vec3 v, float f) {
    return (vec3Mulf(v, f));
}


inline vec3 operator / (vec3 v, float f) {
    return (vec3Divf(v, f));
}


inline vec3 operator * (vec3 v, mat3 m) {
    return (vec3Mulm(v, m));
}


inline bool operator == (vec3 a, vec3 b) {
    return (vec3Equal(a, b));
}


inline bool operator != (vec3 a, vec3 b) {
    return (vec3NoEqual(a, b));
}


inline bool operator > (vec3 a, vec3 b) {
    return (vec3Great(a, b));
}


inline bool operator >= (vec3 a, vec3 b) {
    return (vec3GreatEqual(a, b));
}


inline bool operator < (vec3 a, vec3 b) {
    return (vec3Less(a, b));
}


inline bool operator <= (vec3 a, vec3 b) {
    return (vec3LessEqual(a, b));
}


inline vec3 &operator += (vec3 &a, vec3 b) {
    a = vec3Add(a, b);
    return (a);
}


inline vec3 &operator -= (vec3 &a, vec3 b) {
    a = vec3Sub(a, b);
    return (a);
}


inline vec3 &operator *= (vec3 &a, vec3 b) {
    a = vec3Mul(a, b);
    return (a);
}


inline vec3 &operator /= (vec3 &a, vec3 b) {
    a = vec3Div(a, b);
    return (a);
}


inline vec3 &operator += (vec3 &v, float f) {
    v = vec3Addf(v, f);
    return (v);
}


inline vec3 &operator -= (vec3 &v, float f) {
    v = vec3Subf(v, f);
    return (v);
}


inline vec3 &operator *= (vec3 &v, float f) {
    v = vec3Mulf(v, f);
    return (v);
}


inline vec3 &operator /= (vec3 &v, float f) {
    v = vec3Divf(v, f);
    return (v);
}


# endif /* __cplusplus */
#endif /* _vec3_hpp_ */
