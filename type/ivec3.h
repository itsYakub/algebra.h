#if !defined (_type_vec3_h_)
# define _type_vec3_h_ 1

typedef union u_vec3 vec3;

union u_vec3 {
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

#endif /* _type_vec3_h_ */
