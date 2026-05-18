#if !defined (_vec4_h_)
# define _vec4_h_ 1
#
# include <stdbool.h>
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */

typedef union u_mat4 mat4;

typedef union u_vec4 vec4;

union u_vec4 {
    struct {
        float x;
        float y;
        float z;
        float w;
    };

    struct {
        float r;
        float g;
        float b;
        float a;
    };

# if defined (__cplusplus)

    u_vec4(void);

    u_vec4(float);

    u_vec4(float, float, float, float);

    u_vec4(const u_vec4 &);

    u_vec4 &operator = (const u_vec4 &);

# endif /* __cplusplus */

};

/* Properties */

ALGAPI vec4 vec4zero(void);

ALGAPI vec4 vec4one(void);

ALGAPI vec4 vec4right(void);

ALGAPI vec4 vec4left(void);

ALGAPI vec4 vec4up(void);

ALGAPI vec4 vec4down(void);

ALGAPI vec4 vec4front(void);

ALGAPI vec4 vec4back(void);

/* Math operations */

ALGAPI vec4 vec4add(vec4, vec4);

ALGAPI vec4 vec4sub(vec4, vec4);

ALGAPI vec4 vec4mul(vec4, vec4);

ALGAPI vec4 vec4div(vec4, vec4);

ALGAPI vec4 vec4addf(vec4, float);

ALGAPI vec4 vec4subf(vec4, float);

ALGAPI vec4 vec4mulf(vec4, float);

ALGAPI vec4 vec4divf(vec4, float);

ALGAPI vec4 vec4mulm(vec4, mat4);

/* Boolean expressions */

ALGAPI bool vec4eq(vec4, vec4);

ALGAPI bool vec4noeq(vec4, vec4);

ALGAPI bool vec4great(vec4, vec4);

ALGAPI bool vec4greateq(vec4, vec4);

ALGAPI bool vec4less(vec4, vec4);

ALGAPI bool vec4lesseq(vec4, vec4);

/* Distance operations */

ALGAPI float vec4len(vec4);

ALGAPI float vec4lensq(vec4);

ALGAPI float vec4dist(vec4, vec4);

ALGAPI float vec4distsq(vec4, vec4);

/* Unary arithmetics */

ALGAPI float vec4dot(vec4, vec4);

ALGAPI vec4  vec4norm(vec4);

ALGAPI vec4  vec4neg(vec4);

ALGAPI vec4  vec4abs(vec4);

ALGAPI vec4  vec4sign(vec4);

ALGAPI vec4  vec4sqrt(vec4);

ALGAPI vec4  vec4pow(vec4, float);

ALGAPI vec4  vec4fract(vec4);

ALGAPI vec4  vec4floor(vec4);

ALGAPI vec4  vec4ceil(vec4);

ALGAPI vec4  vec4round(vec4);

ALGAPI vec4  vec4mod(vec4, vec4);

ALGAPI vec4  vec4modf(vec4, float);

/* Constraints */

ALGAPI vec4 vec4min(vec4, vec4);

ALGAPI vec4 vec4minf(vec4, float);

ALGAPI vec4 vec4max(vec4, vec4);

ALGAPI vec4 vec4maxf(vec4, float);

ALGAPI vec4 vec4clamp(vec4, vec4, vec4);

ALGAPI vec4 vec4clampf(vec4, float, float);

/* Interpolation */

ALGAPI vec4 vec4lerp(vec4, vec4, float);

ALGAPI vec4 vec4step(vec4, vec4);

ALGAPI vec4 vec4smoothstep(vec4, vec4, vec4);

/* Geometric operations */

ALGAPI vec4  vec4reflect(vec4, vec4);

ALGAPI vec4  vec4refract(vec4, vec4, float);

ALGAPI float vec4angle(vec4, vec4);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include <math.h>
#
#  include "./mat4.h"
#  include "./utils.h"
#
#  if defined (__cplusplus)

u_vec4::u_vec4(void) : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }


u_vec4::u_vec4(float v) : x(v), y(v), z(v), w(v) { }


u_vec4::u_vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }


u_vec4::u_vec4(const u_vec4 &other) : x(other.x), y(other.y), z(other.z), w(other.w) { }


u_vec4 &u_vec4::operator = (const u_vec4 &other) {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    this->w = other.w;
    return (*this);
}

