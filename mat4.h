#if !defined (_mat4_h_)
# define _mat4_h_ 1
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */

typedef union u_vec3 vec3;

typedef union u_vec4 vec4;

typedef union u_mat3 mat3;

typedef union u_mat4 mat4;

union u_mat4 {
    struct {
        float m00, m01, m02, m03,
              m10, m11, m12, m13,
              m20, m21, m22, m23,
              m30, m31, m32, m33;
    };

# if defined (__cplusplus)

    u_mat4(void);

    u_mat4(float);

    u_mat4(float, float, float, float,
           float, float, float, float,
           float, float, float, float,
           float, float, float, float);

    u_mat4(const u_mat4 &);

    u_mat4 &operator = (const u_mat4 &);

# endif /* __cplusplus */

};

/* Properties */

ALGAPI mat4 mat4zero(void);

ALGAPI mat4 mat4identity(void);

ALGAPI mat4 mat4init(float);

/* Math operations */

ALGAPI mat4 mat4add(mat4, mat4);

ALGAPI mat4 mat4sub(mat4, mat4);

ALGAPI mat4 mat4mul(mat4, mat4);

ALGAPI mat4 mat4mulf(mat4, float);

ALGAPI vec4 mat4mulv(mat4, vec4);

/* Unary operations */

ALGAPI mat4 mat4neg(mat4);

ALGAPI mat4 mat4transpose(mat4);

ALGAPI mat4 mat4inv(mat4);

/* Scalar operations */

ALGAPI float mat4det(mat4);

ALGAPI float mat4trace(mat4);

/* Construction */

ALGAPI mat4 mat4translate(vec3);

ALGAPI mat4 mat4rotate(vec3, float);

ALGAPI mat4 mat4rotateat(vec3, vec3, float);

ALGAPI mat4 mat4rotatex(float);

ALGAPI mat4 mat4rotatey(float);

ALGAPI mat4 mat4rotatez(float);

ALGAPI mat4 mat4lookat(vec3, vec3, vec3);

ALGAPI mat4 mat4scale(vec3);

ALGAPI mat4 mat4frust(float, float, float, float, float, float);

ALGAPI mat4 mat4ortho(float, float, float, float, float, float);

ALGAPI mat4 mat4persp(float, float, float, float);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include <math.h>
#
#  include "./vec3.h"
#  include "./mat3.h"
#  include "./utils.h"
#
#  if defined (__cplusplus)

u_mat4::u_mat4(void) :
    m00(0.0f), m01(0.0f), m02(0.0f), m03(0.0f),
    m10(0.0f), m11(0.0f), m12(0.0f), m13(0.0f),
    m20(0.0f), m21(0.0f), m22(0.0f), m23(0.0f),
    m30(0.0f), m31(0.0f), m32(0.0f), m33(0.0f) { }


u_mat4::u_mat4(float s) :
    m00(1.0f * s), m01(0.0f),     m02(0.0f),     m03(0.0f),
    m10(0.0f),     m11(1.0f * s), m12(0.0f),     m13(0.0f),
    m20(0.0f),     m21(0.0f),     m22(1.0f * s), m23(0.0f),
    m30(0.0f),     m31(0.0f),     m32(0.0f),     m33(1.0f * s) { }


u_mat4::u_mat4(float m00, float m01, float m02, float m03,
               float m10, float m11, float m12, float m13,
               float m20, float m21, float m22, float m23,
               float m30, float m31, float m32, float m33) :
    m00(m00), m01(m01), m02(m02), m03(m03),
    m10(m10), m11(m11), m12(m12), m13(m13),
    m20(m20), m21(m21), m22(m22), m23(m23),
    m30(m30), m31(m31), m32(m32), m33(m33) { }


u_mat4::u_mat4(const u_mat4 &other) :
    m00(other.m00), m01(other.m01), m02(other.m02), m03(other.m03),
    m10(other.m10), m11(other.m11), m12(other.m12), m13(other.m13),
    m20(other.m20), m21(other.m21), m22(other.m22), m23(other.m23),
    m30(other.m30), m31(other.m31), m32(other.m32), m33(other.m33) { }


