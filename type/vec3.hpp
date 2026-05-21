#if !defined (_type_vec3_hpp_)
# define _type_vec3_hpp_ 1

typedef union u_vec3 vec3;

using vec3 = union u_vec3;

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

#endif /* _type_vec3_hpp_ */