#  endif /* __cplusplus */

/* Properties */

ALGAPI vec4 vec4zero(void) {
    vec4 v;

    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    v.w = 0.0f;
    return (v);
}


ALGAPI vec4 vec4one(void) {
    vec4 v;

    v.x = 1.0f;
    v.y = 1.0f;
    v.z = 1.0f;
    v.w = 1.0f;
    return (v);
}


ALGAPI vec4 vec4right(void) {
    vec4 v;

    v.x = 1.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    v.w = 0.0f;
    return (v);
}


ALGAPI vec4 vec4left(void) {
    vec4 v;

    v.x = -1.0f;
    v.y =  0.0f;
    v.z =  0.0f;
    v.w =  0.0f;
    return (v);
}


ALGAPI vec4 vec4up(void) {
    vec4 v;

    v.x = 0.0f;
    v.y = 1.0f;
    v.z = 0.0f;
    v.w = 0.0f;
    return (v);
}


ALGAPI vec4 vec4down(void) {
    vec4 v;

    v.x =  0.0f;
    v.y = -1.0f;
    v.z =  0.0f;
    v.w =  0.0f;
    return (v);
}


ALGAPI vec4 vec4front(void) {
    vec4 v;

    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 1.0f;
    v.w = 0.0f;
    return (v);
}


ALGAPI vec4 vec4back(void) {
    vec4 v;

    v.x =  0.0f;
    v.y =  0.0f;
    v.z = -1.0f;
    v.w =  0.0f;
    return (v);
}

/* Math operations */

ALGAPI vec4 vec4add(vec4 a, vec4 b) {
    vec4 v;

    v.x = a.x + b.x;
    v.y = a.y + b.y;
    v.z = a.z + b.z;
    v.w = a.w + b.w;
    return (v);
}


ALGAPI vec4 vec4sub(vec4 a, vec4 b) {
    vec4 v;

    v.x = a.x - b.x;
    v.y = a.y - b.y;
    v.z = a.z - b.z;
    v.w = a.w - b.w;
    return (v);
}


ALGAPI vec4 vec4mul(vec4 a, vec4 b) {
    vec4 v;

    v.x = a.x * b.x;
    v.y = a.y * b.y;
    v.z = a.z * b.z;
    v.w = a.w * b.w;
    return (v);
}


ALGAPI vec4 vec4div(vec4 a, vec4 b) {
    vec4 v;

    v.x = b.x != 0.0f ? a.x / b.x : 0.0f;
    v.y = b.y != 0.0f ? a.y / b.y : 0.0f;
    v.z = b.z != 0.0f ? a.z / b.z : 0.0f;
    v.w = b.w != 0.0f ? a.w / b.w : 0.0f;
    return (v);
}


ALGAPI vec4 vec4addf(vec4 a, float f) {
    vec4 v;

    v.x = a.x + f;
    v.y = a.y + f;
    v.z = a.z + f;
    v.w = a.w + f;
    return (v);
}


ALGAPI vec4 vec4subf(vec4 a, float f) {
    vec4 v;

    v.x = a.x - f;
    v.y = a.y - f;
    v.z = a.z - f;
    v.w = a.w - f;
    return (v);
}


ALGAPI vec4 vec4mulf(vec4 a, float f) {
    vec4 v;

    v.x = a.x * f;
    v.y = a.y * f;
    v.z = a.z * f;
    v.w = a.w * f;
    return (v);
}


ALGAPI vec4 vec4divf(vec4 a, float f) {
    vec4 v;

    v.x = f != 0.0f ? a.x / f : 0.0f;
    v.y = f != 0.0f ? a.y / f : 0.0f;
    v.z = f != 0.0f ? a.z / f : 0.0f;
    v.w = f != 0.0f ? a.w / f : 0.0f;
    return (v);
}


ALGAPI vec4 vec4mulm(vec4 a, mat4 m) {
    vec4 v;

    v.x = m.m00 * a.x + m.m10 * a.y + m.m20 * a.z + m.m30 * a.w;
    v.y = m.m01 * a.x + m.m11 * a.y + m.m21 * a.z + m.m31 * a.w;
    v.z = m.m02 * a.x + m.m12 * a.y + m.m22 * a.z + m.m32 * a.w;
    v.w = m.m03 * a.x + m.m13 * a.y + m.m23 * a.z + m.m33 * a.w;
    return (v);
}

