#if !defined (_vec2_h_)
# define _vec2_h_ 1
#
# include <stdbool.h>
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */

typedef union u_mat2 mat2;

typedef union u_vec2 vec2;

union u_vec2 {
    struct {
        float x;
        float y;
    };

    struct {
        float w;
        float h;
    };

# if defined (__cplusplus)

    /* Constructors */

    u_vec2(void);

    u_vec2(float);

    u_vec2(float, float);

    u_vec2(const u_vec2 &); 

    u_vec2 &operator = (const u_vec2 &);

# endif /* __cplusplus */

};

/* Properties */

ALGAPI vec2 vec2zero(void);

ALGAPI vec2 vec2one(void);

ALGAPI vec2 vec2right(void);

ALGAPI vec2 vec2left(void);

ALGAPI vec2 vec2up(void);

ALGAPI vec2 vec2down(void);

/* Math operations */

ALGAPI vec2 vec2add(vec2, vec2);

ALGAPI vec2 vec2sub(vec2, vec2);

ALGAPI vec2 vec2mul(vec2, vec2);

ALGAPI vec2 vec2div(vec2, vec2);

ALGAPI vec2 vec2addf(vec2, float);

ALGAPI vec2 vec2subf(vec2, float);

ALGAPI vec2 vec2mulf(vec2, float);

ALGAPI vec2 vec2divf(vec2, float);

ALGAPI vec2 vec2mulm(vec2, mat2);

/* Boolean expressions */

ALGAPI bool vec2eq(vec2, vec2);

ALGAPI bool vec2noeq(vec2, vec2);

ALGAPI bool vec2great(vec2, vec2);

ALGAPI bool vec2greateq(vec2, vec2);

ALGAPI bool vec2less(vec2, vec2);

ALGAPI bool vec2lesseq(vec2, vec2);

/* Distance Operations */

ALGAPI float vec2len(vec2);

ALGAPI float vec2lensq(vec2);

ALGAPI float vec2dist(vec2, vec2);

ALGAPI float vec2distsq(vec2, vec2);

/* Unary Arithmetics */

ALGAPI float vec2dot(vec2, vec2);

ALGAPI float vec2cross(vec2, vec2);

ALGAPI vec2 vec2norm(vec2);

ALGAPI vec2 vec2neg(vec2);

ALGAPI vec2 vec2abs(vec2);

ALGAPI vec2 vec2sign(vec2);

ALGAPI vec2 vec2sqrt(vec2);

ALGAPI vec2 vec2pow(vec2, float);

ALGAPI vec2 vec2fract(vec2);

ALGAPI vec2 vec2floor(vec2);

ALGAPI vec2 vec2ceil(vec2);

ALGAPI vec2 vec2round(vec2);

ALGAPI vec2 vec2mod(vec2, vec2);

ALGAPI vec2 vec2modf(vec2, float);

/* Constraints */

ALGAPI vec2 vec2min(vec2, vec2);

ALGAPI vec2 vec2minf(vec2, float);

ALGAPI vec2 vec2max(vec2, vec2);

ALGAPI vec2 vec2maxf(vec2, float);

ALGAPI vec2 vec2clamp(vec2, vec2, vec2);

ALGAPI vec2 vec2clampf(vec2, float, float);

/* Interpolation */

ALGAPI vec2 vec2lerp(vec2, vec2, float);

ALGAPI vec2 vec2step(vec2, vec2);

ALGAPI vec2 vec2smoothstep(vec2, vec2, vec2);

/* Geometric operations */

ALGAPI vec2 vec2perp(vec2);

ALGAPI vec2 vec2reflect(vec2, vec2);

ALGAPI vec2 vec2refract(vec2, vec2, float);

ALGAPI vec2 vec2rotate(vec2, float);

ALGAPI float vec2angle(vec2, vec2);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include <math.h>
#
#  include "./mat2.h"
#  include "./utils.h"

/* Properties */

ALGAPI vec2 vec2zero(void) {
    vec2 v;

    v.x = 0.0f;
    v.y = 0.0f;
    return (v);
}


ALGAPI vec2 vec2one(void) {
    vec2 v;

    v.x = 1.0f;
    v.y = 1.0f;
    return (v);
}


ALGAPI vec2 vec2right(void) {
    vec2 v;

    v.x = 1.0f;
    v.y = 0.0f;
    return (v);
}


ALGAPI vec2 vec2left(void) {
    vec2 v;

    v.x = -1.0f;
    v.y =  0.0f;
    return (v);
}


ALGAPI vec2 vec2up(void) {
    vec2 v;

    v.x = 0.0f;
    v.y = 1.0f;
    return (v);
}


