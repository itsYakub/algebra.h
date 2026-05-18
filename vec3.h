#if !defined (_vec3_h_)
# define _vec3_h_ 1
#
# include <stdbool.h>
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */

typedef union u_mat3 mat3;

typedef union u_vec3 vec3;

union u_vec3 {
    struct {
        float x;
        float y;
        float z;
    };

    struct {
        float r;
        float g;
        float b;
    };

# if defined (__cplusplus)

    u_vec3(void);

    u_vec3(float);

    u_vec3(float, float, float);

    u_vec3(const u_vec3 &);

    u_vec3 &operator = (const u_vec3 &);

# endif /* __cplusplus */

};

/* Properties */

ALGAPI vec3 vec3zero(void);

ALGAPI vec3 vec3one(void);

ALGAPI vec3 vec3right(void);

ALGAPI vec3 vec3left(void);

ALGAPI vec3 vec3up(void);

ALGAPI vec3 vec3down(void);

ALGAPI vec3 vec3front(void);

ALGAPI vec3 vec3back(void);

/* Math operations */

ALGAPI vec3 vec3add(vec3, vec3);

ALGAPI vec3 vec3sub(vec3, vec3);

ALGAPI vec3 vec3mul(vec3, vec3);

ALGAPI vec3 vec3div(vec3, vec3);

ALGAPI vec3 vec3addf(vec3, float);

ALGAPI vec3 vec3subf(vec3, float);

ALGAPI vec3 vec3mulf(vec3, float);

ALGAPI vec3 vec3divf(vec3, float);

ALGAPI vec3 vec3mulm(vec3, mat3);

/* Boolean expressions */

ALGAPI bool vec3eq(vec3, vec3);

ALGAPI bool vec3noeq(vec3, vec3);

ALGAPI bool vec3great(vec3, vec3);

ALGAPI bool vec3greateq(vec3, vec3);

ALGAPI bool vec3less(vec3, vec3);

ALGAPI bool vec3lesseq(vec3, vec3);

/* Distance operations */

ALGAPI float vec3len(vec3);

ALGAPI float vec3lensq(vec3);

ALGAPI float vec3dist(vec3, vec3);

ALGAPI float vec3distsq(vec3, vec3);

/* Unary arithmetics */

ALGAPI float vec3dot(vec3, vec3);

ALGAPI vec3  vec3cross(vec3, vec3);

ALGAPI vec3  vec3norm(vec3);

ALGAPI vec3  vec3neg(vec3);

ALGAPI vec3  vec3abs(vec3);

ALGAPI vec3  vec3sign(vec3);

ALGAPI vec3  vec3sqrt(vec3);

ALGAPI vec3  vec3pow(vec3, float);

ALGAPI vec3  vec3fract(vec3);

ALGAPI vec3  vec3floor(vec3);

ALGAPI vec3  vec3ceil(vec3);

ALGAPI vec3  vec3round(vec3);

ALGAPI vec3  vec3mod(vec3, vec3);

ALGAPI vec3  vec3modf(vec3, float);

/* Constraints */

ALGAPI vec3 vec3min(vec3, vec3);

ALGAPI vec3 vec3minf(vec3, float);

ALGAPI vec3 vec3max(vec3, vec3);

ALGAPI vec3 vec3maxf(vec3, float);

ALGAPI vec3 vec3clamp(vec3, vec3, vec3);

ALGAPI vec3 vec3clampf(vec3, float, float);

/* Interpolation */

ALGAPI vec3 vec3lerp(vec3, vec3, float);

ALGAPI vec3 vec3step(vec3, vec3);

ALGAPI vec3 vec3smoothstep(vec3, vec3, vec3);

/* Geometric operations */

ALGAPI vec3  vec3reflect(vec3, vec3);

ALGAPI vec3  vec3refract(vec3, vec3, float);

ALGAPI vec3  vec3project(vec3, vec3);

ALGAPI vec3  vec3reject(vec3, vec3);

ALGAPI vec3  vec3rotate(vec3, vec3, float);

ALGAPI float vec3angle(vec3, vec3);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include <math.h>
#
#  include "./mat3.h"
#  include "./utils.h"
#
#  if defined (__cplusplus)

u_vec3::u_vec3(void) : x(0.0f), y(0.0f), z(0.0f) { }


u_vec3::u_vec3(float v) : x(v), y(v), z(v) { }


u_vec3::u_vec3(float x, float y, float z) : x(x), y(y), z(z) { }


u_vec3::u_vec3(const u_vec3 &other) : x(other.x), y(other.y), z(other.z) { }


