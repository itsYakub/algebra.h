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

extern mat3 mat3zero(void);

extern mat3 mat3init(float);

extern mat3 mat3add(mat3, mat3);

extern mat3 mat3sub(mat3, mat3);

extern mat3 mat3mul(mat3, mat3);

extern mat3 mat3mulf(mat3, float);

extern vec3 mat3mulv(mat3, vec3);

extern float mat3det(mat3);

extern float mat3trace(mat3);

extern mat3 mat3transpose(mat3); 

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
    *this = { other.m00, other.m01, other.m02,
              other.m10, other.m11, other.m12,
              other.m20, other.m21, other.m22 };
    
    return (*this);
}

#  endif /* __cplusplus */

extern mat3 mat3zero(void) {
    return ((mat3) { 0.0f, 0.0f, 0.0f,
                     0.0f, 0.0f, 0.0f,
                     0.0f, 0.0f, 0.0f } );
}


extern mat3 mat3init(float s) {
    return ((mat3) { 1.0f * s, 0.0f,     0.0f,
                     0.0f,     1.0f * s, 0.0f,
                     0.0f,     0.0f,     1.0f * s } );
}


extern mat3 mat3add(mat3 a, mat3 b) {
    return ((mat3) { a.m00 + b.m00, a.m01 + b.m01, a.m02 + b.m02,
                     a.m10 + b.m10, a.m11 + b.m11, a.m12 + b.m12,
                     a.m20 + b.m20, a.m21 + b.m21, a.m22 + b.m22 } );
}


extern mat3 mat3sub(mat3 a, mat3 b) {
    return ((mat3) { a.m00 - b.m00, a.m01 - b.m01, a.m02 - b.m02,
                     a.m10 - b.m10, a.m11 - b.m11, a.m12 - b.m12,
                     a.m20 - b.m20, a.m21 - b.m21, a.m22 - b.m22 } );
}


extern mat3 mat3mul(mat3 a, mat3 b) {
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


extern mat3 mat3mulf(mat3 m, float f) {
    return ((mat3) { m.m00 * f, m.m01 * f, m.m02 * f,
                     m.m10 * f, m.m11 * f, m.m12 * f,
                     m.m20 * f, m.m21 * f, m.m22 * f } );
}


extern vec3 mat3mulv(mat3 m, vec3 v) {
    return ((vec3) { m.m00 * v.x + m.m01 * v.y + m.m02 * v.z,
                     m.m10 * v.x + m.m11 * v.y + m.m12 * v.z,
                     m.m20 * v.x + m.m21 * v.y + m.m22 * v.z } );
}


extern float mat3det(mat3 m) {
    return (m.m00 * m.m11 * m.m22 +
            m.m01 * m.m12 * m.m20 +
            m.m02 * m.m10 * m.m21 -
            m.m20 * m.m11 * m.m02 -
            m.m21 * m.m12 * m.m00 -
            m.m22 * m.m10 * m.m01);
}

extern float mat3trace(mat3 m) {
    return (m.m00 + m.m11 + m.m22);
}

extern mat3 mat3transpose(mat3 m) {
    return ((mat3) { m.m00, m.m10, m.m20,
                     m.m01, m.m11, m.m21,
                     m.m02, m.m12, m.m22 } );
} 

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat3_h_ */
