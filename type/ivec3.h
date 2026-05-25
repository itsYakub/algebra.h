#if !defined (_type_ivec3_h_)
# define _type_ivec3_h_ 1

typedef union u_ivec3 ivec3;

union u_ivec3 {
    struct {
        int x;
        int y;
        int z;
    };

    struct {
        int r;
        int g;
        int b;
    };
};

#endif /* _type_ivec3_h_ */
