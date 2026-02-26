#if !defined (_mat4_h_)
# define _mat4_h_ 1
#
# include <math.h>
#
# include "./vec3.h"
# include "./mat3.h"

typedef union u_mat4 mat4;

union u_mat4 {
    struct {
        float m00, m10, m20, m30,
              m01, m11, m21, m31,
              m02, m12, m22, m32,
              m03, m13, m23, m33;
    };

    float ptr[16];
};

extern mat4 mat4Zero(void);

extern mat4 mat4Init(float);

extern mat4 mat4Add(mat4, mat4);

extern mat4 mat4Sub(mat4, mat4);

extern mat4 mat4Mul(mat4, mat4);

extern mat4 mat4Mulf(mat4, float);

extern float mat4Det(mat4);

extern mat4 mat4Translate(vec3);

extern mat4 mat4Rotate(vec3, float);

extern mat4 mat4RotateAt(vec3, vec3, float);

extern mat4 mat4RotateX(float);

extern mat4 mat4RotateY(float);

extern mat4 mat4RotateZ(float);

extern mat4 mat4LookAt(vec3, vec3, vec3);

extern mat4 mat4Scale(vec3);

extern mat4 mat4Frust(float, float, float, float, float, float);

extern mat4 mat4Ortho(float, float, float, float, float, float);

extern mat4 mat4Persp(float, float, float, float);

# if defined (ALGEBRA_IMPLEMENTATION)

extern mat4 mat4Zero(void) {
    return ((mat4) {{ 0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0, 0.0 }} );
}

extern mat4 mat4Init(float s) {
    return ((mat4) {{ 1.0 * s, 0.0,     0.0,     0.0,
                      0.0,     1.0 * s, 0.0,     0.0,
                      0.0,     0.0,     1.0 * s, 0.0,
                      0.0,     0.0,     0.0,     1.0 * s }} );
}

extern mat4 mat4Add(mat4 a, mat4 b) {
    return ((mat4) {{ a.m00 + b.m00, a.m01 + b.m01, a.m02 + b.m02, a.m03 + b.m03,
                      a.m10 + b.m10, a.m11 + b.m11, a.m12 + b.m12, a.m13 + b.m13,
                      a.m20 + b.m20, a.m21 + b.m21, a.m22 + b.m22, a.m23 + b.m23,
                      a.m30 + b.m30, a.m31 + b.m31, a.m32 + b.m32, a.m33 + b.m33 }} );
}

extern mat4 mat4Sub(mat4 a, mat4 b) {
    return ((mat4) {{ a.m00 - b.m00, a.m01 - b.m01, a.m02 - b.m02, a.m03 - b.m03,
                      a.m10 - b.m10, a.m11 - b.m11, a.m12 - b.m12, a.m13 - b.m13,
                      a.m20 - b.m20, a.m21 - b.m21, a.m22 - b.m22, a.m23 - b.m23,
                      a.m30 - b.m30, a.m31 - b.m31, a.m32 - b.m32, a.m33 - b.m33 }} );
}

extern mat4 mat4Mul(mat4 a, mat4 b) {
    return ((mat4) {{ a.m00 * b.m00 + a.m10 * b.m01 + a.m20 * b.m02 + a.m30 * b.m03,
                      a.m01 * b.m00 + a.m11 * b.m01 + a.m21 * b.m02 + a.m31 * b.m03,
                      a.m02 * b.m00 + a.m12 * b.m01 + a.m22 * b.m02 + a.m32 * b.m03,
                      a.m03 * b.m00 + a.m13 * b.m01 + a.m23 * b.m02 + a.m33 * b.m03,

                      a.m00 * b.m10 + a.m10 * b.m11 + a.m20 * b.m12 + a.m30 * b.m13,
                      a.m01 * b.m10 + a.m11 * b.m11 + a.m21 * b.m12 + a.m31 * b.m13,
                      a.m02 * b.m10 + a.m12 * b.m11 + a.m22 * b.m12 + a.m32 * b.m13,
                      a.m03 * b.m10 + a.m13 * b.m11 + a.m23 * b.m12 + a.m33 * b.m13,

                      a.m00 * b.m20 + a.m10 * b.m21 + a.m20 * b.m22 + a.m30 * b.m23,
                      a.m01 * b.m20 + a.m11 * b.m21 + a.m21 * b.m22 + a.m31 * b.m23,
                      a.m02 * b.m20 + a.m12 * b.m21 + a.m22 * b.m22 + a.m32 * b.m23,
                      a.m03 * b.m20 + a.m13 * b.m21 + a.m23 * b.m22 + a.m33 * b.m23,

                      a.m00 * b.m30 + a.m10 * b.m31 + a.m20 * b.m32 + a.m30 * b.m33,
                      a.m01 * b.m30 + a.m11 * b.m31 + a.m21 * b.m32 + a.m31 * b.m33,
                      a.m02 * b.m30 + a.m12 * b.m31 + a.m22 * b.m32 + a.m32 * b.m33,
                      a.m03 * b.m30 + a.m13 * b.m31 + a.m23 * b.m32 + a.m33 * b.m33 }} );
}

