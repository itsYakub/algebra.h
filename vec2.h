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

extern vec2 vec2Add(const vec2, const vec2);

extern vec2 vec2Sub(const vec2, const vec2);

extern vec2 vec2Mul(const vec2, const vec2);

extern vec2 vec2Div(const vec2, const vec2);

# if defined (ALGEBRA_IMPLEMENTATION)

extern vec2 vec2Add(const vec2 a, const vec2 b) {
    return ((vec2) { .x = a.x + b.x,
                     .y = a.y + b.y } );
}

extern vec2 vec2Sub(const vec2 a, const vec2 b) {
    return ((vec2) { .x = a.x - b.x,
                     .y = a.y - b.y } );
}

extern vec2 vec2Mul(const vec2 a, const vec2 b) {
    return ((vec2) { .x = a.x * b.x,
                     .y = a.y * b.y } );
}

extern vec2 vec2Div(const vec2 a, const vec2 b) {
    return ((vec2) { .x = b.x > 0.0 ? a.x / b.x : 0.0,
                     .y = b.y > 0.0 ? a.y / b.y : 0.0 } );
}


# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec2_h_ */