/* Boolean expressions */

ALGAPI bool vec4eq(vec4 a, vec4 b) {
    return (a.x == b.x &&
            a.y == b.y &&
            a.z == b.z &&
            a.w == b.w);
}


ALGAPI bool vec4noeq(vec4 a, vec4 b) {
    return (a.x != b.x ||
            a.y != b.y ||
            a.z != b.z ||
            a.w != b.w);
}


ALGAPI bool vec4great(vec4 a, vec4 b) {
    return (a.x > b.x ||
            a.y > b.y ||
            a.z > b.z ||
            a.w > b.w);
}


ALGAPI bool vec4greateq(vec4 a, vec4 b) {
    return (a.x >= b.x ||
            a.y >= b.y ||
            a.z >= b.z ||
            a.w >= b.w);
}


ALGAPI bool vec4less(vec4 a, vec4 b) {
    return (a.x < b.x ||
            a.y < b.y ||
            a.z < b.z ||
            a.w < b.w);
}


ALGAPI bool vec4lesseq(vec4 a, vec4 b) {
    return (a.x <= b.x ||
            a.y <= b.y ||
            a.z <= b.z ||
            a.w <= b.w);
}

/* Distance operations */

ALGAPI float vec4len(vec4 a) {
    return (sqrtf(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w));
}


