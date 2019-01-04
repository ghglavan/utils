#include "owned_ptr.h"
#include <assert.h>

class DummyClass
{
    int a, b;

  public:
    DummyClass(int a, int b) : a(a), b(b) {}
};

int main()
{
    auto p = utils::make_owned<DummyClass>(2, 3);
    assert(p.owns());

    // test move construction
    auto q = std::move(p);
    assert(q.owns());
    assert(!p.owns());

    // test copy construction
    p = q;
    assert(q.owns());
    assert(!p.owns());
}