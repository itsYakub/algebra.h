#if !defined (_type_vec3_hpp_)
# define _type_vec3_hpp_ 1

using vec3 = union u_vec3;

union u_vec3 {
    struct {
        bool x;
        bool y;
        bool z;
    };

    struct {
        bool r;
        bool g;
        bool b;
    };
};

#endif /* _type_vec3_hpp_ */
