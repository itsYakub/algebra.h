#if !defined (_types_h_)
# define _types_h_ 1

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

# if defined (__cplusplus)

    /* Constructors */

    u_vec2(void);

    u_vec2(float);

    u_vec2(float, float);

    u_vec2(const u_vec2 &); 

    u_vec2 &operator = (const u_vec2 &);

# endif /* __cplusplus */

};


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

# if defined (__cplusplus)

    u_vec3(void);

    u_vec3(float);

    u_vec3(float, float, float);

    u_vec3(const u_vec3 &);

    u_vec3 &operator = (const u_vec3 &);

# endif /* __cplusplus */

};


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

# if defined (__cplusplus)

    u_vec4(void);

    u_vec4(float);

    u_vec4(float, float, float, float);

    u_vec4(const u_vec4 &);

    u_vec4 &operator = (const u_vec4 &);

# endif /* __cplusplus */

};


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

    u_mat3(float, float, float,
           float, float, float,
           float, float, float);

    u_mat3(const u_mat3 &);

    u_mat3 &operator = (const u_mat3 &);

# endif /* __cplusplus */

};


typedef union u_mat4 mat4;

union u_mat4 {
    struct {
        float m00, m01, m02, m03,
              m10, m11, m12, m13,
              m20, m21, m22, m23,
              m30, m31, m32, m33;
    };

# if defined (__cplusplus)

    u_mat4(void);

    u_mat4(float);

    u_mat4(float, float, float, float,
           float, float, float, float,
           float, float, float, float,
           float, float, float, float);

    u_mat4(const u_mat4 &);

    u_mat4 &operator = (const u_mat4 &);

# endif /* __cplusplus */

};

#endif /* _types_h_ */
