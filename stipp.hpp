/* Copyright (c) 2024 Jack Bernard <jack.a.bernard.jr@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef STIPP_HPP
#define STIPP_HPP

#include <compare>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <type_traits>

#if __has_include(<format>)
#include <format>
#endif

// IWYU pragma: no_include <variant>
// IWYU pragma: no_forward_declare std::formatter
// IWYU pragma: no_forward_declare std::hash
// IWYU pragma: no_forward_declare std::numeric_limits
// IWYU pragma: no_forward_declare std::is_integral
// IWYU pragma: no_forward_declare std::is_arithmetic
// IWYU pragma: no_forward_declare std::is_signed
// IWYU pragma: no_forward_declare std::is_unsigned
// IWYU pragma: no_forward_declare std::make_signed
// IWYU pragma: no_forward_declare std::make_unsigned
// IWYU pragma: no_forward_declare stipp::is_stipp_int
// IWYU pragma: no_forward_declare stipp::is_integral
// IWYU pragma: no_forward_declare stipp::is_arithmetic
// IWYU pragma: no_forward_declare stipp::is_signed
// IWYU pragma: no_forward_declare stipp::is_unsigned

// Uncomment or define this macro to implement std type traits
// such as std::is_integral. Be warned: The standard specifies
// that this has undefined behavior. As such, it is not enabled
// by default.
// #define STIPP_UB_TRAITS

#define STIPP_U8_MIN (::stipp::u8{0})
#define STIPP_U16_MIN (::stipp::u16{0})
#define STIPP_U32_MIN (::stipp::u32{0})
#define STIPP_U64_MIN (::stipp::u64{0})
#define STIPP_USIZE_MIN (::stipp::usize{0})
#define STIPP_I8_MIN (::stipp::i8{INT8_MIN})
#define STIPP_I16_MIN (::stipp::i16{INT16_MIN})
#define STIPP_I32_MIN (::stipp::i32{INT32_MIN})
#define STIPP_I64_MIN (::stipp::i64{INT64_MIN})
#define STIPP_ISIZE_MIN (::stipp::isize{PTRDIFF_MIN})

#define STIPP_U8_MAX (::stipp::u8{UINT8_MAX})
#define STIPP_U16_MAX (::stipp::u16{UINT16_MAX})
#define STIPP_U32_MAX (::stipp::u32{UINT32_MAX})
#define STIPP_U64_MAX (::stipp::u64{UINT64_MAX})
#define STIPP_USIZE_MAX (::stipp::usize{SIZE_MAX})
#define STIPP_I8_MAX (::stipp::i8{INT8_MAX})
#define STIPP_I16_MAX (::stipp::i16{INT16_MAX})
#define STIPP_I32_MAX (::stipp::i32{INT32_MAX})
#define STIPP_I64_MAX (::stipp::i64{INT64_MAX})
#define STIPP_ISIZE_MAX (::stipp::isize{PTRDIFF_MAX})

namespace stipp {

enum class u8 : std::uint8_t {};
enum class u16 : std::uint16_t {};
enum class u32 : std::uint32_t {};
enum class u64 : std::uint64_t {};
enum class usize : std::size_t {};
enum class i8 : std::int8_t {};
enum class i16 : std::int16_t {};
enum class i32 : std::int32_t {};
enum class i64 : std::int64_t {};
enum class isize : std::ptrdiff_t {};

namespace types {

using stipp::i16;
using stipp::i32;
using stipp::i64;
using stipp::i8;
using stipp::isize;
using stipp::u16;
using stipp::u32;
using stipp::u64;
using stipp::u8;
using stipp::usize;

} // namespace types

namespace literals {

consteval u8 operator""_u8(unsigned long long int val) {
    if (val >
        static_cast<unsigned long long int>((std::numeric_limits<std::uint8_t>::max)())) {
        throw std::invalid_argument("u8 literal is too large and would overflow");
    }
    return static_cast<u8>(static_cast<std::uint8_t>(val));
}

consteval u8 operator""_U8(unsigned long long int val) { return operator""_u8(val); }

consteval u16 operator""_u16(unsigned long long int val) {
    if (val >
        static_cast<unsigned long long int>((std::numeric_limits<std::uint16_t>::max)())) {
        throw std::invalid_argument("u16 literal is too large and would overflow");
    }
    return static_cast<u16>(static_cast<std::uint16_t>(val));
}

consteval u16 operator""_U16(unsigned long long int val) { return operator""_u16(val); }

consteval u32 operator""_u32(unsigned long long int val) {
    if (val >
        static_cast<unsigned long long int>((std::numeric_limits<std::uint32_t>::max)())) {
        throw std::invalid_argument("u32 literal is too large and would overflow");
    }
    return static_cast<u32>(static_cast<std::uint32_t>(val));
}

consteval u32 operator""_U32(unsigned long long int val) { return operator""_u32(val); }

consteval u64 operator""_u64(unsigned long long int val) {
    if (val >
        static_cast<unsigned long long int>((std::numeric_limits<std::uint64_t>::max)())) {
        throw std::invalid_argument("u64 literal is too large and would overflow");
    }
    return static_cast<u64>(static_cast<std::uint64_t>(val));
}

consteval u64 operator""_U64(unsigned long long int val) { return operator""_u64(val); }

consteval usize operator""_uz(unsigned long long int val) {
    if (val >
        static_cast<unsigned long long int>((std::numeric_limits<std::size_t>::max)())) {
        throw std::invalid_argument("usize literal is too large and would overflow");
    }
    return static_cast<usize>(static_cast<std::size_t>(val));
}

consteval usize operator""_UZ(unsigned long long int val) { return operator""_uz(val); }

consteval i8 operator""_i8(unsigned long long int val) {
    if (val >
        static_cast<unsigned long long int>((std::numeric_limits<std::int8_t>::max)())) {
        throw std::invalid_argument("i8 literal is too large and would overflow");
    }
    return static_cast<i8>(static_cast<std::int8_t>(val));
}

consteval i8 operator""_I8(unsigned long long int val) { return operator""_i8(val); }

consteval i16 operator""_i16(unsigned long long int val) {
    if (val >
        static_cast<unsigned long long int>((std::numeric_limits<std::int16_t>::max)())) {
        throw std::invalid_argument("i16 literal is too large and would overflow");
    }
    return static_cast<i16>(static_cast<std::int16_t>(val));
}

consteval i16 operator""_I16(unsigned long long int val) { return operator""_i16(val); }

consteval i32 operator""_i32(unsigned long long int val) {
    if (val >
        static_cast<unsigned long long int>((std::numeric_limits<std::int32_t>::max)())) {
        throw std::invalid_argument("i32 literal is too large and would overflow");
    }
    return static_cast<i32>(static_cast<std::int32_t>(val));
}

consteval i32 operator""_I32(unsigned long long int val) { return operator""_i32(val); }

consteval i64 operator""_i64(unsigned long long int val) {
    if (val >
        static_cast<unsigned long long int>((std::numeric_limits<std::int64_t>::max)())) {
        throw std::invalid_argument("i64 literal is too large and would overflow");
    }
    return static_cast<i64>(static_cast<std::int64_t>(val));
}

consteval i64 operator""_I64(unsigned long long int val) { return operator""_i64(val); }

consteval isize operator""_iz(unsigned long long int val) {
    if (val >
        static_cast<unsigned long long int>((std::numeric_limits<std::ptrdiff_t>::max)())) {
        throw std::invalid_argument("isize literal is too large and would overflow");
    }
    return static_cast<isize>(static_cast<std::ptrdiff_t>(val));
}

consteval isize operator""_IZ(unsigned long long int val) { return operator""_iz(val); }

} // namespace literals

namespace detail {

template <typename T>
struct is_shift_width : std::false_type {};

template <>
struct is_shift_width<u8> : std::true_type {};

template <>
struct is_shift_width<u16> : std::true_type {};

template <>
struct is_shift_width<u32> : std::true_type {};

template <>
struct is_shift_width<u64> : std::true_type {};

template <>
struct is_shift_width<usize> : std::true_type {};

template <>
struct is_shift_width<i8> : std::true_type {};

template <>
struct is_shift_width<i16> : std::true_type {};

template <>
struct is_shift_width<i32> : std::true_type {};

template <>
struct is_shift_width<i64> : std::true_type {};

template <>
struct is_shift_width<isize> : std::true_type {};

template <>
struct is_shift_width<char> : std::true_type {};

template <>
struct is_shift_width<unsigned char> : std::true_type {};

template <>
struct is_shift_width<signed char> : std::true_type {};

template <>
struct is_shift_width<short int> : std::true_type {};

template <>
struct is_shift_width<unsigned short int> : std::true_type {};

template <>
struct is_shift_width<int> : std::true_type {};

template <>
struct is_shift_width<unsigned int> : std::true_type {};

template <>
struct is_shift_width<long int> : std::true_type {};

template <>
struct is_shift_width<unsigned long int> : std::true_type {};

template <>
struct is_shift_width<long long int> : std::true_type {};

template <>
struct is_shift_width<unsigned long long int> : std::true_type {};

template <typename T>
static inline constexpr bool is_shift_width_v = is_shift_width<T>::value;

template <typename T>
concept shift_width = is_shift_width_v<T>;

template <typename T>
struct repr {
    using type = T;
};

template <>
struct repr<u8> : repr<std::uint8_t> {};

template <>
struct repr<u16> : repr<std::uint16_t> {};

template <>
struct repr<u32> : repr<std::uint32_t> {};

template <>
struct repr<u64> : repr<std::uint64_t> {};

template <>
struct repr<usize> : repr<std::size_t> {};

template <>
struct repr<i8> : repr<std::int8_t> {};

template <>
struct repr<i16> : repr<std::int16_t> {};

template <>
struct repr<i32> : repr<std::int32_t> {};

template <>
struct repr<i64> : repr<std::int64_t> {};

template <>
struct repr<isize> : repr<std::ptrdiff_t> {};

template <typename T>
using repr_t = typename repr<T>::type;

template <typename T>
constexpr repr_t<T> to_repr(T x) noexcept {
    return static_cast<repr_t<T>>(x);
}

} // namespace detail

template <typename T>
struct is_stipp_int : std::false_type {};

template <typename T>
inline constexpr bool is_stipp_int_v = is_stipp_int<T>::value;

template <typename T>
concept stipp_int = is_stipp_int_v<T>;

template <typename T>
struct is_integral : std::is_integral<T> {};

template <typename T>
inline constexpr bool is_integral_v = is_integral<T>::value;

template <typename T>
concept integral = is_integral_v<T>;

template <typename T>
struct is_arithmetic : std::is_arithmetic<T> {};

template <typename T>
inline constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

template <typename T>
concept arithmetic = is_arithmetic_v<T>;

template <typename T>
struct is_signed : std::is_signed<T> {};

template <typename T>
inline constexpr bool is_signed_v = is_signed<T>::value;

template <typename T>
concept signed_integral = is_integral_v<T> && is_signed_v<T>;

template <typename T>
struct is_unsigned : std::is_unsigned<T> {};

template <typename T>
inline constexpr bool is_unsigned_v = is_unsigned<T>::value;

template <typename T>
concept unsigned_integral = is_integral_v<T> && is_unsigned_v<T>;

template <typename T>
struct make_signed : std::make_signed<T> {};

template <typename T>
using make_signed_t = typename make_signed<T>::type;

template <typename T>
struct make_unsigned : std::make_unsigned<T> {};

template <typename T>
using make_unsigned_t = typename make_unsigned<T>::type;

#define STIPP_DEF_TRAITS(type)                                   \
    template <>                                                  \
    struct is_stipp_int<type> : std::true_type {};               \
                                                                 \
    template <>                                                  \
    struct is_integral<type> : std::true_type {};                \
                                                                 \
    template <>                                                  \
    struct is_arithmetic<type> : std::true_type {};              \
                                                                 \
    template <>                                                  \
    struct is_signed<type> : is_signed<detail::repr_t<type>> {}; \
                                                                 \
    template <>                                                  \
    struct is_unsigned<type> : is_unsigned<detail::repr_t<type>> {};

STIPP_DEF_TRAITS(u8)
STIPP_DEF_TRAITS(u16)
STIPP_DEF_TRAITS(u32)
STIPP_DEF_TRAITS(u64)
STIPP_DEF_TRAITS(usize)
STIPP_DEF_TRAITS(i8)
STIPP_DEF_TRAITS(i16)
STIPP_DEF_TRAITS(i32)
STIPP_DEF_TRAITS(i64)
STIPP_DEF_TRAITS(isize)

template <>
struct make_signed<u8> {
    using type = i8;
};

template <>
struct make_signed<u16> {
    using type = i16;
};

template <>
struct make_signed<u32> {
    using type = i32;
};

template <>
struct make_signed<u64> {
    using type = i64;
};

template <>
struct make_signed<usize> {
    using type = isize;
};

template <>
struct make_signed<i8> {
    using type = i8;
};

template <>
struct make_signed<i16> {
    using type = i16;
};

template <>
struct make_signed<i32> {
    using type = i32;
};

template <>
struct make_signed<i64> {
    using type = i64;
};

template <>
struct make_signed<isize> {
    using type = isize;
};

template <>
struct make_unsigned<u8> {
    using type = u8;
};

template <>
struct make_unsigned<u16> {
    using type = u16;
};

template <>
struct make_unsigned<u32> {
    using type = u32;
};

template <>
struct make_unsigned<u64> {
    using type = u64;
};

template <>
struct make_unsigned<usize> {
    using type = usize;
};

template <>
struct make_unsigned<i8> {
    using type = u8;
};

template <>
struct make_unsigned<i16> {
    using type = u16;
};

template <>
struct make_unsigned<i32> {
    using type = u32;
};

template <>
struct make_unsigned<i64> {
    using type = u64;
};

template <>
struct make_unsigned<isize> {
    using type = usize;
};

#undef STIPP_DEF_TRAITS

#define STIPP_DEF_OPS(type)                                                    \
    constexpr type operator+(type x) noexcept { return x; }                    \
                                                                               \
    constexpr type operator-(type x) noexcept {                                \
        return static_cast<type>(detail::to_repr(-detail::to_repr(x)));        \
    }                                                                          \
                                                                               \
    constexpr type operator~(type x) noexcept {                                \
        return static_cast<type>(detail::to_repr(~detail::to_repr(x)));        \
    }                                                                          \
                                                                               \
    constexpr type& operator++(type& x) noexcept {                             \
        x = static_cast<type>(detail::to_repr(x) + 1);                         \
        return x;                                                              \
    }                                                                          \
                                                                               \
    constexpr type operator++(type& x, int) noexcept {                         \
        const type ret = x;                                                    \
        ++x;                                                                   \
        return ret;                                                            \
    }                                                                          \
                                                                               \
    constexpr type operator--(type& x) noexcept {                              \
        x = static_cast<type>(detail::to_repr(x) - 1);                         \
        return x;                                                              \
    }                                                                          \
                                                                               \
    constexpr type operator--(type& x, int) noexcept {                         \
        const type ret = x;                                                    \
        --x;                                                                   \
        return ret;                                                            \
    }                                                                          \
                                                                               \
    constexpr type operator+=(type& lhs, type rhs) noexcept {                  \
        lhs = static_cast<type>(detail::to_repr(lhs) + detail::to_repr(rhs));  \
        return lhs;                                                            \
    }                                                                          \
                                                                               \
    constexpr type operator-=(type& lhs, type rhs) noexcept {                  \
        lhs = static_cast<type>(detail::to_repr(lhs) - detail::to_repr(rhs));  \
        return lhs;                                                            \
    }                                                                          \
                                                                               \
    constexpr type operator*=(type& lhs, type rhs) noexcept {                  \
        lhs = static_cast<type>(detail::to_repr(lhs) * detail::to_repr(rhs));  \
        return lhs;                                                            \
    }                                                                          \
                                                                               \
    constexpr type operator/=(type& lhs, type rhs) noexcept {                  \
        lhs = static_cast<type>(detail::to_repr(lhs) / detail::to_repr(rhs));  \
        return lhs;                                                            \
    }                                                                          \
                                                                               \
    constexpr type operator%=(type& lhs, type rhs) noexcept {                  \
        lhs = static_cast<type>(detail::to_repr(lhs) % detail::to_repr(rhs));  \
        return lhs;                                                            \
    }                                                                          \
                                                                               \
    constexpr type operator&=(type& lhs, type rhs) noexcept {                  \
        lhs = static_cast<type>(detail::to_repr(lhs) & detail::to_repr(rhs));  \
        return lhs;                                                            \
    }                                                                          \
                                                                               \
    constexpr type operator|=(type& lhs, type rhs) noexcept {                  \
        lhs = static_cast<type>(detail::to_repr(lhs) | detail::to_repr(rhs));  \
        return lhs;                                                            \
    }                                                                          \
                                                                               \
    constexpr type operator^=(type& lhs, type rhs) noexcept {                  \
        lhs = static_cast<type>(detail::to_repr(lhs) ^ detail::to_repr(rhs));  \
        return lhs;                                                            \
    }                                                                          \
                                                                               \
    template <detail::shift_width T>                                           \
    constexpr type& operator<<=(type& lhs, T rhs) noexcept {                   \
        lhs = static_cast<type>(detail::to_repr(lhs)                           \
                                << static_cast<detail::repr_t<T>>(rhs));       \
        return lhs;                                                            \
    }                                                                          \
                                                                               \
    template <detail::shift_width T>                                           \
    constexpr type& operator>>=(type& lhs, T rhs) noexcept {                   \
        lhs = static_cast<type>(detail::to_repr(lhs) >>                        \
                                static_cast<detail::repr_t<T>>(rhs));          \
        return lhs;                                                            \
    }                                                                          \
                                                                               \
    constexpr type operator+(type lhs, type rhs) noexcept {                    \
        return static_cast<type>(detail::to_repr(lhs) + detail::to_repr(rhs)); \
    }                                                                          \
                                                                               \
    constexpr type operator-(type lhs, type rhs) noexcept {                    \
        return static_cast<type>(detail::to_repr(lhs) - detail::to_repr(rhs)); \
    }                                                                          \
                                                                               \
    constexpr type operator*(type lhs, type rhs) noexcept {                    \
        return static_cast<type>(detail::to_repr(lhs) * detail::to_repr(rhs)); \
    }                                                                          \
                                                                               \
    constexpr type operator/(type lhs, type rhs) noexcept {                    \
        return static_cast<type>(detail::to_repr(lhs) / detail::to_repr(rhs)); \
    }                                                                          \
                                                                               \
    constexpr type operator%(type lhs, type rhs) noexcept {                    \
        return static_cast<type>(detail::to_repr(lhs) % detail::to_repr(rhs)); \
    }                                                                          \
                                                                               \
    constexpr type operator&(type lhs, type rhs) noexcept {                    \
        return static_cast<type>(detail::to_repr(lhs) & detail::to_repr(rhs)); \
    }                                                                          \
                                                                               \
    constexpr type operator|(type lhs, type rhs) noexcept {                    \
        return static_cast<type>(detail::to_repr(lhs) | detail::to_repr(rhs)); \
    }                                                                          \
                                                                               \
    constexpr type operator^(type lhs, type rhs) noexcept {                    \
        return static_cast<type>(detail::to_repr(lhs) ^ detail::to_repr(rhs)); \
    }                                                                          \
                                                                               \
    template <detail::shift_width T>                                           \
    constexpr type operator<<(type lhs, T rhs) noexcept {                      \
        return static_cast<type>(detail::to_repr(lhs)                          \
                                 << static_cast<detail::repr_t<T>>(rhs));      \
    }                                                                          \
                                                                               \
    template <detail::shift_width T>                                           \
    constexpr type operator>>(type lhs, T rhs) noexcept {                      \
        return static_cast<type>(detail::to_repr(lhs) >>                       \
                                 static_cast<detail::repr_t<T>>(rhs));         \
    }                                                                          \
                                                                               \
    constexpr bool operator==(type lhs, type rhs) noexcept {                   \
        return detail::to_repr(lhs) == detail::to_repr(rhs);                   \
    }                                                                          \
                                                                               \
    constexpr std::strong_ordering operator<=>(type lhs, type rhs) noexcept {  \
        return detail::to_repr(lhs) <=> detail::to_repr(rhs);                  \
    }

STIPP_DEF_OPS(u8)
STIPP_DEF_OPS(u16)
STIPP_DEF_OPS(u32)
STIPP_DEF_OPS(u64)
STIPP_DEF_OPS(usize)
STIPP_DEF_OPS(i8)
STIPP_DEF_OPS(i16)
STIPP_DEF_OPS(i32)
STIPP_DEF_OPS(i64)
STIPP_DEF_OPS(isize)

#undef STIPP_DEF_OPS

#define STIPP_DEF_IO(type)                                       \
    inline std::ostream& operator<<(std::ostream& os, type x) {  \
        os << detail::to_repr(x);                                \
        return os;                                               \
    }                                                            \
                                                                 \
    inline std::istream& operator>>(std::istream& is, type& x) { \
        detail::repr_t<type> tmp{};                              \
        is >> tmp;                                               \
        x = static_cast<type>(tmp);                              \
        return is;                                               \
    }

STIPP_DEF_IO(u16)
STIPP_DEF_IO(u32)
STIPP_DEF_IO(u64)
STIPP_DEF_IO(usize)
STIPP_DEF_IO(i16)
STIPP_DEF_IO(i32)
STIPP_DEF_IO(i64)
STIPP_DEF_IO(isize)

#undef STIPP_DEF_IO

inline std::ostream& operator<<(std::ostream& os, u8 x) {
    os << static_cast<int>(x);
    return os;
}

inline std::ostream& operator<<(std::ostream& os, i8 x) {
    os << static_cast<int>(x);
    return os;
}

inline std::istream& operator>>(std::istream& is, u8& x) {
    unsigned int tmp{};
    is >> tmp;
    if (tmp > static_cast<unsigned int>((std::numeric_limits<std::uint8_t>::max)())) {
        x = static_cast<u8>((std::numeric_limits<std::uint8_t>::max)());
    } else {
        x = static_cast<u8>(static_cast<std::uint8_t>(tmp));
    }
    return is;
}

inline std::istream& operator>>(std::istream& is, i8& x) {
    int tmp{};
    is >> tmp;
    if (tmp < static_cast<int>((std::numeric_limits<std::int8_t>::min)())) {
        x = static_cast<i8>((std::numeric_limits<std::int8_t>::min)());
    } else if (tmp > static_cast<int>((std::numeric_limits<std::int8_t>::max)())) {
        x = static_cast<i8>((std::numeric_limits<std::int8_t>::max)());
    } else {
        x = static_cast<i8>(static_cast<std::int8_t>(tmp));
    }
    return is;
}

} // namespace stipp

#define STIPP_DEF_STD(type)                                                                \
    template <>                                                                            \
    struct std::hash<stipp::type> : std::hash<stipp::detail::repr_t<stipp::type>> {        \
        std::size_t operator()(stipp::type x) const noexcept {                             \
            return std::hash<stipp::detail::repr_t<stipp::type>>::operator()(              \
                static_cast<stipp::detail::repr_t<stipp::type>>(x));                       \
        }                                                                                  \
    };                                                                                     \
                                                                                           \
    template <>                                                                            \
    class std::numeric_limits<stipp::type>                                                 \
        : public std::numeric_limits<stipp::detail::repr_t<stipp::type>> {                 \
      public:                                                                              \
        static constexpr stipp::type max /**/ () noexcept {                                \
            return static_cast<stipp::type>(                                               \
                (std::numeric_limits<stipp::detail::repr_t<stipp::type>>::max)());         \
        }                                                                                  \
        static constexpr stipp::type min /**/ () noexcept {                                \
            return static_cast<stipp::type>(                                               \
                (std::numeric_limits<stipp::detail::repr_t<stipp::type>>::min)());         \
        }                                                                                  \
        static constexpr stipp::type lowest /**/ () noexcept {                             \
            return static_cast<stipp::type>(                                               \
                (std::numeric_limits<stipp::detail::repr_t<stipp::type>>::lowest)());      \
        }                                                                                  \
        static constexpr stipp::type epsilon /**/ () noexcept {                            \
            return static_cast<stipp::type>(                                               \
                (std::numeric_limits<stipp::detail::repr_t<stipp::type>>::epsilon)());     \
        }                                                                                  \
        static constexpr stipp::type round_error /**/ () noexcept {                        \
            return static_cast<stipp::type>(                                               \
                (std::numeric_limits<stipp::detail::repr_t<stipp::type>>::round_error)()); \
        }                                                                                  \
        static constexpr stipp::type infinity /**/ () noexcept {                           \
            return static_cast<stipp::type>(                                               \
                (std::numeric_limits<stipp::detail::repr_t<stipp::type>>::infinity)());    \
        }                                                                                  \
        static constexpr stipp::type quiet_NaN /**/ () noexcept {                          \
            return static_cast<stipp::type>(                                               \
                (std::numeric_limits<stipp::detail::repr_t<stipp::type>>::quiet_NaN)());   \
        }                                                                                  \
        static constexpr stipp::type signaling_NaN /**/ () noexcept {                      \
            return static_cast<stipp::type>(                                               \
                (std::numeric_limits<                                                      \
                    stipp::detail::repr_t<stipp::type>>::signaling_NaN)());                \
        }                                                                                  \
        static constexpr stipp::type denorm_min /**/ () noexcept {                         \
            return static_cast<stipp::type>(                                               \
                (std::numeric_limits<stipp::detail::repr_t<stipp::type>>::denorm_min)());  \
        }                                                                                  \
    };

