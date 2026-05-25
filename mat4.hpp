#if !defined (_mat4_hpp_)
# define _mat4_hpp_ 1
#
# include "./algebra-fwd.hpp"
# include "./type/vec4.hpp"
# include "./type/mat4.hpp"

inline mat4 operator + (mat4, mat4);

inline mat4 operator - (mat4, mat4);

inline mat4 operator * (mat4, mat4);

inline mat4 operator * (mat4, float);

inline vec4 operator * (mat4, vec4);

inline bool operator == (mat4, mat4);

inline bool operator != (mat4, mat4);

inline mat4 &operator += (mat4 &, mat4);

inline mat4 &operator -= (mat4 &, mat4);

inline mat4 &operator *= (mat4 &, mat4);

namespace alg {

    template <>
	mat4 init<mat4>(float);
    
    template <>
	mat4 neg<mat4>(mat4);
    
    template <>
	mat4 transpose<mat4>(mat4);
    
    template <>
	mat4 inv<mat4>(mat4);
    
    template <>
	float det<mat4>(mat4);
    
    template <>
	float trace<mat4>(mat4);

    template <>
	mat4 rotatex<mat4>(float);
    
    template <>
	mat4 rotatey<mat4>(float);
    
    template <>
	mat4 rotatez<mat4>(float);
    
    template <>
	mat4 rotate<mat4>(vec3, float);

    template <>
	mat4 rotateat<mat4>(vec3, vec3, float);

    template <>
	mat4 lookat<mat4>(vec3, vec3, vec3);
    
    template <>
	mat4 scale<mat4>(vec4);
    
    template <>
	mat4 translate<mat4>(vec3);
    
    template <>
	mat4 frust<mat4>(float, float, float, float, float, float);
    
    template <>
	mat4 ortho<mat4>(float, float, float, float, float, float);
    
    template <>
	mat4 perps<mat4>(float, float, float, float);

};

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include <cmath>
#
#  include "./vec3.hpp"
#  include "./mat3.hpp"

inline mat4 operator + (mat4 a, mat4 b) {
    mat4 m;

    m.m00 = a.m00 + b.m00; m.m01 = a.m01 + b.m01; m.m02 = a.m02 + b.m02; m.m03 = a.m03 + b.m03;
    m.m10 = a.m10 + b.m10; m.m11 = a.m11 + b.m11; m.m12 = a.m12 + b.m12; m.m13 = a.m13 + b.m13;
    m.m20 = a.m20 + b.m20; m.m21 = a.m21 + b.m21; m.m22 = a.m22 + b.m22; m.m23 = a.m23 + b.m23;
    m.m30 = a.m30 + b.m30; m.m31 = a.m31 + b.m31; m.m32 = a.m32 + b.m32; m.m33 = a.m33 + b.m33;
    return (m);
}


inline mat4 operator - (mat4 a, mat4 b) {
    mat4 m;

    m.m00 = a.m00 - b.m00; m.m01 = a.m01 - b.m01; m.m02 = a.m02 - b.m02; m.m03 = a.m03 - b.m03;
    m.m10 = a.m10 - b.m10; m.m11 = a.m11 - b.m11; m.m12 = a.m12 - b.m12; m.m13 = a.m13 - b.m13;
    m.m20 = a.m20 - b.m20; m.m21 = a.m21 - b.m21; m.m22 = a.m22 - b.m22; m.m23 = a.m23 - b.m23;
    m.m30 = a.m30 - b.m30; m.m31 = a.m31 - b.m31; m.m32 = a.m32 - b.m32; m.m33 = a.m33 - b.m33;
    return (m);
}


