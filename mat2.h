#if !defined (_mat2_h_)
# define _mat2_h_ 1
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */

typedef union u_vec2 vec2;

typedef union u_mat2 mat2;

union u_mat2 {
    struct {
        float m00, m01,
              m10, m11;
    };

# if defined (__cplusplus)

    u_mat2(void);

    u_mat2(float);

    u_mat2(float, float, float, float);

    u_mat2(const u_mat2 &);

    u_mat2 &operator = (const u_mat2 &);

# endif /* __cplusplus */

};

/* Properties */

ALGAPI mat2 mat2zero(void);

ALGAPI mat2 mat2identity(void);

ALGAPI mat2 mat2init(float);

/* Math operations */

ALGAPI mat2 mat2add(mat2, mat2);

ALGAPI mat2 mat2sub(mat2, mat2);

ALGAPI mat2 mat2mul(mat2, mat2);

ALGAPI mat2 mat2mulf(mat2, float);

ALGAPI vec2 mat2mulv(mat2, vec2);

/* Unary operations */

ALGAPI mat2 mat2neg(mat2);

ALGAPI mat2 mat2transpose(mat2);

ALGAPI mat2 mat2inv(mat2);

/* Scalar operations */

ALGAPI float mat2det(mat2);

ALGAPI float mat2trace(mat2);

/* Construction */

ALGAPI mat2 mat2rotate(float);

ALGAPI mat2 mat2scale(vec2);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include <math.h>
#
#  include "./vec2.h"
#  include "./utils.h"
#
#  if defined (__cplusplus)

u_mat2::u_mat2(void) :
    m00(0.0f), m01(0.0f),
    m10(0.0f), m11(0.0f) { }


u_mat2::u_mat2(float s) :
    m00(1.0f * s), m01(0.0f),
    m10(0.0f),     m11(1.0f * s) { }


u_mat2::u_mat2(float m00, float m01, float m10, float m11) :
    m00(m00), m01(m01),
    m10(m10), m11(m11) { }


u_mat2::u_mat2(const u_mat2 &other) :
    m00(other.m00), m01(other.m01),
    m10(other.m10), m11(other.m11) { }


u_mat2 &u_mat2::operator = (const u_mat2 &other) {
    this->m00 = other.m00;
    this->m01 = other.m01;
    this->m10 = other.m10;
    this->m11 = other.m11;
    return (*this);
}

#  endif /* __cplusplus */

/* Properties */

ALGAPI mat2 mat2zero(void) {
    mat2 m;

    m.m00 = 0.0f; m.m01 = 0.0f;
    m.m10 = 0.0f; m.m11 = 0.0f;
    return (m);
}


ALGAPI mat2 mat2identity(void) {
    mat2 m;

    m.m00 = 1.0f; m.m01 = 0.0f;
    m.m10 = 0.0f; m.m11 = 1.0f;
    return (m);
}


ALGAPI mat2 mat2init(float s) {
    mat2 m;

    m.m00 = 1.0f * s; m.m01 = 0.0f;
    m.m10 = 0.0f;     m.m11 = 1.0f * s;
    return (m);
}

/* Math operations */

ALGAPI mat2 mat2add(mat2 a, mat2 b) {
    mat2 m;

    m.m00 = a.m00 + b.m00; m.m01 = a.m01 + b.m01;
    m.m10 = a.m10 + b.m10; m.m11 = a.m11 + b.m11;
    return (m);
}


ALGAPI mat2 mat2sub(mat2 a, mat2 b) {
    mat2 m;

    m.m00 = a.m00 - b.m00; m.m01 = a.m01 - b.m01;
    m.m10 = a.m10 - b.m10; m.m11 = a.m11 - b.m11;
    return (m);
}


ALGAPI mat2 mat2mul(mat2 a, mat2 b) {
    mat2 m;

    m.m00 = a.m00 * b.m00 + a.m10 * b.m01;
    m.m01 = a.m01 * b.m00 + a.m11 * b.m01;
    m.m10 = a.m00 * b.m10 + a.m10 * b.m11;
    m.m11 = a.m01 * b.m10 + a.m11 * b.m11;
    return (m);
}


ALGAPI mat2 mat2mulf(mat2 a, float f) {
    mat2 m;

    m.m00 = a.m00 * f; m.m01 = a.m01 * f;
    m.m10 = a.m10 * f; m.m11 = a.m11 * f;
    return (m);
}


ALGAPI vec2 mat2mulv(mat2 a, vec2 b) {
    vec2 v;

    v.x = a.m00 * b.x + a.m10 * b.y;
    v.y = a.m01 * b.x + a.m11 * b.y;
    return (v);
}

/* Unary operations */

ALGAPI mat2 mat2neg(mat2 a) {
    a.m00 = -a.m00; a.m01 = -a.m01;
    a.m10 = -a.m10; a.m11 = -a.m11;
    return (a);
}


ALGAPI mat2 mat2transpose(mat2 a) {
    mat2 m;

    m.m00 = a.m00; m.m01 = a.m10;
    m.m10 = a.m01; m.m11 = a.m11;
    return (m);
}


ALGAPI mat2 mat2inv(mat2 a) {
    float det = mat2det(a);
    mat2  m;

    if (det == 0.0f)
        return (mat2zero());

    det = 1.0f / det;

    m.m00 =  a.m11 * det; m.m01 = -a.m01 * det;
    m.m10 = -a.m10 * det; m.m11 =  a.m00 * det;
    return (m);
}

/* Scalar operations */

ALGAPI float mat2det(mat2 m) {
    return (m.m00 * m.m11 - m.m10 * m.m01);
}


ALGAPI float mat2trace(mat2 m) {
    return (m.m00 + m.m11);
}

/* Construction */

ALGAPI mat2 mat2rotate(float angle) {
    float c = cosf(angle);
    float s = sinf(angle);
    mat2  m;

    m.m00 =  c; m.m01 = s;
    m.m10 = -s; m.m11 = c;
    return (m);
}


ALGAPI mat2 mat2scale(vec2 s) {
    mat2 m;

    m.m00 = s.x;  m.m01 = 0.0f;
    m.m10 = 0.0f; m.m11 = s.y;
    return (m);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat2_h_ */
