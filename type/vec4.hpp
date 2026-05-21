#if !defined (_type_vec4_hpp_)
# define _type_vec4_hpp_ 1

using vec4 = union u_vec4;

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

#endif /* _type_vec4_hpp_ */
