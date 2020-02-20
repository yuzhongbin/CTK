project(fit_demo_java)

set(PLUGIN_export_directive "fit_demo_java_EXPORT")

set(PLUGIN_SRCS
    fit_demo_plugin_java.cpp
    fit_demo_plugin_java_activator.cpp
    ../service/fit_demo_service.h
)

set(PLUGIN_MOC_SRCS
    fit_demo_plugin_java.h
    fit_demo_plugin_java_activator.h
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