u_vec3 &u_vec3::operator = (const u_vec3 &other) {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    return (*this);
}

#  endif /* __cplusplus */

/* Properties */

ALGAPI vec3 vec3zero(void) {
    vec3 v;

    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    return (v);
}


ALGAPI vec3 vec3one(void) {
    vec3 v;

    v.x = 1.0f;
    v.y = 1.0f;
    v.z = 1.0f;
    return (v);
}


ALGAPI vec3 vec3right(void) {
    vec3 v;

    v.x = 1.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    return (v);
}


ALGAPI vec3 vec3left(void) {
    vec3 v;

    v.x = -1.0f;
    v.y =  0.0f;
    v.z =  0.0f;
    return (v);
}


ALGAPI vec3 vec3up(void) {
    vec3 v;

    v.x = 0.0f;
    v.y = 1.0f;
    v.z = 0.0f;
    return (v);
}


ALGAPI vec3 vec3down(void) {
    vec3 v;

    v.x =  0.0f;
    v.y = -1.0f;
    v.z =  0.0f;
    return (v);
}


ALGAPI vec3 vec3front(void) {
    vec3 v;

    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 1.0f;
    return (v);
}


ALGAPI vec3 vec3back(void) {
    vec3 v;

    v.x =  0.0f;
    v.y =  0.0f;
    v.z = -1.0f;
    return (v);
}

/* Math operations */

ALGAPI vec3 vec3add(vec3 a, vec3 b) {
    vec3 v;

    v.x = a.x + b.x;
    v.y = a.y + b.y;
    v.z = a.z + b.z;
    return (v);
}


ALGAPI vec3 vec3sub(vec3 a, vec3 b) {
    vec3 v;

    v.x = a.x - b.x;
    v.y = a.y - b.y;
    v.z = a.z - b.z;
    return (v);
}


ALGAPI vec3 vec3mul(vec3 a, vec3 b) {
    vec3 v;

    v.x = a.x * b.x;
    v.y = a.y * b.y;
    v.z = a.z * b.z;
    return (v);
}


ALGAPI vec3 vec3div(vec3 a, vec3 b) {
    vec3 v;

    v.x = b.x != 0.0f ? a.x / b.x : 0.0f;
    v.y = b.y != 0.0f ? a.y / b.y : 0.0f;
    v.z = b.z != 0.0f ? a.z / b.z : 0.0f;
    return (v);
}


ALGAPI vec3 vec3addf(vec3 a, float f) {
    vec3 v;

    v.x = a.x + f;
    v.y = a.y + f;
    v.z = a.z + f;
    return (v);
}


ALGAPI vec3 vec3subf(vec3 a, float f) {
    vec3 v;

    v.x = a.x - f;
    v.y = a.y - f;
    v.z = a.z - f;
    return (v);
}


ALGAPI vec3 vec3mulf(vec3 a, float f) {
    vec3 v;

    v.x = a.x * f;
    v.y = a.y * f;
    v.z = a.z * f;
    return (v);
}


ALGAPI vec3 vec3divf(vec3 a, float f) {
    vec3 v;

    v.x = f != 0.0f ? a.x / f : 0.0f;
    v.y = f != 0.0f ? a.y / f : 0.0f;
    v.z = f != 0.0f ? a.z / f : 0.0f;
    return (v);
}


ALGAPI vec3 vec3mulm(vec3 a, mat3 m) {
    vec3 v;

    v.x = m.m00 * a.x + m.m10 * a.y + m.m20 * a.z;
    v.y = m.m01 * a.x + m.m11 * a.y + m.m21 * a.z;
    v.z = m.m02 * a.x + m.m12 * a.y + m.m22 * a.z;
    return (v);
}

/* Boolean expressions */

ALGAPI bool vec3eq(vec3 a, vec3 b) {
    return (a.x == b.x &&
            a.y == b.y &&
            a.z == b.z);
}


ALGAPI bool vec3noeq(vec3 a, vec3 b) {
    return (a.x != b.x ||
            a.y != b.y ||
            a.z != b.z);
}


ALGAPI bool vec3great(vec3 a, vec3 b) {
    return (a.x > b.x ||
            a.y > b.y ||
            a.z > b.z);
}


ALGAPI bool vec3greateq(vec3 a, vec3 b) {
    return (a.x >= b.x ||
            a.y >= b.y ||
            a.z >= b.z);
}


ALGAPI bool vec3less(vec3 a, vec3 b) {
    return (a.x < b.x ||
            a.y < b.y ||
            a.z < b.z);
}


ALGAPI bool vec3lesseq(vec3 a, vec3 b) {
    return (a.x <= b.x ||
            a.y <= b.y ||
            a.z <= b.z);
}

