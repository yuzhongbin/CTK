project(auth_plugin2)

set(PLUGIN_export_directive "auth_plugin2_EXPORT")

set(PLUGIN_SRCS
    auth_plugin.cpp
    auth_plugin_activator.cpp
    ../service/authentication_service.h
)

set(PLUGIN_MOC_SRCS
    auth_plugin.h
    auth_plugin_activator.h
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