#ifndef FIT_DEMO_SERVICE_H
#define FIT_DEMO_SERVICE_H

#include <QtPlugin>
#include <QString>

class fit_demo_service {
public:
    virtual ~fit_demo_service() = default;

    virtual int32_t add(int32_t x, int32_t y) = 0;
    virtual int32_t multiply(int32_t x, int32_t y) = 0;
};

// 服务接口声明
Q_DECLARE_INTERFACE(fit_demo_service, "huawei.it.fit_demo_service")

#endif