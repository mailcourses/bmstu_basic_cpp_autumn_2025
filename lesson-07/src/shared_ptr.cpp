#include <iostream>

namespace my
{

class shared_ptr
{
public:
    using value_type = int32_t;
private:
    struct object_wrapper
    {
        value_type* data = nullptr;
        size_t count = 0;
    };
public:

    shared_ptr() = default;
    shared_ptr(value_type *ptr) : object_(new object_wrapper)
    {
        object_->data = ptr;
        object_->count += 1;
    }

    shared_ptr(const shared_ptr& rhs)
    {
        object_ = rhs.object_;
        if (object_)
            object_->count += 1;
    }

    shared_ptr(shared_ptr&& rhs)
    {
        object_ = rhs.object_;
        rhs.object_ = nullptr;
    }

    shared_ptr& operator=(const shared_ptr& rhs)
    {
        if (this != &rhs)
        {
            destroy();
            object_ = rhs.object_;
            if (object_)
                object_->count += 1;
        }

        return *this;
    }

    shared_ptr& operator=(shared_ptr&& rhs)
    {
        if (this != &rhs)
        {
            destroy();
            object_ = rhs.object_;
            rhs.object_ = nullptr;
        }
        return *this;
    }

    value_type get() { return *object_->data; }

    void reset(value_type* ptr)
    {
        destroy();
        object_ = new object_wrapper;
        object_->data = ptr;
        object_->count = 1;
    }

    ~shared_ptr()
    {
        std::cout << "~shared_ptr()" << std::endl;
        destroy();
    }
private:
    void destroy()
    {
        if (object_ != nullptr && object_->count != 0 && --object_->count == 0)
        {
            std::cout << "~shared_ptr() freed" << std::endl;
            delete object_->data;
            delete object_;
            object_ = nullptr;
        }
    }
private:
    object_wrapper* object_ = nullptr;
};


} // namespace my

int main()
{
    my::shared_ptr::value_type* num = new my::shared_ptr::value_type{100500};
    my::shared_ptr sp1{num};
    sp1 = sp1;
    my::shared_ptr sp2{sp1};
    sp2 = sp1;
    std::cout << sp2.get() << std::endl;
    my::shared_ptr sp3;
    sp1 = sp3;
    sp3.reset(new my::shared_ptr::value_type{1234});
    std::cout << sp3.get() << std::endl;

    my::shared_ptr sp4{std::move(sp3)};
    sp2 = std::move(sp4);
    sp2 = std::move(sp2);
}
