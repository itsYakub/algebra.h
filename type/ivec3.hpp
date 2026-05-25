#if !defined (_type_vec3_hpp_)
# define _type_vec3_hpp_ 1

using vec3 = union u_vec3;

union u_vec3 {
    struct {
        int x;
        int y;
        int z;
    };

    struct {
        int r;
        int g;
        int b;
    };
};

#endif /* _type_vec3_hpp_ */
