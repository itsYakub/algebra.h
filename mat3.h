#if !defined (_mat3_h_)
# define _mat3_h_ 1

typedef union u_vec3 vec3;

typedef union u_mat3 mat3;

union u_mat3 {
    struct {
        float m00, m01, m02,
              m10, m11, m12,
              m20, m21, m22;
    };

# if defined (__cplusplus)

    u_mat3(void);

    u_mat3(float);

    u_mat3(float, float, float, float, float, float, float, float, float);

    u_mat3(const u_mat3 &); 

    u_mat3 &operator = (const u_mat3 &);

# endif /* __cplusplus */

};

extern mat3 mat3Zero(void);

extern mat3 mat3Init(float);

extern mat3 mat3Add(mat3, mat3);

extern mat3 mat3Sub(mat3, mat3);

extern mat3 mat3Mul(mat3, mat3);

extern mat3 mat3Mulf(mat3, float);

extern vec3 mat3Mulv(mat3, vec3);

extern float mat3Det(mat3);

extern float mat3Trace(mat3);

extern mat3 mat3Trans(mat3); 

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include "./vec3.h"
#
#  if defined (__cplusplus)

u_mat3::u_mat3(void) :
    m00(0.0), m01(0.0), m02(0.0),
    m10(0.0), m11(0.0), m12(0.0),
    m20(0.0), m21(0.0), m22(0.0) { }


u_mat3::u_mat3(float s) :
    m00(1.0 * s), m01(0.0),     m02(0.0),
    m10(0.0),     m11(1.0 * s), m12(0.0),
    m20(0.0),     m21(0.0),     m22(1.0 * s) { }

    
u_mat3::u_mat3(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22) :
    m00(m00), m01(m01), m02(m02),
    m10(m10), m11(m11), m12(m12),
    m20(m20), m21(m21), m22(m22) { }


u_mat3::u_mat3(const u_mat3 &other) :
    m00(other.m00), m01(other.m01), m02(other.m02),
    m10(other.m10), m11(other.m11), m12(other.m12),
    m20(other.m20), m21(other.m21), m22(other.m22) { }


u_mat3 &u_mat3::operator = (const u_mat3 &other) {
    this->m00 = other.m00; 
    this->m01 = other.m01; 
    this->m02 = other.m02;
    
    this->m10 = other.m10; 
    this->m11 = other.m11; 
    this->m12 = other.m12;
    
    this->m20 = other.m20; 
    this->m21 = other.m21; 
    this->m22 = other.m22;
    return (*this);
}

#  endif /* __cplusplus */

extern mat3 mat3Zero(void) {
    return ((mat3) { 0.0f, 0.0f, 0.0f,
                     0.0f, 0.0f, 0.0f,
                     0.0f, 0.0f, 0.0f } );
}


extern mat3 mat3Init(float s) {
    return ((mat3) { 1.0f * s, 0.0f,     0.0f,
                     0.0f,     1.0f * s, 0.0f,
                     0.0f,     0.0f,     1.0f * s } );
}


extern mat3 mat3Add(mat3 a, mat3 b) {
    return ((mat3) { a.m00 + b.m00, a.m01 + b.m01, a.m02 + b.m02,
                     a.m10 + b.m10, a.m11 + b.m11, a.m12 + b.m12,
                     a.m20 + b.m20, a.m21 + b.m21, a.m22 + b.m22 } );
}


extern mat3 mat3Sub(mat3 a, mat3 b) {
    return ((mat3) { a.m00 - b.m00, a.m01 - b.m01, a.m02 - b.m02,
                     a.m10 - b.m10, a.m11 - b.m11, a.m12 - b.m12,
                     a.m20 - b.m20, a.m21 - b.m21, a.m22 - b.m22 } );
}


extern mat3 mat3Mul(mat3 a, mat3 b) {
    return ((mat3) { a.m00 * b.m00 + a.m10 * b.m01 + a.m20 * b.m02,
                     a.m01 * b.m00 + a.m11 * b.m01 + a.m21 * b.m02,
                     a.m02 * b.m00 + a.m12 * b.m01 + a.m22 * b.m02,

                     a.m00 * b.m10 + a.m10 * b.m11 + a.m20 * b.m12,
                     a.m01 * b.m10 + a.m11 * b.m11 + a.m21 * b.m12,
                     a.m02 * b.m10 + a.m12 * b.m11 + a.m22 * b.m12,

                     a.m00 * b.m20 + a.m10 * b.m21 + a.m20 * b.m22,
                     a.m01 * b.m20 + a.m11 * b.m21 + a.m21 * b.m22,
                     a.m02 * b.m20 + a.m12 * b.m21 + a.m22 * b.m22 } );
}


extern mat3 mat3Mulf(mat3 a, float f) {
    return ((mat3) { a.m00 * f, a.m01 * f, a.m02 * f,
                     a.m10 * f, a.m11 * f, a.m12 * f,
                     a.m20 * f, a.m21 * f, a.m22 * f } );
}


extern vec3 mat3Mulv(mat3 m, vec3 v) {
    return ((vec3) { m.m00 * v.x + m.m01 * v.y + m.m02 * v.z,
                     m.m10 * v.x + m.m11 * v.y + m.m12 * v.z,
                     m.m20 * v.x + m.m21 * v.y + m.m22 * v.z } );
}


extern float mat3Det(mat3 a) {
    return (a.m00 * a.m11 * a.m22 +
            a.m01 * a.m12 * a.m20 +
            a.m02 * a.m10 * a.m21 -
            a.m20 * a.m11 * a.m02 -
            a.m21 * a.m12 * a.m00 -
            a.m22 * a.m10 * a.m01);
}

extern float mat3Trace(mat3 m) {
    return (m.m00 + m.m11 + m.m22);
}

extern mat3 mat3Trans(mat3 m) {
    mat3 mat = mat3Zero();
    mat.m00  = m.m00; mat.m01 = m.m10; mat.m02 = m.m20;
    mat.m10  = m.m10; mat.m11 = m.m11; mat.m12 = m.m21;
    mat.m20  = m.m20; mat.m21 = m.m12; mat.m22 = m.m22;
    return (mat);
} 

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat3_h_ */
