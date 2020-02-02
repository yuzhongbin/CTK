#ifndef AUTH_PLUGIN_H
#define AUTH_PLUGIN_H

#include "auth_plugin_service.h"
#include <QObject>

class ctkPluginContext;

class AuthPlugin : public QObject, public AuthPluginService
{
    Q_OBJECT
    Q_INTERFACES(AuthPluginService)

public:
    AuthPlugin(ctkPluginContext* context);
    bool login(const QString& username, const QString& password) override;
};

#endif // AUTH_PLUGIN_H