/* Distance operations */

ALGAPI float vec3len(vec3 a) {
    return (sqrtf(a.x * a.x + a.y * a.y + a.z * a.z));
}


ALGAPI float vec3lensq(vec3 a) {
    return (a.x * a.x + a.y * a.y + a.z * a.z);
}


ALGAPI float vec3dist(vec3 a, vec3 b) {
    return (sqrtf((a.x - b.x) * (a.x - b.x) +
                  (a.y - b.y) * (a.y - b.y) +
                  (a.z - b.z) * (a.z - b.z)));
}


ALGAPI float vec3distsq(vec3 a, vec3 b) {
    return ((a.x - b.x) * (a.x - b.x) +
            (a.y - b.y) * (a.y - b.y) +
            (a.z - b.z) * (a.z - b.z));
}

/* Unary arithmetics */

ALGAPI float vec3dot(vec3 a, vec3 b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}


ALGAPI vec3 vec3cross(vec3 a, vec3 b) {
    vec3 v;

    v.x = a.y * b.z - a.z * b.y;
    v.y = a.z * b.x - a.x * b.z;
    v.z = a.x * b.y - a.y * b.x;
    return (v);
}


ALGAPI vec3 vec3norm(vec3 a) {
    float len = vec3len(a);

    if (len != 0.0f) {
        a.x *= 1.0f / len;
        a.y *= 1.0f / len;
        a.z *= 1.0f / len;
    }
    return (a);
}


ALGAPI vec3 vec3neg(vec3 a) {
    a.x = -a.x;
    a.y = -a.y;
    a.z = -a.z;
    return (a);
}


ALGAPI vec3 vec3abs(vec3 a) {
    a.x = fabsf(a.x);
    a.y = fabsf(a.y);
    a.z = fabsf(a.z);
    return (a);
}


ALGAPI vec3 vec3sign(vec3 a) {
    a.x = a.x > 0.0f ? 1.0f : (a.x < 0.0f ? -1.0f : 0.0f);
    a.y = a.y > 0.0f ? 1.0f : (a.y < 0.0f ? -1.0f : 0.0f);
    a.z = a.z > 0.0f ? 1.0f : (a.z < 0.0f ? -1.0f : 0.0f);
    return (a);
}


ALGAPI vec3 vec3sqrt(vec3 a) {
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    a.z = sqrtf(a.z);
    return (a);
}


ALGAPI vec3 vec3pow(vec3 a, float f) {
    a.x = powf(a.x, f);
    a.y = powf(a.y, f);
    a.z = powf(a.z, f);
    return (a);
}


ALGAPI vec3 vec3fract(vec3 a) {
    a.x = fract(a.x);
    a.y = fract(a.y);
    a.z = fract(a.z);
    return (a);
}


ALGAPI vec3 vec3floor(vec3 a) {
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    a.z = floorf(a.z);
    return (a);
}


ALGAPI vec3 vec3ceil(vec3 a) {
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    a.z = ceilf(a.z);
    return (a);
}


ALGAPI vec3 vec3round(vec3 a) {
    a.x = roundf(a.x);
    a.y = roundf(a.y);
    a.z = roundf(a.z);
    return (a);
}


ALGAPI vec3 vec3mod(vec3 a, vec3 b) {
    vec3 v;

    v.x = a.x - b.x * floorf(a.x / b.x);
    v.y = a.y - b.y * floorf(a.y / b.y);
    v.z = a.z - b.z * floorf(a.z / b.z);
    return (v);
}


ALGAPI vec3 vec3modf(vec3 a, float f) {
    vec3 v;

    v.x = a.x - f * floorf(a.x / f);
    v.y = a.y - f * floorf(a.y / f);
    v.z = a.z - f * floorf(a.z / f);
    return (v);
}

/* Constraints */

ALGAPI vec3 vec3min(vec3 a, vec3 b) {
    vec3 v;

    v.x = min(a.x, b.x);
    v.y = min(a.y, b.y);
    v.z = min(a.z, b.z);
    return (v);
}


ALGAPI vec3 vec3minf(vec3 a, float f) {
    vec3 v;

    v.x = min(a.x, f);
    v.y = min(a.y, f);
    v.z = min(a.z, f);
    return (v);
}


ALGAPI vec3 vec3max(vec3 a, vec3 b) {
    vec3 v;

    v.x = max(a.x, b.x);
    v.y = max(a.y, b.y);
    v.z = max(a.z, b.z);
    return (v);
}


