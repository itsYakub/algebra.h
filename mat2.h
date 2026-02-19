#if !defined (_mat2_h_)
# define _mat2_h_ 1

typedef union u_mat2 mat2;

union u_mat2 {
    struct {
        double m00, m01,
               m10, m11;
    };

    double ptr[2][2];
};

extern mat2 mat2Zero(void);

extern mat2 mat2Identity(void);

extern mat2 mat2Scalar(const double);

extern mat2 mat2Add(const mat2, const mat2);

extern mat2 mat2Sub(const mat2, const mat2);

extern mat2 mat2Mul(const mat2, const mat2);

extern mat2 mat2Mulf(const mat2, const double);

extern double mat2Det(const mat2);

# if defined (ALGEBRA_IMPLEMENTATION)

extern mat2 mat2Zero(void) {
    return ((mat2) {{ 0.0, 0.0,
                      0.0, 0.0 }} );
}

extern mat2 mat2Identity(void) {
    return ((mat2) {{ 1.0, 0.0,
                      0.0, 1.0 }} );
}

extern mat2 mat2Scalar(const double s) {
    return ((mat2) {{ 1.0 * s, 0.0,
                      0.0,     1.0 * s }} );
}

extern mat2 mat2Add(const mat2 a, const mat2 b) {
    return ((mat2) {{ a.m00 + b.m00, a.m01 + b.m01,
                      a.m10 + b.m10, a.m11 + b.m11 }} );
}

extern mat2 mat2Sub(const mat2 a, const mat2 b) {
    return ((mat2) {{ a.m00 - b.m00, a.m01 - b.m01,
                      a.m10 - b.m10, a.m11 - b.m11 }} );
}

extern mat2 mat2Mul(const mat2 a, const mat2 b) {
    return ((mat2) {{ a.m00 * b.m00 + a.m10 * b.m01,
                      a.m01 * b.m00 + a.m11 * b.m01,
                      a.m00 * b.m10 + a.m10 * b.m11,
                      a.m01 * b.m10 + a.m11 * b.m11 }} );
}

extern mat2 mat2Mulf(const mat2 a, const float f) {
    return ((mat2) {{ a.m00 * f, a.m01 * f,
                      a.m10 * f, a.m11 * f }} );
}

extern float mat2Det(const mat2 a) {
    return (a.m00 * a.m11 - a.m10 * a.m01);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat2_h_ */
