#include <catch2/catch_test_macros.hpp>
#include <stipp.hpp> // IWYU pragma: associated

#include <cstddef>
#include <cstdint>
#include <limits>
#include <sstream>
#include <string>
#include <type_traits>

#if __has_include(<format>)
#include <format>
#endif

using namespace stipp::types;
using namespace stipp::literals;

TEST_CASE("literals", "[literals]") {
    REQUIRE(0_u8 == u8{0});
    REQUIRE(0_u16 == u16{0});
    REQUIRE(0_u32 == u32{0});
    REQUIRE(0_u64 == u64{0});
    REQUIRE(0_uz == usize{0});
    REQUIRE(0_i8 == i8{0});
    REQUIRE(0_i16 == i16{0});
    REQUIRE(0_i32 == i32{0});
    REQUIRE(0_i64 == i64{0});
    REQUIRE(0_iz == isize{0});

    REQUIRE(42_u8 == u8{42});
    REQUIRE(42_u16 == u16{42});
    REQUIRE(42_u32 == u32{42});
    REQUIRE(42_u64 == u64{42});
    REQUIRE(42_uz == usize{42});
    REQUIRE(42_i8 == i8{42});
    REQUIRE(42_i16 == i16{42});
    REQUIRE(42_i32 == i32{42});
    REQUIRE(42_i64 == i64{42});
    REQUIRE(42_iz == isize{42});

    REQUIRE(42_U8 == 42_u8);
    REQUIRE(42_U16 == 42_u16);
    REQUIRE(42_U32 == 42_u32);
    REQUIRE(42_U64 == 42_u64);
    REQUIRE(42_UZ == 42_uz);
    REQUIRE(42_I8 == 42_i8);
    REQUIRE(42_I16 == 42_i16);
    REQUIRE(42_I32 == 42_i32);
    REQUIRE(42_I64 == 42_i64);
    REQUIRE(42_IZ == 42_iz);
}

TEST_CASE("unary plus", "[ops]") {
    REQUIRE(+42_u8 == 42_u8);
    REQUIRE(+42_u16 == 42_u16);
    REQUIRE(+42_u32 == 42_u32);
    REQUIRE(+42_u64 == 42_u64);
    REQUIRE(+42_uz == 42_uz);
    REQUIRE(+42_i8 == 42_i8);
    REQUIRE(+42_i16 == 42_i16);
    REQUIRE(+42_i32 == 42_i32);
    REQUIRE(+42_i64 == 42_i64);
    REQUIRE(+42_iz == 42_iz);
}

TEST_CASE("unary minus", "[ops]") {
    REQUIRE(-42_u8 == u8{static_cast<std::uint8_t>(-std::uint8_t{42})});
    REQUIRE(-42_u16 == u16{static_cast<std::uint16_t>(-std::uint16_t{42})});
    REQUIRE(-42_u32 == u32{static_cast<std::uint32_t>(-std::uint32_t{42})});
    REQUIRE(-42_u64 == u64{static_cast<std::uint64_t>(-std::uint64_t{42})});
    REQUIRE(-42_uz == usize{static_cast<std::size_t>(-std::size_t{42})});
    REQUIRE(-42_i8 == i8{-42});
    REQUIRE(-42_i16 == i16{-42});
    REQUIRE(-42_i32 == i32{-42});
    REQUIRE(-42_i64 == i64{-42});
    REQUIRE(-42_iz == isize{-42});

    REQUIRE(-(-42_u8) == 42_u8);
    REQUIRE(-(-42_u16) == 42_u16);
    REQUIRE(-(-42_u32) == 42_u32);
    REQUIRE(-(-42_u64) == 42_u64);
    REQUIRE(-(-42_uz) == 42_uz);
    REQUIRE(-(-42_i8) == 42_i8);
    REQUIRE(-(-42_i16) == 42_i16);
    REQUIRE(-(-42_i32) == 42_i32);
    REQUIRE(-(-42_i64) == 42_i64);
    REQUIRE(-(-42_iz) == 42_iz);
}

TEST_CASE("invert", "[ops]") {
    REQUIRE(~42_u8 == u8{static_cast<std::uint8_t>(~std::uint8_t{42})});
    REQUIRE(~42_u16 == u16{static_cast<std::uint16_t>(~std::uint16_t{42})});
    REQUIRE(~42_u32 == u32{static_cast<std::uint32_t>(~std::uint32_t{42})});
    REQUIRE(~42_u64 == u64{static_cast<std::uint64_t>(~std::uint64_t{42})});
    REQUIRE(~42_uz == usize{static_cast<std::size_t>(~std::size_t{42})});
    REQUIRE(~42_i8 == i8{static_cast<std::int8_t>(~std::int8_t{42})});
    REQUIRE(~42_i16 == i16{static_cast<std::int16_t>(~std::int16_t{42})});
    REQUIRE(~42_i32 == i32{static_cast<std::int32_t>(~std::int32_t{42})});
    REQUIRE(~42_i64 == i64{static_cast<std::int64_t>(~std::int64_t{42})});
    REQUIRE(~42_iz == isize{static_cast<std::ptrdiff_t>(~std::ptrdiff_t{42})});

    REQUIRE(~(~42_u8) == 42_u8);
    REQUIRE(~(~42_u16) == 42_u16);
    REQUIRE(~(~42_u32) == 42_u32);
    REQUIRE(~(~42_u64) == 42_u64);
    REQUIRE(~(~42_uz) == 42_uz);
    REQUIRE(~(~42_i8) == 42_i8);
    REQUIRE(~(~42_i16) == 42_i16);
    REQUIRE(~(~42_i32) == 42_i32);
    REQUIRE(~(~42_i64) == 42_i64);
    REQUIRE(~(~42_iz) == 42_iz);
}

TEST_CASE("pre increment", "[ops]") {
    auto val_u8 = 42_u8;
    auto val_u16 = 42_u16;
    auto val_u32 = 42_u32;
    auto val_u64 = 42_u64;
    auto val_uz = 42_uz;
    auto val_i8 = 42_i8;
    auto val_i16 = 42_i16;
    auto val_i32 = 42_i32;
    auto val_i64 = 42_i64;
    auto val_iz = 42_iz;

    REQUIRE(++val_u8 == 43_u8);
    REQUIRE(++val_u16 == 43_u16);
    REQUIRE(++val_u32 == 43_u32);
    REQUIRE(++val_u64 == 43_u64);
    REQUIRE(++val_uz == 43_uz);
    REQUIRE(++val_i8 == 43_i8);
    REQUIRE(++val_i16 == 43_i16);
    REQUIRE(++val_i32 == 43_i32);
    REQUIRE(++val_i64 == 43_i64);
    REQUIRE(++val_iz == 43_iz);

    REQUIRE(val_u8 == 43_u8);
    REQUIRE(val_u16 == 43_u16);
    REQUIRE(val_u32 == 43_u32);
    REQUIRE(val_u64 == 43_u64);
    REQUIRE(val_uz == 43_uz);
    REQUIRE(val_i8 == 43_i8);
    REQUIRE(val_i16 == 43_i16);
    REQUIRE(val_i32 == 43_i32);
    REQUIRE(val_i64 == 43_i64);
    REQUIRE(val_iz == 43_iz);
}

TEST_CASE("post increment", "[ops]") {
    auto val_u8 = 42_u8;
    auto val_u16 = 42_u16;
    auto val_u32 = 42_u32;
    auto val_u64 = 42_u64;
    auto val_uz = 42_uz;
    auto val_i8 = 42_i8;
    auto val_i16 = 42_i16;
    auto val_i32 = 42_i32;
    auto val_i64 = 42_i64;
    auto val_iz = 42_iz;

    REQUIRE(val_u8++ == 42_u8);
    REQUIRE(val_u16++ == 42_u16);
    REQUIRE(val_u32++ == 42_u32);
    REQUIRE(val_u64++ == 42_u64);
    REQUIRE(val_uz++ == 42_uz);
    REQUIRE(val_i8++ == 42_i8);
    REQUIRE(val_i16++ == 42_i16);
    REQUIRE(val_i32++ == 42_i32);
    REQUIRE(val_i64++ == 42_i64);
    REQUIRE(val_iz++ == 42_iz);

    REQUIRE(val_u8 == 43_u8);
    REQUIRE(val_u16 == 43_u16);
    REQUIRE(val_u32 == 43_u32);
    REQUIRE(val_u64 == 43_u64);
    REQUIRE(val_uz == 43_uz);
    REQUIRE(val_i8 == 43_i8);
    REQUIRE(val_i16 == 43_i16);
    REQUIRE(val_i32 == 43_i32);
    REQUIRE(val_i64 == 43_i64);
    REQUIRE(val_iz == 43_iz);
}

