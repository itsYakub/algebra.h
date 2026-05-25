#if !defined (_type_bvec3_h_)
# define _type_bvec3_h_ 1
#
# include <stdbool.h>

typedef union u_bvec3 bvec3;

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

#endif /* _type_bvec3_h_ */