u_mat4 &u_mat4::operator = (const u_mat4 &other) {
    this->m00 = other.m00; this->m01 = other.m01; this->m02 = other.m02; this->m03 = other.m03;
    this->m10 = other.m10; this->m11 = other.m11; this->m12 = other.m12; this->m13 = other.m13;
    this->m20 = other.m20; this->m21 = other.m21; this->m22 = other.m22; this->m23 = other.m23;
    this->m30 = other.m30; this->m31 = other.m31; this->m32 = other.m32; this->m33 = other.m33;
    return (*this);
}

#  endif /* __cplusplus */

/* Properties */

ALGAPI mat4 mat4zero(void) {
    mat4 m;

    m.m00 = 0.0f; m.m01 = 0.0f; m.m02 = 0.0f; m.m03 = 0.0f;
    m.m10 = 0.0f; m.m11 = 0.0f; m.m12 = 0.0f; m.m13 = 0.0f;
    m.m20 = 0.0f; m.m21 = 0.0f; m.m22 = 0.0f; m.m23 = 0.0f;
    m.m30 = 0.0f; m.m31 = 0.0f; m.m32 = 0.0f; m.m33 = 0.0f;
    return (m);
}


ALGAPI mat4 mat4identity(void) {
    mat4 m;

    m.m00 = 1.0f; m.m01 = 0.0f; m.m02 = 0.0f; m.m03 = 0.0f;
    m.m10 = 0.0f; m.m11 = 1.0f; m.m12 = 0.0f; m.m13 = 0.0f;
    m.m20 = 0.0f; m.m21 = 0.0f; m.m22 = 1.0f; m.m23 = 0.0f;
    m.m30 = 0.0f; m.m31 = 0.0f; m.m32 = 0.0f; m.m33 = 1.0f;
    return (m);
}


ALGAPI mat4 mat4init(float s) {
    mat4 m;

    m.m00 = 1.0f * s; m.m01 = 0.0f;     m.m02 = 0.0f;     m.m03 = 0.0f;
    m.m10 = 0.0f;     m.m11 = 1.0f * s; m.m12 = 0.0f;     m.m13 = 0.0f;
    m.m20 = 0.0f;     m.m21 = 0.0f;     m.m22 = 1.0f * s; m.m23 = 0.0f;
    m.m30 = 0.0f;     m.m31 = 0.0f;     m.m32 = 0.0f;     m.m33 = 1.0f * s;
    return (m);
}

/* Math operations */

ALGAPI mat4 mat4add(mat4 a, mat4 b) {
    mat4 m;

    m.m00 = a.m00 + b.m00; m.m01 = a.m01 + b.m01; m.m02 = a.m02 + b.m02; m.m03 = a.m03 + b.m03;
    m.m10 = a.m10 + b.m10; m.m11 = a.m11 + b.m11; m.m12 = a.m12 + b.m12; m.m13 = a.m13 + b.m13;
    m.m20 = a.m20 + b.m20; m.m21 = a.m21 + b.m21; m.m22 = a.m22 + b.m22; m.m23 = a.m23 + b.m23;
    m.m30 = a.m30 + b.m30; m.m31 = a.m31 + b.m31; m.m32 = a.m32 + b.m32; m.m33 = a.m33 + b.m33;
    return (m);
}


ALGAPI mat4 mat4sub(mat4 a, mat4 b) {
    mat4 m;

    m.m00 = a.m00 - b.m00; m.m01 = a.m01 - b.m01; m.m02 = a.m02 - b.m02; m.m03 = a.m03 - b.m03;
    m.m10 = a.m10 - b.m10; m.m11 = a.m11 - b.m11; m.m12 = a.m12 - b.m12; m.m13 = a.m13 - b.m13;
    m.m20 = a.m20 - b.m20; m.m21 = a.m21 - b.m21; m.m22 = a.m22 - b.m22; m.m23 = a.m23 - b.m23;
    m.m30 = a.m30 - b.m30; m.m31 = a.m31 - b.m31; m.m32 = a.m32 - b.m32; m.m33 = a.m33 - b.m33;
    return (m);
}


