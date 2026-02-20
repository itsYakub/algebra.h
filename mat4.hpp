#if !defined (_mat4_hpp_)
# define _mat4_hpp_ 1
#
# include <cmath>
#
# include "./mat3.hpp"

struct mat4 {
    union {
        struct {
            double m00, m10, m20, m30,
                   m01, m11, m21, m31,
                   m02, m12, m22, m32,
                   m03, m13, m23, m33;
        };

        double ptr[4][4];
    };

    mat4(void);

    mat4(const double);

    mat4(const mat4 &);

    const mat4 &operator = (const mat4 &);

    mat4 operator + (const mat4 &);

    mat4 operator - (const mat4 &);

    mat4 operator * (const mat4 &);
    
    mat4 operator * (double);

    double det(void);
    
    static mat4 frust(const double, const double, const double, const double, const double, const double);

    static mat4 ortho(const double, const double, const double, const double, const double, const double);
    
    static mat4 persp(const double, const double, const double, const double);
};

# if defined (ALGEBRA_IMPLEMENTATION)

mat4::mat4(void) :
    m00(0.0), m01(0.0), m02(0.0), m03(0.0),
    m10(0.0), m11(0.0), m12(0.0), m13(0.0),
    m20(0.0), m21(0.0), m22(0.0), m23(0.0),
    m30(0.0), m31(0.0), m32(0.0), m33(0.0) { }

mat4::mat4(const double s) :
    m00(1.0 * s), m01(0.0),     m02(0.0),     m03(0.0),
    m10(0.0),     m11(1.0 * s), m12(0.0),     m13(0.0),
    m20(0.0),     m21(0.0),     m22(1.0 * s), m23(0.0),
    m30(0.0),     m31(0.0),     m32(0.0),     m33(1.0 * s) { }

mat4::mat4(const mat4 &other) :
    m00(other.m00), m01(other.m01), m02(other.m02), m03(other.m03),
    m10(other.m10), m11(other.m11), m12(other.m12), m13(other.m13),
    m20(other.m20), m21(other.m21), m22(other.m22), m23(other.m23),
    m30(other.m30), m31(other.m31), m32(other.m32), m33(other.m33) { }

const mat4 &mat4::operator = (const mat4 &other) {
    this->m00 = other.m00; 
    this->m01 = other.m01; 
    this->m02 = other.m02;
    this->m03 = other.m03;
    
    this->m10 = other.m10; 
    this->m11 = other.m11; 
    this->m12 = other.m12;
    this->m13 = other.m13;
    
    this->m20 = other.m20; 
    this->m21 = other.m21; 
    this->m22 = other.m22;
    this->m23 = other.m23;
    
    this->m30 = other.m30; 
    this->m31 = other.m31; 
    this->m32 = other.m32;
    this->m33 = other.m33;
    return (*this);
}

mat4 mat4::operator + (const mat4 &other) {
    mat4 result = mat4();
    result.m00 = this->m00 + other.m00; 
    result.m01 = this->m01 + other.m01; 
    result.m02 = this->m02 + other.m02; 
    result.m03 = this->m03 + other.m03; 
    
    result.m10 = this->m10 + other.m10; 
    result.m11 = this->m11 + other.m11; 
    result.m12 = this->m12 + other.m12; 
    result.m13 = this->m13 + other.m13; 
    
    result.m20 = this->m20 + other.m20; 
    result.m21 = this->m21 + other.m21; 
    result.m22 = this->m22 + other.m22; 
    result.m23 = this->m23 + other.m23; 
    
    result.m30 = this->m30 + other.m30; 
    result.m31 = this->m31 + other.m31; 
    result.m32 = this->m32 + other.m32; 
    result.m33 = this->m33 + other.m33; 
    return (result);
}

mat4 mat4::operator - (const mat4 &other) {
    mat4 result = mat4();
    result.m00 = this->m00 - other.m00; 
    result.m01 = this->m01 - other.m01; 
    result.m02 = this->m02 - other.m02; 
    result.m03 = this->m03 - other.m03; 
    
    result.m10 = this->m10 - other.m10; 
    result.m11 = this->m11 - other.m11; 
    result.m12 = this->m12 - other.m12; 
    result.m13 = this->m13 - other.m13; 
    
    result.m20 = this->m20 - other.m20; 
    result.m21 = this->m21 - other.m21; 
    result.m22 = this->m22 - other.m22; 
    result.m23 = this->m23 - other.m23; 
    
    result.m30 = this->m30 - other.m30; 
    result.m31 = this->m31 - other.m31; 
    result.m32 = this->m32 - other.m32; 
    result.m33 = this->m33 - other.m33; 
    return (result);
}

