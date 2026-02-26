#if !defined (_mat3_h_)
# define _mat3_h_ 1

typedef union u_mat3 mat3;

union u_mat3 {
    struct {
        float m00, m01, m02,
              m10, m11, m12,
              m20, m21, m22;
    };

    float ptr[9];
};

extern mat3 mat3Zero(void);

extern mat3 mat3Init(float);

extern mat3 mat3Add(mat3, mat3);

extern mat3 mat3Sub(mat3, mat3);

extern mat3 mat3Mul(mat3, mat3);

extern mat3 mat3Mulf(mat3, float);

extern float mat3Det(mat3);

# if defined (ALGEBRA_IMPLEMENTATION)

extern mat3 mat3Zero(void) {
    return ((mat3) {{ 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0 }} );
}

extern mat3 mat3Init(float s) {
    return ((mat3) {{ 1.0 * s, 0.0,     0.0,
                      0.0,     1.0 * s, 0.0,
                      0.0,     0.0,     1.0 * s }} );
}

extern mat3 mat3Add(mat3 a, mat3 b) {
    return ((mat3) {{ a.m00 + b.m00, a.m01 + b.m01, a.m02 + b.m02,
                      a.m10 + b.m10, a.m11 + b.m11, a.m12 + b.m12,
                      a.m20 + b.m20, a.m21 + b.m21, a.m22 + b.m22 }} );
}

extern mat3 mat3Sub(mat3 a, mat3 b) {
    return ((mat3) {{ a.m00 - b.m00, a.m01 - b.m01, a.m02 - b.m02,
                      a.m10 - b.m10, a.m11 - b.m11, a.m12 - b.m12,
                      a.m20 - b.m20, a.m21 - b.m21, a.m22 - b.m22 }} );
}

extern mat3 mat3Mul(mat3 a, mat3 b) {
    return ((mat3) {{ a.m00 * b.m00 + a.m10 * b.m01 + a.m20 * b.m02,
                      a.m01 * b.m00 + a.m11 * b.m01 + a.m21 * b.m02,
                      a.m02 * b.m00 + a.m12 * b.m01 + a.m22 * b.m02,

                      a.m00 * b.m10 + a.m10 * b.m11 + a.m20 * b.m12,
                      a.m01 * b.m10 + a.m11 * b.m11 + a.m21 * b.m12,
                      a.m02 * b.m10 + a.m12 * b.m11 + a.m22 * b.m12,

                      a.m00 * b.m20 + a.m10 * b.m21 + a.m20 * b.m22,
                      a.m01 * b.m20 + a.m11 * b.m21 + a.m21 * b.m22,
                      a.m02 * b.m20 + a.m12 * b.m21 + a.m22 * b.m22 }} );
}

extern mat3 mat3Mulf(mat3 a, float f) {
    return ((mat3) {{ a.m00 * f, a.m01 * f, a.m02 * f,
                      a.m10 * f, a.m11 * f, a.m12 * f,
                      a.m20 * f, a.m21 * f, a.m22 * f }} );
}

extern float mat3Det(mat3 a) {
    return (a.m00 * a.m11 * a.m22 +
            a.m01 * a.m12 * a.m20 +
            a.m02 * a.m10 * a.m21 -
            a.m20 * a.m11 * a.m02 -
            a.m21 * a.m12 * a.m00 -
            a.m22 * a.m10 * a.m01);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat3_h_ */
