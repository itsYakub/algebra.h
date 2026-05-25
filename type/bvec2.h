#if !defined (_type_bvec2_h_)
# define _type_bvec2_h_ 1
#
# include <stdbool.h>

typedef union u_bvec2 bvec2;

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

#endif /* _type_bvec2_h_ */
