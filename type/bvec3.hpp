#if !defined (_type_bvec3_hpp_)
# define _type_bvec3_hpp_ 1

using bvec3 = union u_bvec3;

union u_bvec3 {
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

#endif /* _type_bvec3_hpp_ */
