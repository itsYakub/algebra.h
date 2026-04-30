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

extern vec3 vec3zero(void);

extern vec3 vec3one(void);

extern vec3 vec3right(void);

extern vec3 vec3left(void);

extern vec3 vec3up(void);

extern vec3 vec3down(void);

extern vec3 vec3front(void);

extern vec3 vec3back(void);

extern vec3 vec3add(vec3, vec3);

extern vec3 vec3sub(vec3, vec3);

extern vec3 vec3mul(vec3, vec3);

extern vec3 vec3div(vec3, vec3);

extern vec3 vec3addf(vec3, float);

extern vec3 vec3subf(vec3, float);

extern vec3 vec3mulf(vec3, float);

extern vec3 vec3divf(vec3, float);

extern vec3 vec3mulm(vec3, mat3);

extern bool vec3eq(vec3, vec3);

extern bool vec3noeq(vec3, vec3);

extern bool vec3great(vec3, vec3);

extern bool vec3greateq(vec3, vec3);

extern bool vec3less(vec3, vec3);

extern bool vec3lesseq(vec3, vec3);

extern float vec3dot(vec3, vec3);

extern float vec3len(vec3);

extern float vec3dist(vec3, vec3);

extern vec3 vec3cross(vec3, vec3);

extern vec3 vec3norm(vec3);

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

extern vec3 vec3zero(void) {
    return ((vec3) { 0.0f, 0.0f, 0.0f } );
}


extern vec3 vec3one(void) {
    return ((vec3) { 1.0f, 1.0f, 1.0f } );
}


extern vec3 vec3right(void) {
    return ((vec3) { 1.0f, 0.0f, 0.0f } );
}


extern vec3 vec3left(void) {
    return ((vec3) { -1.0f, 0.0f, 0.0f } );
}


extern vec3 vec3up(void) {
    return ((vec3) { 0.0f, 1.0f, 0.0f } );
}


extern vec3 vec3down(void) {
    return ((vec3) { 0.0f, -1.0f, 0.0f } );
}


extern vec3 vec3front(void) {
    return ((vec3) { 0.0f, 0.0f, 1.0f } );
}


extern vec3 vec3back(void) {
    return ((vec3) { 0.0f, 0.0f, -1.0f } );
}


extern vec3 vec3add(vec3 a, vec3 b) {
    return ((vec3) { a.x + b.x,
                     a.y + b.y,
                     a.z + b.z } );
}


extern vec3 vec3sub(vec3 a, vec3 b) {
    return ((vec3) { a.x - b.x,
                     a.y - b.y,
                     a.z - b.z } );
}


extern vec3 vec3mul(vec3 a, vec3 b) {
    return ((vec3) { a.x * b.x,
                     a.y * b.y,
                     a.z * b.z } );
}


extern vec3 vec3div(vec3 a, vec3 b) {
    return ((vec3) { b.x != 0.0f ? a.x / b.x : 0.0f,
                     b.y != 0.0f ? a.y / b.y : 0.0f,
                     b.z != 0.0f ? a.z / b.z : 0.0f } );
}


extern vec3 vec3addf(vec3 a, float f) {
    return ((vec3) { a.x + f,
                     a.y + f,
                     a.z + f } );
}


extern vec3 vec3subf(vec3 a, float f) {
    return ((vec3) { a.x - f,
                     a.y - f,
                     a.z - f } );
}


extern vec3 vec3mulf(vec3 a, float f) {
    return ((vec3) { a.x * f,
                     a.y * f,
                     a.z * f } );
}


extern vec3 vec3divf(vec3 a, float f) {
    return ((vec3) { f != 0.0f ? a.x / f : 0.0f,
                     f != 0.0f ? a.y / f : 0.0f,
                     f != 0.0f ? a.z / f : 0.0f } );
}


extern vec3 vec3mulm(vec3 v, mat3 m) {
    return ((vec3) { m.m00 * v.x + m.m10 * v.y + m.m20 * v.z,
                     m.m01 * v.x + m.m11 * v.y + m.m21 * v.z,
                     m.m02 * v.x + m.m12 * v.y + m.m22 * v.z } );
}


extern bool vec3eq(vec3 a, vec3 b) {
    return (a.x == b.x &&
            a.y == b.y &&
            a.z == b.z);
}


extern bool vec3noeq(vec3 a, vec3 b) {
    return (a.x != b.x ||
            a.y != b.y ||
            a.z != b.z);
}


extern bool vec3great(vec3 a, vec3 b) {
    return (a.x > b.x ||
            a.y > b.y ||
            a.z > b.z);
}


extern bool vec3greateq(vec3 a, vec3 b) {
    return (a.x >= b.x ||
            a.y >= b.y ||
            a.z >= b.z);
}


extern bool vec3less(vec3 a, vec3 b) {
    return (a.x < b.x ||
            a.y < b.y ||
            a.z < b.z);
}


extern bool vec3lesseq(vec3 a, vec3 b) {
    return (a.x <= b.x ||
            a.y <= b.y ||
            a.z <= b.z);
}


extern float vec3dot(vec3 a, vec3 b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}


extern float vec3len(vec3 a) {
    return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}


extern float vec3dist(vec3 a, vec3 b) {
    return (sqrt((a.x - b.x) * (a.x - b.x) +
                 (a.y - b.y) * (a.y * b.y) +
                 (a.z - b.z) * (a.z * b.z)));
}


extern vec3 vec3cross(vec3 a, vec3 b) {
    vec3 vec;

    vec.x = a.y * b.z - a.z * b.y;
    vec.y = a.z * b.x - a.x * b.z;
    vec.z = a.x * b.y - a.y * b.x;
    return (vec);
}


extern vec3 vec3norm(vec3 a) {
    float len = vec3len(a);

    vec3 vec = a;
    if (len != 0.0f) {
        vec.x *= 1.0f / len;
        vec.y *= 1.0f / len;
        vec.z *= 1.0f / len;
    }
    return (vec);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec3_h_ */
