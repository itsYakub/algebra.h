#if !defined (_type_vec4_hpp_)
# define _type_vec4_hpp_ 1

using vec4 = union u_vec4;

union u_vec4 {
    struct {
        int x;
        int y;
        int z;
        int w;
    };

    struct {
        int r;
        int g;
        int b;
        int a;
    };
};

#endif /* _type_vec4_hpp_ */
