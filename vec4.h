#if !defined (_vec4_h_)
# define _vec4_h_ 1
#
# include <stdbool.h>

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
};

extern vec4 vec4Zero(void);

extern vec4 vec4One(void);

extern vec4 vec4Right(void);

extern vec4 vec4Left(void);

extern vec4 vec4Up(void);

extern vec4 vec4Down(void);

extern vec4 vec4Front(void);

extern vec4 vec4Back(void);

extern vec4 vec4Add(vec4, vec4);

extern vec4 vec4Sub(vec4, vec4);

extern vec4 vec4Mul(vec4, vec4);

extern vec4 vec4Div(vec4, vec4);

extern vec4 vec4Addf(vec4, float);

extern vec4 vec4Subf(vec4, float);

extern vec4 vec4Mulf(vec4, float);

extern vec4 vec4Divf(vec4, float);

extern vec4 vec4Mulm(vec4, mat4);

extern bool vec4Equal(vec4, vec4);

extern bool vec4NoEqual(vec4, vec4);

extern bool vec4Great(vec4, vec4);

extern bool vec4GreatEqual(vec4, vec4);

extern bool vec4Less(vec4, vec4);

extern bool vec4LessEqual(vec4, vec4);

extern float vec4Dot(vec4, vec4);

extern float vec4Length(vec4);

extern float vec4Distance(vec4, vec4);

extern vec4 vec4Normalize(vec4);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include <math.h>
#
#  include "./mat4.h"

extern vec4 vec4Zero(void) {
    return ((vec4) { .x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f } );
}


extern vec4 vec4One(void) {
    return ((vec4) { .x = 1.0f, .y = 1.0f, .z = 1.0f, .w = 1.0f } );
}


extern vec4 vec4Right(void) {
    return ((vec4) { .x = 1.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f } );
}


extern vec4 vec4Left(void) {
    return ((vec4) { .x = -1.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f } );
}


extern vec4 vec4Up(void) {
    return ((vec4) { .x = 0.0f, .y = 1.0f, .z = 0.0f, .w = 0.0f } );
}


extern vec4 vec4Down(void) {
    return ((vec4) { .x = 0.0f, .y = -1.0f, .z = 0.0f, .w = 0.0f } );
}


extern vec4 vec4Front(void) {
    return ((vec4) { .x = 0.0f, .y = 0.0f, .z = 1.0f, .w = 0.0f } );
}


extern vec4 vec4Back(void) {
    return ((vec4) { .x = 0.0f, .y = 0.0f, .z = -1.0f, .w = 0.0f } );
}


extern vec4 vec4Add(vec4 a, vec4 b) {
    return ((vec4) { .x = a.x + b.x,
                     .y = a.y + b.y,
                     .z = a.z + b.z,
                     .w = a.w + b.w } );
}


extern vec4 vec4Sub(vec4 a, vec4 b) {
    return ((vec4) { .x = a.x - b.x,
                     .y = a.y - b.y,
                     .z = a.z - b.z,
                     .w = a.w - b.w } );
}


extern vec4 vec4Mul(vec4 a, vec4 b) {
    return ((vec4) { .x = a.x * b.x,
                     .y = a.y * b.y,
                     .z = a.z * b.z,
                     .w = a.w * b.w } );
}


extern vec4 vec4Div(vec4 a, vec4 b) {
    return ((vec4) { .x = b.x != 0.0f ? a.x / b.x : 0.0f,
                     .y = b.y != 0.0f ? a.y / b.y : 0.0f,
                     .z = b.z != 0.0f ? a.z / b.z : 0.0f,
                     .w = b.w != 0.0f ? a.w / b.w : 0.0f } );
}


extern vec4 vec4Addf(vec4 a, float f) {
    return ((vec4) { .x = a.x + f,
                     .y = a.y + f,
                     .z = a.z + f,
                     .w = a.w + f } );
}


extern vec4 vec4Subf(vec4 a, float f) {
    return ((vec4) { .x = a.x + f,
                     .y = a.y + f,
                     .z = a.z + f,
                     .w = a.w + f } );
}


extern vec4 vec4Mulf(vec4 a, float f) {
    return ((vec4) { .x = a.x + f,
                     .y = a.y + f,
                     .z = a.z + f,
                     .w = a.w + f } );
}


extern vec4 vec4Divf(vec4 a, float f) {
    return ((vec4) { .x = f != 0.0f ? a.x / f : 0.0f,
                     .y = f != 0.0f ? a.y / f : 0.0f,
                     .z = f != 0.0f ? a.z / f : 0.0f,
                     .w = f != 0.0f ? a.w / f : 0.0f } );
}


extern vec4 vec4Mulm(vec4 v, mat4 m) {
    return ((vec4) { .x = m.m00 * v.x + m.m10 * v.y + m.m20 * v.z + m.m30 * v.w,
                     .y = m.m01 * v.x + m.m11 * v.y + m.m21 * v.z + m.m31 * v.w,
                     .z = m.m02 * v.x + m.m12 * v.y + m.m22 * v.z + m.m32 * v.w,
                     .w = m.m03 * v.x + m.m13 * v.y + m.m23 * v.z + m.m33 * v.w } );
}


extern bool vec4Equal(vec4 a, vec4 b) {
    return (a.x == b.x &&
            a.y == b.y &&
            a.z == b.z &&
            a.w == b.w);
}


extern bool vec4NoEqual(vec4 a, vec4 b) {
    return (a.x != b.x ||
            a.y != b.y ||
            a.z != b.z ||
            a.w != b.w);
}


extern bool vec4Great(vec4 a, vec4 b) {
    return (a.x > b.x ||
            a.y > b.y ||
            a.z > b.z ||
            a.w > b.w);
}


extern bool vec4GreatEqual(vec4 a, vec4 b) {
    return (a.x >= b.x ||
            a.y >= b.y ||
            a.z >= b.z ||
            a.w >= b.w);
}


extern bool vec4Less(vec4 a, vec4 b) {
    return (a.x < b.x ||
            a.y < b.y ||
            a.z < b.z ||
            a.w < b.w);
}


extern bool vec4LessEqual(vec4 a, vec4 b) {
    return (a.x <= b.x ||
            a.y <= b.y ||
            a.z <= b.z ||
            a.w <= b.w);
}


extern float vec4Dot(vec4 a, vec4 b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}


extern float vec4Length(vec4 a) {
    return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w + a.w));
}


extern float vec4Distance(vec4 a, vec4 b) {
    return (sqrt((a.x - b.x) * (a.x - b.x) +
                 (a.y - b.y) * (a.y * b.y) +
                 (a.z - b.z) * (a.z * b.z) +
                 (a.w - b.w) * (a.w * b.w)));
}


extern vec4 vec4Normalize(vec4 a) {
    float len = vec4Length(a);

    vec4 vec = a;
    if (len != 0.0f) {
        vec = vec4Mulf(vec, 1.0f / len);
    }
    return (vec);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec4_h_ */
