#if !defined (_type_vec2_hpp_)
# define _type_vec2_hpp_ 1

using vec2 = union u_vec2;

union u_vec2 {
    struct {
        int x;
        int y;
    };

    struct {
        int w;
        int h;
    };
};

#endif /* _type_vec2_hpp_ */