TEST_CASE("pre decrement", "[ops]") {
    auto val_u8 = 42_u8;
    auto val_u16 = 42_u16;
    auto val_u32 = 42_u32;
    auto val_u64 = 42_u64;
    auto val_uz = 42_uz;
    auto val_i8 = 42_i8;
    auto val_i16 = 42_i16;
    auto val_i32 = 42_i32;
    auto val_i64 = 42_i64;
    auto val_iz = 42_iz;

    REQUIRE(--val_u8 == 41_u8);
    REQUIRE(--val_u16 == 41_u16);
    REQUIRE(--val_u32 == 41_u32);
    REQUIRE(--val_u64 == 41_u64);
    REQUIRE(--val_uz == 41_uz);
    REQUIRE(--val_i8 == 41_i8);
    REQUIRE(--val_i16 == 41_i16);
    REQUIRE(--val_i32 == 41_i32);
    REQUIRE(--val_i64 == 41_i64);
    REQUIRE(--val_iz == 41_iz);

    REQUIRE(val_u8 == 41_u8);
    REQUIRE(val_u16 == 41_u16);
    REQUIRE(val_u32 == 41_u32);
    REQUIRE(val_u64 == 41_u64);
    REQUIRE(val_uz == 41_uz);
    REQUIRE(val_i8 == 41_i8);
    REQUIRE(val_i16 == 41_i16);
    REQUIRE(val_i32 == 41_i32);
    REQUIRE(val_i64 == 41_i64);
    REQUIRE(val_iz == 41_iz);
}

TEST_CASE("post decrement", "[ops]") {
    auto val_u8 = 42_u8;
    auto val_u16 = 42_u16;
    auto val_u32 = 42_u32;
    auto val_u64 = 42_u64;
    auto val_uz = 42_uz;
    auto val_i8 = 42_i8;
    auto val_i16 = 42_i16;
    auto val_i32 = 42_i32;
    auto val_i64 = 42_i64;
    auto val_iz = 42_iz;

    REQUIRE(val_u8-- == 42_u8);
    REQUIRE(val_u16-- == 42_u16);
    REQUIRE(val_u32-- == 42_u32);
    REQUIRE(val_u64-- == 42_u64);
    REQUIRE(val_uz-- == 42_uz);
    REQUIRE(val_i8-- == 42_i8);
    REQUIRE(val_i16-- == 42_i16);
    REQUIRE(val_i32-- == 42_i32);
    REQUIRE(val_i64-- == 42_i64);
    REQUIRE(val_iz-- == 42_iz);

    REQUIRE(val_u8 == 41_u8);
    REQUIRE(val_u16 == 41_u16);
    REQUIRE(val_u32 == 41_u32);
    REQUIRE(val_u64 == 41_u64);
    REQUIRE(val_uz == 41_uz);
    REQUIRE(val_i8 == 41_i8);
    REQUIRE(val_i16 == 41_i16);
    REQUIRE(val_i32 == 41_i32);
    REQUIRE(val_i64 == 41_i64);
    REQUIRE(val_iz == 41_iz);
}

TEST_CASE("add assign", "[ops]") {
    auto val_u8 = 42_u8;
    auto val_u16 = 42_u16;
    auto val_u32 = 42_u32;
    auto val_u64 = 42_u64;
    auto val_uz = 42_uz;
    auto val_i8 = 42_i8;
    auto val_i16 = 42_i16;
    auto val_i32 = 42_i32;
    auto val_i64 = 42_i64;
    auto val_iz = 42_iz;

    REQUIRE((val_u8 += 10_u8) == 52_u8);
    REQUIRE((val_u16 += 10_u16) == 52_u16);
    REQUIRE((val_u32 += 10_u32) == 52_u32);
    REQUIRE((val_u64 += 10_u64) == 52_u64);
    REQUIRE((val_uz += 10_uz) == 52_uz);
    REQUIRE((val_i8 += 10_i8) == 52_i8);
    REQUIRE((val_i16 += 10_i16) == 52_i16);
    REQUIRE((val_i32 += 10_i32) == 52_i32);
    REQUIRE((val_i64 += 10_i64) == 52_i64);
    REQUIRE((val_iz += 10_iz) == 52_iz);

    REQUIRE(val_u8 == 52_u8);
    REQUIRE(val_u16 == 52_u16);
    REQUIRE(val_u32 == 52_u32);
    REQUIRE(val_u64 == 52_u64);
    REQUIRE(val_uz == 52_uz);
    REQUIRE(val_i8 == 52_i8);
    REQUIRE(val_i16 == 52_i16);
    REQUIRE(val_i32 == 52_i32);
    REQUIRE(val_i64 == 52_i64);
    REQUIRE(val_iz == 52_iz);
}

TEST_CASE("sub assign", "[ops]") {
    auto val_u8 = 42_u8;
    auto val_u16 = 42_u16;
    auto val_u32 = 42_u32;
    auto val_u64 = 42_u64;
    auto val_uz = 42_uz;
    auto val_i8 = 42_i8;
    auto val_i16 = 42_i16;
    auto val_i32 = 42_i32;
    auto val_i64 = 42_i64;
    auto val_iz = 42_iz;

    REQUIRE((val_u8 -= 10_u8) == 32_u8);
    REQUIRE((val_u16 -= 10_u16) == 32_u16);
    REQUIRE((val_u32 -= 10_u32) == 32_u32);
    REQUIRE((val_u64 -= 10_u64) == 32_u64);
    REQUIRE((val_uz -= 10_uz) == 32_uz);
    REQUIRE((val_i8 -= 10_i8) == 32_i8);
    REQUIRE((val_i16 -= 10_i16) == 32_i16);
    REQUIRE((val_i32 -= 10_i32) == 32_i32);
    REQUIRE((val_i64 -= 10_i64) == 32_i64);
    REQUIRE((val_iz -= 10_iz) == 32_iz);

    REQUIRE(val_u8 == 32_u8);
    REQUIRE(val_u16 == 32_u16);
    REQUIRE(val_u32 == 32_u32);
    REQUIRE(val_u64 == 32_u64);
    REQUIRE(val_uz == 32_uz);
    REQUIRE(val_i8 == 32_i8);
    REQUIRE(val_i16 == 32_i16);
    REQUIRE(val_i32 == 32_i32);
    REQUIRE(val_i64 == 32_i64);
    REQUIRE(val_iz == 32_iz);
}

TEST_CASE("mul assign", "[ops]") {
    auto val_u8 = 42_u8;
    auto val_u16 = 42_u16;
    auto val_u32 = 42_u32;
    auto val_u64 = 42_u64;
    auto val_uz = 42_uz;
    auto val_i8 = 42_i8;
    auto val_i16 = 42_i16;
    auto val_i32 = 42_i32;
    auto val_i64 = 42_i64;
    auto val_iz = 42_iz;

    REQUIRE((val_u8 *= 2_u8) == 84_u8);
    REQUIRE((val_u16 *= 2_u16) == 84_u16);
    REQUIRE((val_u32 *= 2_u32) == 84_u32);
    REQUIRE((val_u64 *= 2_u64) == 84_u64);
    REQUIRE((val_uz *= 2_uz) == 84_uz);
    REQUIRE((val_i8 *= 2_i8) == 84_i8);
    REQUIRE((val_i16 *= 2_i16) == 84_i16);
    REQUIRE((val_i32 *= 2_i32) == 84_i32);
    REQUIRE((val_i64 *= 2_i64) == 84_i64);
    REQUIRE((val_iz *= 2_iz) == 84_iz);

    REQUIRE(val_u8 == 84_u8);
    REQUIRE(val_u16 == 84_u16);
    REQUIRE(val_u32 == 84_u32);
    REQUIRE(val_u64 == 84_u64);
    REQUIRE(val_uz == 84_uz);
    REQUIRE(val_i8 == 84_i8);
    REQUIRE(val_i16 == 84_i16);
    REQUIRE(val_i32 == 84_i32);
    REQUIRE(val_i64 == 84_i64);
    REQUIRE(val_iz == 84_iz);
}