ALGAPI vec3 vec3maxf(vec3 a, float f) {
    vec3 v;

    v.x = max(a.x, f);
    v.y = max(a.y, f);
    v.z = max(a.z, f);
    return (v);
}


ALGAPI vec3 vec3clamp(vec3 a, vec3 lo, vec3 hi) {
    vec3 v;

    v.x = clamp(a.x, lo.x, hi.x);
    v.y = clamp(a.y, lo.y, hi.y);
    v.z = clamp(a.z, lo.z, hi.z);
    return (v);
}


ALGAPI vec3 vec3clampf(vec3 a, float lo, float hi) {
    vec3 v;

    v.x = clamp(a.x, lo, hi);
    v.y = clamp(a.y, lo, hi);
    v.z = clamp(a.z, lo, hi);
    return (v);
}

/* Interpolation */

ALGAPI vec3 vec3lerp(vec3 a, vec3 b, float t) {
    vec3 v;

    v.x = lerp(a.x, b.x, t);
    v.y = lerp(a.y, b.y, t);
    v.z = lerp(a.z, b.z, t);
    return (v);
}


ALGAPI vec3 vec3step(vec3 a, vec3 x) {
    vec3 v;

    v.x = step(a.x, x.x);
    v.y = step(a.y, x.y);
    v.z = step(a.z, x.z);
    return (v);
}


ALGAPI vec3 vec3smoothstep(vec3 e0, vec3 e1, vec3 x) {
    vec3 v;

    v.x = smoothstep(e0.x, e1.x, x.x);
    v.y = smoothstep(e0.y, e1.y, x.y);
    v.z = smoothstep(e0.z, e1.z, x.z);
    return (v);
}

/* Geometric operations */

ALGAPI vec3 vec3reflect(vec3 a, vec3 n) {
    float dot = vec3dot(a, n);
    vec3  v;

    v.x = a.x - 2.0f * dot * n.x;
    v.y = a.y - 2.0f * dot * n.y;
    v.z = a.z - 2.0f * dot * n.z;
    return (v);
}


ALGAPI vec3 vec3refract(vec3 a, vec3 n, float eta) {
    float dot = vec3dot(a, n);
    float d   = 1.0f - eta * eta * (1.0 - dot * dot);

    vec3 v = vec3zero();
    if (d >= 0) {
        d = sqrtf(d);
        v.x = eta * a.x - (eta * dot + d) * n.x;
        v.y = eta * a.y - (eta * dot + d) * n.y;
        v.z = eta * a.z - (eta * dot + d) * n.z;
    }

    return (v);
}


ALGAPI vec3 vec3project(vec3 a, vec3 b) {
    float len0 = vec3lensq(a);
    float len1 = vec3lensq(b);
    float mag  = len0 / len1;

    vec3 v;
    v.x = b.x * mag;
    v.y = b.y * mag;
    v.z = b.z * mag;
    return (v);
}


ALGAPI vec3 vec3reject(vec3 a, vec3 b) {
    float len0 = vec3lensq(a);
    float len1 = vec3lensq(b);
    float mag  = len0 / len1;

    vec3 v;
    v.x = a.x - b.x * mag;
    v.y = a.y - b.y * mag;
    v.z = a.z - b.z * mag;
    return (v);
}


/* Euler-Rodrigues Formula:
 *      
 *      v' = v + 2a(w * x) + 2(w * (w * x))
 *
 * - https://en.wikipedia.org/w/index.php?title=Euler%E2%80%93Rodrigues_formula
 * - https://en.wikipedia.org/w/index.php?title=Euler%E2%80%93Rodrigues_formula#Vector_formulation
 * */
ALGAPI vec3 vec3rotate(vec3 x, vec3 axis, float angle) {
    float a = cosf(angle / 2.0);

    vec3  n = vec3norm(axis);
    float s = sinf(angle / 2.0);
    float b = n.x * s;
    float c = n.y * s;
    float d = n.z * s;

    vec3 w;
    w.x = b, w.y = c, w.z = d;
    
    vec3 v;
    v.x = x.x + 2.0 * a * (w.x * x.x) + 2.0 * (w.x * (w.x * x.x));
    v.y = x.y + 2.0 * a * (w.y * x.y) + 2.0 * (w.y * (w.y * x.y));
    v.z = x.z + 2.0 * a * (w.z * x.z) + 2.0 * (w.z * (w.z * x.z));
    return (v);
}


ALGAPI float vec3angle(vec3 a, vec3 b) {
    vec3 cross = vec3cross(a, b);

    float len = vec3len(cross);
    float dot = vec3dot(a, b);

    return (atan2f(len, dot));

}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec3_h_ */
