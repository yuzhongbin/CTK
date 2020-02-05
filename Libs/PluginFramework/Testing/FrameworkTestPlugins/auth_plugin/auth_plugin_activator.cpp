#include "auth_plugin_activator.h"
#include "auth_plugin.h"

void AuthPluginActivator::start(ctkPluginContext* context)
{
	ctkDictionary properties;

    properties.insert(ctkPluginConstants::SERVICE_RANKING, 2);
    properties.insert("name", "plugin1");

    m_implement = new AuthPlugin();
    context->registerService<AuthenticationService>(m_implement, properties);
}

void AuthPluginActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)
    delete m_implement;
    m_implement = nullptr;
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
Q_EXPORT_PLUGIN2(auth_plugin, AuthPluginActivator)
#endif