STIPP_DEF_STD(u8)
STIPP_DEF_STD(u16)
STIPP_DEF_STD(u32)
STIPP_DEF_STD(u64)
STIPP_DEF_STD(usize)
STIPP_DEF_STD(i8)
STIPP_DEF_STD(i16)
STIPP_DEF_STD(i32)
STIPP_DEF_STD(i64)
STIPP_DEF_STD(isize)

#undef STIPP_DEF_STD

#if __has_include(<format>)

#define STIPP_DEF_FMT(type)                                                    \
    template <>                                                                \
    struct std::formatter<stipp::type>                                         \
        : std::formatter<stipp::detail::repr_t<stipp::type>> {                 \
        template <typename FmtCtx>                                             \
        constexpr auto format(stipp::type x, FmtCtx& ctx) const {              \
            return std::formatter<stipp::detail::repr_t<stipp::type>>::format( \
                static_cast<stipp::detail::repr_t<stipp::type>>(x), ctx);      \
        }                                                                      \
    };

STIPP_DEF_FMT(u8)
STIPP_DEF_FMT(u16)
STIPP_DEF_FMT(u32)
STIPP_DEF_FMT(u64)
STIPP_DEF_FMT(usize)
STIPP_DEF_FMT(i8)
STIPP_DEF_FMT(i16)
STIPP_DEF_FMT(i32)
STIPP_DEF_FMT(i64)
STIPP_DEF_FMT(isize)

