// Copyright (c) 2017 Baidu, Inc.
// Author: Zhangyi Chen (chenzhangyi01@baidu.com)

#ifndef BUTIL_TEST_SSTREAM_WORKAROUND
#define BUTIL_TEST_SSTREAM_WORKAROUND

// defining private as public makes it fail to compile sstream with gcc5.x like this:
// "error: ‘struct std::__cxx11::basic_stringbuf<_CharT, _Traits, _Alloc>::
// __xfer_bufptrs’ redeclared with different access"

#ifdef private
# undef private
# include <sstream>
# if __cplusplus >= 201703L
// Same story for C++17 stdlib headers (e.g. <any> redeclares
// _Manager_internal/_Manager_external with different access)
#  include <any>
#  include <optional>
#  include <variant>
# endif
# define private public
#else
# include <sstream>
# if __cplusplus >= 201703L
#  include <any>
#  include <optional>
#  include <variant>
# endif
#endif

#endif  //  BUTIL_TEST_SSTREAM_WORKAROUND
