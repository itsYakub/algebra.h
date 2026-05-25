#if !defined (_type_dvec2_hpp_)
# define _type_dvec2_hpp_ 1

using dvec2 = union u_dvec2;

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

#endif /* _type_dvec2_hpp_ */
