#include <QtDebug>
#include "auth_plugin.h"
#include <ctkPluginContext.h>

AuthPlugin::AuthPlugin()
{
    // context->registerService<AuthenticationService>(this);
}

bool AuthPlugin::login(const QString& username, const QString& password)
{
	qDebug() << __FILE__ << __FUNCTION__;

    if (QString::compare(username, "root") == 0
    	&& QString::compare(password, "123456") == 0) {
        return true;
    } else {
        return false;
    }
}