ALGAPI vec2 vec2down(void) {
    vec2 v;

    v.x =  0.0f;
    v.y = -1.0f;
    return (v);
}

/* Math operations */

ALGAPI vec2 vec2add(vec2 a, vec2 b) {
    vec2 v;

    v.x = a.x + b.x;
    v.y = a.y + b.y;
    return (v);
}


ALGAPI vec2 vec2sub(vec2 a, vec2 b) {
    vec2 v;

    v.x = a.x - b.x;
    v.y = a.y - b.y;
    return (v);
}


ALGAPI vec2 vec2mul(vec2 a, vec2 b) {
    vec2 v;

    v.x = a.x * b.x;
    v.y = a.y * b.y;
    return (v);
}


ALGAPI vec2 vec2div(vec2 a, vec2 b) {
    vec2 v;

    v.x = b.x != 0.0f ? a.x / b.x : 0.0f;
    v.y = b.y != 0.0f ? a.y / b.y : 0.0f;
    return (v);
}


ALGAPI vec2 vec2addf(vec2 a, float f) {
    vec2 v;

    v.x = a.x + f;
    v.y = a.y + f;
    return (v);
}


ALGAPI vec2 vec2subf(vec2 a, float f) {
    vec2 v;

    v.x = a.x - f;
    v.y = a.y - f;
    return (v);
}


ALGAPI vec2 vec2mulf(vec2 a, float f) {
    vec2 v;

    v.x = a.x * f;
    v.y = a.y * f;
    return (v);
}


ALGAPI vec2 vec2divf(vec2 a, float f) {
    vec2 v;

    v.x = f != 0.0f ? a.x / f : 0.0f;
    v.y = f != 0.0f ? a.y / f : 0.0f;
    return (v);
}


ALGAPI vec2 vec2mulm(vec2 a, mat2 m) {
    vec2 v;

    v.x = m.m00 * a.x + m.m10 * a.y;
    v.y = m.m01 * a.x + m.m11 * a.y;
    return (v);
}

/* Boolean expressions */

ALGAPI bool vec2eq(vec2 a, vec2 b) {
    return (a.x == b.x &&
            a.y == b.y);
}


ALGAPI bool vec2noeq(vec2 a, vec2 b) {
    return (a.x != b.x ||
            a.y != b.y);
}


ALGAPI bool vec2great(vec2 a, vec2 b) {
    return (a.x > b.x ||
            a.y > b.y);
}


ALGAPI bool vec2greateq(vec2 a, vec2 b) {
    return (a.x >= b.x ||
            a.y >= b.y);
}


ALGAPI bool vec2less(vec2 a, vec2 b) {
    return (a.x < b.x ||
            a.y < b.y);
}


ALGAPI bool vec2lesseq(vec2 a, vec2 b) {
    return (a.x <= b.x ||
            a.y <= b.y);
}

/* Distance Operations */

ALGAPI float vec2len(vec2 a) {
    return (sqrtf(a.x * a.x + a.y * a.y));
}


ALGAPI float vec2lensq(vec2 a) {
    return (a.x * a.x + a.y * a.y);
}


ALGAPI float vec2dist(vec2 a, vec2 b) {
    return (sqrtf((a.x - b.x) * (a.x - b.x) +
                  (a.y - b.y) * (a.y - b.y)));
}


ALGAPI float vec2distsq(vec2 a, vec2 b) {
    return ((a.x - b.x) * (a.x - b.x) +
            (a.y - b.y) * (a.y - b.y));
}

/* Unary Arithmetics */

ALGAPI float vec2dot(vec2 a, vec2 b) {
    return (a.x * b.x + a.y * b.y);
}


ALGAPI float vec2cross(vec2 a, vec2 b) {
    return (a.x * b.y - a.y * b.x);
}


ALGAPI vec2 vec2norm(vec2 a) {
    float len = vec2len(a);

    if (len != 0.0f) {
        a.x *= 1.0f / len;
        a.y *= 1.0f / len;
    }
    return (a);
}


ALGAPI vec2 vec2neg(vec2 a) {
    a.x = -a.x;
    a.y = -a.y;
    return (a);
}


ALGAPI vec2 vec2abs(vec2 a) {
    a.x = fabsf(a.x);
    a.y = fabsf(a.y);
    return (a);
}


ALGAPI vec2 vec2sign(vec2 a) {
    a.x = a.x > 0.0f ? 1.0f : (a.x < 0.0f ? -1.0f : 0.0f);
    a.y = a.y > 0.0f ? 1.0f : (a.y < 0.0f ? -1.0f : 0.0f);
    return (a);
}


