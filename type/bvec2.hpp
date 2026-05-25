#if !defined (_type_bvec2_hpp_)
# define _type_bvec2_hpp_ 1

using bvec2 = union u_bvec2;

union u_bvec2 {
    struct {
        bool x;
        bool y;
    };

    struct {
        bool w;
        bool h;
    };
};

#endif /* _type_bvec2_hpp_ */
