#include "CppUnitTest.h"
#include "../Report.h"
#include <limits>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace XMLToolsTests {
    TEST_CLASS(ConversionTests) {
    public:
        TEST_METHOD(Char2WcharTooLarge) {
            CComBSTR dest;
            size_t huge = static_cast<size_t>(std::numeric_limits<unsigned int>::max()) + 10;
            Report::char2wchar("abc", huge, dest);
            Assert::AreEqual(static_cast<UINT>(0), dest.Length());
        }

        TEST_METHOD(Char2WcharNullInput) {
            wchar_t* result = Report::char2wchar(nullptr);
            Assert::IsNull(result);
        }
    };
}
