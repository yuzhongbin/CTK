project(fit_add_proxy)

set(FIT_ROOT ../../../../../../../../..)
include_directories(../service)
include_directories(${FIT_ROOT}/include)
include_directories(${FIT_ROOT}/src/helper)
include_directories(${FIT_ROOT}/src/broker)
include_directories(${FIT_ROOT}/src/register)
include_directories(${FIT_ROOT}/src/core/engine)
include_directories(${FIT_ROOT}/src/fitable)
include_directories(${FIT_ROOT}/src/fitable/fit_add)

set(PLUGIN_export_directive "fit_add_proxy_EXPORT")

set(PLUGIN_SRCS
    fit_add_proxy_plugin.cpp
    fit_add_proxy_activator.cpp
)

set(PLUGIN_MOC_SRCS
    fit_add_proxy_plugin.h
    fit_add_proxy_activator.h
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