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

    u_vec2(void);

    u_vec2(float);

    u_vec2(float, float);

    u_vec2(const u_vec2 &); 

    u_vec2 &operator = (const u_vec2 &);

# endif /* __cplusplus */

};

extern vec2 vec2Zero(void);

extern vec2 vec2One(void);

extern vec2 vec2Right(void);

extern vec2 vec2Left(void);

extern vec2 vec2Up(void);

extern vec2 vec2Down(void);

extern vec2 vec2Add(vec2, vec2);

extern vec2 vec2Sub(vec2, vec2);

extern vec2 vec2Mul(vec2, vec2);

extern vec2 vec2Div(vec2, vec2);

extern vec2 vec2Addf(vec2, float);

extern vec2 vec2Subf(vec2, float);

extern vec2 vec2Mulf(vec2, float);

extern vec2 vec2Divf(vec2, float);

extern vec2 vec2Mulm(vec2, mat2);

extern bool vec2Equal(vec2, vec2);

extern bool vec2NoEqual(vec2, vec2);

extern bool vec2Great(vec2, vec2);

extern bool vec2GreatEqual(vec2, vec2);

extern bool vec2Less(vec2, vec2);

extern bool vec2LessEqual(vec2, vec2);

extern float vec2Dot(vec2, vec2);

extern float vec2Length(vec2);

extern float vec2Distance(vec2, vec2);

extern float vec2Cross(vec2, vec2);

extern vec2 vec2Normalize(vec2);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include <math.h>
#
#  include "./mat2.h"
#
#  if defined (__cplusplus)

u_vec2::u_vec2(void) : x(0.0), y(0.0) { }


u_vec2::u_vec2(float v) : x(v), y(v) { }


u_vec2::u_vec2(float x, float y) : x(x), y(y) { }


u_vec2::u_vec2(const u_vec2 &other) : x(other.x), y(other.y) { }


u_vec2 &u_vec2::operator = (const u_vec2 &other) {
    this->x = other.x;
    this->y = other.y;
    return (*this);
}

#  endif /* __cplusplus */

extern vec2 vec2Zero(void) {
    return ((vec2) { 0.0f, 0.0f } );
}


extern vec2 vec2One(void) {
    return ((vec2) { 1.0f, 1.0f } );
}


extern vec2 vec2Right(void) {
    return ((vec2) { 1.0f, 0.0f } );
}


extern vec2 vec2Left(void) {
    return ((vec2) { -1.0f, 0.0f } );
}


extern vec2 vec2Up(void) {
    return ((vec2) { 0.0f, 1.0f } );
}


extern vec2 vec2Down(void) {
    return ((vec2) { 0.0f, -1.0f } );
}


extern vec2 vec2Add(vec2 a, vec2 b) {
    return ((vec2) { a.x + b.x,
                     a.y + b.y } );
}


extern vec2 vec2Sub(vec2 a, vec2 b) {
    return ((vec2) { a.x - b.x,
                     a.y - b.y } );
}


extern vec2 vec2Mul(vec2 a, vec2 b) {
    return ((vec2) { a.x * b.x,
                     a.y * b.y } );
}


extern vec2 vec2Div(vec2 a, vec2 b) {
    return ((vec2) { b.x != 0.0f ? a.x / b.x : 0.0f,
                     b.y != 0.0f ? a.y / b.y : 0.0f } );
}


extern vec2 vec2Addf(vec2 a, float f) {
    return ((vec2) { a.x + f,
                     a.y + f } );
}


extern vec2 vec2Subf(vec2 a, float f) {
    return ((vec2) { a.x - f,
                     a.y - f } );
}


extern vec2 vec2Mulf(vec2 a, float f) {
    return ((vec2) { a.x * f,
                     a.y * f } );
}


extern vec2 vec2Divf(vec2 a, float f) {
    return ((vec2) { f != 0.0f ? a.x / f : 0.0f,
                     f != 0.0f ? a.y / f : 0.0f } );
}


extern vec2 vec2Mulm(vec2 v, mat2 m) {
    return ((vec2) { m.m00 * v.x + m.m10 * v.y,
                     m.m01 * v.x + m.m11 * v.y } );
}


extern bool vec2Equal(vec2 a, vec2 b) {
    return (a.x == b.x &&
            a.y == b.y);
}


extern bool vec2NoEqual(vec2 a, vec2 b) {
    return (a.x != b.x ||
            a.y != b.y);
}


extern bool vec2Great(vec2 a, vec2 b) {
    return (a.x > b.x ||
            a.y > b.y);
}


extern bool vec2GreatEqual(vec2 a, vec2 b) {
    return (a.x >= b.x ||
            a.y >= b.y);
}


extern bool vec2Less(vec2 a, vec2 b) {
    return (a.x < b.x ||
            a.y < b.y);
}


extern bool vec2LessEqual(vec2 a, vec2 b) {
    return (a.x <= b.x ||
            a.y <= b.y);
}


extern float vec2Dot(vec2 a, vec2 b) {
    return (a.x * b.x + a.y * b.y);
}


extern float vec2Length(vec2 a) {
    return (sqrt(a.x * a.x + a.y * a.y));
}


extern float vec2Distance(vec2 a, vec2 b) {
    return (sqrt((a.x - b.x) * (a.x - b.x) +
                 (a.y - b.y) * (a.y * b.y)));
}


extern float vec2Cross(vec2 a, vec2 b) {
    return (a.x * b.y - a.y * b.x);
}


extern vec2 vec2Normalize(vec2 a) {
    float len = vec2Length(a);

    vec2 vec = a;
    if (len != 0.0f) {
        vec = vec2Mulf(vec, 1.0f / len);
    }
    return (vec);
}


# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec2_h_ */
