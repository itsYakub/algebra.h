#if !defined (_type_vec2_hpp_)
# define _type_vec2_hpp_ 1

using vec2 = union u_vec2;

union u_vec2 {
    struct {
        bool x;
        bool y;
    };

    struct {
        bool w;
        bool h;
    };
};

#endif /* _type_vec2_hpp_ */
