#if !defined (_mat4_h_)
# define _mat4_h_ 1

typedef union u_vec3 vec3;

typedef union u_vec4 vec4;

typedef union u_mat3 mat3;

typedef union u_mat4 mat4;

union u_mat4 {
    struct {
        float m00, m01, m02, m03,
              m10, m11, m12, m13,
              m20, m21, m22, m23,
              m30, m31, m32, m33;
    };

# if defined (__cplusplus)

    u_mat4(void);

    u_mat4(float);

    u_mat4(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);

    u_mat4(const u_mat4 &); 

    u_mat4 &operator = (const u_mat4 &);

# endif /* __cplusplus */

};

extern mat4 mat4Zero(void);

extern mat4 mat4Identity(void);

extern mat4 mat4Init(float);

extern mat4 mat4Add(mat4, mat4);

extern mat4 mat4Sub(mat4, mat4);

extern mat4 mat4Mul(mat4, mat4);

extern mat4 mat4Mulf(mat4, float);

extern vec4 mat4Mulv(mat4, vec4);

extern float mat4Det(mat4);

extern float mat4Trace(mat4);

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

extern mat4 mat4Trans(mat4);

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include <math.h>
#
#  include "./vec3.h"
#  include "./mat3.h"
#
#  if defined (__cplusplus)

u_mat4::u_mat4(void) :
    m00(0.0), m01(0.0), m02(0.0), m03(0.0),
    m10(0.0), m11(0.0), m12(0.0), m13(0.0),
    m20(0.0), m21(0.0), m22(0.0), m23(0.0),
    m30(0.0), m31(0.0), m32(0.0), m33(0.0) { }


u_mat4::u_mat4(float s) :
    m00(1.0 * s), m01(0.0),     m02(0.0),     m03(0.0),
    m10(0.0),     m11(1.0 * s), m12(0.0),     m13(0.0),
    m20(0.0),     m21(0.0),     m22(1.0 * s), m23(0.0),
    m30(0.0),     m31(0.0),     m32(0.0),     m33(1.0 * s) { }

    
u_mat4::u_mat4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33) :
    m00(m00), m01(m01), m02(m02), m03(m03),
    m10(m10), m11(m11), m12(m12), m13(m13),
    m20(m20), m21(m21), m22(m22), m23(m23),
    m30(m30), m31(m31), m32(m32), m33(m33) { }


u_mat4::u_mat4(const u_mat4 &other) :
    m00(other.m00), m01(other.m01), m02(other.m02), m03(other.m03),
    m10(other.m10), m11(other.m11), m12(other.m12), m13(other.m13),
    m20(other.m20), m21(other.m21), m22(other.m22), m23(other.m23),
    m30(other.m30), m31(other.m31), m32(other.m32), m33(other.m33) { }


u_mat4 &u_mat4::operator = (const u_mat4 &other) {
    *this = { other.m00, other.m01, other.m02, other.m03,
              other.m10, other.m11, other.m12, other.m13,
              other.m20, other.m21, other.m22, other.m23,
              other.m20, other.m21, other.m22, other.m33 };
    
    return (*this);
}

#  endif /* __cplusplus */

extern mat4 mat4Zero(void) {
    return (mat4Init(0.0f));
}


extern mat4 mat4Identity(void) {
    return (mat4Init(1.0f));
}


extern mat4 mat4Init(float s) {
    return ((mat4) { 1.0f * s, 0.0f,     0.0f,     0.0f,
                     0.0f,     1.0f * s, 0.0f,     0.0f,
                     0.0f,     0.0f,     1.0f * s, 0.0f,
                     0.0f,     0.0f,     0.0f,     1.0f * s } );
}


extern mat4 mat4Add(mat4 a, mat4 b) {
    return ((mat4) { a.m00 + b.m00, a.m01 + b.m01, a.m02 + b.m02, a.m03 + b.m03,
                     a.m10 + b.m10, a.m11 + b.m11, a.m12 + b.m12, a.m13 + b.m13,
                     a.m20 + b.m20, a.m21 + b.m21, a.m22 + b.m22, a.m23 + b.m23,
                     a.m30 + b.m30, a.m31 + b.m31, a.m32 + b.m32, a.m33 + b.m33 } );
}


extern mat4 mat4Sub(mat4 a, mat4 b) {
    return ((mat4) { a.m00 - b.m00, a.m01 - b.m01, a.m02 - b.m02, a.m03 - b.m03,
                     a.m10 - b.m10, a.m11 - b.m11, a.m12 - b.m12, a.m13 - b.m13,
                     a.m20 - b.m20, a.m21 - b.m21, a.m22 - b.m22, a.m23 - b.m23,
                     a.m30 - b.m30, a.m31 - b.m31, a.m32 - b.m32, a.m33 - b.m33 } );
}


extern mat4 mat4Mul(mat4 a, mat4 b) {
    return ((mat4) { a.m00 * b.m00 + a.m10 * b.m01 + a.m20 * b.m02 + a.m30 * b.m03,
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
                     a.m03 * b.m30 + a.m13 * b.m31 + a.m23 * b.m32 + a.m33 * b.m33 } );
}


extern mat4 mat4Mulf(mat4 a, float f) {
    return ((mat4) { a.m00 * f, a.m01 * f, a.m02 * f, a.m03 * f,
                     a.m10 * f, a.m11 * f, a.m12 * f, a.m13 * f,
                     a.m20 * f, a.m21 * f, a.m22 * f, a.m23 * f,
                     a.m30 * f, a.m31 * f, a.m32 * f, a.m33 * f } );
}


