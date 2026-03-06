#if !defined (_vec3_h_)
# define _vec3_h_ 1
#
# include <math.h>

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

    float ptr[3];
};

extern const vec3 vec3Zero(void);

extern const vec3 vec3One(void);

extern const vec3 vec3Right(void);

extern const vec3 vec3Left(void);

extern const vec3 vec3Up(void);

extern const vec3 vec3Down(void);

extern const vec3 vec3Front(void);

extern const vec3 vec3Back(void);

extern vec3 vec3Add(vec3, vec3);

extern vec3 vec3Sub(vec3, vec3);

extern vec3 vec3Mul(vec3, vec3);

extern vec3 vec3Div(vec3, vec3);

extern vec3 vec3Addf(vec3, float);

extern vec3 vec3Subf(vec3, float);

extern vec3 vec3Mulf(vec3, float);

extern vec3 vec3Divf(vec3, float);

extern bool vec3Equal(vec3, vec3);

extern bool vec3NoEqual(vec3, vec3);

extern bool vec3Great(vec3, vec3);

extern bool vec3GreatEqual(vec3, vec3);

extern bool vec3Less(vec3, vec3);

extern bool vec3LessEqual(vec3, vec3);

extern float vec3Dot(vec3, vec3);

extern float vec3Length(vec3);

extern float vec3Distance(vec3, vec3);

extern vec3 vec3Cross(vec3, vec3);

extern vec3 vec3Normalize(vec3);

# if defined (ALGEBRA_IMPLEMENTATION)

extern const vec3 vec3Zero(void) {
    return ((vec3) { 0.0, 0.0, 0.0 } );
}

extern const vec3 vec3One(void) {
    return ((vec3) { 1.0, 1.0, 1.0 } );
}

extern const vec3 vec3Right(void) {
    return ((vec3) { 1.0, 0.0, 0.0 } );
}

extern const vec3 vec3Left(void) {
    return ((vec3) { -1.0, 0.0, 0.0 } );
}

extern const vec3 vec3Up(void) {
    return ((vec3) { 0.0, 1.0, 0.0 } );
}

extern const vec3 vec3Down(void) {
    return ((vec3) { 0.0, -1.0, 0.0 } );
}

extern const vec3 vec3Front(void) {
    return ((vec3) { 0.0, 0.0, 1.0 } );
}

extern const vec3 vec3Back(void) {
    return ((vec3) { 0.0, 0.0, -1.0 } );
}

extern vec3 vec3Add(vec3 a, vec3 b) {
    return ((vec3) { .x = a.x + b.x,
                     .y = a.y + b.y,
                     .z = a.z + b.z } );
}

extern vec3 vec3Sub(vec3 a, vec3 b) {
    return ((vec3) { .x = a.x - b.x,
                     .y = a.y - b.y,
                     .z = a.z - b.z } );
}

extern vec3 vec3Mul(vec3 a, vec3 b) {
    return ((vec3) { .x = a.x * b.x,
                     .y = a.y * b.y,
                     .z = a.z * b.z } );
}

extern vec3 vec3Div(vec3 a, vec3 b) {
    return ((vec3) { .x = b.x != 0.0 ? a.x / b.x : 0.0,
                     .y = b.y != 0.0 ? a.y / b.y : 0.0,
                     .z = b.z != 0.0 ? a.z / b.z : 0.0 } );
}

extern vec3 vec3Addf(vec3 a, float f) {
    return ((vec3) { .x = a.x + f,
                     .y = a.y + f,
                     .z = a.z + f } );
}

extern vec3 vec3Subf(vec3 a, float f) {
    return ((vec3) { .x = a.x - f,
                     .y = a.y - f,
                     .z = a.z - f } );
}

extern vec3 vec3Mulf(vec3 a, float f) {
    return ((vec3) { .x = a.x * f,
                     .y = a.y * f,
                     .z = a.z * f } );
}

extern vec3 vec3Divf(vec3 a, float f) {
    return ((vec3) { .x = f != 0.0 ? a.x / f : 0.0,
                     .y = f != 0.0 ? a.y / f : 0.0,
                     .z = f != 0.0 ? a.z / f : 0.0 } );
}

extern bool vec3Equal(vec3 a, vec3 b) {
    return (a.x == b.x &&
            a.y == b.y &&
            a.z == b.z);
}

extern bool vec3NoEqual(vec3 a, vec3 b) {
    return (a.x != b.x ||
            a.y != b.y ||
            a.z != b.z);
}

extern bool vec3Great(vec3 a, vec3 b) {
    return (a.x > b.x ||
            a.y > b.y ||
            a.z > b.z);
}

extern bool vec3GreatEqual(vec3 a, vec3 b) {
    return (a.x >= b.x ||
            a.y >= b.y ||
            a.z >= b.z);
}

extern bool vec3Less(vec3 a, vec3 b) {
    return (a.x < b.x ||
            a.y < b.y ||
            a.z < b.z);
}

extern bool vec3LessEqual(vec3 a, vec3 b) {
    return (a.x <= b.x ||
            a.y <= b.y ||
            a.z <= b.z);
}

extern float vec3Dot(vec3 a, vec3 b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

extern float vec3Length(vec3 a) {
    return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

extern float vec3Distance(vec3 a, vec3 b) {
    return (sqrt((a.x - b.x) * (a.x - b.x) +
                 (a.y - b.y) * (a.y * b.y) +
                 (a.z - b.z) * (a.z * b.z)));
}

extern vec3 vec3Cross(vec3 a, vec3 b) {
    vec3 vec;

    vec.x = a.y * b.z - a.z * b.y;
    vec.y = a.z * b.x - a.x * b.z;
    vec.z = a.x * b.y - a.y * b.x;
    return (vec);
}

extern vec3 vec3Normalize(vec3 a) {
    float len = vec3Length(a);

    vec3 vec = a;
    if (len != 0.0) {
        vec = vec3Mulf(vec, 1.0 / len);
    }
    return (vec);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec3_h_ */
