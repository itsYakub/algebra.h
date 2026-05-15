#if !defined (_vec2_h_)
# define _vec2_h_ 1
#
# include <stdbool.h>

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

extern vec2 vec2zero(void);

extern vec2 vec2one(void);

extern vec2 vec2right(void);

extern vec2 vec2left(void);

extern vec2 vec2up(void);

extern vec2 vec2down(void);

/* Math operations */

extern vec2 vec2add(vec2, vec2);

extern vec2 vec2sub(vec2, vec2);

extern vec2 vec2mul(vec2, vec2);

extern vec2 vec2div(vec2, vec2);

extern vec2 vec2addf(vec2, float);

extern vec2 vec2subf(vec2, float);

extern vec2 vec2mulf(vec2, float);

extern vec2 vec2divf(vec2, float);

extern vec2 vec2mulm(vec2, mat2);

/* Boolean expressions */

extern bool vec2eq(vec2, vec2);

extern bool vec2noeq(vec2, vec2);

extern bool vec2great(vec2, vec2);

extern bool vec2greateq(vec2, vec2);

extern bool vec2less(vec2, vec2);

extern bool vec2lesseq(vec2, vec2);

/* Distance Operations */

extern float vec2len(vec2);

extern float vec2lensq(vec2);

extern float vec2dist(vec2, vec2);

extern float vec2distsq(vec2, vec2);

/* Unary Arithmetics */

extern float vec2dot(vec2, vec2);

extern float vec2cross(vec2, vec2);

extern vec2 vec2norm(vec2);

extern vec2 vec2neg(vec2);

extern vec2 vec2abs(vec2);

extern vec2 vec2sign(vec2);

extern vec2 vec2sqrt(vec2);

extern vec2 vec2pow(vec2, float);

extern vec2 vec2fract(vec2);

extern vec2 vec2floor(vec2);

extern vec2 vec2ceil(vec2);

extern vec2 vec2round(vec2);

extern vec2 vec2mod(vec2, vec2);

extern vec2 vec2modf(vec2, float);

/* Constraints */

extern vec2 vec2min(vec2, vec2);

extern vec2 vec2minf(vec2, float);

extern vec2 vec2max(vec2, vec2);

extern vec2 vec2maxf(vec2, float);

extern vec2 vec2clamp(vec2, vec2, vec2);

extern vec2 vec2clampf(vec2, float, float);

/* Interpolation */

extern vec2 vec2lerp(vec2, vec2, float);

extern vec2 vec2step(vec2, vec2);

extern vec2 vec2smoothstep(vec2, vec2, vec2);

/* Geometric operations */

extern vec2 vec2perp(vec2);

extern vec2 vec2reflect(vec2, vec2);

extern vec2 vec2refract(vec2, vec2, float);

extern vec2 vec2project(vec2, vec2);

extern vec2 vec2reject(vec2, vec2);

extern vec2 vec2rotate(vec2, float);

extern float vec2angle(vec2, vec2);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include <math.h>
#
#  include "./mat2.h"
#  include "./utils.h"

/* Properties */

extern vec2 vec2zero(void) {
    return ((vec2) { .x = 0.0f,
                     .y = 0.0f } );
}


extern vec2 vec2one(void) {
    return ((vec2) { .x = 1.0f,
                     .y = 1.0f } );
}


extern vec2 vec2right(void) {
    return ((vec2) { .x = 1.0f,
                     .y = 0.0f } );
}


extern vec2 vec2left(void) {
    return ((vec2) { .x = -1.0f,
                     .y =  0.0f } );
}


extern vec2 vec2up(void) {
    return ((vec2) { .x = 0.0f,
                     .y = 1.0f } );
}


extern vec2 vec2down(void) {
    return ((vec2) { .x =  0.0f,
                     .y = -1.0f } );
}

/* Math operations */

extern vec2 vec2add(vec2 a, vec2 b) {
    return ((vec2) { .x = a.x + b.x,
                     .y = a.y + b.y } );
}


extern vec2 vec2sub(vec2 a, vec2 b) {
    return ((vec2) { .x = a.x - b.x,
                     .y = a.y - b.y } );
}


extern vec2 vec2mul(vec2 a, vec2 b) {
    return ((vec2) { .x = a.x * b.x,
                     .y = a.y * b.y } );
}


extern vec2 vec2div(vec2 a, vec2 b) {
    return ((vec2) { .x = b.x != 0.0f ? a.x / b.x : 0.0f,
                     .y = b.y != 0.0f ? a.y / b.y : 0.0f } );
}


extern vec2 vec2addf(vec2 a, float f) {
    return ((vec2) { .x = a.x + f,
                     .y = a.y + f } );
}


extern vec2 vec2subf(vec2 a, float f) {
    return ((vec2) { .x = a.x - f,
                     .y = a.y - f } );
}


extern vec2 vec2mulf(vec2 a, float f) {
    return ((vec2) { .x = a.x * f,
                     .y = a.y * f } );
}


extern vec2 vec2divf(vec2 a, float f) {
    return ((vec2) { .x = f != 0.0f ? a.x / f : 0.0f,
                     .y = f != 0.0f ? a.y / f : 0.0f } );
}


extern vec2 vec2mulm(vec2 v, mat2 m) {
    return ((vec2) { .x = m.m00 * v.x + m.m10 * v.y,
                     .y = m.m01 * v.x + m.m11 * v.y } );
}

/* Boolean expressions */

extern bool vec2eq(vec2 a, vec2 b) {
    return (a.x == b.x &&
            a.y == b.y);
}


extern bool vec2noeq(vec2 a, vec2 b) {
    return (a.x != b.x ||
            a.y != b.y);
}


extern bool vec2great(vec2 a, vec2 b) {
    return (a.x > b.x ||
            a.y > b.y);
}


