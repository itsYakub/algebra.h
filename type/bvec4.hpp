#if !defined (_type_bvec4_hpp_)
# define _type_bvec4_hpp_ 1

using bvec4 = union u_bvec4;

union u_bvec4 {
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

#endif /* _type_bvec4_hpp_ */