ALGAPI mat4 mat4mul(mat4 a, mat4 b) {
    mat4 m;

    m.m00 = a.m00 * b.m00 + a.m10 * b.m01 + a.m20 * b.m02 + a.m30 * b.m03;
    m.m01 = a.m01 * b.m00 + a.m11 * b.m01 + a.m21 * b.m02 + a.m31 * b.m03;
    m.m02 = a.m02 * b.m00 + a.m12 * b.m01 + a.m22 * b.m02 + a.m32 * b.m03;
    m.m03 = a.m03 * b.m00 + a.m13 * b.m01 + a.m23 * b.m02 + a.m33 * b.m03;

    m.m10 = a.m00 * b.m10 + a.m10 * b.m11 + a.m20 * b.m12 + a.m30 * b.m13;
    m.m11 = a.m01 * b.m10 + a.m11 * b.m11 + a.m21 * b.m12 + a.m31 * b.m13;
    m.m12 = a.m02 * b.m10 + a.m12 * b.m11 + a.m22 * b.m12 + a.m32 * b.m13;
    m.m13 = a.m03 * b.m10 + a.m13 * b.m11 + a.m23 * b.m12 + a.m33 * b.m13;

    m.m20 = a.m00 * b.m20 + a.m10 * b.m21 + a.m20 * b.m22 + a.m30 * b.m23;
    m.m21 = a.m01 * b.m20 + a.m11 * b.m21 + a.m21 * b.m22 + a.m31 * b.m23;
    m.m22 = a.m02 * b.m20 + a.m12 * b.m21 + a.m22 * b.m22 + a.m32 * b.m23;
    m.m23 = a.m03 * b.m20 + a.m13 * b.m21 + a.m23 * b.m22 + a.m33 * b.m23;

    m.m30 = a.m00 * b.m30 + a.m10 * b.m31 + a.m20 * b.m32 + a.m30 * b.m33;
    m.m31 = a.m01 * b.m30 + a.m11 * b.m31 + a.m21 * b.m32 + a.m31 * b.m33;
    m.m32 = a.m02 * b.m30 + a.m12 * b.m31 + a.m22 * b.m32 + a.m32 * b.m33;
    m.m33 = a.m03 * b.m30 + a.m13 * b.m31 + a.m23 * b.m32 + a.m33 * b.m33;
    return (m);
}


ALGAPI mat4 mat4mulf(mat4 a, float f) {
    mat4 m;

    m.m00 = a.m00 * f; m.m01 = a.m01 * f; m.m02 = a.m02 * f; m.m03 = a.m03 * f;
    m.m10 = a.m10 * f; m.m11 = a.m11 * f; m.m12 = a.m12 * f; m.m13 = a.m13 * f;
    m.m20 = a.m20 * f; m.m21 = a.m21 * f; m.m22 = a.m22 * f; m.m23 = a.m23 * f;
    m.m30 = a.m30 * f; m.m31 = a.m31 * f; m.m32 = a.m32 * f; m.m33 = a.m33 * f;
    return (m);
}


ALGAPI vec4 mat4mulv(mat4 a, vec4 b) {
    vec4 v;

    v.x = a.m00 * b.x + a.m10 * b.y + a.m20 * b.z + a.m30 * b.w;
    v.y = a.m01 * b.x + a.m11 * b.y + a.m21 * b.z + a.m31 * b.w;
    v.z = a.m02 * b.x + a.m12 * b.y + a.m22 * b.z + a.m32 * b.w;
    v.w = a.m03 * b.x + a.m13 * b.y + a.m23 * b.z + a.m33 * b.w;
    return (v);
}

/* Unary operations */

