#if !defined (_mat2_h_)
# define _mat2_h_ 1

typedef union u_vec2 vec2;

typedef union u_mat2 mat2;

union u_mat2 {
    struct {
        float m00, m01,
              m10, m11;
    };

# if defined (__cplusplus)

    u_mat2(void);

    u_mat2(float);

    u_mat2(float, float, float, float);

    u_mat2(const u_mat2 &); 

    u_mat2 &operator = (const u_mat2 &);

# endif /* __cplusplus */

};

extern mat2 mat2Zero(void);

extern mat2 mat2Init(float);

extern mat2 mat2Add(mat2, mat2);

extern mat2 mat2Sub(mat2, mat2);

extern mat2 mat2Mul(mat2, mat2);

extern mat2 mat2Mulf(mat2, float);

extern vec2 mat2Mulv(mat2, vec2);

extern float mat2Det(mat2);

extern float mat2Trace(mat2);

extern mat2 mat2Trans(mat2); 

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include "./vec3.h"
#
#  if defined (__cplusplus)

u_mat2::u_mat2(void) :
    m00(0.0), m01(0.0),
    m10(0.0), m11(0.0) { }


u_mat2::u_mat2(float s) :
    m00(1.0 * s), m01(0.0),
    m10(0.0),     m11(1.0 * s) { }


u_mat2::u_mat2(float m00, float m01, float m10, float m11) :
    m00(m00), m01(m01),
    m10(m10), m11(m11) { }


u_mat2::u_mat2(const u_mat2 &other) :
    m00(other.m00), m01(other.m01),
    m10(other.m10), m11(other.m11) { }


u_mat2 &u_mat2::operator = (const u_mat2 &other) {
    this->m00 = other.m00; 
    this->m01 = other.m01; 
    this->m10 = other.m10; 
    this->m11 = other.m11; 
    return (*this);
}

#  endif /* __cplusplus */

extern mat2 mat2Zero(void) {
    return ((mat2) { 0.0f, 0.0f,
                     0.0f, 0.0f } );
}


extern mat2 mat2Init(float s) {
    return ((mat2) { 1.0f * s, 0.0f,
                     0.0f,     1.0f * s } );
}


extern mat2 mat2Add(mat2 a, mat2 b) {
    return ((mat2) { a.m00 + b.m00, a.m01 + b.m01,
                     a.m10 + b.m10, a.m11 + b.m11 } );
}


extern mat2 mat2Sub(mat2 a, mat2 b) {
    return ((mat2) { a.m00 - b.m00, a.m01 - b.m01,
                     a.m10 - b.m10, a.m11 - b.m11 } );
}


extern mat2 mat2Mul(mat2 a, mat2 b) {
    return ((mat2) { a.m00 * b.m00 + a.m10 * b.m01,
                     a.m01 * b.m00 + a.m11 * b.m01,
                     a.m00 * b.m10 + a.m10 * b.m11,
                     a.m01 * b.m10 + a.m11 * b.m11 } );
}


extern mat2 mat2Mulf(mat2 a, float f) {
    return ((mat2) { a.m00 * f, a.m01 * f,
                     a.m10 * f, a.m11 * f } );
}


extern vec2 mat2Mulv(mat2 m, vec2 v) {
    return ((vec2) { m.m00 * v.x + m.m10 * v.y,
                     m.m01 * v.x + m.m11 * v.y } );
}


extern float mat2Det(mat2 a) {
    return (a.m00 * a.m11 - a.m10 * a.m01);
}

extern float mat2Trace(mat2 m) {
    return (m.m00 + m.m11);
}

extern mat2 mat2Trans(mat2 m) {
    mat2 mat = mat2Zero();
    mat.m00  = m.m00; mat.m01 = m.m10;
    mat.m10  = m.m10; mat.m11 = m.m11;
    return (mat);
} 

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat2_h_ */
