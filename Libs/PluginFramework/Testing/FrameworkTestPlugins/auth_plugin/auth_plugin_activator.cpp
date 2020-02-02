#include "auth_plugin_activator.h"
#include "auth_plugin.h"

void AuthPluginActivator::start(ctkPluginContext* context)
{
    s.reset(new AuthPlugin(context));
}

void AuthPluginActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
Q_EXPORT_PLUGIN2(auth_plugin, AuthPluginActivator)
#endif
