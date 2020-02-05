#include <QtDebug>
#include "auth_plugin.h"
#include <ctkPluginContext.h>

AuthPlugin2::AuthPlugin2()
{
    // context->registerService<AuthenticationService>(this);
}

bool AuthPlugin2::login(const QString& username, const QString& password)
{
	qDebug() << __FILE__ << __FUNCTION__;

    if (QString::compare(username, "root") == 0
            && QString::compare(password, "auth2") == 0) {
        return true;
    } else {
        return false;
    }
}