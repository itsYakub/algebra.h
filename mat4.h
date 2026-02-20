#if !defined (_mat4_h_)
# define _mat4_h_ 1
#
# include <math.h>
#
# include "./mat3.h"

typedef union u_mat4 mat4;

union u_mat4 {
    struct {
        double m00, m10, m20, m30,
               m01, m11, m21, m31,
               m02, m12, m22, m32,
               m03, m13, m23, m33;
    };

    double ptr[4][4];
};

extern mat4 mat4Zero(void);

extern mat4 mat4Init(const double);

extern mat4 mat4Add(const mat4, const mat4);

extern mat4 mat4Sub(const mat4, const mat4);

extern mat4 mat4Mul(const mat4, const mat4);

extern mat4 mat4Mulf(const mat4, const double);

extern double mat4Det(const mat4);

extern mat4 mat4Frust(const double, const double, const double, const double, const double, const double);

extern mat4 mat4Ortho(const double, const double, const double, const double, const double, const double);

extern mat4 mat4Persp(const double, const double, const double, const double);

# if defined (ALGEBRA_IMPLEMENTATION)

extern mat4 mat4Zero(void) {
    return ((mat4) {{ 0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0, 0.0 }} );
}

extern mat4 mat4Init(const double s) {
    return ((mat4) {{ 1.0 * s, 0.0,     0.0,     0.0,
                      0.0,     1.0 * s, 0.0,     0.0,
                      0.0,     0.0,     1.0 * s, 0.0,
                      0.0,     0.0,     0.0,     1.0 * s }} );
}

extern mat4 mat4Add(const mat4 a, const mat4 b) {
    return ((mat4) {{ a.m00 + b.m00, a.m01 + b.m01, a.m02 + b.m02, a.m03 + b.m03,
                      a.m10 + b.m10, a.m11 + b.m11, a.m12 + b.m12, a.m13 + b.m13,
                      a.m20 + b.m20, a.m21 + b.m21, a.m22 + b.m22, a.m23 + b.m23,
                      a.m30 + b.m30, a.m31 + b.m31, a.m32 + b.m32, a.m33 + b.m33 }} );
}

extern mat4 mat4Sub(const mat4 a, const mat4 b) {
    return ((mat4) {{ a.m00 - b.m00, a.m01 - b.m01, a.m02 - b.m02, a.m03 - b.m03,
                      a.m10 - b.m10, a.m11 - b.m11, a.m12 - b.m12, a.m13 - b.m13,
                      a.m20 - b.m20, a.m21 - b.m21, a.m22 - b.m22, a.m23 - b.m23,
                      a.m30 - b.m30, a.m31 - b.m31, a.m32 - b.m32, a.m33 - b.m33 }} );
}

