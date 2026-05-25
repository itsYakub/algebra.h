#if !defined (_type_ivec4_h_)
# define _type_ivec4_h_ 1

typedef union u_ivec4 ivec4;

union u_ivec4 {
    struct {
        int x;
        int y;
        int z;
        int w;
    };

    struct {
        int r;
        int g;
        int b;
        int a;
    };
};

#endif /* _type_ivec4_h_ */