extern vec4 mat4Mulv(mat4 m, vec4 v) {
    return ((vec4) { m.m00 * v.x + m.m10 * v.y + m.m20 * v.z + m.m30 * v.w,
                     m.m01 * v.x + m.m11 * v.y + m.m21 * v.z + m.m31 * v.w,
                     m.m02 * v.x + m.m12 * v.y + m.m22 * v.z + m.m32 * v.w,
                     m.m03 * v.x + m.m13 * v.y + m.m23 * v.z + m.m33 * v.w } );
}


extern float mat4Det(mat4 m) {
    float result = 0.0f;
    mat3 mat = (mat3) { m.m11, m.m12, m.m13,
                        m.m21, m.m22, m.m23,
                        m.m31, m.m32, m.m33 }; 
    result += m.m00 * mat3Det(mat);

    mat = (mat3) { m.m10, m.m12, m.m13,
                   m.m20, m.m22, m.m23,
                   m.m30, m.m32, m.m33 }; 
    result -= m.m01 * mat3Det(mat);

    mat = (mat3) { m.m10, m.m11, m.m13,
                   m.m20, m.m21, m.m23,
                   m.m30, m.m31, m.m33 }; 
    result += m.m02 * mat3Det(mat);

    mat = (mat3) { m.m10, m.m11, m.m12,
                   m.m20, m.m21, m.m22,
                   m.m30, m.m31, m.m32 }; 
    result -= m.m03 * mat3Det(mat);

    return (result);
}


extern float mat4Trace(mat4 m) {
    return (m.m00 + m.m11 + m.m22 + m.m33);
}


extern mat4 mat4Translate(vec3 v) {
    return ((mat4) { 1.0, 0.0, 0.0, 0.0,
                     0.0, 1.0, 0.0, 0.0,
                     0.0, 0.0, 1.0, 0.0,
                     v.x, v.y, v.z, 1.0 } );
}


extern mat4 mat4Rotate(vec3 axis, float angle) {
    float c = cos(angle);
    float s = sin(angle);
    float t = 1.0f - c;

    vec3 axisn = vec3Normalize(axis);
    float x = axisn.x,
          y = axisn.y,
          z = axisn.z;

    mat4 mat = mat4Init(1.0f);
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
    mat4 mat = mat4Init(1.0f);
         mat = mat4Mul(mat4Translate(pivot), mat);
         mat = mat4Mul(mat4Rotate(axis, angle), mat);
         mat = mat4Mul(mat4Translate(vec3Mulf(pivot, -1.0f)), mat);
    return (mat);
}


extern mat4 mat4RotateX(float f) {
    float sinres = sin(f),
          cosres = cos(f);

    mat4 mat = mat4Init(1.0f);
    mat.m11  = cosres;
    mat.m21  = sinres;
    mat.m12  = -sinres;
    mat.m22  = cosres;
    return (mat);
}


extern mat4 mat4RotateY(float f) {
    float sinres = sin(f),
          cosres = cos(f);

    mat4 mat = mat4Init(1.0f);
    mat.m00  = cosres;
    mat.m20  = -sinres;
    mat.m02  = sinres;
    mat.m22  = cosres;
    return (mat);
}


extern mat4 mat4RotateZ(float f) {
    float sinres = sin(f),
          cosres = cos(f);

    mat4 mat = mat4Init(1.0f);
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

    mat4 mat =  mat4Init(1.0f);
    mat.m00  =  s.x; mat.m10 =  s.y; mat.m20 =  s.z;
    mat.m01  =  u.x; mat.m11 =  u.y; mat.m21 =  u.z;
    mat.m02  = -f.x; mat.m12 = -f.y; mat.m22 = -f.z;
    mat.m03  = -vec3Dot(s, eye);
    mat.m13  = -vec3Dot(u, eye);
    mat.m23  =  vec3Dot(f, eye);
    return (mat);
}


extern mat4 mat4Scale(vec3 v) {
    return ((mat4) { v.x, 0.0, 0.0, 0.0,
                     0.0, v.y, 0.0, 0.0,
                     0.0, 0.0, v.z, 0.0,
                     0.0, 0.0, 0.0, 1.0 } );
}


extern mat4 mat4Frust(float left, float right, float down, float top, float near, float far) {
    mat4 mat = mat4Zero();
    mat.m00  =  (near * 2.0f) / (right - left);
    mat.m11  =  (near * 2.0f) / (top   - down);
    mat.m20  =  (right + left) / (right - left);
    mat.m21  =  (top + down) / (top - down);
    mat.m22  = -(far + near) / (far - near);
    mat.m23  = -(1.0f);
    mat.m32  = -(2 * far * near) / (far - near);
    return (mat);
}


extern mat4 mat4Ortho(float left, float right, float down, float top, float near, float far) {
    mat4 mat = mat4Zero();
    mat.m00 =  2.0f / (right - left);
    mat.m11 =  2.0f / (top   - down);
    mat.m22 = -2.0f / (far   - near);
    mat.m03 = -(left  + right) / (right - left);
    mat.m13 = -(top   + down)  / (top   - down);
    mat.m23 = -(far   + near)  / (far   - near);
    mat.m33 =  1.0f;
    return (mat);
}


extern mat4 mat4Persp(float fieldOfView, float aspect, float near, float far) {
    float top   = near * tan(fieldOfView * 0.5f);
    float right = top * aspect;
    return (mat4Frust(-right, right, -top, top, near, far));
}


extern mat4 mat4Trans(mat4 m) {
    return ((mat4) { m.m00, m.m10, m.m20, m.m30,
                     m.m01, m.m11, m.m21, m.m31,
                     m.m02, m.m12, m.m22, m.m32,
                     m.m03, m.m13, m.m23, m.m33 } );
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat4_h_ */