TEST_CASE("div assign", "[ops]") {
    auto val_u8 = 42_u8;
    auto val_u16 = 42_u16;
    auto val_u32 = 42_u32;
    auto val_u64 = 42_u64;
    auto val_uz = 42_uz;
    auto val_i8 = 42_i8;
    auto val_i16 = 42_i16;
    auto val_i32 = 42_i32;
    auto val_i64 = 42_i64;
    auto val_iz = 42_iz;

    REQUIRE((val_u8 /= 2_u8) == 21_u8);
    REQUIRE((val_u16 /= 2_u16) == 21_u16);
    REQUIRE((val_u32 /= 2_u32) == 21_u32);
    REQUIRE((val_u64 /= 2_u64) == 21_u64);
    REQUIRE((val_uz /= 2_uz) == 21_uz);
    REQUIRE((val_i8 /= 2_i8) == 21_i8);
    REQUIRE((val_i16 /= 2_i16) == 21_i16);
    REQUIRE((val_i32 /= 2_i32) == 21_i32);
    REQUIRE((val_i64 /= 2_i64) == 21_i64);
    REQUIRE((val_iz /= 2_iz) == 21_iz);

    REQUIRE(val_u8 == 21_u8);
    REQUIRE(val_u16 == 21_u16);
    REQUIRE(val_u32 == 21_u32);
    REQUIRE(val_u64 == 21_u64);
    REQUIRE(val_uz == 21_uz);
    REQUIRE(val_i8 == 21_i8);
    REQUIRE(val_i16 == 21_i16);
    REQUIRE(val_i32 == 21_i32);
    REQUIRE(val_i64 == 21_i64);
    REQUIRE(val_iz == 21_iz);
}

TEST_CASE("mod assign", "[ops]") {
    auto val_u8 = 42_u8;
    auto val_u16 = 42_u16;
    auto val_u32 = 42_u32;
    auto val_u64 = 42_u64;
    auto val_uz = 42_uz;
    auto val_i8 = 42_i8;
    auto val_i16 = 42_i16;
    auto val_i32 = 42_i32;
    auto val_i64 = 42_i64;
    auto val_iz = 42_iz;

    REQUIRE((val_u8 %= 10_u8) == 2_u8);
    REQUIRE((val_u16 %= 10_u16) == 2_u16);
    REQUIRE((val_u32 %= 10_u32) == 2_u32);
    REQUIRE((val_u64 %= 10_u64) == 2_u64);
    REQUIRE((val_uz %= 10_uz) == 2_uz);
    REQUIRE((val_i8 %= 10_i8) == 2_i8);
    REQUIRE((val_i16 %= 10_i16) == 2_i16);
    REQUIRE((val_i32 %= 10_i32) == 2_i32);
    REQUIRE((val_i64 %= 10_i64) == 2_i64);
    REQUIRE((val_iz %= 10_iz) == 2_iz);

    REQUIRE(val_u8 == 2_u8);
    REQUIRE(val_u16 == 2_u16);
    REQUIRE(val_u32 == 2_u32);
    REQUIRE(val_u64 == 2_u64);
    REQUIRE(val_uz == 2_uz);
    REQUIRE(val_i8 == 2_i8);
    REQUIRE(val_i16 == 2_i16);
    REQUIRE(val_i32 == 2_i32);
    REQUIRE(val_i64 == 2_i64);
    REQUIRE(val_iz == 2_iz);
}

TEST_CASE("and assign", "[ops]") {
    auto val_u8 = 0x0c_u8;
    auto val_u16 = 0x0c_u16;
    auto val_u32 = 0x0c_u32;
    auto val_u64 = 0x0c_u64;
    auto val_uz = 0x0c_uz;
    auto val_i8 = 0x0c_i8;
    auto val_i16 = 0x0c_i16;
    auto val_i32 = 0x0c_i32;
    auto val_i64 = 0x0c_i64;
    auto val_iz = 0x0c_iz;

    REQUIRE((val_u8 &= 9_u8) == 8_u8);
    REQUIRE((val_u16 &= 9_u16) == 8_u16);
    REQUIRE((val_u32 &= 9_u32) == 8_u32);
    REQUIRE((val_u64 &= 9_u64) == 8_u64);
    REQUIRE((val_uz &= 9_uz) == 8_uz);
    REQUIRE((val_i8 &= 9_i8) == 8_i8);
    REQUIRE((val_i16 &= 9_i16) == 8_i16);
    REQUIRE((val_i32 &= 9_i32) == 8_i32);
    REQUIRE((val_i64 &= 9_i64) == 8_i64);
    REQUIRE((val_iz &= 9_iz) == 8_iz);

    REQUIRE(val_u8 == 8_u8);
    REQUIRE(val_u16 == 8_u16);
    REQUIRE(val_u32 == 8_u32);
    REQUIRE(val_u64 == 8_u64);
    REQUIRE(val_uz == 8_uz);
    REQUIRE(val_i8 == 8_i8);
    REQUIRE(val_i16 == 8_i16);
    REQUIRE(val_i32 == 8_i32);
    REQUIRE(val_i64 == 8_i64);
    REQUIRE(val_iz == 8_iz);
}

TEST_CASE("or assign", "[ops]") {
    auto val_u8 = 0x0c_u8;
    auto val_u16 = 0x0c_u16;
    auto val_u32 = 0x0c_u32;
    auto val_u64 = 0x0c_u64;
    auto val_uz = 0x0c_uz;
    auto val_i8 = 0x0c_i8;
    auto val_i16 = 0x0c_i16;
    auto val_i32 = 0x0c_i32;
    auto val_i64 = 0x0c_i64;
    auto val_iz = 0x0c_iz;

    REQUIRE((val_u8 |= 9_u8) == 0x0d_u8);
    REQUIRE((val_u16 |= 9_u16) == 0x0d_u16);
    REQUIRE((val_u32 |= 9_u32) == 0x0d_u32);
    REQUIRE((val_u64 |= 9_u64) == 0x0d_u64);
    REQUIRE((val_uz |= 9_uz) == 0x0d_uz);
    REQUIRE((val_i8 |= 9_i8) == 0x0d_i8);
    REQUIRE((val_i16 |= 9_i16) == 0x0d_i16);
    REQUIRE((val_i32 |= 9_i32) == 0x0d_i32);
    REQUIRE((val_i64 |= 9_i64) == 0x0d_i64);
    REQUIRE((val_iz |= 9_iz) == 0x0d_iz);

    REQUIRE(val_u8 == 0x0d_u8);
    REQUIRE(val_u16 == 0x0d_u16);
    REQUIRE(val_u32 == 0x0d_u32);
    REQUIRE(val_u64 == 0x0d_u64);
    REQUIRE(val_uz == 0x0d_uz);
    REQUIRE(val_i8 == 0x0d_i8);
    REQUIRE(val_i16 == 0x0d_i16);
    REQUIRE(val_i32 == 0x0d_i32);
    REQUIRE(val_i64 == 0x0d_i64);
    REQUIRE(val_iz == 0x0d_iz);
}

TEST_CASE("xor assign", "[ops]") {
    auto val_u8 = 0x0c_u8;
    auto val_u16 = 0x0c_u16;
    auto val_u32 = 0x0c_u32;
    auto val_u64 = 0x0c_u64;
    auto val_uz = 0x0c_uz;
    auto val_i8 = 0x0c_i8;
    auto val_i16 = 0x0c_i16;
    auto val_i32 = 0x0c_i32;
    auto val_i64 = 0x0c_i64;
    auto val_iz = 0x0c_iz;

    REQUIRE((val_u8 ^= 9_u8) == 5_u8);
    REQUIRE((val_u16 ^= 9_u16) == 5_u16);
    REQUIRE((val_u32 ^= 9_u32) == 5_u32);
    REQUIRE((val_u64 ^= 9_u64) == 5_u64);
    REQUIRE((val_uz ^= 9_uz) == 5_uz);
    REQUIRE((val_i8 ^= 9_i8) == 5_i8);
    REQUIRE((val_i16 ^= 9_i16) == 5_i16);
    REQUIRE((val_i32 ^= 9_i32) == 5_i32);
    REQUIRE((val_i64 ^= 9_i64) == 5_i64);
    REQUIRE((val_iz ^= 9_iz) == 5_iz);

    REQUIRE(val_u8 == 5_u8);
    REQUIRE(val_u16 == 5_u16);
    REQUIRE(val_u32 == 5_u32);
    REQUIRE(val_u64 == 5_u64);
    REQUIRE(val_uz == 5_uz);
    REQUIRE(val_i8 == 5_i8);
    REQUIRE(val_i16 == 5_i16);
    REQUIRE(val_i32 == 5_i32);
    REQUIRE(val_i64 == 5_i64);
    REQUIRE(val_iz == 5_iz);
}

