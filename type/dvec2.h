#if !defined (_type_dvec2_h_)
# define _type_dvec2_h_ 1

typedef union u_dvec2 dvec2;

union u_dvec2 {
    struct {
        double x;
        double y;
    };

    struct {
        double w;
        double h;
    };
};

#endif /* _type_dvec2_h_ */
