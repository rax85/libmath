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
  hdrs = ["point.h"],
  visibility = ["//visibility:public"],
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
