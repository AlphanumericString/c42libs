/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comon.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:02:42 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/12 16:02:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// C++17 features detection and portability macros
// nullptr, noexcept, constexpr, deprecated, unused, inline, fallthrough,
// nodiscard, likely, unlikely, static_assert
//

// abort
#include <cstdlib>

// --
// macro
// --
// [math]
#define MIN(a, b)			   ((a) < (b) ? (a) : (b))
#define MAX(a, b)			   ((a) > (b) ? (a) : (b))
#define CLAMP(x, lower, upper) (MIN((upper), MAX((x), (lower))))
// [utils]
#define _STRINGIFY(x)		   #x
#define STRINGIFY(x)		   _STRINGIFY(x)
#define ARRAYSIZE(arr)		   (sizeof(arr) / sizeof((arr)[0]))
#define SWAP(a, b)                                                             \
	do {                                                                       \
		auto tmp = (a);                                                        \
		(a) = (b);                                                             \
		(b) = tmp;                                                             \
	} while (0)

// Likely and unlikely branch prediction hints
#ifndef LIKELY
#	if defined(__cplusplus) && __cplusplus >= 201103L
#		define LIKELY(x)	__builtin_expect(!!(x), 1)
#		define UNLIKELY(x) __builtin_expect(!!(x), 0)
#	else
#		define LIKELY(x)	(x)
#		define UNLIKELY(x) (x)
#	endif
#endif

// static_assert for compile-time assertions
// tldr: if ok array of size 1 is mapped to char, else to char[-1] which is
// invalid
#ifndef STATIC_ASSERT
#	if defined(__cplusplus) && __cplusplus >= 201103L
#		define STATIC_ASSERT(cond, msg) static_assert(cond, msg)
#	else
#		define STATIC_ASSERT(cond, msg)                                       \
			typedef char static_assertion_fail[(cond) ? 1 : -1] UNUSED
#	endif
#endif

#define UNUSED_PARAM(x) (void)(x)
#define DBG_DUMP(X)                                                            \
	do {                                                                       \
		std::cerr << "[dbg] " << STRINGIFY(X) << "\t=\t" << X << std::endl;    \
	} while (0)

// --
// keywords
// --

// nullptr keyword
#ifndef NULLPTR
#	if defined(__cplusplus) && __cplusplus >= 201103L
#		define NULLPTR nullptr
#	else
#		define NULLPTR NULL
#	endif
#endif

// noexcept keyword
#ifndef NOEXCEPT
#	if defined(__cplusplus) && __cplusplus >= 201103L
#		define NOEXCEPT noexcept
#	else
#		define NOEXCEPT throw()
#	endif
#endif

// Compile-time constant expression
#ifndef CONSTEXPR
#	if defined(__cplusplus) && __cplusplus >= 201103L
#		define CONSTEXPR constexpr
#	else
#		define CONSTEXPR
#	endif
#endif

// --
// attributes
// --

// Performance hint for the compiler to try to inline the function
// when possible
#ifndef INLINE
#	if defined(__cplusplus) && __cplusplus >= 201103L
#		define INLINE inline
#	else
#		define INLINE __attribute__((hot))
#	endif
#endif

// Marking deprecated functions or variables
#ifndef DEPRECATED
#	if defined(__cplusplus) && __cplusplus >= 201103L
#		define DEPRECATED			[[deprecated]]
#		define DEPRECATED_MSG(msg) [[deprecated(msg)]]
#	else
#		define DEPRECATED			__attribute__((deprecated))
#		define DEPRECATED_MSG(msg) __attribute__((deprecated(msg)))
#	endif
#endif

// warning suppression when unused w/ Wall or higher
#ifndef UNUSED
#	if defined(__cplusplus) && __cplusplus >= 201103L
#		define UNUSED [[maybe_unused]]
#	else
#		define UNUSED __attribute__((unused))
#	endif
#endif

// Indicate that a switch case is intended to fall through
#ifndef FALLTHROUGH
#	if defined(__cplusplus) && __cplusplus >= 201103L
#		define FALLTHROUGH [[fallthrough]]
#	else
#		define FALLTHROUGH __attribute__((fallthrough))
#	endif
#endif

// Indicate that the return value of a function should not be ignored
#ifndef NODISCARD
#	if defined(__cplusplus) && __cplusplus >= 201103L
#		define NODISCARD [[nodiscard]]
#	else
#		define NODISCARD __attribute__((warn_unused_result))
#	endif
#endif

#ifndef NORETURN
#	if defined(__cplusplus) && __cplusplus >= 201103L
#		define NORETURN [[noreturn]]
#	else
#		define NORETURN __attribute__((noreturn))
#	endif
#endif

#ifndef PURE
#	if defined(__cplusplus) && __cplusplus >= 201103L &&                      \
		__has_cpp_attribute(pure)
#		define PURE [[pure]]
#	else
#		define PURE __attribute__((pure))
#	endif
#endif

#ifndef CONST
#	if defined(__cplusplus) && __cplusplus >= 201103L &&                      \
		__has_cpp_attribute(const)
#		define CONST [[const]]
#	else
#		define CONST __attribute__((const))
#	endif
#endif
