#if !defined (_vec4_hpp_)
# define _vec4_hpp_ 1

struct vec4 {
    union {
        struct {
            float x;
            float y;
            float z;
            float w;
        };

        struct {
            float r;
            float g;
            float b;
            float a;
        };

        float ptr[4];
    };
   
    /* constructors... */

    vec4(void);

    vec4(float);

    vec4(float, float, float, float);

    vec4(const vec4 &);
   
    /* operator overloading... */

    vec4 &operator = (const vec4 &);

    vec4 operator + (vec4) const;
    
    vec4 operator - (vec4) const;
    
    vec4 operator * (vec4) const;
    
    vec4 operator / (vec4) const;
    
    vec4 operator + (float) const;
    
    vec4 operator - (float) const;
    
    vec4 operator * (float) const;
    
    vec4 operator / (float) const;
    
    vec4 &operator += (vec4);

    vec4 &operator -= (vec4);

    vec4 &operator *= (vec4);

    vec4 &operator /= (vec4);
    
    vec4 &operator += (float);

    vec4 &operator -= (float);

    vec4 &operator *= (float);

    vec4 &operator /= (float);
};

# if defined (ALGEBRA_IMPLEMENTATION)

vec4::vec4(void) : x(0.0), y(0.0), z(0.0), w(0.0) { }

vec4::vec4(float v) : x(v), y(v), z(v), w(v) { }

vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }

vec4::vec4(const vec4 &other) : x(other.x), y(other.y), z(other.z), w(other.w) { }

vec4 &vec4::operator = (const vec4 &other) {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    this->w = other.w;
    return (*this);
}

vec4 vec4::operator + (vec4 other) const {
    return (vec4(this->x + other.x,
                 this->y + other.y,
                 this->z + other.z,
                 this->w + other.w));
}

vec4 vec4::operator - (vec4 other) const {
    return (vec4(this->x - other.x,
                 this->y - other.y,
                 this->z - other.z,
                 this->w - other.w));
}

vec4 vec4::operator * (vec4 other) const {
    return (vec4(this->x * other.x,
                 this->y * other.y,
                 this->z * other.z,
                 this->w * other.w));
}

vec4 vec4::operator / (vec4 other) const {
    return (vec4(other.x != 0.0 ? this->x / other.x : 0.0,
                 other.y != 0.0 ? this->y / other.y : 0.0,
                 other.z != 0.0 ? this->z / other.z : 0.0,
                 other.w != 0.0 ? this->w / other.w : 0.0));
}

vec4 vec4::operator + (float f) const {
    return (vec4(this->x + f,
                 this->y + f,
                 this->z + f,
                 this->w + f));
}

vec4 vec4::operator - (float f) const {
    return (vec4(this->x - f,
                 this->y - f,
                 this->z - f,
                 this->w - f));
}

vec4 vec4::operator * (float f) const {
    return (vec4(this->x * f,
                 this->y * f,
                 this->z * f,
                 this->w * f));
}

vec4 vec4::operator / (float f) const {
    return (vec4(f != 0.0 ? this->x / f : 0.0,
                 f != 0.0 ? this->y / f : 0.0,
                 f != 0.0 ? this->z / f : 0.0,
                 f != 0.0 ? this->w / f : 0.0));
}

vec4 &vec4::operator += (vec4 other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    this->w += other.w;
    return (*this);
}

vec4 &vec4::operator -= (vec4 other) {
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    this->w -= other.w;
    return (*this);
}

vec4 &vec4::operator *= (vec4 other) {
    this->x *= other.x;
    this->y *= other.y;
    this->z *= other.z;
    this->w *= other.w;
    return (*this);
}

vec4 &vec4::operator /= (vec4 other) {
    this->x = other.x != 0.0 ? this->x / other.x : 0.0;
    this->y = other.y != 0.0 ? this->y / other.y : 0.0;
    this->z = other.z != 0.0 ? this->z / other.z : 0.0;
    this->w = other.w != 0.0 ? this->w / other.w : 0.0;
    return (*this);
}

vec4 &vec4::operator += (float f) {
    this->x += f;
    this->y += f;
    this->z += f;
    this->w += f;
    return (*this);
}

vec4 &vec4::operator -= (float f) {
    this->x -= f;
    this->y -= f;
    this->z -= f;
    this->w -= f;
    return (*this);
}

vec4 &vec4::operator *= (float f) {
    this->x *= f;
    this->y *= f;
    this->z *= f;
    this->w *= f;
    return (*this);
}

vec4 &vec4::operator /= (float f) {
    this->x = f != 0.0 ? this->x / f : 0.0;
    this->y = f != 0.0 ? this->y / f : 0.0;
    this->z = f != 0.0 ? this->z / f : 0.0;
    this->w = f != 0.0 ? this->w / f : 0.0;
    return (*this);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec4_hpp_ */