#undef STIPP_DEF_FMT

#endif

#ifdef STIPP_UB_TRAITS

#define STIPP_DEF_TRAITS(type)                                                 \
    template <>                                                                \
    struct std::is_integral<stipp::type> : std::true_type {};                  \
                                                                               \
    template <>                                                                \
    struct std::is_arithmetic<stipp::type> : std::true_type {};                \
                                                                               \
    template <>                                                                \
    struct std::is_signed<stipp::type> : stipp::is_signed<stipp::type> {};     \
                                                                               \
    template <>                                                                \
    struct std::is_unsigned<stipp::type> : stipp::is_unsigned<stipp::type> {}; \
                                                                               \
    template <>                                                                \
    struct std::make_signed<stipp::type> : stipp::make_signed<stipp::type> {}; \
                                                                               \
    template <>                                                                \
    struct std::make_unsigned<stipp::type> : stipp::make_unsigned<stipp::type> {};

STIPP_DEF_TRAITS(u8)
STIPP_DEF_TRAITS(u16)
STIPP_DEF_TRAITS(u32)
STIPP_DEF_TRAITS(u64)
STIPP_DEF_TRAITS(usize)
STIPP_DEF_TRAITS(i8)
STIPP_DEF_TRAITS(i16)
STIPP_DEF_TRAITS(i32)
STIPP_DEF_TRAITS(i64)
STIPP_DEF_TRAITS(isize)

#undef STIPP_DEF_TRAITS

#endif

#endif
