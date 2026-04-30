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

# if defined (__cplusplus)

    u_vec4(void);

    u_vec4(float);

    u_vec4(float, float, float, float);

    u_vec4(const u_vec4 &); 

    u_vec4 &operator = (const u_vec4 &);

# endif /* __cplusplus */

};

extern vec4 vec4zero(void);

extern vec4 vec4one(void);

extern vec4 vec4right(void);

extern vec4 vec4left(void);

extern vec4 vec4up(void);

extern vec4 vec4down(void);

extern vec4 vec4front(void);

extern vec4 vec4back(void);

extern vec4 vec4add(vec4, vec4);

extern vec4 vec4sub(vec4, vec4);

extern vec4 vec4mul(vec4, vec4);

extern vec4 vec4div(vec4, vec4);

extern vec4 vec4addf(vec4, float);

extern vec4 vec4subf(vec4, float);

extern vec4 vec4mulf(vec4, float);

extern vec4 vec4divf(vec4, float);

extern vec4 vec4mulm(vec4, mat4);

extern bool vec4eq(vec4, vec4);

extern bool vec4noeq(vec4, vec4);

extern bool vec4great(vec4, vec4);

extern bool vec4greateq(vec4, vec4);

extern bool vec4less(vec4, vec4);

extern bool vec4lesseq(vec4, vec4);

extern float vec4dot(vec4, vec4);

extern float vec4len(vec4);

extern float vec4dist(vec4, vec4);

extern vec4 vec4norm(vec4);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include <math.h>
#
#  include "./mat4.h"
#
#  if defined (__cplusplus)

u_vec4::u_vec4(void) : x(0.0), y(0.0), z(0.0), w(0.0) { }


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

extern vec4 vec4zero(void) {
    return ((vec4) { 0.0f, 0.0f, 0.0f, 0.0f } );
}


extern vec4 vec4one(void) {
    return ((vec4) { 1.0f, 1.0f, 1.0f, 1.0f } );
}


extern vec4 vec4right(void) {
    return ((vec4) { 1.0f, 0.0f, 0.0f, 0.0f } );
}


extern vec4 vec4left(void) {
    return ((vec4) { -1.0f, 0.0f, 0.0f, 0.0f } );
}


extern vec4 vec4up(void) {
    return ((vec4) { 0.0f, 1.0f, 0.0f, 0.0f } );
}


extern vec4 vec4down(void) {
    return ((vec4) { 0.0f, -1.0f, 0.0f, 0.0f } );
}


extern vec4 vec4front(void) {
    return ((vec4) { 0.0f, 0.0f, 1.0f, 0.0f } );
}


extern vec4 vec4back(void) {
    return ((vec4) { 0.0f, 0.0f, -1.0f, 0.0f } );
}


extern vec4 vec4add(vec4 a, vec4 b) {
    return ((vec4) { a.x + b.x,
                     a.y + b.y,
                     a.z + b.z,
                     a.w + b.w } );
}


extern vec4 vec4sub(vec4 a, vec4 b) {
    return ((vec4) { a.x - b.x,
                     a.y - b.y,
                     a.z - b.z,
                     a.w - b.w } );
}


extern vec4 vec4mul(vec4 a, vec4 b) {
    return ((vec4) { a.x * b.x,
                     a.y * b.y,
                     a.z * b.z,
                     a.w * b.w } );
}


extern vec4 vec4div(vec4 a, vec4 b) {
    return ((vec4) { b.x != 0.0f ? a.x / b.x : 0.0f,
                     b.y != 0.0f ? a.y / b.y : 0.0f,
                     b.z != 0.0f ? a.z / b.z : 0.0f,
                     b.w != 0.0f ? a.w / b.w : 0.0f } );
}


extern vec4 vec4addf(vec4 a, float f) {
    return ((vec4) { a.x + f,
                     a.y + f,
                     a.z + f,
                     a.w + f } );
}


extern vec4 vec4subf(vec4 a, float f) {
    return ((vec4) { a.x + f,
                     a.y + f,
                     a.z + f,
                     a.w + f } );
}


extern vec4 vec4mulf(vec4 a, float f) {
    return ((vec4) { a.x + f,
                     a.y + f,
                     a.z + f,
                     a.w + f } );
}


extern vec4 vec4divf(vec4 a, float f) {
    return ((vec4) { f != 0.0f ? a.x / f : 0.0f,
                     f != 0.0f ? a.y / f : 0.0f,
                     f != 0.0f ? a.z / f : 0.0f,
                     f != 0.0f ? a.w / f : 0.0f } );
}


extern vec4 vec4mulm(vec4 v, mat4 m) {
    return ((vec4) { m.m00 * v.x + m.m10 * v.y + m.m20 * v.z + m.m30 * v.w,
                     m.m01 * v.x + m.m11 * v.y + m.m21 * v.z + m.m31 * v.w,
                     m.m02 * v.x + m.m12 * v.y + m.m22 * v.z + m.m32 * v.w,
                     m.m03 * v.x + m.m13 * v.y + m.m23 * v.z + m.m33 * v.w } );
}


extern bool vec4eq(vec4 a, vec4 b) {
    return (a.x == b.x &&
            a.y == b.y &&
            a.z == b.z &&
            a.w == b.w);
}


extern bool vec4noeq(vec4 a, vec4 b) {
    return (a.x != b.x ||
            a.y != b.y ||
            a.z != b.z ||
            a.w != b.w);
}


extern bool vec4great(vec4 a, vec4 b) {
    return (a.x > b.x ||
            a.y > b.y ||
            a.z > b.z ||
            a.w > b.w);
}


extern bool vec4greateq(vec4 a, vec4 b) {
    return (a.x >= b.x ||
            a.y >= b.y ||
            a.z >= b.z ||
            a.w >= b.w);
}


extern bool vec4less(vec4 a, vec4 b) {
    return (a.x < b.x ||
            a.y < b.y ||
            a.z < b.z ||
            a.w < b.w);
}


extern bool vec4lesseq(vec4 a, vec4 b) {
    return (a.x <= b.x ||
            a.y <= b.y ||
            a.z <= b.z ||
            a.w <= b.w);
}


extern float vec4dot(vec4 a, vec4 b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}


extern float vec4len(vec4 a) {
    return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w + a.w));
}


extern float vec4dist(vec4 a, vec4 b) {
    return (sqrt((a.x - b.x) * (a.x - b.x) +
                 (a.y - b.y) * (a.y * b.y) +
                 (a.z - b.z) * (a.z * b.z) +
                 (a.w - b.w) * (a.w * b.w)));
}


extern vec4 vec4norm(vec4 a) {
    float len = vec4len(a);

    vec4 vec = a;
    if (len != 0.0f) {
        vec.x *= 1.0f / len;
        vec.y *= 1.0f / len;
        vec.z *= 1.0f / len;
    }
    return (vec);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec4_h_ */