mat4 mat4::operator * (const mat4 &other) {
    mat4 result = mat4();
    result.m00 = this->m00 * other.m00 + this->m10 * other.m01 + this->m20 * other.m02 + this->m30 * other.m03;
    result.m01 = this->m01 * other.m00 + this->m11 * other.m01 + this->m21 * other.m02 + this->m31 * other.m03;
    result.m02 = this->m02 * other.m00 + this->m12 * other.m01 + this->m22 * other.m02 + this->m32 * other.m03;
    result.m03 = this->m03 * other.m00 + this->m13 * other.m01 + this->m23 * other.m02 + this->m33 * other.m03;

    result.m10 = this->m00 * other.m10 + this->m10 * other.m11 + this->m20 * other.m12 + this->m30 * other.m13;
    result.m11 = this->m01 * other.m10 + this->m11 * other.m11 + this->m21 * other.m12 + this->m31 * other.m13;
    result.m12 = this->m02 * other.m10 + this->m12 * other.m11 + this->m22 * other.m12 + this->m32 * other.m13;
    result.m13 = this->m03 * other.m10 + this->m13 * other.m11 + this->m23 * other.m12 + this->m33 * other.m13;

    result.m20 = this->m00 * other.m20 + this->m10 * other.m21 + this->m20 * other.m22 + this->m30 * other.m23;
    result.m21 = this->m01 * other.m20 + this->m11 * other.m21 + this->m21 * other.m22 + this->m31 * other.m23;
    result.m22 = this->m02 * other.m20 + this->m12 * other.m21 + this->m22 * other.m22 + this->m32 * other.m23;
    result.m23 = this->m03 * other.m20 + this->m13 * other.m21 + this->m23 * other.m22 + this->m33 * other.m23;

    result.m30 = this->m00 * other.m30 + this->m10 * other.m31 + this->m20 * other.m32 + this->m30 * other.m33;
    result.m31 = this->m01 * other.m30 + this->m11 * other.m31 + this->m21 * other.m32 + this->m31 * other.m33;
    result.m32 = this->m02 * other.m30 + this->m12 * other.m31 + this->m22 * other.m32 + this->m32 * other.m33;
    result.m33 = this->m03 * other.m30 + this->m13 * other.m31 + this->m23 * other.m32 + this->m33 * other.m33;
    return (result);
}

mat4 mat4::operator * (const double f) {
    mat4 result = mat4();
    result.m00 = this->m00 * f; 
    result.m01 = this->m01 * f; 
    result.m02 = this->m02 * f; 
    result.m03 = this->m03 * f; 
    
    result.m10 = this->m10 * f; 
    result.m11 = this->m11 * f; 
    result.m12 = this->m12 * f; 
    result.m13 = this->m13 * f; 
    
    result.m20 = this->m20 * f; 
    result.m21 = this->m21 * f; 
    result.m22 = this->m22 * f; 
    result.m23 = this->m23 * f; 
    
    result.m30 = this->m30 * f; 
    result.m31 = this->m31 * f; 
    result.m32 = this->m32 * f; 
    result.m33 = this->m33 * f; 
    return (result);
}

double mat4::det(void) {
    double result = 0.0;
    mat3 mat = mat3();
   
    mat.m00 = this->m11; mat.m01 = this->m12; mat.m02 = this->m13;
    mat.m10 = this->m21; mat.m11 = this->m22; mat.m12 = this->m23;
    mat.m20 = this->m31; mat.m21 = this->m32; mat.m22 = this->m33;
    result += m00 * mat.det();

    mat.m00 = this->m10; mat.m01 = this->m12; mat.m02 = this->m13;
    mat.m10 = this->m20; mat.m11 = this->m22; mat.m12 = this->m23;
    mat.m20 = this->m30; mat.m21 = this->m32; mat.m22 = this->m33;
    result -= m01 * mat.det();

    mat.m00 = this->m10; mat.m01 = this->m11; mat.m02 = this->m13;
    mat.m10 = this->m20; mat.m11 = this->m21; mat.m12 = this->m23;
    mat.m20 = this->m30; mat.m21 = this->m31; mat.m22 = this->m33;
    result += m02 * mat.det();

    mat.m00 = this->m10; mat.m01 = this->m11; mat.m02 = this->m12;
    mat.m10 = this->m20; mat.m11 = this->m21; mat.m12 = this->m22;
    mat.m20 = this->m30; mat.m21 = this->m31; mat.m22 = this->m32;
    result -= m03 * mat.det();

    return (result);
}

mat4 mat4::frust(const double left, const double right, const double top, const double down, const double near, const double far) {
    mat4 mat = mat4();
    mat.m00  = (near * 2.0) / (right - left);
    mat.m11  = (near * 2.0) / (top   - down);
    mat.m20  = (left + right) / (right - left);
    mat.m21  = (top + down) / (top - down);
    mat.m22  = -(far + near) / (far - near);
    mat.m23  = -1.0;
    mat.m32  = -(far * near * 2.0) / (far - near);
    return (mat);
}

mat4 mat4::ortho(const double left, const double right, const double top, const double down, const double near, const double far) {
    mat4 mat = mat4();
    mat.m00  =  2.0 / (right - left);
    mat.m11  =  2.0 / (top   - down);
    mat.m22  = -2.0 / (far   - near);
    mat.m30  = -(left + right) / (right - left);
    mat.m31  = -(top + down) / (top - down);
    mat.m32  = -(far + near) / (far - near);
    mat.m33  =  1.0;
    return (mat);
}

mat4 mat4::persp(const double fieldOfView, const double aspect, const double near, const double far) {
    float top   = near * tan(fieldOfView * 0.5);
    float right = top * aspect;
    return (mat4::frust(-right, right, top, -top, near, far));
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat4_hpp_ */
