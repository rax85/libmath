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