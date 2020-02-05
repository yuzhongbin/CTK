#include "auth_plugin_activator.h"
#include "auth_plugin.h"

void AuthPluginActivator2::start(ctkPluginContext* context)
{
	ctkDictionary properties;

    // SERVICE_RANKING数字越小，优先级越高
    properties.insert(ctkPluginConstants::SERVICE_RANKING, std::numeric_limits<int>::min());
    properties.insert("name", "plugin2");

    m_implement = new AuthPlugin2();
    context->registerService<AuthenticationService>(m_implement, properties);
}

void AuthPluginActivator2::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)

    delete m_implement;
    m_implement = nullptr;
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
Q_EXPORT_PLUGIN2(auth_plugin2, AuthPluginActivator2)
#endif