inline mat4 operator * (mat4 a, mat4 b) {
    mat4 m;

    m.m00 = a.m00 * b.m00 + a.m10 * b.m01 + a.m20 * b.m02 + a.m30 * b.m03;
    m.m01 = a.m01 * b.m00 + a.m11 * b.m01 + a.m21 * b.m02 + a.m31 * b.m03;
    m.m02 = a.m02 * b.m00 + a.m12 * b.m01 + a.m22 * b.m02 + a.m32 * b.m03;
    m.m03 = a.m03 * b.m00 + a.m13 * b.m01 + a.m23 * b.m02 + a.m33 * b.m03;

    m.m10 = a.m00 * b.m10 + a.m10 * b.m11 + a.m20 * b.m12 + a.m30 * b.m13;
    m.m11 = a.m01 * b.m10 + a.m11 * b.m11 + a.m21 * b.m12 + a.m31 * b.m13;
    m.m12 = a.m02 * b.m10 + a.m12 * b.m11 + a.m22 * b.m12 + a.m32 * b.m13;
    m.m13 = a.m03 * b.m10 + a.m13 * b.m11 + a.m23 * b.m12 + a.m33 * b.m13;

    m.m20 = a.m00 * b.m20 + a.m10 * b.m21 + a.m20 * b.m22 + a.m30 * b.m23;
    m.m21 = a.m01 * b.m20 + a.m11 * b.m21 + a.m21 * b.m22 + a.m31 * b.m23;
    m.m22 = a.m02 * b.m20 + a.m12 * b.m21 + a.m22 * b.m22 + a.m32 * b.m23;
    m.m23 = a.m03 * b.m20 + a.m13 * b.m21 + a.m23 * b.m22 + a.m33 * b.m23;

    m.m30 = a.m00 * b.m30 + a.m10 * b.m31 + a.m20 * b.m32 + a.m30 * b.m33;
    m.m31 = a.m01 * b.m30 + a.m11 * b.m31 + a.m21 * b.m32 + a.m31 * b.m33;
    m.m32 = a.m02 * b.m30 + a.m12 * b.m31 + a.m22 * b.m32 + a.m32 * b.m33;
    m.m33 = a.m03 * b.m30 + a.m13 * b.m31 + a.m23 * b.m32 + a.m33 * b.m33;
    return (m);
}


inline mat4 operator * (mat4 a, float f) {
    mat4 m;

    m.m00 = a.m00 * f; m.m01 = a.m01 * f; m.m02 = a.m02 * f; m.m03 = a.m03 * f;
    m.m10 = a.m10 * f; m.m11 = a.m11 * f; m.m12 = a.m12 * f; m.m13 = a.m13 * f;
    m.m20 = a.m20 * f; m.m21 = a.m21 * f; m.m22 = a.m22 * f; m.m23 = a.m23 * f;
    m.m30 = a.m30 * f; m.m31 = a.m31 * f; m.m32 = a.m32 * f; m.m33 = a.m33 * f;
    return (m);
}


inline vec4 operator * (mat4 a, vec4 b) {
    vec4 v;

    v.x = a.m00 * b.x + a.m10 * b.y + a.m20 * b.z + a.m30 * b.w;
    v.y = a.m01 * b.x + a.m11 * b.y + a.m21 * b.z + a.m31 * b.w;
    v.z = a.m02 * b.x + a.m12 * b.y + a.m22 * b.z + a.m32 * b.w;
    v.w = a.m03 * b.x + a.m13 * b.y + a.m23 * b.z + a.m33 * b.w;
    return (v);
}


inline bool operator == (mat4 a, mat4 b) {
    return (fabsf(a.m00 - b.m00) < 1e-6f && fabsf(a.m01 - b.m01) < 1e-6f && fabsf(a.m02 - b.m02) < 1e-6f && fabsf(a.m12 - b.m12) < 1e-6f &&
            fabsf(a.m10 - b.m10) < 1e-6f && fabsf(a.m11 - b.m11) < 1e-6f && fabsf(a.m12 - b.m12) < 1e-6f && fabsf(a.m12 - b.m12) < 1e-6f &&
            fabsf(a.m20 - b.m20) < 1e-6f && fabsf(a.m21 - b.m21) < 1e-6f && fabsf(a.m22 - b.m22) < 1e-6f && fabsf(a.m22 - b.m22) < 1e-6f &&
            fabsf(a.m30 - b.m30) < 1e-6f && fabsf(a.m31 - b.m31) < 1e-6f && fabsf(a.m32 - b.m32) < 1e-6f && fabsf(a.m32 - b.m32) < 1e-6f);
}


inline bool operator != (mat4 a, mat4 b) {
    return (!(a == b));
}


inline mat4 &operator += (mat4 &a, mat4 b) {
    a = a + b;
    return (a);
}


inline mat4 &operator -= (mat4 &a, mat4 b) {
    a = a - b;
    return (a);
}


inline mat4 &operator *= (mat4 &a, mat4 b) {
    a = a * b;
    return (a);
}

namespace alg {

