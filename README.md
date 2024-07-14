# `stipp`: Strongly Typed Integers for C++

`stipp` is a single-header C++20 library that implements alternative integer
types. These integer types are scalar types that have the same representation
and operators as built-in integer types, but do not have implicit conversions
or promotion semantics. They are distinct types from the built-in integer
types, but they can be `static_cast`, `reinterpret_cast`, or `std::bit_cast`
to and from built-in integer types.

This library aims to prevent common and easy-to-miss bugs that arise from the
implicit conversions and integer promotion that C++ inherits from C. Any
conversion from one `stipp` integer type to another must be explicit; otherwise
operations always return the same type as was input.

For example:
```cpp
// built-in
signed char val_char = 10;
auto res_char = val_char + val_char;

// `res_char` is of type `int` instead of `signed char`
assert(std::is_same_v<decltype(res_char), int>);
```

```cpp
// stipp

// imports i8 and all other stipp integer types
using namespace stipp::types;
//using stipp::i8; // to import `i8` only

// allows usage of stipp integer literals, such as `10_i8`
using namespace stipp::literals;

i8 val_i8 = 10_i8;
auto res_i8 = val_i8 + val_i8;

// `res_i8` is of type `i8`
assert(std::is_same_v<decltype(res_i8), i8>);
```

## Types
| type    | signedness | bit width | built-in equivalent | literal suffix |
|---------|------------|-----------|---------------------|----------------|
| `u8`    | unsigned   | 8         | `std::uint8_t`      | `_u8`          |
| `u16`   | unsigned   | 16        | `std::uint16_t`     | `_u16`         |
| `u32`   | unsigned   | 32        | `std::uint32_t`     | `_u32`         |
| `u64`   | usngiend   | 64        | `std::uint64_t`     | `_u64`         |
| `usize` | unsigned   | arch      | `std::size_t`       | `_uz`          |
| `i8`    | signed     | 8         | `std::int8_t`       | `_i8`          |
| `i16`   | signed     | 16        | `std::int16_t`      | `_i16`         |
| `i32`   | signed     | 32        | `std::int32_t`      | `_i32`         |
| `i64`   | signed     | 64        | `std::int64_t`      | `_i64`         |
| `isize` | signed     | arch      | `std::ptrdiff_t`    | `_iz`          |

Note that `usize` and `isize` are distinct types and will never implicitly convert
to or from another `stipp` integer type. This helps prevents architecture dependent
bugs.

## Limitations

1. Due to being distinct types, `stipp` integers can not be transparently used with
the STL or other libraries that are not aware of `stipp`. Such usage will involve
frequent casting to and from built-in integer types, which can easily become an
entrypoint for conversion bugs.

2. By default, STL type traits (and related concepts) such as `std::is_integeral`,
`std::is_arithmetic`, `std::is_signed`, etc do not work with `stipp` integer types.
The `STIPP_UB_TRAITS` macro can be defined to override these traits to work with
`stipp` integer types, but the standard specifies that this has undefined behavior.
As such, this feature may not work as expected under all compilers and is gated
behind this feature macro. Note that `stipp` provides it's own version of these
traits in the `stipp` namespace that will work as expected.

## How It Works
`stipp` takes inspiration from `std::byte`, which is defined as:
`enum class byte : unsigned char {};`. Each `stipp` integer type is an `enum class`
with a representation type that matches the signedness and bit width it declares.
For example `i32` is defined as `enum class i32 : std::int32_t {};`.

From there, all integral operators are implemented on these types such that no
mixing of integral types is permitted. For example, the addition operator on `i32`
has the signature `constexpr i32 operator+(i32, i32) noexcept;`.

Note that bit shift operators (e.g. `<<`, `<<=`) allow the right-hand argument to
vary in type. The right-hand argument can be of any `stipp` integer type, or any
built-in "true" integer type (meaning, not `bool`, `char8_t`, or multibyte
character types).

## Misc. Features
* `std::numeric_limits` is specialized for each `stipp` integer type
* Each `stipp` integer type has an `operator<<` overload for formatting to `std::ostream`
  * Unlike `char`, `stipp::u8` and `stipp::i8` format as an integer instead of a character
* Each `stipp` integer type has an `operator>>` overload for parsing from `std::istream`
* `std::formatter` is specialized for each `stipp` integer type
  * Presence of the `<format>` header is detected in order to support compilers with
    only partial C++20 support
* `std::hash` is specialized for each `stipp` integer type
* Various type traits are provided in the `stipp` namespace
  * `template <typename T> struct is_stipp_int;`
    * `template <typename T> inline constexpr bool is_stipp_int_v;`
    * `template <typename T> concept stipp_int;`
  * `template <typename T> struct is_integral;`
    * `template <typename T> inline constexpr bool is_integral_v;`
    * `template <typename T> concept integral;`
  * `template <typename T> struct is_arithmetic;`
    * `template <typename T> inline constexpr bool is_arithmetic_v;`
    * `template <typename T> concept arithmetic;`
  * `template <typename T> struct is_signed;`
    * `template <typename T> inline constexpr bool is_signed_v;`
    * `template <typename T> concept signed_integral;`
  * `template <typename T> struct is_unsigned;`
    * `template <typename T> inline constexpr bool is_unsigned_v;`
    * `template <typename T> concept unsigned_integral;`
  * `template <typename T> struct make_signed;`
    * `template <typename T> using make_signed_t;`
  * `template <typename T> struct make_unsigned;`
    * `template <typename T> using make_unsigned_t;`
* For all the type traits above, STL traits can also be made to support `stipp` integers
  * Requires defining the `STIPP_UB_TRAITS` macro. See [Limitations](#limitations).
