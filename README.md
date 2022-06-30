# Example
```
#include "assumption.h"

int main()
{
    ASSERT_EQUAL(4*5, 4*6, "simple {}", "maths");
}
```
Output:
```
ASSUMPTION FAILED! (example.cpp:5)

Expression: 4*5 == 4*6
Values:     4*5 = 20
            4*6 = 24
simple maths
```