TEST_CASE("shift left assign", "[ops]") {
    auto val_u8 = 0x0c_u8;
    auto val_u16 = 0x0c_u16;
    auto val_u32 = 0x0c_u32;
    auto val_u64 = 0x0c_u64;
    auto val_uz = 0x0c_uz;
    auto val_i8 = 0x0c_i8;
    auto val_i16 = 0x0c_i16;
    auto val_i32 = 0x0c_i32;
    auto val_i64 = 0x0c_i64;
    auto val_iz = 0x0c_iz;

    REQUIRE((val_u8 <<= 1_iz) == 0x18_u8);
    REQUIRE((val_u16 <<= 1_iz) == 0x18_u16);
    REQUIRE((val_u32 <<= 1_iz) == 0x18_u32);
    REQUIRE((val_u64 <<= 1_iz) == 0x18_u64);
    REQUIRE((val_uz <<= 1_iz) == 0x18_uz);
    REQUIRE((val_i8 <<= 1_iz) == 0x18_i8);
    REQUIRE((val_i16 <<= 1_iz) == 0x18_i16);
    REQUIRE((val_i32 <<= 1_iz) == 0x18_i32);
    REQUIRE((val_i64 <<= 1_iz) == 0x18_i64);
    REQUIRE((val_iz <<= 1_iz) == 0x18_iz);

    REQUIRE(val_u8 == 0x18_u8);
    REQUIRE(val_u16 == 0x18_u16);
    REQUIRE(val_u32 == 0x18_u32);
    REQUIRE(val_u64 == 0x18_u64);
    REQUIRE(val_uz == 0x18_uz);
    REQUIRE(val_i8 == 0x18_i8);
    REQUIRE(val_i16 == 0x18_i16);
    REQUIRE(val_i32 == 0x18_i32);
    REQUIRE(val_i64 == 0x18_i64);
    REQUIRE(val_iz == 0x18_iz);

    val_u8 = 0x0c_u8;
    val_u16 = 0x0c_u16;
    val_u32 = 0x0c_u32;
    val_u64 = 0x0c_u64;
    val_uz = 0x0c_uz;
    val_i8 = 0x0c_i8;
    val_i16 = 0x0c_i16;
    val_i32 = 0x0c_i32;
    val_i64 = 0x0c_i64;
    val_iz = 0x0c_iz;

    REQUIRE((val_u8 <<= 1) == 0x18_u8);
    REQUIRE((val_u16 <<= 1) == 0x18_u16);
    REQUIRE((val_u32 <<= 1) == 0x18_u32);
    REQUIRE((val_u64 <<= 1) == 0x18_u64);
    REQUIRE((val_uz <<= 1) == 0x18_uz);
    REQUIRE((val_i8 <<= 1) == 0x18_i8);
    REQUIRE((val_i16 <<= 1) == 0x18_i16);
    REQUIRE((val_i32 <<= 1) == 0x18_i32);
    REQUIRE((val_i64 <<= 1) == 0x18_i64);
    REQUIRE((val_iz <<= 1) == 0x18_iz);

    REQUIRE(val_u8 == 0x18_u8);
    REQUIRE(val_u16 == 0x18_u16);
    REQUIRE(val_u32 == 0x18_u32);
    REQUIRE(val_u64 == 0x18_u64);
    REQUIRE(val_uz == 0x18_uz);
    REQUIRE(val_i8 == 0x18_i8);
    REQUIRE(val_i16 == 0x18_i16);
    REQUIRE(val_i32 == 0x18_i32);
    REQUIRE(val_i64 == 0x18_i64);
    REQUIRE(val_iz == 0x18_iz);
}

TEST_CASE("shift right assign", "[ops]") {
    auto val_u8 = 0x0c_u8;
    auto val_u16 = 0x0c_u16;
    auto val_u32 = 0x0c_u32;
    auto val_u64 = 0x0c_u64;
    auto val_uz = 0x0c_uz;
    auto val_i8 = 0x0c_i8;
    auto val_i16 = 0x0c_i16;
    auto val_i32 = 0x0c_i32;
    auto val_i64 = 0x0c_i64;
    auto val_iz = 0x0c_iz;

    REQUIRE((val_u8 >>= 1_iz) == 6_u8);
    REQUIRE((val_u16 >>= 1_iz) == 6_u16);
    REQUIRE((val_u32 >>= 1_iz) == 6_u32);
    REQUIRE((val_u64 >>= 1_iz) == 6_u64);
    REQUIRE((val_uz >>= 1_iz) == 6_uz);
    REQUIRE((val_i8 >>= 1_iz) == 6_i8);
    REQUIRE((val_i16 >>= 1_iz) == 6_i16);
    REQUIRE((val_i32 >>= 1_iz) == 6_i32);
    REQUIRE((val_i64 >>= 1_iz) == 6_i64);
    REQUIRE((val_iz >>= 1_iz) == 6_iz);

    REQUIRE(val_u8 == 6_u8);
    REQUIRE(val_u16 == 6_u16);
    REQUIRE(val_u32 == 6_u32);
    REQUIRE(val_u64 == 6_u64);
    REQUIRE(val_uz == 6_uz);
    REQUIRE(val_i8 == 6_i8);
    REQUIRE(val_i16 == 6_i16);
    REQUIRE(val_i32 == 6_i32);
    REQUIRE(val_i64 == 6_i64);
    REQUIRE(val_iz == 6_iz);

    val_u8 = 0x0c_u8;
    val_u16 = 0x0c_u16;
    val_u32 = 0x0c_u32;
    val_u64 = 0x0c_u64;
    val_uz = 0x0c_uz;
    val_i8 = 0x0c_i8;
    val_i16 = 0x0c_i16;
    val_i32 = 0x0c_i32;
    val_i64 = 0x0c_i64;
    val_iz = 0x0c_iz;

    REQUIRE((val_u8 >>= 1) == 6_u8);
    REQUIRE((val_u16 >>= 1) == 6_u16);
    REQUIRE((val_u32 >>= 1) == 6_u32);
    REQUIRE((val_u64 >>= 1) == 6_u64);
    REQUIRE((val_uz >>= 1) == 6_uz);
    REQUIRE((val_i8 >>= 1) == 6_i8);
    REQUIRE((val_i16 >>= 1) == 6_i16);
    REQUIRE((val_i32 >>= 1) == 6_i32);
    REQUIRE((val_i64 >>= 1) == 6_i64);
    REQUIRE((val_iz >>= 1) == 6_iz);

    REQUIRE(val_u8 == 6_u8);
    REQUIRE(val_u16 == 6_u16);
    REQUIRE(val_u32 == 6_u32);
    REQUIRE(val_u64 == 6_u64);
    REQUIRE(val_uz == 6_uz);
    REQUIRE(val_i8 == 6_i8);
    REQUIRE(val_i16 == 6_i16);
    REQUIRE(val_i32 == 6_i32);
    REQUIRE(val_i64 == 6_i64);
    REQUIRE(val_iz == 6_iz);
}

TEST_CASE("add", "[ops]") {
    REQUIRE((42_u8 + 10_u8) == 52_u8);
    REQUIRE((42_u16 + 10_u16) == 52_u16);
    REQUIRE((42_u32 + 10_u32) == 52_u32);
    REQUIRE((42_u64 + 10_u64) == 52_u64);
    REQUIRE((42_uz + 10_uz) == 52_uz);
    REQUIRE((42_i8 + 10_i8) == 52_i8);
    REQUIRE((42_i16 + 10_i16) == 52_i16);
    REQUIRE((42_i32 + 10_i32) == 52_i32);
    REQUIRE((42_i64 + 10_i64) == 52_i64);
    REQUIRE((42_iz + 10_iz) == 52_iz);
}

TEST_CASE("sub", "[ops]") {
    REQUIRE((42_u8 - 10_u8) == 32_u8);
    REQUIRE((42_u16 - 10_u16) == 32_u16);
    REQUIRE((42_u32 - 10_u32) == 32_u32);
    REQUIRE((42_u64 - 10_u64) == 32_u64);
    REQUIRE((42_uz - 10_uz) == 32_uz);
    REQUIRE((42_i8 - 10_i8) == 32_i8);
    REQUIRE((42_i16 - 10_i16) == 32_i16);
    REQUIRE((42_i32 - 10_i32) == 32_i32);
    REQUIRE((42_i64 - 10_i64) == 32_i64);
    REQUIRE((42_iz - 10_iz) == 32_iz);
}

