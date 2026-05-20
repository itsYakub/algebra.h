#if !defined (_types_h_)
# define _types_h_ 1
#
# if !defined (ALGEBRA_TYPE_VEC2)
#  define ALGEBRA_TYPE_VEC2 1

typedef union u_vec2 vec2;

union u_vec2 {
    struct {
        float x;
        float y;
    };

    struct {
        float w;
        float h;
    };
};

# endif /* ALGEBRA_TYPE_VEC2 */
#
# if !defined (ALGEBRA_TYPE_VEC3)
#  define ALGEBRA_TYPE_VEC3

typedef union u_vec3 vec3;

union u_vec3 {
    struct {
        float x;
        float y;
        float z;
    };

    struct {
        float r;
        float g;
        float b;
    };
};

# endif /* ALGEBRA_TYPE_VEC3 */
#
# if !defined (ALGEBRA_TYPE_VEC4)
#  define ALGEBRA_TYPE_VEC4

typedef union u_vec4 vec4;

union u_vec4 {
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
};

# endif /* ALGEBRA_TYPE_VEC4 */
#
# if !defined (ALGEBRA_TYPE_MAT2)
#  define ALGEBRA_TYPE_MAT2

typedef union u_mat2 mat2;

union u_mat2 {
    struct {
        float m00, m01,
              m10, m11;
    };
};

# endif /* ALGEBRA_TYPE_MAT2 */
#
# if !defined (ALGEBRA_TYPE_MAT3)
#  define ALGEBRA_TYPE_MAT3

typedef union u_mat3 mat3;

union u_mat3 {
    struct {
        float m00, m01, m02,
              m10, m11, m12,
              m20, m21, m22;
    };
};

# endif /* ALGEBRA_TYPE_MAT3 */
#
# if !defined (ALGEBRA_TYPE_MAT4)
#  define ALGEBRA_TYPE_MAT4

typedef union u_mat4 mat4;

union u_mat4 {
    struct {
        float m00, m01, m02, m03,
              m10, m11, m12, m13,
              m20, m21, m22, m23,
              m30, m31, m32, m33;
    };
};

# endif /* ALGEBRA_TYPE_MAT4 */
#endif /* _types_h_ */
