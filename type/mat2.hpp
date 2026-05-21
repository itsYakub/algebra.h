#if !defined (_type_mat2_hpp_)
# define _type_mat2_hpp_ 1

using mat2 = union u_mat2;

union u_mat2 {
    struct {
        float m00, m01,
              m10, m11;
    };
};

#endif /* _type_mat2_hpp_ */
