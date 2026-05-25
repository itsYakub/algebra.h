#if !defined (_type_vec4_h_)
# define _type_vec4_h_ 1

typedef union u_vec4 vec4;

union u_vec4 {
    struct {
        double x;
        double y;
        double z;
        double w;
    };

    struct {
        double r;
        double g;
        double b;
        double a;
    };
};

#endif /* _type_vec4_h_ */
