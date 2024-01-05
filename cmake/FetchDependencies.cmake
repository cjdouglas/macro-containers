include(FetchContent)

if(MC_BUILD_TESTS)
  FetchContent_Declare(
    unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG v2.5.2)
  set(UNITY_EXTENSION_FIXTURE
      ON
      CACHE BOOL "Build unity fixture extension" FORCE)
  FetchContent_MakeAvailable(unity)
endif()
