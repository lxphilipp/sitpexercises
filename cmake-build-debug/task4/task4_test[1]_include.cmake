if(EXISTS "/Users/philipple/Papers/Seminar/DesignPattern/Code/exercise-sitp/cmake-build-debug/task4/task4_test[1]_tests.cmake")
  include("/Users/philipple/Papers/Seminar/DesignPattern/Code/exercise-sitp/cmake-build-debug/task4/task4_test[1]_tests.cmake")
else()
  add_test(task4_test_NOT_BUILT task4_test_NOT_BUILT)
endif()
