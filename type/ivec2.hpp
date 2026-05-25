#if !defined (_type_ivec2_hpp_)
# define _type_ivec2_hpp_ 1

using ivec2 = union u_ivec2;

union u_ivec2 {
    struct {
        int x;
        int y;
    };

    struct {
        int w;
        int h;
    };
};

#endif /* _type_ivec2_hpp_ */
