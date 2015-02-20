class GenericReader {
    Reader4k reader4k_;
    int buf_ptr_;
    char* internal_buf_;

    public:
    int Read(int n, char* buf) {
        int count = 0;
        int remain = n;
        int buf_ptr = 0;

        while (remain > 0) {
            if (buf_ptr_ == -1) {
                int bytes_read = reader4k.Read(internal_buf_);

                if (bytes_read == 0) // we have exhausted the buffer
                    break;

                buf_ptr_ = 0;
                if (bytes_read > remain) {       
                    memcpy(buf + buf_ptr, internal_buf_, remain);
                    count += remain;
                    buf_ptr_ += remain;
                    return count;
                } else {
                    remain -= bytes_read;
                    count += bytes_read;
                    buf_ptr_ = -1;
                    memcpy(buf + buf_ptr, internal_buf_, bytes_read);
                    buf_ptr += bytes_read;
                }
            } else { // we still have stuff in internal_buf_, read those first
                if (4096 - buf_ptr_ > remain) {
                    memcpy(buf + buf_ptr, internal_buf_ + buf_ptr_, remain);
                    buf_ptr_ += remain;
                    count += remain;
                    return count;
                } else {
                    remain -= (4096 - buf_ptr_);
                    count += (4096 - buf_ptr_);
                    memcpy(but + buf_ptr, internal_buf_ + buf_ptr_, 4096 - buf_ptr_);
                    buf_ptr += (4096 - buf_ptr_);
                    buf_ptr_ = -1;
                }       
            }         
        }

        return count;
    }  
};