extern bool vec2greateq(vec2 a, vec2 b) {
    return (a.x >= b.x ||
            a.y >= b.y);
}


extern bool vec2less(vec2 a, vec2 b) {
    return (a.x < b.x ||
            a.y < b.y);
}


extern bool vec2lesseq(vec2 a, vec2 b) {
    return (a.x <= b.x ||
            a.y <= b.y);
}

/* Distance Operations */

extern float vec2len(vec2 a) {
    return (sqrt(a.x * a.x + a.y * a.y));
}


extern float vec2lensq(vec2 a) {
    return (a.x * a.x + a.y * a.y);
}


extern float vec2dist(vec2 a, vec2 b) {
    return (sqrt((a.x - b.x) * (a.x - b.x) +
                 (a.y - b.y) * (a.y * b.y)));
}


extern float vec2distsq(vec2 a, vec2 b) {
    return ((a.x - b.x) * (a.x - b.x) +
            (a.y - b.y) * (a.y * b.y));
}

/* Unary Arithmetics */

extern float vec2dot(vec2 a, vec2 b) {
    return (a.x * b.x + a.y * b.y);
}


extern float vec2cross(vec2 a, vec2 b) {
    return (a.x * b.y - a.y * b.x);
}


extern vec2 vec2norm(vec2 a) {
    float len = vec2len(a);

    vec2 vec = a;
    if (len != 0.0f) {
        vec.x *= 1.0f / len;
        vec.y *= 1.0f / len;
    }
    return (vec);
}


extern vec2 vec2neg(vec2 a) { }


extern vec2 vec2abs(vec2 a) {
    return ((vec2) {
                .x = fabsf(a.x),
                .y = fabsf(a.y)
            } );
}


extern vec2 vec2sign(vec2 a) { }


extern vec2 vec2sqrt(vec2 a) {
    return ((vec2) {
                .x = sqrtf(a.x),
                .y = sqrtf(a.y)
            } );
}


extern vec2 vec2pow(vec2 a, float f) {
    return ((vec2) {
                .x = powf(a.x, f),
                .y = powf(a.y, f)
            } );
}


extern vec2 vec2fract(vec2 a) {
    return ((vec2) {
                .x = fract(a.x),
                .y = fract(a.y)
            } );
}


extern vec2 vec2floor(vec2 a) {
    return ((vec2) {
                .x = floorf(a.x),
                .y = floorf(a.y)
            } );
}


extern vec2 vec2ceil(vec2 a) {
    return ((vec2) {
                .x = ceilf(a.x),
                .y = ceilf(a.y)
            } );
}


extern vec2 vec2round(vec2 a) {
    return ((vec2) {
                .x = roundf(a.x),
                .y = roundf(a.y)
            } );
}


extern vec2 vec2mod(vec2 a, vec2 b) {
    return ((vec2) {
                .x = a.x - b.x * floorf(a.x / b.x),
                .y = a.y - b.y * floorf(a.y / b.y)
            } );
}


extern vec2 vec2modf(vec2 a, float f) {
    return ((vec2) {
                .x = a.x - f * floorf(a.x / f),
                .y = a.y - f * floorf(a.y / f)
            } );
}

/* Constraints */

extern vec2 vec2min(vec2 a, vec2 b) {
    return ((vec2) {
                .x = min(a.x, b.x),
                .y = min(a.y, b.y)
            } );
}


extern vec2 vec2minf(vec2 a, float f) {
    return ((vec2) {
                .x = min(a.x, f),
                .y = min(a.y, f)
            } );
}


extern vec2 vec2max(vec2 a, vec2 b) {
    return ((vec2) {
                .x = max(a.x, b.x),
                .y = max(a.y, b.y)
            } );
}


extern vec2 vec2maxf(vec2 a, float f) {
    return ((vec2) {
                .x = max(a.x, f),
                .y = max(a.y, f)
            } );
}


extern vec2 vec2clamp(vec2 a, vec2 min, vec2 max) {
    return ((vec2) {
                .x = clamp(a.x, min.x, max.x),
                .y = clamp(a.y, min.y, max.y)
            } );
}


extern vec2 vec2clampf(vec2 a, float min, float max) {
    return ((vec2) {
                .x = clamp(a.x, min, max),
                .y = clamp(a.y, min, max)
            } );
}

/* Interpolation */

extern vec2 vec2lerp(vec2 a, vec2 b, float t) {
    return ((vec2) {
                .x = lerp(a.x, b.x, t),
                .y = lerp(a.y, b.y, t)
            } );
}


extern vec2 vec2step(vec2 a, vec2 x) {
    return ((vec2) {
                .x = step(a.x, x.x),
                .y = step(a.y, x.y)
            } );
}


extern vec2 vec2smoothstep(vec2 e0, vec2 e1, vec2 x) {
    return ((vec2) {
                .x = smoothstep(e0.x, e1.x, x.x),
                .y = smoothstep(e0.y, e1.y, x.y)
            } );
}

/* Geometric operations */

extern vec2 vec2perp(vec2 a) {
    return ((vec2) {
                .x =  a.x,
                .y = -a.y 
            } );
}


extern vec2 vec2reflect(vec2 a, vec2 b) {
    float dot = vec2dot(a, b);

    return ((vec2) {
                .x = a.x - 2.0 * dot * b.x,
                .y = a.y - 2.0 * dot * b.y
            } );
}


extern vec2 vec2refract(vec2 a, vec2 n, float eta) { }


extern vec2 vec2project(vec2 a, vec2 b) { }


extern vec2 vec2reject(vec2 a, vec2 b) { }


extern vec2 vec2rotate(vec2 a, float f) { }


extern float vec2angle(vec2 a, vec2 b) { }

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec2_h_ */
