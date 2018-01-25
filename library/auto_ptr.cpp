
//auto_ptr reference
/*
*   int b = 10;
*	int* a = &b;
*	auto_ptr_ref<int> d(a);
*/
template<class T>
struct auto_ptr_ref
{
    T *m_ptr;
    auto_ptr_ref(T* p) : m_ptr(p) {}
};

template<class T>
class auto_ptr
{
private:
    T *m_ptr;

public:
    typedef T elem_type;
    
public:
    explicit auto_ptr(T* p = 0) noexcept : m_ptr(p) {}

    auto_ptr(auto_ptr& a) noexcept : m_ptr(a.release()) {}

    template<class Tp>
    auto_ptr(auto_ptr<Tp>& a) noexcept : m_ptr(a.release()) {}

    ~auto_ptr() noexcept
    {
        delete m_ptr;
    }

    auto_ptr& operator=(auto_ptr& a) noexcept
    {
        if(&a != this)
        {
            delete m_ptr;
            m_ptr = a.release();
        }
        return *this;
    }

    template<class Tp>
    auto_ptr& operator=(auto_ptr<Tp>& a) noexcept
    {
        if(a.get() != this->get())
        {
            delete m_ptr;
            m_ptr = a.release();
        }
        return *this;
    }

    T& operator*() const noexcept
    {
        return *m_ptr;
    }

    T* operator->() const noexcept
    {
        return m_ptr;
    }

    T* get() const noexcept
    {
        return m_ptr;
    }

    void reset(T* p = 0) noexcept
    {
        if(p != m_ptr)
        {
            delete m_ptr;
            m_ptr = p;
        }
    }

    T* release() noexcept
    {
        T *tmp = m_ptr;
        m_ptr = 0;
        return tmp;
    }
};