    template <>
	mat4 init<mat4>(float s) {
        mat4 m;

        m.m00 = 1.0f * s; m.m01 = 0.0f;     m.m02 = 0.0f;     m.m03 = 0.0f;
        m.m10 = 0.0f;     m.m11 = 1.0f * s; m.m12 = 0.0f;     m.m13 = 0.0f;
        m.m20 = 0.0f;     m.m21 = 0.0f;     m.m22 = 1.0f * s; m.m23 = 0.0f;
        m.m30 = 0.0f;     m.m31 = 0.0f;     m.m32 = 0.0f;     m.m33 = 1.0f * s;
        return (m);
    }
    
   
    template <>
	mat4 neg<mat4>(mat4 a) {
        a.m00 = -a.m00; a.m01 = -a.m01; a.m02 = -a.m02; a.m03 = -a.m03;
        a.m10 = -a.m10; a.m11 = -a.m11; a.m12 = -a.m12; a.m13 = -a.m13;
        a.m20 = -a.m20; a.m21 = -a.m21; a.m22 = -a.m22; a.m23 = -a.m23;
        a.m30 = -a.m30; a.m31 = -a.m31; a.m32 = -a.m32; a.m33 = -a.m33;
        return (a);
	}
   

    template <>
	mat4 transpose<mat4>(mat4 a) {
        mat4 m;

        m.m00 = a.m00; m.m01 = a.m10; m.m02 = a.m20; m.m03 = a.m30;
        m.m10 = a.m01; m.m11 = a.m11; m.m12 = a.m21; m.m13 = a.m31;
        m.m20 = a.m02; m.m21 = a.m12; m.m22 = a.m22; m.m23 = a.m32;
        m.m30 = a.m03; m.m31 = a.m13; m.m32 = a.m23; m.m33 = a.m33;
        return (m);
	}
   

    template <>
	mat4 inv<mat4>(mat4 a) {
        float det = alg::det<mat4>(a);
        mat4  m;

        if (det == 0.0f)
            return (alg::init<mat4>(0.0));

        det = 1.0f / det;

        m.m00 =  det * (a.m11 * (a.m22 * a.m33 - a.m23 * a.m32) - a.m12 * (a.m21 * a.m33 - a.m23 * a.m31) + a.m13 * (a.m21 * a.m32 - a.m22 * a.m31));
        m.m01 = -det * (a.m01 * (a.m22 * a.m33 - a.m23 * a.m32) - a.m02 * (a.m21 * a.m33 - a.m23 * a.m31) + a.m03 * (a.m21 * a.m32 - a.m22 * a.m31));
        m.m02 =  det * (a.m01 * (a.m12 * a.m33 - a.m13 * a.m32) - a.m02 * (a.m11 * a.m33 - a.m13 * a.m31) + a.m03 * (a.m11 * a.m32 - a.m12 * a.m31));
        m.m03 = -det * (a.m01 * (a.m12 * a.m23 - a.m13 * a.m22) - a.m02 * (a.m11 * a.m23 - a.m13 * a.m21) + a.m03 * (a.m11 * a.m22 - a.m12 * a.m21));

        m.m10 = -det * (a.m10 * (a.m22 * a.m33 - a.m23 * a.m32) - a.m12 * (a.m20 * a.m33 - a.m23 * a.m30) + a.m13 * (a.m20 * a.m32 - a.m22 * a.m30));
        m.m11 =  det * (a.m00 * (a.m22 * a.m33 - a.m23 * a.m32) - a.m02 * (a.m20 * a.m33 - a.m23 * a.m30) + a.m03 * (a.m20 * a.m32 - a.m22 * a.m30));
        m.m12 = -det * (a.m00 * (a.m12 * a.m33 - a.m13 * a.m32) - a.m02 * (a.m10 * a.m33 - a.m13 * a.m30) + a.m03 * (a.m10 * a.m32 - a.m12 * a.m30));
        m.m13 =  det * (a.m00 * (a.m12 * a.m23 - a.m13 * a.m22) - a.m02 * (a.m10 * a.m23 - a.m13 * a.m20) + a.m03 * (a.m10 * a.m22 - a.m12 * a.m20));

        m.m20 =  det * (a.m10 * (a.m21 * a.m33 - a.m23 * a.m31) - a.m11 * (a.m20 * a.m33 - a.m23 * a.m30) + a.m13 * (a.m20 * a.m31 - a.m21 * a.m30));
        m.m21 = -det * (a.m00 * (a.m21 * a.m33 - a.m23 * a.m31) - a.m01 * (a.m20 * a.m33 - a.m23 * a.m30) + a.m03 * (a.m20 * a.m31 - a.m21 * a.m30));
        m.m22 =  det * (a.m00 * (a.m11 * a.m33 - a.m13 * a.m31) - a.m01 * (a.m10 * a.m33 - a.m13 * a.m30) + a.m03 * (a.m10 * a.m31 - a.m11 * a.m30));
        m.m23 = -det * (a.m00 * (a.m11 * a.m23 - a.m13 * a.m21) - a.m01 * (a.m10 * a.m23 - a.m13 * a.m20) + a.m03 * (a.m10 * a.m21 - a.m11 * a.m20));

        m.m30 = -det * (a.m10 * (a.m21 * a.m32 - a.m22 * a.m31) - a.m11 * (a.m20 * a.m32 - a.m22 * a.m30) + a.m12 * (a.m20 * a.m31 - a.m21 * a.m30));
        m.m31 =  det * (a.m00 * (a.m21 * a.m32 - a.m22 * a.m31) - a.m01 * (a.m20 * a.m32 - a.m22 * a.m30) + a.m02 * (a.m20 * a.m31 - a.m21 * a.m30));
        m.m32 = -det * (a.m00 * (a.m11 * a.m32 - a.m12 * a.m31) - a.m01 * (a.m10 * a.m32 - a.m12 * a.m30) + a.m02 * (a.m10 * a.m31 - a.m11 * a.m30));
        m.m33 =  det * (a.m00 * (a.m11 * a.m22 - a.m12 * a.m21) - a.m01 * (a.m10 * a.m22 - a.m12 * a.m20) + a.m02 * (a.m10 * a.m21 - a.m11 * a.m20));
        return (m);
	}
   

