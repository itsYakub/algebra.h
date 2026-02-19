#if !defined (_vec3_h_)
# define _vec3_h_ 1

typedef union u_vec3 vec3;

union u_vec3 {
    struct {
        double x;
        double y;
        double z;
    };

    struct {
        double r;
        double g;
        double b;
    };

    double ptr[3];
};

extern vec3 vec3Add(const vec3, const vec3);

extern vec3 vec3Sub(const vec3, const vec3);

extern vec3 vec3Mul(const vec3, const vec3);

extern vec3 vec3Div(const vec3, const vec3);

# if defined (ALGEBRA_IMPLEMENTATION)

extern vec3 vec3Add(const vec3 a, const vec3 b) {
    return ((vec3) { .x = a.x + b.x,
                     .y = a.y + b.y,
                     .z = a.z + b.z } );
}

extern vec3 vec3Sub(const vec3 a, const vec3 b) {
    return ((vec3) { .x = a.x - b.x,
                     .y = a.y - b.y,
                     .z = a.z - b.z } );
}

extern vec3 vec3Mul(const vec3 a, const vec3 b) {
    return ((vec3) { .x = a.x * b.x,
                     .y = a.y * b.y,
                     .z = a.z * b.z } );
}

extern vec3 vec3Div(const vec3 a, const vec3 b) {
    return ((vec3) { .x = b.x > 0.0 ? a.x / b.x : 0.0,
                     .y = b.y > 0.0 ? a.y / b.y : 0.0,
                     .z = b.z > 0.0 ? a.z / b.z : 0.0 } );
}


# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec3_h_ */