TEST_CASE("mul", "[ops]") {
    REQUIRE((42_u8 * 2_u8) == 84_u8);
    REQUIRE((42_u16 * 2_u16) == 84_u16);
    REQUIRE((42_u32 * 2_u32) == 84_u32);
    REQUIRE((42_u64 * 2_u64) == 84_u64);
    REQUIRE((42_uz * 2_uz) == 84_uz);
    REQUIRE((42_i8 * 2_i8) == 84_i8);
    REQUIRE((42_i16 * 2_i16) == 84_i16);
    REQUIRE((42_i32 * 2_i32) == 84_i32);
    REQUIRE((42_i64 * 2_i64) == 84_i64);
    REQUIRE((42_iz * 2_iz) == 84_iz);
}

TEST_CASE("div", "[ops]") {
    REQUIRE((42_u8 / 2_u8) == 21_u8);
    REQUIRE((42_u16 / 2_u16) == 21_u16);
    REQUIRE((42_u32 / 2_u32) == 21_u32);
    REQUIRE((42_u64 / 2_u64) == 21_u64);
    REQUIRE((42_uz / 2_uz) == 21_uz);
    REQUIRE((42_i8 / 2_i8) == 21_i8);
    REQUIRE((42_i16 / 2_i16) == 21_i16);
    REQUIRE((42_i32 / 2_i32) == 21_i32);
    REQUIRE((42_i64 / 2_i64) == 21_i64);
    REQUIRE((42_iz / 2_iz) == 21_iz);
}

TEST_CASE("mod", "[ops]") {
    REQUIRE((42_u8 % 10_u8) == 2_u8);
    REQUIRE((42_u16 % 10_u16) == 2_u16);
    REQUIRE((42_u32 % 10_u32) == 2_u32);
    REQUIRE((42_u64 % 10_u64) == 2_u64);
    REQUIRE((42_uz % 10_uz) == 2_uz);
    REQUIRE((42_i8 % 10_i8) == 2_i8);
    REQUIRE((42_i16 % 10_i16) == 2_i16);
    REQUIRE((42_i32 % 10_i32) == 2_i32);
    REQUIRE((42_i64 % 10_i64) == 2_i64);
    REQUIRE((42_iz % 10_iz) == 2_iz);
}

TEST_CASE("and", "[ops]") {
    REQUIRE((0x0c_u8 & 9_u8) == 8_u8);
    REQUIRE((0x0c_u16 & 9_u16) == 8_u16);
    REQUIRE((0x0c_u32 & 9_u32) == 8_u32);
    REQUIRE((0x0c_u64 & 9_u64) == 8_u64);
    REQUIRE((0x0c_uz & 9_uz) == 8_uz);
    REQUIRE((0x0c_i8 & 9_i8) == 8_i8);
    REQUIRE((0x0c_i16 & 9_i16) == 8_i16);
    REQUIRE((0x0c_i32 & 9_i32) == 8_i32);
    REQUIRE((0x0c_i64 & 9_i64) == 8_i64);
    REQUIRE((0x0c_iz & 9_iz) == 8_iz);
}

TEST_CASE("or", "[ops]") {
    REQUIRE((0x0c_u8 | 9_u8) == 0x0d_u8);
    REQUIRE((0x0c_u16 | 9_u16) == 0x0d_u16);
    REQUIRE((0x0c_u32 | 9_u32) == 0x0d_u32);
    REQUIRE((0x0c_u64 | 9_u64) == 0x0d_u64);
    REQUIRE((0x0c_uz | 9_uz) == 0x0d_uz);
    REQUIRE((0x0c_i8 | 9_i8) == 0x0d_i8);
    REQUIRE((0x0c_i16 | 9_i16) == 0x0d_i16);
    REQUIRE((0x0c_i32 | 9_i32) == 0x0d_i32);
    REQUIRE((0x0c_i64 | 9_i64) == 0x0d_i64);
    REQUIRE((0x0c_iz | 9_iz) == 0x0d_iz);
}

TEST_CASE("xor", "[ops]") {
    REQUIRE((0x0c_u8 ^ 9_u8) == 5_u8);
    REQUIRE((0x0c_u16 ^ 9_u16) == 5_u16);
    REQUIRE((0x0c_u32 ^ 9_u32) == 5_u32);
    REQUIRE((0x0c_u64 ^ 9_u64) == 5_u64);
    REQUIRE((0x0c_uz ^ 9_uz) == 5_uz);
    REQUIRE((0x0c_i8 ^ 9_i8) == 5_i8);
    REQUIRE((0x0c_i16 ^ 9_i16) == 5_i16);
    REQUIRE((0x0c_i32 ^ 9_i32) == 5_i32);
    REQUIRE((0x0c_i64 ^ 9_i64) == 5_i64);
    REQUIRE((0x0c_iz ^ 9_iz) == 5_iz);
}

TEST_CASE("shift left", "[ops]") {
    REQUIRE((0x0c_u8 << 1_iz) == 0x18_u8);
    REQUIRE((0x0c_u16 << 1_iz) == 0x18_u16);
    REQUIRE((0x0c_u32 << 1_iz) == 0x18_u32);
    REQUIRE((0x0c_u64 << 1_iz) == 0x18_u64);
    REQUIRE((0x0c_uz << 1_iz) == 0x18_uz);
    REQUIRE((0x0c_i8 << 1_iz) == 0x18_i8);
    REQUIRE((0x0c_i16 << 1_iz) == 0x18_i16);
    REQUIRE((0x0c_i32 << 1_iz) == 0x18_i32);
    REQUIRE((0x0c_i64 << 1_iz) == 0x18_i64);
    REQUIRE((0x0c_iz << 1_iz) == 0x18_iz);

    REQUIRE((0x0c_u8 << 1) == 0x18_u8);
    REQUIRE((0x0c_u16 << 1) == 0x18_u16);
    REQUIRE((0x0c_u32 << 1) == 0x18_u32);
    REQUIRE((0x0c_u64 << 1) == 0x18_u64);
    REQUIRE((0x0c_uz << 1) == 0x18_uz);
    REQUIRE((0x0c_i8 << 1) == 0x18_i8);
    REQUIRE((0x0c_i16 << 1) == 0x18_i16);
    REQUIRE((0x0c_i32 << 1) == 0x18_i32);
    REQUIRE((0x0c_i64 << 1) == 0x18_i64);
    REQUIRE((0x0c_iz << 1) == 0x18_iz);
}

TEST_CASE("shift right", "[ops]") {
    REQUIRE((0x0c_u8 >> 1_iz) == 6_u8);
    REQUIRE((0x0c_u16 >> 1_iz) == 6_u16);
    REQUIRE((0x0c_u32 >> 1_iz) == 6_u32);
    REQUIRE((0x0c_u64 >> 1_iz) == 6_u64);
    REQUIRE((0x0c_uz >> 1_iz) == 6_uz);
    REQUIRE((0x0c_i8 >> 1_iz) == 6_i8);
    REQUIRE((0x0c_i16 >> 1_iz) == 6_i16);
    REQUIRE((0x0c_i32 >> 1_iz) == 6_i32);
    REQUIRE((0x0c_i64 >> 1_iz) == 6_i64);
    REQUIRE((0x0c_iz >> 1_iz) == 6_iz);

    REQUIRE((0x0c_u8 >> 1) == 6_u8);
    REQUIRE((0x0c_u16 >> 1) == 6_u16);
    REQUIRE((0x0c_u32 >> 1) == 6_u32);
    REQUIRE((0x0c_u64 >> 1) == 6_u64);
    REQUIRE((0x0c_uz >> 1) == 6_uz);
    REQUIRE((0x0c_i8 >> 1) == 6_i8);
    REQUIRE((0x0c_i16 >> 1) == 6_i16);
    REQUIRE((0x0c_i32 >> 1) == 6_i32);
    REQUIRE((0x0c_i64 >> 1) == 6_i64);
    REQUIRE((0x0c_iz >> 1) == 6_iz);
}

