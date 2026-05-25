#if !defined (_type_bvec4_h_)
# define _type_bvec4_h_ 1
#
# include <stdbool.h>

typedef union u_bvec4 bvec4;

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

#endif /* _type_bvec4_h_ */
