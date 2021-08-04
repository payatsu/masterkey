#ifndef TARGET_HPP_
#define TARGET_HPP_
#endif // TARGET_HPP_

#include <memory>

class target{
public:
    target(const char* filename, std::size_t offset = 0ul, std::size_t length = 0ul);
    target(int fd);
    ~target(){}

    int transfer_to(const target& dest)const;

    // deprecated.
    char* offset()const{return mmapped_data_.get() + preamble_;}
    std::size_t length()const{return pa_length_ - preamble_;}

private:
    std::shared_ptr<int> ptr_to_fd_;
    std::shared_ptr<char> mmapped_data_;
    std::size_t preamble_;
    std::size_t pa_length_;

    static void close(int*);

    const static long page_size_;
};

// vim: expandtab shiftwidth=0 tabstop=4 :
