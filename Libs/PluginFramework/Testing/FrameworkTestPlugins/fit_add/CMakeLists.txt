project(fit_add)

set(FIT_ROOT ../../../../../../../../..)
include_directories(${FIT_ROOT}/include)
include_directories(${FIT_ROOT}/src/helper)
include_directories(${FIT_ROOT}/src/broker)
include_directories(${FIT_ROOT}/src/register)
include_directories(${FIT_ROOT}/src/core/engine)
include_directories(${FIT_ROOT}/src/fitable)
include_directories(${FIT_ROOT}/src/fitable/fit_add)

set(PLUGIN_export_directive "fit_add_EXPORT")

set(PLUGIN_SRCS
    fit_add_plugin.cpp
    fit_add_activator.cpp
    ../service/fit_add_service.h
)

set(PLUGIN_MOC_SRCS
    fit_add_plugin.h
    fit_add_activator.h
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

set(FIT_ROOT ../../../../../../../../..)
include_directories(../service)
include_directories(${FIT_ROOT}/include)
include_directories(${FIT_ROOT}/src/helper)
include_directories(${FIT_ROOT}/src/broker)
include_directories(${FIT_ROOT}/src/register)
include_directories(${FIT_ROOT}/src/core/engine)
include_directories(${FIT_ROOT}/src/fitable)
include_directories(${FIT_ROOT}/src/fitable/fit_add)

set(SRCS
  ${FIT_ROOT}/src/broker/fit_broker.cpp  
  ${FIT_ROOT}/src/fitable/fit_add/fit_add.cpp
  ${FIT_ROOT}/src/core/engine/fit_plugin_engine_ctk.cpp
  ${FIT_ROOT}/test/ut_fit_main.cpp
)

set(MY_MOC_CXX )

if(CTK_QT_VERSION VERSION_GREATER "4")
  qt5_wrap_cpp(MY_MOC_CXX ${MOC_SRCS})
else()
  qt4_wrap_cpp(MY_MOC_CXX ${MOC_SRCS})
endif()

set(test_executable fit_register)

add_executable(${test_executable} ${SRCS} ${MY_MOC_CXX})
target_link_libraries(${test_executable}
  ${fw_lib}
)

if(CTK_QT_VERSION VERSION_GREATER "4")
  target_link_libraries(${test_executable} Qt5::Test)
endif()

add_dependencies(${test_executable} ${PROJECT_NAME})

add_test(fit_register ${CPP_TEST_PATH}/${test_executable})
set_property(TEST fit_register PROPERTY LABELS ${fw_lib})
set_property(TEST fit_register PROPERTY ENVIRONMENT "QT_FATAL_WARNINGS=1")