#if !defined (_type_vec3_h_)
# define _type_vec3_h_ 1

typedef union u_vec3 vec3;

union u_vec3 {
    struct {
        double x;
        double y;
        double z;
    };

    struct {
        double r;
        double g;
        double b;
    };
};

#endif /* _type_vec3_h_ */
