#ifndef AUTH_PLUGIN_H
#define AUTH_PLUGIN_H

#include "../service/authentication_service.h"
#include <QObject>

class ctkPluginContext;

class AuthPlugin2 : public QObject, public AuthenticationService
{
    Q_OBJECT
    Q_INTERFACES(AuthenticationService)

public:
    AuthPlugin2();
    bool login(const QString& username, const QString& password) override;
};

#endif // AUTH_PLUGIN_H