    template <>
	float det<mat4>(mat4 m) {
        float result = 0.0f;
        mat3  sub;

        sub.m00 = m.m11; sub.m01 = m.m12; sub.m02 = m.m13;
        sub.m10 = m.m21; sub.m11 = m.m22; sub.m12 = m.m23;
        sub.m20 = m.m31; sub.m21 = m.m32; sub.m22 = m.m33;
        result += m.m00 * alg::det<mat3>(sub);

        sub.m00 = m.m10; sub.m01 = m.m12; sub.m02 = m.m13;
        sub.m10 = m.m20; sub.m11 = m.m22; sub.m12 = m.m23;
        sub.m20 = m.m30; sub.m21 = m.m32; sub.m22 = m.m33;
        result -= m.m01 * alg::det<mat3>(sub);

        sub.m00 = m.m10; sub.m01 = m.m11; sub.m02 = m.m13;
        sub.m10 = m.m20; sub.m11 = m.m21; sub.m12 = m.m23;
        sub.m20 = m.m30; sub.m21 = m.m31; sub.m22 = m.m33;
        result += m.m02 * alg::det<mat3>(sub);

        sub.m00 = m.m10; sub.m01 = m.m11; sub.m02 = m.m12;
        sub.m10 = m.m20; sub.m11 = m.m21; sub.m12 = m.m22;
        sub.m20 = m.m30; sub.m21 = m.m31; sub.m22 = m.m32;
        result -= m.m03 * alg::det<mat3>(sub);

        return (result);
	}
   

    template <>
	float trace<mat4>(mat4 m) {
        return (m.m00 + m.m11 + m.m22 + m.m33);
	}


    template <>
	mat4 rotatex<mat4>(float angle) {
        float c   = cosf(angle);
        float s   = sinf(angle);
        mat4  m;

        m.m11 =  c;
        m.m21 =  s;
        m.m12 = -s;
        m.m22 =  c;
        return (m);
	}


    template <>
	mat4 rotatey<mat4>(float angle) {
        float c   = cosf(angle);
        float s   = sinf(angle);
        mat4  m;

        m.m00 =  c;
        m.m20 = -s;
        m.m02 =  s;
        m.m22 =  c;
        return (m);
	}


    template <>
	mat4 rotatez<mat4>(float angle) {
        float c   = cosf(angle);
        float s   = sinf(angle);
        mat4  m;

        m.m00 =  c;
        m.m10 =  s;
        m.m01 = -s;
        m.m11 =  c;
        return (m);
	}


