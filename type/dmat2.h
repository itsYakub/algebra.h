#if !defined (_type_dmat2_h_)
# define _type_dmat2_h_ 1

typedef union u_dmat2 dmat2;

union u_dmat2 {
    struct {
        double m00, m01,
               m10, m11;
    };
};

#endif /* _type_dmat2_h_ */
