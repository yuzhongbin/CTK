project(fit_demo_cpp)

set(PLUGIN_export_directive "fit_demo_cpp_EXPORT")

set(PLUGIN_SRCS
    fit_demo_plugin_cpp.cpp
    fit_demo_plugin_cpp_activator.cpp
    ../service/fit_demo_service.h
)

set(PLUGIN_MOC_SRCS
    fit_demo_plugin_cpp.h
    fit_demo_plugin_cpp_activator.h
)

set(PLUGIN_resources

)

ctkFunctionGetTargetLibraries(PLUGIN_target_libraries)

ctkMacroBuildPlugin(
    NAME ${PROJECT_NAME}
    EXPORT_DIRECTIVE ${PLUGIN_export_directive}
    SRCS ${PLUGIN_SRCS}
    MOC_SRCS ${PLUGIN_MOC_SRCS}
    RESOURCES ${PLUGIN_resources}
    TARGET_LIBRARIES ${PLUGIN_target_libraries}
    TEST_PLUGIN
)

# =========== Build a separate test executable ===============
set(SRCS
  fit_demo_main.cpp
)

set(MOC_SRCS )

set(MY_MOC_CXX )

if(CTK_QT_VERSION VERSION_GREATER "4")
  qt5_wrap_cpp(MY_MOC_CXX ${MOC_SRCS})
else()
  qt4_wrap_cpp(MY_MOC_CXX ${MOC_SRCS})
endif()

set(test_executable fit_demo)

add_executable(${test_executable} ${SRCS} ${MY_MOC_CXX})
target_link_libraries(${test_executable}
  ${fw_lib}
)

if(CTK_QT_VERSION VERSION_GREATER "4")
  target_link_libraries(${test_executable} Qt5::Test)
endif()

add_dependencies(${test_executable} ${PROJECT_NAME})

add_test(fit_demo ${CPP_TEST_PATH}/${test_executable})
set_property(TEST fit_demo PROPERTY LABELS ${fw_lib})
set_property(TEST fit_demo PROPERTY ENVIRONMENT "QT_FATAL_WARNINGS=1")