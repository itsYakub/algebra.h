#if !defined (_vec2_h_)
# define _vec2_h_ 1
#
# include <stdbool.h>
#
# include <math.h>

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

    float ptr[2];
};

extern const vec2 vec2Zero(void);

extern const vec2 vec2One(void);

extern const vec2 vec2Right(void);

extern const vec2 vec2Left(void);

extern const vec2 vec2Up(void);

extern const vec2 vec2Down(void);

extern vec2 vec2Add(vec2, vec2);

extern vec2 vec2Sub(vec2, vec2);

extern vec2 vec2Mul(vec2, vec2);

extern vec2 vec2Div(vec2, vec2);

extern vec2 vec2Addf(vec2, float);

extern vec2 vec2Subf(vec2, float);

extern vec2 vec2Mulf(vec2, float);

extern vec2 vec2Divf(vec2, float);

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

extern const vec2 vec2Zero(void) {
    return ((vec2) { 0.0, 0.0 } );
}


extern const vec2 vec2One(void) {
    return ((vec2) { 1.0, 1.0 } );
}


extern const vec2 vec2Right(void) {
    return ((vec2) { 1.0, 0.0 } );
}


extern const vec2 vec2Left(void) {
    return ((vec2) { -1.0, 0.0 } );
}


extern const vec2 vec2Up(void) {
    return ((vec2) { 0.0, 1.0 } );
}


extern const vec2 vec2Down(void) {
    return ((vec2) { 0.0, -1.0 } );
}


extern vec2 vec2Add(vec2 a, vec2 b) {
    return ((vec2) { .x = a.x + b.x,
                     .y = a.y + b.y } );
}


extern vec2 vec2Sub(vec2 a, vec2 b) {
    return ((vec2) { .x = a.x - b.x,
                     .y = a.y - b.y } );
}


extern vec2 vec2Mul(vec2 a, vec2 b) {
    return ((vec2) { .x = a.x * b.x,
                     .y = a.y * b.y } );
}


extern vec2 vec2Div(vec2 a, vec2 b) {
    return ((vec2) { .x = b.x != 0.0 ? a.x / b.x : 0.0,
                     .y = b.y != 0.0 ? a.y / b.y : 0.0 } );
}


extern vec2 vec2Addf(vec2 a, float f) {
    return ((vec2) { .x = a.x + f,
                     .y = a.y + f } );
}


extern vec2 vec2Subf(vec2 a, float f) {
    return ((vec2) { .x = a.x - f,
                     .y = a.y - f } );
}


extern vec2 vec2Mulf(vec2 a, float f) {
    return ((vec2) { .x = a.x * f,
                     .y = a.y * f } );
}


extern vec2 vec2Divf(vec2 a, float f) {
    return ((vec2) { .x = f != 0.0 ? a.x / f : 0.0,
                     .y = f != 0.0 ? a.y / f : 0.0 } );
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
    if (len != 0.0) {
        vec = vec2Mulf(vec, 1.0 / len);
    }
    return (vec);
}


# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec2_h_ */
