#if !defined (_vec3_h_)
# define _vec3_h_ 1
#
# include <stdbool.h>

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

extern vec3 vec3Zero(void);

extern vec3 vec3One(void);

extern vec3 vec3Right(void);

extern vec3 vec3Left(void);

extern vec3 vec3Up(void);

extern vec3 vec3Down(void);

extern vec3 vec3Front(void);

extern vec3 vec3Back(void);

extern vec3 vec3Add(vec3, vec3);

extern vec3 vec3Sub(vec3, vec3);

extern vec3 vec3Mul(vec3, vec3);

extern vec3 vec3Div(vec3, vec3);

extern vec3 vec3Addf(vec3, float);

extern vec3 vec3Subf(vec3, float);

extern vec3 vec3Mulf(vec3, float);

extern vec3 vec3Divf(vec3, float);

extern vec3 vec3Mulm(vec3, mat3);

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
#
#  include <math.h>
#
#  include "./mat3.h"
#
#  if defined (__cplusplus)

u_vec3::u_vec3(void) : x(0.0), y(0.0), z(0.0) { }


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

extern vec3 vec3Zero(void) {
    return ((vec3) { 0.0f, 0.0f, 0.0f } );
}


extern vec3 vec3One(void) {
    return ((vec3) { 1.0f, 1.0f, 1.0f } );
}


extern vec3 vec3Right(void) {
    return ((vec3) { 1.0f, 0.0f, 0.0f } );
}


extern vec3 vec3Left(void) {
    return ((vec3) { -1.0f, 0.0f, 0.0f } );
}


extern vec3 vec3Up(void) {
    return ((vec3) { 0.0f, 1.0f, 0.0f } );
}


extern vec3 vec3Down(void) {
    return ((vec3) { 0.0f, -1.0f, 0.0f } );
}


extern vec3 vec3Front(void) {
    return ((vec3) { 0.0f, 0.0f, 1.0f } );
}


extern vec3 vec3Back(void) {
    return ((vec3) { 0.0f, 0.0f, -1.0f } );
}


extern vec3 vec3Add(vec3 a, vec3 b) {
    return ((vec3) { a.x + b.x,
                     a.y + b.y,
                     a.z + b.z } );
}


extern vec3 vec3Sub(vec3 a, vec3 b) {
    return ((vec3) { a.x - b.x,
                     a.y - b.y,
                     a.z - b.z } );
}


extern vec3 vec3Mul(vec3 a, vec3 b) {
    return ((vec3) { a.x * b.x,
                     a.y * b.y,
                     a.z * b.z } );
}


extern vec3 vec3Div(vec3 a, vec3 b) {
    return ((vec3) { b.x != 0.0f ? a.x / b.x : 0.0f,
                     b.y != 0.0f ? a.y / b.y : 0.0f,
                     b.z != 0.0f ? a.z / b.z : 0.0f } );
}


extern vec3 vec3Addf(vec3 a, float f) {
    return ((vec3) { a.x + f,
                     a.y + f,
                     a.z + f } );
}


extern vec3 vec3Subf(vec3 a, float f) {
    return ((vec3) { a.x - f,
                     a.y - f,
                     a.z - f } );
}


extern vec3 vec3Mulf(vec3 a, float f) {
    return ((vec3) { a.x * f,
                     a.y * f,
                     a.z * f } );
}


extern vec3 vec3Divf(vec3 a, float f) {
    return ((vec3) { f != 0.0f ? a.x / f : 0.0f,
                     f != 0.0f ? a.y / f : 0.0f,
                     f != 0.0f ? a.z / f : 0.0f } );
}


extern vec3 vec3Mulm(vec3 v, mat3 m) {
    return ((vec3) { m.m00 * v.x + m.m10 * v.y + m.m20 * v.z,
                     m.m01 * v.x + m.m11 * v.y + m.m21 * v.z,
                     m.m02 * v.x + m.m12 * v.y + m.m22 * v.z } );
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
    if (len != 0.0f) {
        vec = vec3Mulf(vec, 1.0f / len);
    }
    return (vec);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec3_h_ */