ALGAPI vec2 vec2sqrt(vec2 a) {
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    return (a);
}


ALGAPI vec2 vec2pow(vec2 a, float f) {
    a.x = powf(a.x, f);
    a.y = powf(a.y, f);
    return (a);
}


ALGAPI vec2 vec2fract(vec2 a) {
    a.x = fract(a.x);
    a.y = fract(a.y);
    return (a);
}


ALGAPI vec2 vec2floor(vec2 a) {
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    return (a);
}


ALGAPI vec2 vec2ceil(vec2 a) {
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    return (a);
}


ALGAPI vec2 vec2round(vec2 a) {
    a.x = roundf(a.x);
    a.y = roundf(a.y);
    return (a);
}


ALGAPI vec2 vec2mod(vec2 a, vec2 b) {
    vec2 v;

    v.x = a.x - b.x * floorf(a.x / b.x);
    v.y = a.y - b.y * floorf(a.y / b.y);
    return (v);
}


ALGAPI vec2 vec2modf(vec2 a, float f) {
    vec2 v;

    v.x = a.x - f * floorf(a.x / f);
    v.y = a.y - f * floorf(a.y / f);
    return (v);
}

/* Constraints */

ALGAPI vec2 vec2min(vec2 a, vec2 b) {
    vec2 v;

    v.x = min(a.x, b.x);
    v.y = min(a.y, b.y);
    return (v);
}


ALGAPI vec2 vec2minf(vec2 a, float f) {
    vec2 v;

    v.x = min(a.x, f);
    v.y = min(a.y, f);
    return (v);
}


ALGAPI vec2 vec2max(vec2 a, vec2 b) {
    vec2 v;

    v.x = max(a.x, b.x);
    v.y = max(a.y, b.y);
    return (v);
}


ALGAPI vec2 vec2maxf(vec2 a, float f) {
    vec2 v;

    v.x = max(a.x, f);
    v.y = max(a.y, f);
    return (v);
}


ALGAPI vec2 vec2clamp(vec2 a, vec2 lo, vec2 hi) {
    vec2 v;

    v.x = clamp(a.x, lo.x, hi.x);
    v.y = clamp(a.y, lo.y, hi.y);
    return (v);
}


ALGAPI vec2 vec2clampf(vec2 a, float lo, float hi) {
    vec2 v;

    v.x = clamp(a.x, lo, hi);
    v.y = clamp(a.y, lo, hi);
    return (v);
}

/* Interpolation */

ALGAPI vec2 vec2lerp(vec2 a, vec2 b, float t) {
    vec2 v;

    v.x = lerp(a.x, b.x, t);
    v.y = lerp(a.y, b.y, t);
    return (v);
}


ALGAPI vec2 vec2step(vec2 a, vec2 x) {
    vec2 v;

    v.x = step(a.x, x.x);
    v.y = step(a.y, x.y);
    return (v);
}


ALGAPI vec2 vec2smoothstep(vec2 e0, vec2 e1, vec2 x) {
    vec2 v;

    v.x = smoothstep(e0.x, e1.x, x.x);
    v.y = smoothstep(e0.y, e1.y, x.y);
    return (v);
}

/* Geometric operations */

ALGAPI vec2 vec2perp(vec2 a) {
    vec2 v;

    v.x = -a.y;
    v.y =  a.x;
    return (v);
}


ALGAPI vec2 vec2reflect(vec2 a, vec2 n) {
    float dot = vec2dot(a, n);
    vec2  v;

    v.x = a.x - 2.0f * dot * n.x;
    v.y = a.y - 2.0f * dot * n.y;
    return (v);
}


ALGAPI vec2 vec2refract(vec2 a, vec2 n, float eta) {
    float dot = vec2dot(a, n);
    float d   = 1.0f - eta * eta * (1.0 - dot * dot);

    vec2 v = vec2zero();
    if (d >= 0) {
        d = sqrtf(d);
        v.x = eta * a.x - (eta * dot + d) * n.x;
        v.y = eta * a.y - (eta * dot + d) * n.y;
    }

    return (v);
}


ALGAPI vec2 vec2rotate(vec2 a, float f) {
    float s = sinf(f);
    float c = cosf(f);
    vec2  v;

    v.x = c * a.x - s * a.y;
    v.y = s * a.x + c * a.y;
    return (v);
}


ALGAPI float vec2angle(vec2 a, vec2 b) {
    float dot = vec2dot(a, b);
    float det = a.x * b.y - a.y * b.x;

    return (atan2f(det, dot));
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec2_h_ */
