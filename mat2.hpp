#if !defined (_mat2_hpp_)
# define _mat2_hpp_ 1

struct mat2 {
    union {
        struct {
            double m00, m10,
                   m01, m11;
        };

        double ptr[2][2];
    };

    mat2(void);

    mat2(const double);

    mat2(const mat2 &);

    const mat2 &operator = (const mat2 &);

    mat2 operator + (const mat2 &);

    mat2 operator - (const mat2 &);

    mat2 operator * (const mat2 &);
    
    mat2 operator * (double);

    double det(void);
};

# if defined (ALGEBRA_IMPLEMENTATION)

mat2::mat2(void) :
    m00(0.0), m10(0.0),
    m01(0.0), m11(0.0) { }

mat2::mat2(const double s) :
    m00(1.0 * s), m10(0.0),
    m01(0.0),     m11(1.0 * s) { }

mat2::mat2(const mat2 &other) :
    m00(other.m00), m10(other.m01),
    m01(other.m10), m11(other.m11) { }

const mat2 &mat2::operator = (const mat2 &other) {
    this->m00 = other.m00; 
    this->m01 = other.m01; 
    this->m10 = other.m10; 
    this->m11 = other.m11; 
    return (*this);
}

mat2 mat2::operator + (const mat2 &other) {
    mat2 result = mat2();
    result.m00 = this->m00 + other.m00; 
    result.m01 = this->m01 + other.m01; 
    result.m10 = this->m10 + other.m10; 
    result.m11 = this->m11 + other.m11; 
    return (result);
}

mat2 mat2::operator - (const mat2 &other) {
    mat2 result = mat2();
    result.m00 = this->m00 - other.m00; 
    result.m01 = this->m01 - other.m01; 
    result.m10 = this->m10 - other.m10; 
    result.m11 = this->m11 - other.m11; 
    return (result);
}

mat2 mat2::operator * (const mat2 &other) {
    mat2 result = mat2();
    result.m00 = this->m00 * other.m00 + this->m10 * other.m01; 
    result.m01 = this->m01 * other.m00 + this->m11 * other.m01; 
    result.m10 = this->m00 * other.m10 + this->m10 * other.m11; 
    result.m11 = this->m01 * other.m10 + this->m11 * other.m11; 
    return (result);
}

mat2 mat2::operator * (const double f) {
    mat2 result = mat2();
    result.m00 = this->m00 * f; 
    result.m01 = this->m01 * f; 
    result.m10 = this->m10 * f; 
    result.m11 = this->m11 * f; 
    return (result);
}

double mat2::det(void) {
    return (this->m00 * this->m11 - this->m10 * this->m01);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat2_hpp_ */
