class DynamicArray {
    std::unique_ptr<int[]> array_;
    int length_;
    int capacity_;

public:

    DynamicArray(int capacity) 
        : capacity_ { capacity } 
        , length_ { 0 }
        , array_ { std::make_unique<int[]>(capacity) }
    {  }

    int get(int i)
    {
        return array_[i];
    }

    void set(int i, int n)
    {
        array_[i] = n;
    }

    void pushback(int n)
    {
        if (length_ == capacity_)
        {
            resize();
        }

        array_[length_] = n;
        ++length_;
    }

    int popback()
    {
        if (length_ > 0)
        {
            --length_;
        }

        return array_[length_];
    }

    void resize()
    {
        capacity_ *= 2;
        std::unique_ptr<int[]> new_array {
             std::make_unique<int[]>(capacity_)};

        for (auto i {0uz}; i < length_; ++i)
        {
            new_array[i] = array_[i];
        }

        array_.reset();
        array_ = std::move(new_array);
    }

    int getSize()
    {
        return length_;
    }

    int getCapacity() 
    {
        return capacity_;
    }
};
