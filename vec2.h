#if !defined (_vec2_h_)
# define _vec2_h_ 1

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

extern vec2 vec2Add(vec2, vec2);

extern vec2 vec2Sub(vec2, vec2);

extern vec2 vec2Mul(vec2, vec2);

extern vec2 vec2Div(vec2, vec2);

extern vec2 vec2Addf(vec2, float);

extern vec2 vec2Subf(vec2, float);

extern vec2 vec2Mulf(vec2, float);

extern vec2 vec2Divf(vec2, float);

# if defined (ALGEBRA_IMPLEMENTATION)

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


# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec2_h_ */