TEST_CASE("ostream format", "[format]") {
    std::stringstream ss;

    ss = std::stringstream();
    ss << 42_u8;
    REQUIRE(ss.str() == "42");

    ss = std::stringstream();
    ss << 42_u16;
    REQUIRE(ss.str() == "42");

    ss = std::stringstream();
    ss << 42_u32;
    REQUIRE(ss.str() == "42");

    ss = std::stringstream();
    ss << 42_u64;
    REQUIRE(ss.str() == "42");

    ss = std::stringstream();
    ss << 42_uz;
    REQUIRE(ss.str() == "42");

    ss = std::stringstream();
    ss << 42_i8;
    REQUIRE(ss.str() == "42");

    ss = std::stringstream();
    ss << 42_i16;
    REQUIRE(ss.str() == "42");

    ss = std::stringstream();
    ss << 42_i32;
    REQUIRE(ss.str() == "42");

    ss = std::stringstream();
    ss << 42_i64;
    REQUIRE(ss.str() == "42");

    ss = std::stringstream();
    ss << 42_iz;
    REQUIRE(ss.str() == "42");
}

TEST_CASE("istream format", "[format]") {
    std::stringstream ss;

    ss = std::stringstream("42");
    u8 val_u8{};
    ss >> val_u8;
    REQUIRE(val_u8 == 42_u8);

    ss = std::stringstream("42");
    u16 val_u16{};
    ss >> val_u16;
    REQUIRE(val_u16 == 42_u16);

    ss = std::stringstream("42");
    u32 val_u32{};
    ss >> val_u32;
    REQUIRE(val_u32 == 42_u32);

    ss = std::stringstream("42");
    u64 val_u64{};
    ss >> val_u64;
    REQUIRE(val_u64 == 42_u64);

    ss = std::stringstream("42");
    usize val_uz{};
    ss >> val_uz;
    REQUIRE(val_uz == 42_uz);

    ss = std::stringstream("42");
    i8 val_i8{};
    ss >> val_i8;
    REQUIRE(val_i8 == 42_i8);

    ss = std::stringstream("42");
    i16 val_i16{};
    ss >> val_i16;
    REQUIRE(val_i16 == 42_i16);

    ss = std::stringstream("42");
    i32 val_i32{};
    ss >> val_i32;
    REQUIRE(val_i32 == 42_i32);

    ss = std::stringstream("42");
    i64 val_i64{};
    ss >> val_i64;
    REQUIRE(val_i64 == 42_i64);

    ss = std::stringstream("42");
    isize val_iz{};
    ss >> val_iz;
    REQUIRE(val_iz == 42_iz);
}

#if __has_include(<format>)

TEST_CASE("formatter", "[format]") {
    REQUIRE(std::format("{}", 42_u8) == "42");
    REQUIRE(std::format("{}", 42_u16) == "42");
    REQUIRE(std::format("{}", 42_u32) == "42");
    REQUIRE(std::format("{}", 42_u64) == "42");
    REQUIRE(std::format("{}", 42_uz) == "42");
    REQUIRE(std::format("{}", 42_i8) == "42");
    REQUIRE(std::format("{}", 42_i16) == "42");
    REQUIRE(std::format("{}", 42_i32) == "42");
    REQUIRE(std::format("{}", 42_i64) == "42");
    REQUIRE(std::format("{}", 42_iz) == "42");
}

#endif

TEST_CASE("is_stipp_int", "[traits]") {
    STATIC_REQUIRE(stipp::is_stipp_int<u8>::value);
    STATIC_REQUIRE(stipp::is_stipp_int<u16>::value);
    STATIC_REQUIRE(stipp::is_stipp_int<u32>::value);
    STATIC_REQUIRE(stipp::is_stipp_int<u64>::value);
    STATIC_REQUIRE(stipp::is_stipp_int<usize>::value);
    STATIC_REQUIRE(stipp::is_stipp_int<i8>::value);
    STATIC_REQUIRE(stipp::is_stipp_int<i16>::value);
    STATIC_REQUIRE(stipp::is_stipp_int<i32>::value);
    STATIC_REQUIRE(stipp::is_stipp_int<i64>::value);
    STATIC_REQUIRE(stipp::is_stipp_int<isize>::value);

    STATIC_REQUIRE(!stipp::is_stipp_int<int>::value);
}

TEST_CASE("is_stipp_int_v", "[traits]") {
    STATIC_REQUIRE(stipp::is_stipp_int_v<u8>);
    STATIC_REQUIRE(stipp::is_stipp_int_v<u16>);
    STATIC_REQUIRE(stipp::is_stipp_int_v<u32>);
    STATIC_REQUIRE(stipp::is_stipp_int_v<u64>);
    STATIC_REQUIRE(stipp::is_stipp_int_v<usize>);
    STATIC_REQUIRE(stipp::is_stipp_int_v<i8>);
    STATIC_REQUIRE(stipp::is_stipp_int_v<i16>);
    STATIC_REQUIRE(stipp::is_stipp_int_v<i32>);
    STATIC_REQUIRE(stipp::is_stipp_int_v<i64>);
    STATIC_REQUIRE(stipp::is_stipp_int_v<isize>);

    STATIC_REQUIRE(!stipp::is_stipp_int_v<int>);
}

TEST_CASE("stipp_int", "[traits]") {
    STATIC_REQUIRE(stipp::stipp_int<u8>);
    STATIC_REQUIRE(stipp::stipp_int<u16>);
    STATIC_REQUIRE(stipp::stipp_int<u32>);
    STATIC_REQUIRE(stipp::stipp_int<u64>);
    STATIC_REQUIRE(stipp::stipp_int<usize>);
    STATIC_REQUIRE(stipp::stipp_int<i8>);
    STATIC_REQUIRE(stipp::stipp_int<i16>);
    STATIC_REQUIRE(stipp::stipp_int<i32>);
    STATIC_REQUIRE(stipp::stipp_int<i64>);
    STATIC_REQUIRE(stipp::stipp_int<isize>);

    STATIC_REQUIRE(!stipp::stipp_int<int>);
}

TEST_CASE("is_integral", "[traits]") {
    STATIC_REQUIRE(stipp::is_integral<u8>::value);
    STATIC_REQUIRE(stipp::is_integral<u16>::value);
    STATIC_REQUIRE(stipp::is_integral<u32>::value);
    STATIC_REQUIRE(stipp::is_integral<u64>::value);
    STATIC_REQUIRE(stipp::is_integral<usize>::value);
    STATIC_REQUIRE(stipp::is_integral<i8>::value);
    STATIC_REQUIRE(stipp::is_integral<i16>::value);
    STATIC_REQUIRE(stipp::is_integral<i32>::value);
    STATIC_REQUIRE(stipp::is_integral<i64>::value);
    STATIC_REQUIRE(stipp::is_integral<isize>::value);

    STATIC_REQUIRE(stipp::is_integral<int>::value);
}

TEST_CASE("is_integral_v", "[traits]") {
    STATIC_REQUIRE(stipp::is_integral_v<u8>);
    STATIC_REQUIRE(stipp::is_integral_v<u16>);
    STATIC_REQUIRE(stipp::is_integral_v<u32>);
    STATIC_REQUIRE(stipp::is_integral_v<u64>);
    STATIC_REQUIRE(stipp::is_integral_v<usize>);
    STATIC_REQUIRE(stipp::is_integral_v<i8>);
    STATIC_REQUIRE(stipp::is_integral_v<i16>);
    STATIC_REQUIRE(stipp::is_integral_v<i32>);
    STATIC_REQUIRE(stipp::is_integral_v<i64>);
    STATIC_REQUIRE(stipp::is_integral_v<isize>);

    STATIC_REQUIRE(stipp::is_integral_v<int>);
}

TEST_CASE("integral", "[traits]") {
    STATIC_REQUIRE(stipp::integral<u8>);
    STATIC_REQUIRE(stipp::integral<u16>);
    STATIC_REQUIRE(stipp::integral<u32>);
    STATIC_REQUIRE(stipp::integral<u64>);
    STATIC_REQUIRE(stipp::integral<usize>);
    STATIC_REQUIRE(stipp::integral<i8>);
    STATIC_REQUIRE(stipp::integral<i16>);
    STATIC_REQUIRE(stipp::integral<i32>);
    STATIC_REQUIRE(stipp::integral<i64>);
    STATIC_REQUIRE(stipp::integral<isize>);

    STATIC_REQUIRE(stipp::integral<int>);
}

