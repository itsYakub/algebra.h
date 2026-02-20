#if !defined (_mat3_hpp_)
# define _mat3_hpp_ 1

struct mat3 {
    union {
        struct {
            double m00, m10, m20,
                   m01, m11, m21,
                   m02, m12, m22;
        };

        double ptr[3][3];
    };

    mat3(void);

    mat3(const double);

    mat3(const mat3 &);

    const mat3 &operator = (const mat3 &);

    mat3 operator + (const mat3 &);

    mat3 operator - (const mat3 &);

    mat3 operator * (const mat3 &);
    
    mat3 operator * (double);

    double det(void);
};

# if defined (ALGEBRA_IMPLEMENTATION)

mat3::mat3(void) :
    m00(0.0), m01(0.0), m02(0.0),
    m10(0.0), m11(0.0), m12(0.0),
    m20(0.0), m21(0.0), m22(0.0) { }

mat3::mat3(const double s) :
    m00(1.0 * s), m01(0.0),     m02(0.0),
    m10(0.0),     m11(1.0 * s), m12(0.0),
    m20(0.0),     m21(0.0),     m22(1.0 * s) { }

mat3::mat3(const mat3 &other) :
    m00(other.m00), m01(other.m01), m02(other.m02),
    m10(other.m10), m11(other.m11), m12(other.m12),
    m20(other.m20), m21(other.m21), m22(other.m22) { }

const mat3 &mat3::operator = (const mat3 &other) {
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

mat3 mat3::operator + (const mat3 &other) {
    mat3 result = mat3();
    result.m00 = this->m00 + other.m00; 
    result.m01 = this->m01 + other.m01; 
    result.m02 = this->m02 + other.m02; 
    
    result.m10 = this->m10 + other.m10; 
    result.m11 = this->m11 + other.m11; 
    result.m12 = this->m12 + other.m12; 
    
    result.m20 = this->m20 + other.m20; 
    result.m21 = this->m21 + other.m21; 
    result.m22 = this->m22 + other.m22; 
    return (result);
}

mat3 mat3::operator - (const mat3 &other) {
    mat3 result = mat3();
    result.m00 = this->m00 - other.m00; 
    result.m01 = this->m01 - other.m01; 
    result.m02 = this->m02 - other.m02; 
    
    result.m10 = this->m10 - other.m10; 
    result.m11 = this->m11 - other.m11; 
    result.m12 = this->m12 - other.m12; 
    
    result.m20 = this->m20 - other.m20; 
    result.m21 = this->m21 - other.m21; 
    result.m22 = this->m22 - other.m22; 
    return (result);
}

mat3 mat3::operator * (const mat3 &other) {
    mat3 result = mat3();
    result.m00 = this->m00 * other.m00 + this->m10 * other.m01 + this->m20 * other.m02;
    result.m01 = this->m01 * other.m00 + this->m11 * other.m01 + this->m21 * other.m02;
    result.m02 = this->m02 * other.m00 + this->m12 * other.m01 + this->m22 * other.m02;

    result.m10 = this->m00 * other.m10 + this->m10 * other.m11 + this->m20 * other.m12;
    result.m11 = this->m01 * other.m10 + this->m11 * other.m11 + this->m21 * other.m12;
    result.m12 = this->m02 * other.m10 + this->m12 * other.m11 + this->m22 * other.m12;

    result.m20 = this->m00 * other.m20 + this->m10 * other.m21 + this->m20 * other.m22;
    result.m21 = this->m01 * other.m20 + this->m11 * other.m21 + this->m21 * other.m22;
    result.m22 = this->m02 * other.m20 + this->m12 * other.m21 + this->m22 * other.m22;
    return (result);
}

mat3 mat3::operator * (const double f) {
    mat3 result = mat3();
    result.m00 = this->m00 * f; 
    result.m01 = this->m01 * f; 
    result.m02 = this->m02 * f; 
    
    result.m10 = this->m10 * f; 
    result.m11 = this->m11 * f; 
    result.m12 = this->m12 * f; 
    
    result.m20 = this->m20 * f; 
    result.m21 = this->m21 * f; 
    result.m22 = this->m22 * f; 
    return (result);
}

double mat3::det(void) {
    return (this->m00 * this->m11 * this->m22 +
            this->m01 * this->m12 * this->m20 +
            this->m02 * this->m10 * this->m21 -
            this->m20 * this->m11 * this->m02 -
            this->m21 * this->m12 * this->m00 -
            this->m22 * this->m10 * this->m01);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat3_hpp_ */
