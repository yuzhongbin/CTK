#ifndef FIT_ADD_SERVICE_H
#define FIT_ADD_SERVICE_H

#include <QtPlugin>
#include <QString>

#include "fit_fitable.h"

class fit_add_service : public fitable{
public:
    virtual ~fit_add_service() = default;

    virtual const fitable_id &id() = 0;

    virtual int32_t add(int32_t x, int32_t y) = 0;
};

// 服务接口声明
Q_DECLARE_INTERFACE(fit_add_service, "huawei.it.fit_add_service")


#endif