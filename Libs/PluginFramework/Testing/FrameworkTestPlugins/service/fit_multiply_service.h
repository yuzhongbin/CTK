#ifndef FIT_MUTIPLY_SERVICE_H
#define FIT_MUTIPLY_SERVICE_H

#include <QtPlugin>
#include <QString>

class fit_multiply_service {
public:
    virtual ~fit_multiply_service() = default;

    virtual int32_t multiply(int32_t x, int32_t y) = 0;
};

// 服务接口声明
Q_DECLARE_INTERFACE(fit_multiply_service, "huawei.it.fit_multiply_service")

#endif