#if !defined (_type_dvec3_h_)
# define _type_dvec3_h_ 1

typedef union u_dvec3 dvec3;

union u_dvec3 {
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

#endif /* _type_dvec3_h_ */
