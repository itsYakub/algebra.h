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

    /* properties... */

    static const vec4 zero;

    static const vec4 one;

    static const vec4 right;

    static const vec4 left;

    static const vec4 up;

    static const vec4 down;

    static const vec4 front;

    static const vec4 back;
   
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

    bool operator == (vec4) const;
    
    bool operator != (vec4) const;
    
    bool operator > (vec4) const;
    
    bool operator >= (vec4) const;
    
    bool operator < (vec4) const;
    
    bool operator <= (vec4) const;
   
    /* static methods... */
    
    static float dot(vec4, vec4);
    
    static float length(vec4);

    static float distance(vec4, vec4);
    
    static vec4 normalize(vec4);
};

# if defined (ALGEBRA_IMPLEMENTATION)

/* constructors... */

vec4::vec4(void) : x(0.0), y(0.0), z(0.0), w(0.0) { }


vec4::vec4(float v) : x(v), y(v), z(v), w(v) { }


vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }


vec4::vec4(const vec4 &other) : x(other.x), y(other.y), z(other.z), w(other.w) { }

/* properties... */

const vec4 vec4::zero = vec4(0.0);


const vec4 vec4::one = vec4(1.0);


const vec4 vec4::right = vec4(1.0, 0.0, 0.0, 0.0);


const vec4 vec4::left = vec4(-1.0, 0.0, 0.0, 0.0);


const vec4 vec4::up = vec4(0.0, 1.0, 0.0, 0.0);


const vec4 vec4::down = vec4(0.0, -1.0, 0.0, 0.0);


const vec4 vec4::front = vec4(0.0, 0.0, 1.0, 0.0);


const vec4 vec4::back = vec4(0.0, 0.0, -1.0, 0.0);

/* operator overloading... */

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


bool vec4::operator == (vec4 other) const {
    return (this->x == other.x &&
            this->y == other.y &&
            this->z == other.z &&
            this->w == other.w);
}


bool vec4::operator != (vec4 other) const {
    return (this->x != other.x ||
            this->y != other.y ||
            this->z != other.z ||
            this->w != other.w);
}


bool vec4::operator > (vec4 other) const {
    return (this->x > other.x ||
            this->y > other.y ||
            this->z > other.z ||
            this->w > other.w);
}


bool vec4::operator >= (vec4 other) const {
    return (this->x >= other.x ||
            this->y >= other.y ||
            this->z >= other.z ||
            this->w >= other.w);
}


bool vec4::operator < (vec4 other) const {
    return (this->x < other.x ||
            this->y < other.y ||
            this->z < other.z ||
            this->w < other.w);
}


bool vec4::operator <= (vec4 other) const {
    return (this->x <= other.x ||
            this->y <= other.y ||
            this->y <= other.y ||
            this->z <= other.z);
}

/* static methods... */

float vec4::dot(vec4 a, vec4 b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}


float vec4::length(vec4 a) {
    return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w + a.w));
}


float vec4::distance(vec4 a, vec4 b) {
    return (sqrt((a.x - b.x) * (a.x - b.x) +
                 (a.y - b.y) * (a.y * b.y) +
                 (a.z - b.z) * (a.z * b.z) +
                 (a.w - b.w) * (a.w * b.w)));
}


vec4 vec4::normalize(vec4 a) {
    float len = vec4::length(a);

    vec4 vec = a;
    if (len == 0.0) {
        len = 1.0;
    }
    
    return (vec * (1.0 / len));
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec4_hpp_ */
