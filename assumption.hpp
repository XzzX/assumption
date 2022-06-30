///
/// Copyright (c) 2020 Sebastian Eibl
///
/// Permission is hereby granted, free of charge, to any person obtaining
/// a copy of this software and associated documentation files (the
/// "Software"), to deal in the Software without restriction, including
/// without limitation the rights to use, copy, modify, merge, publish,
/// distribute, sublicense, and/or sell copies of the Software, and to
/// permit persons to whom the Software is furnished to do so, subject to
/// the following conditions:
///
/// The above copyright notice and this permission notice shall be
/// included in all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
/// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
/// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
/// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
/// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
/// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
/// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
///

#pragma once

#include <fmt/format.h>

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace assumption
{

inline void publishAssertion(const std::string &msg)
{
    std::cout << msg << std::endl;
    exit(EXIT_FAILURE);
}

template <typename T, typename U, class... TYPES>
std::string generateAssertionMessage(const T &lhs,
                                     const U &rhs,
                                     const std::string &lhsExpression,
                                     const std::string &rhsExpression,
                                     const std::string &opString,
                                     const std::string &filename,
                                     const int64_t lineno,
                                     const std::string & /*function*/,
                                     const std::string &msg,
                                     TYPES... args)
{
    std::stringstream ss;
    int length = static_cast<int>(std::max(lhsExpression.length(), rhsExpression.length()));
    ss << "======================================================================"
          "==\n"
       << "ASSUMPTION FAILED! (" << filename << ":" << lineno << ")\n\n"
       << "Expression: " << lhsExpression << opString << rhsExpression << "\n"
       << "Values:     " << std::setw(length) << std::setfill(' ') << lhsExpression << " = " << lhs
       << "\n"
       << "            " << std::setw(length) << std::setfill(' ') << rhsExpression << " = " << rhs
       << "\n"
       << "Msg:\n"
       << fmt::format(msg, args...);
    return ss.str();
}

template <typename FLOAT>
bool isFloatEqual(const FLOAT &lhs, const FLOAT &rhs)
{
    return std::abs(lhs - rhs) < FLOAT(1e-10);
}

template <typename T, typename U, class... TYPES>
void assert_equal(const T &lhs,
                  const U &rhs,
                  const std::string &lhsExpression,
                  const std::string &rhsExpression,
                  const std::string &filename,
                  const int64_t lineno,
                  const std::string &function,
                  const std::string &msg,
                  TYPES... args)
{
    if (!(lhs == rhs))
    {
        publishAssertion(assumption::generateAssertionMessage(lhs,
                                                              rhs,
                                                              lhsExpression,
                                                              rhsExpression,
                                                              " == ",
                                                              filename,
                                                              lineno,
                                                              function,
                                                              msg,
                                                              args...));
    }
}

template <typename T, typename U, class... TYPES>
void assert_not_equal(const T &lhs,
                      const U &rhs,
                      const std::string &lhsExpression,
                      const std::string &rhsExpression,
                      const std::string &filename,
                      const int64_t lineno,
                      const std::string &function,
                      const std::string &msg,
                      TYPES... args)
{
    if (!(lhs != rhs))
    {
        publishAssertion(assumption::generateAssertionMessage(lhs,
                                                              rhs,
                                                              lhsExpression,
                                                              rhsExpression,
                                                              " != ",
                                                              filename,
                                                              lineno,
                                                              function,
                                                              msg,
                                                              args...));
    }
}

template <typename T, typename U, class... TYPES>
void assert_less(const T &lhs,
                 const U &rhs,
                 const std::string &lhsExpression,
                 const std::string &rhsExpression,
                 const std::string &filename,
                 const int64_t lineno,
                 const std::string &function,
                 const std::string &msg,
                 TYPES... args)
{
    if (!(lhs < rhs))
    {
        publishAssertion(assumption::generateAssertionMessage(lhs,
                                                              rhs,
                                                              lhsExpression,
                                                              rhsExpression,
                                                              " < ",
                                                              filename,
                                                              lineno,
                                                              function,
                                                              msg,
                                                              args...));
    }
}

template <typename T, typename U, class... TYPES>
void assert_greater(const T &lhs,
                    const U &rhs,
                    const std::string &lhsExpression,
                    const std::string &rhsExpression,
                    const std::string &filename,
                    const int64_t lineno,
                    const std::string &function,
                    const std::string &msg,
                    TYPES... args)
{
    if (!(lhs > rhs))
    {
        publishAssertion(assumption::generateAssertionMessage(lhs,
                                                              rhs,
                                                              lhsExpression,
                                                              rhsExpression,
                                                              " > ",
                                                              filename,
                                                              lineno,
                                                              function,
                                                              msg,
                                                              args...));
    }
}

template <typename T, typename U, class... TYPES>
void assert_less_equal(const T &lhs,
                       const U &rhs,
                       const std::string &lhsExpression,
                       const std::string &rhsExpression,
                       const std::string &filename,
                       const int64_t lineno,
                       const std::string &function,
                       const std::string &msg,
                       TYPES... args)
{
    if (!(lhs <= rhs))
    {
        publishAssertion(assumption::generateAssertionMessage(lhs,
                                                              rhs,
                                                              lhsExpression,
                                                              rhsExpression,
                                                              " <= ",
                                                              filename,
                                                              lineno,
                                                              function,
                                                              msg,
                                                              args...));
    }
}

template <typename T, typename U, class... TYPES>
void assert_greater_equal(const T &lhs,
                          const U &rhs,
                          const std::string &lhsExpression,
                          const std::string &rhsExpression,
                          const std::string &filename,
                          const int64_t lineno,
                          const std::string &function,
                          const std::string &msg,
                          TYPES... args)
{
    if (!(lhs >= rhs))
    {
        publishAssertion(assumption::generateAssertionMessage(lhs,
                                                              rhs,
                                                              lhsExpression,
                                                              rhsExpression,
                                                              " >= ",
                                                              filename,
                                                              lineno,
                                                              function,
                                                              msg,
                                                              args...));
    }
}

#define CHECK(X, ...)    \
    assumption::assert_equal( \
        (X), true, #X, "true", __FILE__, __LINE__, __func__, __VA_ARGS__);
#define CHECK_EQUAL(X, Y, ...) \
    assumption::assert_equal((X), (Y), #X, #Y, __FILE__, __LINE__, __func__, __VA_ARGS__);
#define CHECK_NOT_EQUAL(X, Y, ...) \
    assumption::assert_not_equal(       \
        (X), (Y), #X, #Y, __FILE__, __LINE__, __func__, __VA_ARGS__);
#define CHECK_GREATER(X, Y, ...) \
    assumption::assert_greater((X), (Y), #X, #Y, __FILE__, __LINE__, __func__, __VA_ARGS__);
#define CHECK_LESS(X, Y, ...) \
    assumption::assert_less((X), (Y), #X, #Y, __FILE__, __LINE__, __func__, __VA_ARGS__);
#define CHECK_GREATER_EQUAL(X, Y, ...) \
    assumption::assert_greater_equal(       \
        (X), (Y), #X, #Y, __FILE__, __LINE__, __func__, __VA_ARGS__);
#define CHECK_LESS_EQUAL(X, Y, ...) \
    assumption::assert_less_equal(       \
        (X), (Y), #X, #Y, __FILE__, __LINE__, __func__, __VA_ARGS__);

#ifdef NDEBUG

#define ASSERT(X, ...) \
    assumption::assert_equal((X), true, #X, "true", __FILE__, __LINE__, __func__, __VA_ARGS__);
#define ASSERT_EQUAL(X, Y, ...) \
    assumption::assert_equal((X), (Y), #X, #Y, __FILE__, __LINE__, __func__, __VA_ARGS__);
#define ASSERT_NOT_EQUAL(X, Y, ...) \
    assumption::assert_not_equal(        \
        (X), (Y), #X, #Y, __FILE__, __LINE__, __func__, __VA_ARGS__);
#define ASSERT_GREATER(X, Y, ...) \
    assumption::assert_greater((X), (Y), #X, #Y, __FILE__, __LINE__, __func__, __VA_ARGS__);
#define ASSERT_LESS(X, Y, ...) \
    assumption::assert_less((X), (Y), #X, #Y, __FILE__, __LINE__, __func__, __VA_ARGS__);
#define ASSERT_GREATER_EQUAL(X, Y, ...) \
    assumption::assert_greater_equal(        \
        (X), (Y), #X, #Y, __FILE__, __LINE__, __func__, __VA_ARGS__);
#define ASSERT_LESS_EQUAL(X, Y, ...) \
    assumption::assert_less_equal(        \
        (X), (Y), #X, #Y, __FILE__, __LINE__, __func__, __VA_ARGS__);

#else

#define ASSERT(X, MSG, ...)
#define ASSERT_EQUAL(X, Y, MSG, ...)
#define ASSERT_NOT_EQUAL(X, Y, MSG, ...)
#define ASSERT_GREATER(X, Y, MSG, ...)
#define ASSERT_LESS(X, Y, MSG, ...)
#define ASSERT_GREATER_EQUAL(X, Y, MSG, ...)
#define ASSERT_LESS_EQUAL(X, Y, MSG, ...)

#endif

}  // namespace assumption