extern mat4 mat4Mulf(mat4 a, float f) {
    return ((mat4) {{ a.m00 * f, a.m01 * f, a.m02 * f, a.m03 * f,
                      a.m10 * f, a.m11 * f, a.m12 * f, a.m13 * f,
                      a.m20 * f, a.m21 * f, a.m22 * f, a.m23 * f,
                      a.m30 * f, a.m31 * f, a.m32 * f, a.m33 * f }} );
}

extern float mat4Det(mat4 a) {
    float result = 0.0;

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

extern mat4 mat4Translate(vec3 v) {
    mat4 mat = mat4Init(1.0);
    mat.m30 = v.x;
    mat.m31 = v.y;
    mat.m32 = v.z;
    return (mat);
}

extern mat4 mat4Rotate(vec3 axis, float angle) {
    float c = cos(angle);
    float s = sin(angle);
    float t = 1.0f - c;

    vec3 axisn = vec3Normalize(axis);
    float x = axisn.x,
          y = axisn.y,
          z = axisn.z;

    mat4 mat = mat4Init(1.0);
    mat.m00 = t*x*x + c;
    mat.m01 = t*y*x + s*z;
    mat.m02 = t*z*x - s*y;

    mat.m10 = t*x*y - s*z;
    mat.m11 = t*y*y + c;
    mat.m12 = t*z*y + s*x;

    mat.m20 = t*x*z + s*y;
    mat.m21 = t*y*z - s*x;
    mat.m22 = t*z*z + c;
    return (mat);
}

extern mat4 mat4RotateAt(vec3 pivot, vec3 axis, float angle) {
    mat4 mat = mat4Init(1.0);
         mat = mat4Mul(mat4Translate(pivot), mat);
         mat = mat4Mul(mat4Rotate(axis, angle), mat);
         mat = mat4Mul(mat4Translate(vec3Mulf(pivot, -1.0)), mat);
    return (mat);
}

extern mat4 mat4RotateX(float f) {
    float sinres = sin(f),
          cosres = cos(f);

    mat4 mat = mat4Init(1.0);
    mat.m11  = cosres;
    mat.m21  = sinres;
    mat.m12  = -sinres;
    mat.m22  = cosres;
    return (mat);
}

extern mat4 mat4RotateY(float f) {
    float sinres = sin(f),
          cosres = cos(f);

    mat4 mat = mat4Init(1.0);
    mat.m00  = cosres;
    mat.m20  = -sinres;
    mat.m02  = sinres;
    mat.m22  = cosres;
    return (mat);
}

extern mat4 mat4RotateZ(float f) {
    float sinres = sin(f),
          cosres = cos(f);

    mat4 mat = mat4Init(1.0);
    mat.m00  = cosres;
    mat.m10  = sinres;
    mat.m01  = -sinres;
    mat.m11  = cosres;
    return (mat);
}

extern mat4 mat4LookAt(vec3 eye, vec3 center, vec3 up) {
    vec3 f = vec3Normalize(vec3Sub(center, eye));
    vec3 s = vec3Normalize(vec3Cross(f, up));
    vec3 u = vec3Cross(s, f);

    mat4 mat =  mat4Init(1.0);
    mat.m00  =  s.x; mat.m10 =  s.y; mat.m20 =  s.z;
    mat.m01  =  u.x; mat.m11 =  u.y; mat.m21 =  u.z;
    mat.m02  = -f.x; mat.m12 = -f.y; mat.m22 = -f.z;
    mat.m30  = -vec3Dot(s, eye);
    mat.m31  = -vec3Dot(u, eye);
    mat.m32  =  vec3Dot(f, eye);
    return (mat);
}

extern mat4 mat4Scale(vec3 v) {
    mat4 mat = mat4Init(1.0);
    mat.m00 = v.x;
    mat.m11 = v.y;
    mat.m22 = v.z;
    return (mat);
}

extern mat4 mat4Frust(float left, float right, float top, float down, float near, float far) {
    mat4 mat = mat4Zero();
    mat.m00  = (near * 2.0) / (right - left);
    mat.m11  = (near * 2.0) / (top   - down);
    mat.m02  = (left + right) / (right - left);
    mat.m12  = (top + down) / (top - down);
    mat.m22  = -(far + near) / (far - near);
    mat.m32  = -1.0;
    mat.m23  = -(far * near * 2.0) / (far - near);
    return (mat);
}

extern mat4 mat4Ortho(float left, float right, float top, float down, float near, float far) {
    mat4 mat = mat4Zero();
    mat.m00 =  2.0 / (right - left);
    mat.m11 =  2.0 / (top   - down);
    mat.m22 = -2.0 / (far   - near);
    mat.m03 = -(left  + right) / (right - left);
    mat.m13 = -(top   + down)  / (top   - down);
    mat.m23 = -(far   + near)  / (far   - near);
    mat.m33 =  1.0;
    return (mat);
}

extern mat4 mat4Persp(float fieldOfView, float aspect, float near, float far) {
    float top   = near * tan(fieldOfView * 0.5);
    float right = top * aspect;
    return (mat4Frust(-right, right, top, -top, near, far));
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat4_h_ */
