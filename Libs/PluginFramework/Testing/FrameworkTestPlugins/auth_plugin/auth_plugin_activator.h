#ifndef AUTH_PLUGIN_ACTIVATOR_H
#define AUTH_PLUGIN_ACTIVATOR_H

#include <ctkPluginActivator.h>
#include "../service/authentication_service.h"

class AuthPluginActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)

#ifdef HAVE_QT5    
    Q_PLUGIN_METADATA(IID "auth_plugin")
#endif

public:
    void start(ctkPluginContext* context) override;
    void stop(ctkPluginContext* context) override;

private:
    class AuthPlugin *m_implement;
};

#endif