#include <memory>

namespace utils
{

template <typename T>
class OwnedPtr
{
  protected:
    std::unique_ptr<T> ptr;
    bool owned;

  public:
    OwnedPtr() : ptr(new T()), owned(true) {}
    OwnedPtr(T *ptr) : ptr(std::unique_ptr<T>(ptr)), owned(true) {}

    OwnedPtr(const OwnedPtr &oth) : ptr(oth.ptr.get()), owned(false) {}

    OwnedPtr(OwnedPtr &&oth) : ptr(oth.ptr.get()), owned(true)
    {
        oth.owned = false;
    }

    ~OwnedPtr()
    {
        if (!owned)
            ptr.release();
    }

    OwnedPtr &operator=(const OwnedPtr &oth)
    {
        ptr = std::unique_ptr<T>(oth.ptr.get());
        owned = false;
    }

    OwnedPtr &operator=(OwnedPtr &&oth)
    {
        ptr = std::unique_ptr<T>(oth.ptr.get());

        if (oth.owned)
        {
            owned = true;
            oth.owned = false;
        }
    }

    bool
    owns()
    {
        return owned;
    }
    T *get() { return ptr.get(); }

    // todo: implement operators to mimic unique_ptr interface
};

template <typename T, typename... Args>
OwnedPtr<T> make_owned(Args &&... args)
{
    return OwnedPtr<T>(new T(std::forward<Args>(args)...));
}

} // namespace utils