extern mat4 mat4Mul(const mat4 a, const mat4 b) {
    return ((mat4) {{ m0.m00 * m1.m00 + m0.m10 * m1.m01 + m0.m20 * m1.m02 + m0.m30 * m1.m03,
                      m0.m01 * m1.m00 + m0.m11 * m1.m01 + m0.m21 * m1.m02 + m0.m31 * m1.m03,
                      m0.m02 * m1.m00 + m0.m12 * m1.m01 + m0.m22 * m1.m02 + m0.m32 * m1.m03,
                      m0.m03 * m1.m00 + m0.m13 * m1.m01 + m0.m23 * m1.m02 + m0.m33 * m1.m03,
                      
                      m0.m00 * m1.m10 + m0.m10 * m1.m11 + m0.m20 * m1.m12 + m0.m30 * m1.m13,
                      m0.m01 * m1.m10 + m0.m11 * m1.m11 + m0.m21 * m1.m12 + m0.m31 * m1.m13,
                      m0.m02 * m1.m10 + m0.m12 * m1.m11 + m0.m22 * m1.m12 + m0.m32 * m1.m13,
                      m0.m03 * m1.m10 + m0.m13 * m1.m11 + m0.m23 * m1.m12 + m0.m33 * m1.m13,
                      
                      m0.m00 * m1.m20 + m0.m10 * m1.m21 + m0.m20 * m1.m22 + m0.m30 * m1.m23,
                      m0.m01 * m1.m20 + m0.m11 * m1.m21 + m0.m21 * m1.m22 + m0.m31 * m1.m23,
                      m0.m02 * m1.m20 + m0.m12 * m1.m21 + m0.m22 * m1.m22 + m0.m32 * m1.m23,
                      m0.m03 * m1.m20 + m0.m13 * m1.m21 + m0.m23 * m1.m22 + m0.m33 * m1.m23,
                      
                      m0.m00 * m1.m30 + m0.m10 * m1.m31 + m0.m20 * m1.m32 + m0.m30 * m1.m33,
                      m0.m01 * m1.m30 + m0.m11 * m1.m31 + m0.m21 * m1.m32 + m0.m31 * m1.m33,
                      m0.m02 * m1.m30 + m0.m12 * m1.m31 + m0.m22 * m1.m32 + m0.m32 * m1.m33,
                      m0.m03 * m1.m30 + m0.m13 * m1.m31 + m0.m23 * m1.m32 + m0.m33 * m1.m33 }} );
}

extern mat4 mat4Mulf(const mat4 a, const double f) {
    return ((mat4) {{ a.m00 * f, a.m01 * f, a.m02 * f, a.m03 * f,
                      a.m10 * f, a.m11 * f, a.m12 * f, a.m13 * f,
                      a.m20 * f, a.m21 * f, a.m22 * f, a.m23 * f,
                      a.m30 * f, a.m31 * f, a.m32 * f, a.m33 * f }} );
}

extern double mat4Det(const mat4 a) {
    double result = 0.0;

    result += a.m00 * mat3Det((mat3) {{ a.m11, a.m12, a.m13,
                                        a.m21, a.m22, a.m23,
                                        a.m31, a.m32, a.m33  }} );

    result -= a.m01 * mat3Det((mat3) {{ a.m10, a.m12, a.m13,
                                        a.m20, a.m22, a.m23,
                                        a.m30, a.m32, a.m33  }} );

    result += a.m02 * mat3Det((mat3) {{ a.m10, a.m11, a.m13,
                                        a.m20, a.m21, a.m23,
                                        a.m30, a.m31, a.m33  }} );

    result -= a.m03 * mat3Det((mat3) {{ a.m10, a.m11, a.m12,
                                        a.m20, a.m21, a.m22,
                                        a.m30, a.m31, a.m32  }} );

    return (result);
}

extern mat4 mat4Frust(const double left, const double right, const double top, const double down, const double near, const double far) {
    mat4 mat = mat4Zero();
    mat.m00  = (near * 2.0) / (right - left);
    mat.m11  = (near * 2.0) / (top   - down);
    mat.m20  = (left + right) / (right - left);
    mat.m21  = (top + down) / (top - down);
    mat.m22  = -(far + near) / (far - near);
    mat.m23  = -1.0;
    mat.m32  = -(far * near * 2.0) / (far - near);
    return (mat);
}

extern mat4 mat4Ortho(const double left, const double right, const double top, const double down, const double near, const double far) {
    mat4 mat = mat4Zero();
    mat.m00  = 2.0 / (right - left);
    mat.m11  = 2.0 / (top   - down);
    mat.m22  = 2.0 / (far   - near);
    mat.m30  = -(left + right) / (right - left);
    mat.m31  = -(top + down) / (top - down);
    mat.m32  = -(far + near) / (far - near);
    mat.m33  = 1.0;
    return (mat);
}

extern mat4 mat4Persp(const double fieldOfView, const double aspect, const double near, const double far) {
    float top   = near * tan(fieldOfView * 0.5);
    float right = top * aspect;
    return (mat4Frustum(-right, right, top, -top, near, far));
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat4_h_ */
