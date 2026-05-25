#if !defined (_type_mat2_h_)
# define _type_mat2_h_ 1

typedef union u_mat2 mat2;

union u_mat2 {
    struct {
        double m00, m01,
               m10, m11;
    };
};

#endif /* _type_mat2_h_ */