TEST_CASE("is_arithmetic", "[traits]") {
    STATIC_REQUIRE(stipp::is_arithmetic<u8>::value);
    STATIC_REQUIRE(stipp::is_arithmetic<u16>::value);
    STATIC_REQUIRE(stipp::is_arithmetic<u32>::value);
    STATIC_REQUIRE(stipp::is_arithmetic<u64>::value);
    STATIC_REQUIRE(stipp::is_arithmetic<usize>::value);
    STATIC_REQUIRE(stipp::is_arithmetic<i8>::value);
    STATIC_REQUIRE(stipp::is_arithmetic<i16>::value);
    STATIC_REQUIRE(stipp::is_arithmetic<i32>::value);
    STATIC_REQUIRE(stipp::is_arithmetic<i64>::value);
    STATIC_REQUIRE(stipp::is_arithmetic<isize>::value);

    STATIC_REQUIRE(stipp::is_arithmetic<int>::value);
    STATIC_REQUIRE(stipp::is_arithmetic<float>::value);
}

TEST_CASE("is_arithmetic_v", "[traits]") {
    STATIC_REQUIRE(stipp::is_arithmetic_v<u8>);
    STATIC_REQUIRE(stipp::is_arithmetic_v<u16>);
    STATIC_REQUIRE(stipp::is_arithmetic_v<u32>);
    STATIC_REQUIRE(stipp::is_arithmetic_v<u64>);
    STATIC_REQUIRE(stipp::is_arithmetic_v<usize>);
    STATIC_REQUIRE(stipp::is_arithmetic_v<i8>);
    STATIC_REQUIRE(stipp::is_arithmetic_v<i16>);
    STATIC_REQUIRE(stipp::is_arithmetic_v<i32>);
    STATIC_REQUIRE(stipp::is_arithmetic_v<i64>);
    STATIC_REQUIRE(stipp::is_arithmetic_v<isize>);

    STATIC_REQUIRE(stipp::is_arithmetic_v<int>);
    STATIC_REQUIRE(stipp::is_arithmetic_v<float>);
}

TEST_CASE("arithmetic", "[traits]") {
    STATIC_REQUIRE(stipp::arithmetic<u8>);
    STATIC_REQUIRE(stipp::arithmetic<u16>);
    STATIC_REQUIRE(stipp::arithmetic<u32>);
    STATIC_REQUIRE(stipp::arithmetic<u64>);
    STATIC_REQUIRE(stipp::arithmetic<usize>);
    STATIC_REQUIRE(stipp::arithmetic<i8>);
    STATIC_REQUIRE(stipp::arithmetic<i16>);
    STATIC_REQUIRE(stipp::arithmetic<i32>);
    STATIC_REQUIRE(stipp::arithmetic<i64>);
    STATIC_REQUIRE(stipp::arithmetic<isize>);

    STATIC_REQUIRE(stipp::arithmetic<int>);
    STATIC_REQUIRE(stipp::arithmetic<float>);
}

TEST_CASE("is_signed", "[traits]") {
    STATIC_REQUIRE(!stipp::is_signed<u8>::value);
    STATIC_REQUIRE(!stipp::is_signed<u16>::value);
    STATIC_REQUIRE(!stipp::is_signed<u32>::value);
    STATIC_REQUIRE(!stipp::is_signed<u64>::value);
    STATIC_REQUIRE(!stipp::is_signed<usize>::value);
    STATIC_REQUIRE(stipp::is_signed<i8>::value);
    STATIC_REQUIRE(stipp::is_signed<i16>::value);
    STATIC_REQUIRE(stipp::is_signed<i32>::value);
    STATIC_REQUIRE(stipp::is_signed<i64>::value);
    STATIC_REQUIRE(stipp::is_signed<isize>::value);

    STATIC_REQUIRE(stipp::is_signed<int>::value);
    STATIC_REQUIRE(!stipp::is_signed<unsigned int>::value);
}

TEST_CASE("is_signed_v", "[traits]") {
    STATIC_REQUIRE(!stipp::is_signed_v<u8>);
    STATIC_REQUIRE(!stipp::is_signed_v<u16>);
    STATIC_REQUIRE(!stipp::is_signed_v<u32>);
    STATIC_REQUIRE(!stipp::is_signed_v<u64>);
    STATIC_REQUIRE(!stipp::is_signed_v<usize>);
    STATIC_REQUIRE(stipp::is_signed_v<i8>);
    STATIC_REQUIRE(stipp::is_signed_v<i16>);
    STATIC_REQUIRE(stipp::is_signed_v<i32>);
    STATIC_REQUIRE(stipp::is_signed_v<i64>);
    STATIC_REQUIRE(stipp::is_signed_v<isize>);

    STATIC_REQUIRE(stipp::is_signed_v<int>);
    STATIC_REQUIRE(!stipp::is_signed_v<unsigned int>);
}

TEST_CASE("signed_integral", "[traits]") {
    STATIC_REQUIRE(!stipp::signed_integral<u8>);
    STATIC_REQUIRE(!stipp::signed_integral<u16>);
    STATIC_REQUIRE(!stipp::signed_integral<u32>);
    STATIC_REQUIRE(!stipp::signed_integral<u64>);
    STATIC_REQUIRE(!stipp::signed_integral<usize>);
    STATIC_REQUIRE(stipp::signed_integral<i8>);
    STATIC_REQUIRE(stipp::signed_integral<i16>);
    STATIC_REQUIRE(stipp::signed_integral<i32>);
    STATIC_REQUIRE(stipp::signed_integral<i64>);
    STATIC_REQUIRE(stipp::signed_integral<isize>);

    STATIC_REQUIRE(stipp::signed_integral<int>);
    STATIC_REQUIRE(!stipp::signed_integral<unsigned int>);
}

TEST_CASE("is_unsigned", "[traits]") {
    STATIC_REQUIRE(stipp::is_unsigned<u8>::value);
    STATIC_REQUIRE(stipp::is_unsigned<u16>::value);
    STATIC_REQUIRE(stipp::is_unsigned<u32>::value);
    STATIC_REQUIRE(stipp::is_unsigned<u64>::value);
    STATIC_REQUIRE(stipp::is_unsigned<usize>::value);
    STATIC_REQUIRE(!stipp::is_unsigned<i8>::value);
    STATIC_REQUIRE(!stipp::is_unsigned<i16>::value);
    STATIC_REQUIRE(!stipp::is_unsigned<i32>::value);
    STATIC_REQUIRE(!stipp::is_unsigned<i64>::value);
    STATIC_REQUIRE(!stipp::is_unsigned<isize>::value);

    STATIC_REQUIRE(!stipp::is_unsigned<int>::value);
    STATIC_REQUIRE(stipp::is_unsigned<unsigned int>::value);
}

TEST_CASE("is_unsigned_v", "[traits]") {
    STATIC_REQUIRE(stipp::is_unsigned_v<u8>);
    STATIC_REQUIRE(stipp::is_unsigned_v<u16>);
    STATIC_REQUIRE(stipp::is_unsigned_v<u32>);
    STATIC_REQUIRE(stipp::is_unsigned_v<u64>);
    STATIC_REQUIRE(stipp::is_unsigned_v<usize>);
    STATIC_REQUIRE(!stipp::is_unsigned_v<i8>);
    STATIC_REQUIRE(!stipp::is_unsigned_v<i16>);
    STATIC_REQUIRE(!stipp::is_unsigned_v<i32>);
    STATIC_REQUIRE(!stipp::is_unsigned_v<i64>);
    STATIC_REQUIRE(!stipp::is_unsigned_v<isize>);

    STATIC_REQUIRE(!stipp::is_unsigned_v<int>);
    STATIC_REQUIRE(stipp::is_unsigned_v<unsigned int>);
}

TEST_CASE("unsigned_integral", "[traits]") {
    STATIC_REQUIRE(stipp::unsigned_integral<u8>);
    STATIC_REQUIRE(stipp::unsigned_integral<u16>);
    STATIC_REQUIRE(stipp::unsigned_integral<u32>);
    STATIC_REQUIRE(stipp::unsigned_integral<u64>);
    STATIC_REQUIRE(stipp::unsigned_integral<usize>);
    STATIC_REQUIRE(!stipp::unsigned_integral<i8>);
    STATIC_REQUIRE(!stipp::unsigned_integral<i16>);
    STATIC_REQUIRE(!stipp::unsigned_integral<i32>);
    STATIC_REQUIRE(!stipp::unsigned_integral<i64>);
    STATIC_REQUIRE(!stipp::unsigned_integral<isize>);

    STATIC_REQUIRE(!stipp::unsigned_integral<int>);
    STATIC_REQUIRE(stipp::unsigned_integral<unsigned int>);
}

