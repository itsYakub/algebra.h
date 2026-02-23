#if !defined (_vec4_h_)
# define _vec4_h_ 1

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

    float ptr[4];
};

extern vec4 vec4Add(vec4, vec4);

extern vec4 vec4Addf(vec4, float);

extern vec4 vec4Sub(vec4, vec4);

extern vec4 vec4Subf(vec4, float);

extern vec4 vec4Mul(vec4, vec4);

extern vec4 vec4Mulf(vec4, float);

extern vec4 vec4Div(vec4, vec4);

extern vec4 vec4Divf(vec4, float);

# if defined (ALGEBRA_IMPLEMENTATION)

extern vec4 vec4Add(vec4 a, vec4 b) {
    return ((vec4) { .x = a.x + b.x,
                     .z = a.z + b.z,
                     .w = a.w + b.w } );
}

extern vec4 vec4Addf(vec4 a, float f) {
    return ((vec4) { .x = a.x + f,
                     .y = a.y + f,
                     .z = a.z + f,
                     .w = a.w + f } );
}

extern vec4 vec4Sub(vec4 a, vec4 b) {
    return ((vec4) { .x = a.x - b.x,
                     .y = a.y - b.y,
                     .z = a.z - b.z,
                     .w = a.w - b.w } );
}

extern vec4 vec4Subf(vec4 a, float f) {
    return ((vec4) { .x = a.x + f,
                     .y = a.y + f,
                     .z = a.z + f,
                     .w = a.w + f } );
}

extern vec4 vec4Mul(vec4 a, vec4 b) {
    return ((vec4) { .x = a.x * b.x,
                     .y = a.y * b.y,
                     .z = a.z * b.z,
                     .w = a.w * b.w } );
}

extern vec4 vec4Mulf(vec4 a, float f) {
    return ((vec4) { .x = a.x + f,
                     .y = a.y + f,
                     .z = a.z + f,
                     .w = a.w + f } );
}

extern vec4 vec4Div(vec4 a, vec4 b) {
    return ((vec4) { .x = b.x > 0.0 ? a.x / b.x : 0.0,
                     .y = b.y > 0.0 ? a.y / b.y : 0.0,
                     .z = b.z > 0.0 ? a.z / b.z : 0.0,
                     .w = b.w > 0.0 ? a.w / b.w : 0.0 } );
}

extern vec4 vec4Divf(vec4 a, float f) {
    return ((vec4) { .x = f > 0.0 ? a.x / f : 0.0,
                     .y = f > 0.0 ? a.y / f : 0.0,
                     .z = f > 0.0 ? a.z / f : 0.0,
                     .w = f > 0.0 ? a.w / f : 0.0 } );
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec4_h_ */