ALGAPI float vec4lensq(vec4 a) {
    return (a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}


ALGAPI float vec4dist(vec4 a, vec4 b) {
    return (sqrtf((a.x - b.x) * (a.x - b.x) +
                  (a.y - b.y) * (a.y - b.y) +
                  (a.z - b.z) * (a.z - b.z) +
                  (a.w - b.w) * (a.w - b.w)));
}


ALGAPI float vec4distsq(vec4 a, vec4 b) {
    return ((a.x - b.x) * (a.x - b.x) +
            (a.y - b.y) * (a.y - b.y) +
            (a.z - b.z) * (a.z - b.z) +
            (a.w - b.w) * (a.w - b.w));
}

/* Unary arithmetics */

ALGAPI float vec4dot(vec4 a, vec4 b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}


ALGAPI vec4 vec4norm(vec4 a) {
    float len = vec4len(a);

    if (len != 0.0f) {
        a.x *= 1.0f / len;
        a.y *= 1.0f / len;
        a.z *= 1.0f / len;
        a.w *= 1.0f / len;
    }
    return (a);
}


ALGAPI vec4 vec4neg(vec4 a) {
    a.x = -a.x;
    a.y = -a.y;
    a.z = -a.z;
    a.w = -a.w;
    return (a);
}


ALGAPI vec4 vec4abs(vec4 a) {
    a.x = fabsf(a.x);
    a.y = fabsf(a.y);
    a.z = fabsf(a.z);
    a.w = fabsf(a.w);
    return (a);
}


ALGAPI vec4 vec4sign(vec4 a) {
    a.x = a.x > 0.0f ? 1.0f : (a.x < 0.0f ? -1.0f : 0.0f);
    a.y = a.y > 0.0f ? 1.0f : (a.y < 0.0f ? -1.0f : 0.0f);
    a.z = a.z > 0.0f ? 1.0f : (a.z < 0.0f ? -1.0f : 0.0f);
    a.w = a.w > 0.0f ? 1.0f : (a.w < 0.0f ? -1.0f : 0.0f);
    return (a);
}


ALGAPI vec4 vec4sqrt(vec4 a) {
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    a.z = sqrtf(a.z);
    a.w = sqrtf(a.w);
    return (a);
}


ALGAPI vec4 vec4pow(vec4 a, float f) {
    a.x = powf(a.x, f);
    a.y = powf(a.y, f);
    a.z = powf(a.z, f);
    a.w = powf(a.w, f);
    return (a);
}


ALGAPI vec4 vec4fract(vec4 a) {
    a.x = fract(a.x);
    a.y = fract(a.y);
    a.z = fract(a.z);
    a.w = fract(a.w);
    return (a);
}


ALGAPI vec4 vec4floor(vec4 a) {
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    a.z = floorf(a.z);
    a.w = floorf(a.w);
    return (a);
}


ALGAPI vec4 vec4ceil(vec4 a) {
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    a.z = ceilf(a.z);
    a.w = ceilf(a.w);
    return (a);
}


ALGAPI vec4 vec4round(vec4 a) {
    a.x = roundf(a.x);
    a.y = roundf(a.y);
    a.z = roundf(a.z);
    a.w = roundf(a.w);
    return (a);
}


ALGAPI vec4 vec4mod(vec4 a, vec4 b) {
    vec4 v;

    v.x = a.x - b.x * floorf(a.x / b.x);
    v.y = a.y - b.y * floorf(a.y / b.y);
    v.z = a.z - b.z * floorf(a.z / b.z);
    v.w = a.w - b.w * floorf(a.w / b.w);
    return (v);
}


ALGAPI vec4 vec4modf(vec4 a, float f) {
    vec4 v;

    v.x = a.x - f * floorf(a.x / f);
    v.y = a.y - f * floorf(a.y / f);
    v.z = a.z - f * floorf(a.z / f);
    v.w = a.w - f * floorf(a.w / f);
    return (v);
}

/* Constraints */

ALGAPI vec4 vec4min(vec4 a, vec4 b) {
    vec4 v;

    v.x = min(a.x, b.x);
    v.y = min(a.y, b.y);
    v.z = min(a.z, b.z);
    v.w = min(a.w, b.w);
    return (v);
}


ALGAPI vec4 vec4minf(vec4 a, float f) {
    vec4 v;

    v.x = min(a.x, f);
    v.y = min(a.y, f);
    v.z = min(a.z, f);
    v.w = min(a.w, f);
    return (v);
}


ALGAPI vec4 vec4max(vec4 a, vec4 b) {
    vec4 v;

    v.x = max(a.x, b.x);
    v.y = max(a.y, b.y);
    v.z = max(a.z, b.z);
    v.w = max(a.w, b.w);
    return (v);
}


ALGAPI vec4 vec4maxf(vec4 a, float f) {
    vec4 v;

    v.x = max(a.x, f);
    v.y = max(a.y, f);
    v.z = max(a.z, f);
    v.w = max(a.w, f);
    return (v);
}


ALGAPI vec4 vec4clamp(vec4 a, vec4 lo, vec4 hi) {
    vec4 v;

    v.x = clamp(a.x, lo.x, hi.x);
    v.y = clamp(a.y, lo.y, hi.y);
    v.z = clamp(a.z, lo.z, hi.z);
    v.w = clamp(a.w, lo.w, hi.w);
    return (v);
}


ALGAPI vec4 vec4clampf(vec4 a, float lo, float hi) {
    vec4 v;

    v.x = clamp(a.x, lo, hi);
    v.y = clamp(a.y, lo, hi);
    v.z = clamp(a.z, lo, hi);
    v.w = clamp(a.w, lo, hi);
    return (v);
}

/* Interpolation */

ALGAPI vec4 vec4lerp(vec4 a, vec4 b, float t) {
    vec4 v;

    v.x = lerp(a.x, b.x, t);
    v.y = lerp(a.y, b.y, t);
    v.z = lerp(a.z, b.z, t);
    v.w = lerp(a.w, b.w, t);
    return (v);
}


ALGAPI vec4 vec4step(vec4 a, vec4 x) {
    vec4 v;

    v.x = step(a.x, x.x);
    v.y = step(a.y, x.y);
    v.z = step(a.z, x.z);
    v.w = step(a.w, x.w);
    return (v);
}


ALGAPI vec4 vec4smoothstep(vec4 e0, vec4 e1, vec4 x) {
    vec4 v;

    v.x = smoothstep(e0.x, e1.x, x.x);
    v.y = smoothstep(e0.y, e1.y, x.y);
    v.z = smoothstep(e0.z, e1.z, x.z);
    v.w = smoothstep(e0.w, e1.w, x.w);
    return (v);
}

/* Geometric operations */

ALGAPI vec4 vec4reflect(vec4 a, vec4 n) {
    float dot = vec4dot(a, n);
    vec4  v;

    v.x = a.x - 2.0f * dot * n.x;
    v.y = a.y - 2.0f * dot * n.y;
    v.z = a.z - 2.0f * dot * n.z;
    v.w = a.w - 2.0f * dot * n.w;
    return (v);
}


ALGAPI vec4 vec4refract(vec4 a, vec4 n, float eta) { }


ALGAPI float vec4angle(vec4 a, vec4 b) { }

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec4_h_ */
