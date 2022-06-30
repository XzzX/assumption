#include <assumption.hpp>

int main()
{
    ASSERT(false, "");
    ASSERT_EQUAL(4*5, 4*6, "simple {}", "maths");
}
