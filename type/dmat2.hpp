#if !defined (_type_dmat2_hpp_)
# define _type_dmat2_hpp_ 1

using dmat2 = union u_dmat2;

union u_dmat2 {
    struct {
        double m00, m01,
               m10, m11;
    };
};

#endif /* _type_dmat2_hpp_ */