ALGAPI mat4 mat4neg(mat4 a) {
    a.m00 = -a.m00; a.m01 = -a.m01; a.m02 = -a.m02; a.m03 = -a.m03;
    a.m10 = -a.m10; a.m11 = -a.m11; a.m12 = -a.m12; a.m13 = -a.m13;
    a.m20 = -a.m20; a.m21 = -a.m21; a.m22 = -a.m22; a.m23 = -a.m23;
    a.m30 = -a.m30; a.m31 = -a.m31; a.m32 = -a.m32; a.m33 = -a.m33;
    return (a);
}


ALGAPI mat4 mat4transpose(mat4 a) {
    mat4 m;

    m.m00 = a.m00; m.m01 = a.m10; m.m02 = a.m20; m.m03 = a.m30;
    m.m10 = a.m01; m.m11 = a.m11; m.m12 = a.m21; m.m13 = a.m31;
    m.m20 = a.m02; m.m21 = a.m12; m.m22 = a.m22; m.m23 = a.m32;
    m.m30 = a.m03; m.m31 = a.m13; m.m32 = a.m23; m.m33 = a.m33;
    return (m);
}


ALGAPI mat4 mat4inv(mat4 a) {
    float det = mat4det(a);
    mat4  m;

    if (det == 0.0f)
        return (mat4zero());

    det = 1.0f / det;

    m.m00 =  det * (a.m11 * (a.m22 * a.m33 - a.m23 * a.m32) - a.m12 * (a.m21 * a.m33 - a.m23 * a.m31) + a.m13 * (a.m21 * a.m32 - a.m22 * a.m31));
    m.m01 = -det * (a.m01 * (a.m22 * a.m33 - a.m23 * a.m32) - a.m02 * (a.m21 * a.m33 - a.m23 * a.m31) + a.m03 * (a.m21 * a.m32 - a.m22 * a.m31));
    m.m02 =  det * (a.m01 * (a.m12 * a.m33 - a.m13 * a.m32) - a.m02 * (a.m11 * a.m33 - a.m13 * a.m31) + a.m03 * (a.m11 * a.m32 - a.m12 * a.m31));
    m.m03 = -det * (a.m01 * (a.m12 * a.m23 - a.m13 * a.m22) - a.m02 * (a.m11 * a.m23 - a.m13 * a.m21) + a.m03 * (a.m11 * a.m22 - a.m12 * a.m21));

    m.m10 = -det * (a.m10 * (a.m22 * a.m33 - a.m23 * a.m32) - a.m12 * (a.m20 * a.m33 - a.m23 * a.m30) + a.m13 * (a.m20 * a.m32 - a.m22 * a.m30));
    m.m11 =  det * (a.m00 * (a.m22 * a.m33 - a.m23 * a.m32) - a.m02 * (a.m20 * a.m33 - a.m23 * a.m30) + a.m03 * (a.m20 * a.m32 - a.m22 * a.m30));
    m.m12 = -det * (a.m00 * (a.m12 * a.m33 - a.m13 * a.m32) - a.m02 * (a.m10 * a.m33 - a.m13 * a.m30) + a.m03 * (a.m10 * a.m32 - a.m12 * a.m30));
    m.m13 =  det * (a.m00 * (a.m12 * a.m23 - a.m13 * a.m22) - a.m02 * (a.m10 * a.m23 - a.m13 * a.m20) + a.m03 * (a.m10 * a.m22 - a.m12 * a.m20));

    m.m20 =  det * (a.m10 * (a.m21 * a.m33 - a.m23 * a.m31) - a.m11 * (a.m20 * a.m33 - a.m23 * a.m30) + a.m13 * (a.m20 * a.m31 - a.m21 * a.m30));
    m.m21 = -det * (a.m00 * (a.m21 * a.m33 - a.m23 * a.m31) - a.m01 * (a.m20 * a.m33 - a.m23 * a.m30) + a.m03 * (a.m20 * a.m31 - a.m21 * a.m30));
    m.m22 =  det * (a.m00 * (a.m11 * a.m33 - a.m13 * a.m31) - a.m01 * (a.m10 * a.m33 - a.m13 * a.m30) + a.m03 * (a.m10 * a.m31 - a.m11 * a.m30));
    m.m23 = -det * (a.m00 * (a.m11 * a.m23 - a.m13 * a.m21) - a.m01 * (a.m10 * a.m23 - a.m13 * a.m20) + a.m03 * (a.m10 * a.m21 - a.m11 * a.m20));

    m.m30 = -det * (a.m10 * (a.m21 * a.m32 - a.m22 * a.m31) - a.m11 * (a.m20 * a.m32 - a.m22 * a.m30) + a.m12 * (a.m20 * a.m31 - a.m21 * a.m30));
    m.m31 =  det * (a.m00 * (a.m21 * a.m32 - a.m22 * a.m31) - a.m01 * (a.m20 * a.m32 - a.m22 * a.m30) + a.m02 * (a.m20 * a.m31 - a.m21 * a.m30));
    m.m32 = -det * (a.m00 * (a.m11 * a.m32 - a.m12 * a.m31) - a.m01 * (a.m10 * a.m32 - a.m12 * a.m30) + a.m02 * (a.m10 * a.m31 - a.m11 * a.m30));
    m.m33 =  det * (a.m00 * (a.m11 * a.m22 - a.m12 * a.m21) - a.m01 * (a.m10 * a.m22 - a.m12 * a.m20) + a.m02 * (a.m10 * a.m21 - a.m11 * a.m20));
    return (m);
}

