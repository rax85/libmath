cc_library(
  name = "gauss_seidel",
  srcs = ["gauss_seidel.cc"],
  hdrs = ["gauss_seidel.h"],
  visibility = ["//visibility:public"],
)

cc_test(
  name = "gauss_seidel_test",
  srcs = ["gauss_seidel_test.cc"],
  deps = [
    ":gauss_seidel",
    "@com_google_googletest//:gtest_main",
  ]
)

cc_library(
  name = "point",
  srcs = ["point.cc"],
  hdrs = ["point.h"],
  visibility = ["//visibility:public"],
)

cc_test(
  name = "point_test",
  srcs = ["point_test.cc"],
  deps = [
    ":point",
    "@com_google_googletest//:gtest_main",
  ]
)

cc_library(
  name = "vector",
  srcs = ["vector.cc"],
  hdrs = ["vector.h"],
  visibility = ["//visibility:public"],
  deps = [
    ":point",
  ]
)

cc_test(
  name = "vector_test",
  srcs = ["vector_test.cc"],
  deps = [
    ":vector",
    "@com_google_googletest//:gtest_main",
  ]
)

cc_library(
  name = "interpolate",
  srcs = ["interpolate.cc"],
  hdrs = ["interpolate.h"],
  deps = [
    ":point",
    ":vector",
  ]
)

cc_test(
  name = "interpolate_test",
  srcs = ["interpolate_test.cc"],
  deps = [
    ":interpolate",
    ":vector",
    "@com_google_googletest//:gtest_main",
  ]
)