    template <>
	mat4 rotate<mat4>(vec3 axis, float angle) {
        float c   = cosf(angle);
        float s   = sinf(angle);
        float t   = 1.0f - c;
        vec3  n   = alg::norm<vec3>(axis);
        mat4  m   = alg::init<mat4>(1.0);

        m.m00 = t * n.x * n.x + c;
        m.m01 = t * n.y * n.x + s * n.z;
        m.m02 = t * n.z * n.x - s * n.y;

        m.m10 = t * n.x * n.y - s * n.z;
        m.m11 = t * n.y * n.y + c;
        m.m12 = t * n.z * n.y + s * n.x;

        m.m20 = t * n.x * n.z + s * n.y;
        m.m21 = t * n.y * n.z - s * n.x;
        m.m22 = t * n.z * n.z + c;
        return (m);
	}


    template <>
	mat4 rotateat<mat4>(vec3 pivot, vec3 axis, float angle) {
        mat4 m = alg::init<mat4>(1.0);

        m  = alg::translate<mat4>(pivot);           /* move to pivot */
        m *= alg::rotate<mat4>(axis, angle);        /* rotate by angle with axis */
        m *= alg::translate<mat4>(pivot * -1.0);    /* move back from pivot */
        return (m);
    }


    template <>
	mat4 lookat<mat4>(vec3 eye, vec3 center, vec3 up) {
        vec3 f = alg::norm<vec3>(center - eye);
        vec3 s = alg::norm<vec3>(alg::cross<vec3>(f, up));
        vec3 u = alg::cross<vec3>(s, f);
        mat4 m = alg::init<mat4>(1.0);

        m.m00 =  s.x; m.m10 =  s.y; m.m20 =  s.z;
        m.m01 =  u.x; m.m11 =  u.y; m.m21 =  u.z;
        m.m02 = -f.x; m.m12 = -f.y; m.m22 = -f.z;
        m.m03 = -alg::dot<vec3>(s, eye);
        m.m13 = -alg::dot<vec3>(u, eye);
        m.m23 =  alg::dot<vec3>(f, eye);
        return (m);
    }
    

    template <>
	mat4 scale<mat4>(vec4 s) {
        mat4 m;

        m.m00 = s.x;  m.m01 = 0.0f; m.m02 = 0.0f; m.m03 = 0.0f;
        m.m10 = 0.0f; m.m11 = s.y;  m.m12 = 0.0f; m.m13 = 0.0f;
        m.m20 = 0.0f; m.m21 = 0.0f; m.m22 = s.z;  m.m23 = 0.0f;
        m.m30 = 0.0f; m.m31 = 0.0f; m.m32 = 0.0f; m.m33 = 1.0f;
        return (m);
	}
   

    template <>
	mat4 translate<mat4>(vec3 v) {
        mat4 m;

        m.m00 = 1.0f; m.m01 = 0.0f; m.m02 = 0.0f; m.m03 = 0.0f;
        m.m10 = 0.0f; m.m11 = 1.0f; m.m12 = 0.0f; m.m13 = 0.0f;
        m.m20 = 0.0f; m.m21 = 0.0f; m.m22 = 1.0f; m.m23 = 0.0f;
        m.m30 = v.x;  m.m31 = v.y;  m.m32 = v.z;  m.m33 = 1.0f;
        return (m);
    }
   

    template <>
	mat4 frust<mat4>(float left, float right, float down, float top, float near, float far) {
        mat4 m = alg::init<mat4>(1.0);

        m.m00 =  (near * 2.0f) / (right - left);
        m.m11 =  (near * 2.0f) / (top   - down);
        m.m20 =  (right + left) / (right - left);
        m.m21 =  (top   + down) / (top   - down);
        m.m22 = -(far   + near) / (far   - near);
        m.m23 = -1.0f;
        m.m32 = -(2.0f * far * near) / (far - near);
        return (m);
    }
   

    template <>
	mat4 ortho<mat4>(float left, float right, float down, float top, float near, float far) {
        mat4 m = alg::init<mat4>(1.0);

        m.m00 =  2.0f / (right - left);
        m.m11 =  2.0f / (top   - down);
        m.m22 = -2.0f / (far   - near);
        m.m03 = -(left  + right) / (right - left);
        m.m13 = -(top   + down)  / (top   - down);
        m.m23 = -(far   + near)  / (far   - near);
        m.m33 =  1.0f;
        return (m);
    }
   

    template <>
	mat4 perps<mat4>(float fov, float aspect, float near, float far) {
        float t = near * tanf(fov * 0.5f);
        float r = t * aspect;

        return (alg::frust<mat4>(-r, r, -t, t, near, far));
    }

};

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat4_hpp_ */