TEST_CASE("make_signed", "[traits]") {
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_signed<u8>::type, i8>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_signed<u16>::type, i16>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_signed<u32>::type, i32>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_signed<u64>::type, i64>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_signed<usize>::type, isize>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_signed<i8>::type, i8>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_signed<i16>::type, i16>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_signed<i32>::type, i32>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_signed<i64>::type, i64>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_signed<isize>::type, isize>);

    STATIC_REQUIRE(std::is_same_v<typename stipp::make_signed<int>::type, int>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_signed<unsigned int>::type, int>);
}

TEST_CASE("make_signed_t", "[traits]") {
    STATIC_REQUIRE(std::is_same_v<stipp::make_signed_t<u8>, i8>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_signed_t<u16>, i16>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_signed_t<u32>, i32>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_signed_t<u64>, i64>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_signed_t<usize>, isize>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_signed_t<i8>, i8>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_signed_t<i16>, i16>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_signed_t<i32>, i32>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_signed_t<i64>, i64>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_signed_t<isize>, isize>);

    STATIC_REQUIRE(std::is_same_v<stipp::make_signed_t<int>, int>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_signed_t<unsigned int>, int>);
}

TEST_CASE("make_unsigned", "[traits]") {
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_unsigned<u8>::type, u8>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_unsigned<u16>::type, u16>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_unsigned<u32>::type, u32>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_unsigned<u64>::type, u64>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_unsigned<usize>::type, usize>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_unsigned<i8>::type, u8>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_unsigned<i16>::type, u16>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_unsigned<i32>::type, u32>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_unsigned<i64>::type, u64>);
    STATIC_REQUIRE(std::is_same_v<typename stipp::make_unsigned<isize>::type, usize>);

    STATIC_REQUIRE(std::is_same_v<typename stipp::make_unsigned<int>::type, unsigned int>);
    STATIC_REQUIRE(
        std::is_same_v<typename stipp::make_unsigned<unsigned int>::type, unsigned int>);
}

TEST_CASE("make_unsigned_t", "[traits]") {
    STATIC_REQUIRE(std::is_same_v<stipp::make_unsigned_t<u8>, u8>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_unsigned_t<u16>, u16>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_unsigned_t<u32>, u32>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_unsigned_t<u64>, u64>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_unsigned_t<usize>, usize>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_unsigned_t<i8>, u8>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_unsigned_t<i16>, u16>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_unsigned_t<i32>, u32>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_unsigned_t<i64>, u64>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_unsigned_t<isize>, usize>);

    STATIC_REQUIRE(std::is_same_v<stipp::make_unsigned_t<int>, unsigned int>);
    STATIC_REQUIRE(std::is_same_v<stipp::make_unsigned_t<unsigned int>, unsigned int>);
}

TEST_CASE("numeric_limits::max", "[limits]") {
    STATIC_REQUIRE(std::numeric_limits<u8>::max() ==
                   u8{std::numeric_limits<std::uint8_t>::max()});
    STATIC_REQUIRE(std::numeric_limits<u16>::max() ==
                   u16{std::numeric_limits<std::uint16_t>::max()});
    STATIC_REQUIRE(std::numeric_limits<u32>::max() ==
                   u32{std::numeric_limits<std::uint32_t>::max()});
    STATIC_REQUIRE(std::numeric_limits<u64>::max() ==
                   u64{std::numeric_limits<std::uint64_t>::max()});
    STATIC_REQUIRE(std::numeric_limits<usize>::max() ==
                   usize{std::numeric_limits<std::size_t>::max()});
    STATIC_REQUIRE(std::numeric_limits<i8>::max() ==
                   i8{std::numeric_limits<std::int8_t>::max()});
    STATIC_REQUIRE(std::numeric_limits<i16>::max() ==
                   i16{std::numeric_limits<std::int16_t>::max()});
    STATIC_REQUIRE(std::numeric_limits<i32>::max() ==
                   i32{std::numeric_limits<std::int32_t>::max()});
    STATIC_REQUIRE(std::numeric_limits<i64>::max() ==
                   i64{std::numeric_limits<std::int64_t>::max()});
    STATIC_REQUIRE(std::numeric_limits<isize>::max() ==
                   isize{std::numeric_limits<std::ptrdiff_t>::max()});
}

TEST_CASE("numeric_limits::min", "[limits]") {
    STATIC_REQUIRE(std::numeric_limits<u8>::min() ==
                   u8{std::numeric_limits<std::uint8_t>::min()});
    STATIC_REQUIRE(std::numeric_limits<u16>::min() ==
                   u16{std::numeric_limits<std::uint16_t>::min()});
    STATIC_REQUIRE(std::numeric_limits<u32>::min() ==
                   u32{std::numeric_limits<std::uint32_t>::min()});
    STATIC_REQUIRE(std::numeric_limits<u64>::min() ==
                   u64{std::numeric_limits<std::uint64_t>::min()});
    STATIC_REQUIRE(std::numeric_limits<usize>::min() ==
                   usize{std::numeric_limits<std::size_t>::min()});
    STATIC_REQUIRE(std::numeric_limits<i8>::min() ==
                   i8{std::numeric_limits<std::int8_t>::min()});
    STATIC_REQUIRE(std::numeric_limits<i16>::min() ==
                   i16{std::numeric_limits<std::int16_t>::min()});
    STATIC_REQUIRE(std::numeric_limits<i32>::min() ==
                   i32{std::numeric_limits<std::int32_t>::min()});
    STATIC_REQUIRE(std::numeric_limits<i64>::min() ==
                   i64{std::numeric_limits<std::int64_t>::min()});
    STATIC_REQUIRE(std::numeric_limits<isize>::min() ==
                   isize{std::numeric_limits<std::ptrdiff_t>::min()});
}

TEST_CASE("numeric_limits::lowest", "[limits]") {
    STATIC_REQUIRE(std::numeric_limits<u8>::lowest() ==
                   u8{std::numeric_limits<std::uint8_t>::lowest()});
    STATIC_REQUIRE(std::numeric_limits<u16>::lowest() ==
                   u16{std::numeric_limits<std::uint16_t>::lowest()});
    STATIC_REQUIRE(std::numeric_limits<u32>::lowest() ==
                   u32{std::numeric_limits<std::uint32_t>::lowest()});
    STATIC_REQUIRE(std::numeric_limits<u64>::lowest() ==
                   u64{std::numeric_limits<std::uint64_t>::lowest()});
    STATIC_REQUIRE(std::numeric_limits<usize>::lowest() ==
                   usize{std::numeric_limits<std::size_t>::lowest()});
    STATIC_REQUIRE(std::numeric_limits<i8>::lowest() ==
                   i8{std::numeric_limits<std::int8_t>::lowest()});
    STATIC_REQUIRE(std::numeric_limits<i16>::lowest() ==
                   i16{std::numeric_limits<std::int16_t>::lowest()});
    STATIC_REQUIRE(std::numeric_limits<i32>::lowest() ==
                   i32{std::numeric_limits<std::int32_t>::lowest()});
    STATIC_REQUIRE(std::numeric_limits<i64>::lowest() ==
                   i64{std::numeric_limits<std::int64_t>::lowest()});
    STATIC_REQUIRE(std::numeric_limits<isize>::lowest() ==
                   isize{std::numeric_limits<std::ptrdiff_t>::lowest()});
}

TEST_CASE("numeric_limits::digits", "[limits]") {
    STATIC_REQUIRE(std::numeric_limits<u8>::digits == 8);
    STATIC_REQUIRE(std::numeric_limits<u16>::digits == 16);
    STATIC_REQUIRE(std::numeric_limits<u32>::digits == 32);
    STATIC_REQUIRE(std::numeric_limits<u64>::digits == 64);
    STATIC_REQUIRE(std::numeric_limits<usize>::digits ==
                   std::numeric_limits<std::size_t>::digits);
    STATIC_REQUIRE(std::numeric_limits<i8>::digits == 7);
    STATIC_REQUIRE(std::numeric_limits<i16>::digits == 15);
    STATIC_REQUIRE(std::numeric_limits<i32>::digits == 31);
    STATIC_REQUIRE(std::numeric_limits<i64>::digits == 63);
    STATIC_REQUIRE(std::numeric_limits<isize>::digits ==
                   std::numeric_limits<std::ptrdiff_t>::digits);
}
