#ifndef L5__VISIBILITY_CONTROL_H_
#define L5__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define L5_EXPORT __attribute__ ((dllexport))
    #define L5_IMPORT __attribute__ ((dllimport))
  #else
    #define L5_EXPORT __declspec(dllexport)
    #define L5_IMPORT __declspec(dllimport)
  #endif
  #ifdef L5_BUILDING_LIBRARY
    #define L5_PUBLIC L5_EXPORT
  #else
    #define L5_PUBLIC L5_IMPORT
  #endif
  #define L5_PUBLIC_TYPE L5_PUBLIC
  #define L5_LOCAL
#else
  #define L5_EXPORT __attribute__ ((visibility("default")))
  #define L5_IMPORT
  #if __GNUC__ >= 4
    #define L5_PUBLIC __attribute__ ((visibility("default")))
    #define L5_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define L5_PUBLIC
    #define L5_LOCAL
  #endif
  #define L5_PUBLIC_TYPE
#endif
#endif  // L5__VISIBILITY_CONTROL_H_
// Generated 20-Nov-2024 03:37:54
// Copyright 2019-2020 The MathWorks, Inc.