/* Scalar operations */

ALGAPI float mat4det(mat4 m) {
    float result = 0.0f;
    mat3  sub;

    sub.m00 = m.m11; sub.m01 = m.m12; sub.m02 = m.m13;
    sub.m10 = m.m21; sub.m11 = m.m22; sub.m12 = m.m23;
    sub.m20 = m.m31; sub.m21 = m.m32; sub.m22 = m.m33;
    result += m.m00 * mat3det(sub);

    sub.m00 = m.m10; sub.m01 = m.m12; sub.m02 = m.m13;
    sub.m10 = m.m20; sub.m11 = m.m22; sub.m12 = m.m23;
    sub.m20 = m.m30; sub.m21 = m.m32; sub.m22 = m.m33;
    result -= m.m01 * mat3det(sub);

    sub.m00 = m.m10; sub.m01 = m.m11; sub.m02 = m.m13;
    sub.m10 = m.m20; sub.m11 = m.m21; sub.m12 = m.m23;
    sub.m20 = m.m30; sub.m21 = m.m31; sub.m22 = m.m33;
    result += m.m02 * mat3det(sub);

    sub.m00 = m.m10; sub.m01 = m.m11; sub.m02 = m.m12;
    sub.m10 = m.m20; sub.m11 = m.m21; sub.m12 = m.m22;
    sub.m20 = m.m30; sub.m21 = m.m31; sub.m22 = m.m32;
    result -= m.m03 * mat3det(sub);

    return (result);
}


ALGAPI float mat4trace(mat4 m) {
    return (m.m00 + m.m11 + m.m22 + m.m33);
}

/* Construction */

ALGAPI mat4 mat4translate(vec3 v) {
    mat4 m;

    m.m00 = 1.0f; m.m01 = 0.0f; m.m02 = 0.0f; m.m03 = 0.0f;
    m.m10 = 0.0f; m.m11 = 1.0f; m.m12 = 0.0f; m.m13 = 0.0f;
    m.m20 = 0.0f; m.m21 = 0.0f; m.m22 = 1.0f; m.m23 = 0.0f;
    m.m30 = v.x;  m.m31 = v.y;  m.m32 = v.z;  m.m33 = 1.0f;
    return (m);
}


ALGAPI mat4 mat4rotate(vec3 axis, float angle) {
    float c = cosf(angle);
    float s = sinf(angle);
    float t = 1.0f - c;
    vec3  n = vec3norm(axis);
    mat4  m = mat4identity();

    m.m00 = t * n.x * n.x + c;
    m.m01 = t * n.y * n.x + s * n.z;
    m.m02 = t * n.z * n.x - s * n.y;

    m.m10 = t * n.x * n.y - s * n.z;
    m.m11 = t * n.y * n.y + c;
    m.m12 = t * n.z * n.y + s * n.x;

    m.m20 = t * n.x * n.z + s * n.y;
    m.m21 = t * n.y * n.z - s * n.x;
    m.m22 = t * n.z * n.z + c;
    return (m);
}


