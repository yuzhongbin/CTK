#ifndef AUTHENTICATION_SERVICE_H
#define AUTHENTICATION_SERVICE_H

#include <QtPlugin>
#include <QString>

class AuthenticationService {
public:
    virtual ~AuthenticationService() = default;
    virtual bool login(const QString& username, const QString& password) = 0;
};

#define AuthService_iid "huawei.it.test.AuthenticationService"

// 服务接口声明
Q_DECLARE_INTERFACE(AuthenticationService, AuthService_iid)

#endif