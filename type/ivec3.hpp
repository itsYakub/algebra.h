#if !defined (_type_ivec3_hpp_)
# define _type_ivec3_hpp_ 1

using ivec3 = union u_ivec3;

union u_ivec3 {
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

#endif /* _type_ivec3_hpp_ */