ALGAPI mat4 mat4rotateat(vec3 pivot, vec3 axis, float angle) {
    mat4 m = mat4identity();

    m = mat4mul(mat4translate(pivot), m);
    m = mat4mul(mat4rotate(axis, angle), m);
    m = mat4mul(mat4translate(vec3mulf(pivot, -1.0f)), m);
    return (m);
}


ALGAPI mat4 mat4rotatex(float angle) {
    float c = cosf(angle);
    float s = sinf(angle);
    mat4  m = mat4identity();

    m.m11 =  c;
    m.m21 =  s;
    m.m12 = -s;
    m.m22 =  c;
    return (m);
}


ALGAPI mat4 mat4rotatey(float angle) {
    float c = cosf(angle);
    float s = sinf(angle);
    mat4  m = mat4identity();

    m.m00 =  c;
    m.m20 = -s;
    m.m02 =  s;
    m.m22 =  c;
    return (m);
}


ALGAPI mat4 mat4rotatez(float angle) {
    float c = cosf(angle);
    float s = sinf(angle);
    mat4  m = mat4identity();

    m.m00 =  c;
    m.m10 =  s;
    m.m01 = -s;
    m.m11 =  c;
    return (m);
}


ALGAPI mat4 mat4lookat(vec3 eye, vec3 center, vec3 up) {
    vec3 f = vec3norm(vec3sub(center, eye));
    vec3 s = vec3norm(vec3cross(f, up));
    vec3 u = vec3cross(s, f);
    mat4 m = mat4identity();

    m.m00 =  s.x; m.m10 =  s.y; m.m20 =  s.z;
    m.m01 =  u.x; m.m11 =  u.y; m.m21 =  u.z;
    m.m02 = -f.x; m.m12 = -f.y; m.m22 = -f.z;
    m.m03 = -vec3dot(s, eye);
    m.m13 = -vec3dot(u, eye);
    m.m23 =  vec3dot(f, eye);
    return (m);
}


ALGAPI mat4 mat4scale(vec3 v) {
    mat4 m;

    m.m00 = v.x;  m.m01 = 0.0f; m.m02 = 0.0f; m.m03 = 0.0f;
    m.m10 = 0.0f; m.m11 = v.y;  m.m12 = 0.0f; m.m13 = 0.0f;
    m.m20 = 0.0f; m.m21 = 0.0f; m.m22 = v.z;  m.m23 = 0.0f;
    m.m30 = 0.0f; m.m31 = 0.0f; m.m32 = 0.0f; m.m33 = 1.0f;
    return (m);
}


ALGAPI mat4 mat4frust(float left, float right, float down, float top, float near, float far) {
    mat4 m = mat4zero();

    m.m00 =  (near * 2.0f) / (right - left);
    m.m11 =  (near * 2.0f) / (top   - down);
    m.m20 =  (right + left) / (right - left);
    m.m21 =  (top   + down) / (top   - down);
    m.m22 = -(far   + near) / (far   - near);
    m.m23 = -1.0f;
    m.m32 = -(2.0f * far * near) / (far - near);
    return (m);
}


ALGAPI mat4 mat4ortho(float left, float right, float down, float top, float near, float far) {
    mat4 m = mat4zero();

    m.m00 =  2.0f / (right - left);
    m.m11 =  2.0f / (top   - down);
    m.m22 = -2.0f / (far   - near);
    m.m03 = -(left  + right) / (right - left);
    m.m13 = -(top   + down)  / (top   - down);
    m.m23 = -(far   + near)  / (far   - near);
    m.m33 =  1.0f;
    return (m);
}


ALGAPI mat4 mat4persp(float fov, float aspect, float near, float far) {
    float t = near * tanf(fov * 0.5f);
    float r = t * aspect;

    return (mat4frust(-r, r, -t, t, near, far));
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat4_h_ */
