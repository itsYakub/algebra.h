#if !defined (_type_vec4_hpp_)
# define _type_vec4_hpp_ 1

using vec4 = union u_vec4;

union u_vec4 {
    struct {
        bool x;
        bool y;
        bool z;
        bool w;
    };

    struct {
        bool r;
        bool g;
        bool b;
        bool a;
    };
};

#endif /* _type_vec4_hpp_ */
