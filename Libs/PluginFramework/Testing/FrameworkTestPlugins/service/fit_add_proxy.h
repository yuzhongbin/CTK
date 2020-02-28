/**
 * @file fit_add_proxy.h
 * @copyright 2019 Huawei. All rights reserved.
 * @author Zhongbin Yu 00286766
 *
 * @brief
 */

#ifndef FIT_ADD_PROXY_H
#define FIT_ADD_PROXY_H

#include <QtPlugin>
#include <QString>

#include "fit_fitable.h"

class fit_add_proxy : public fitable {
public:
    virtual ~fit_add_proxy() = default;

    virtual const fitable_id &id() = 0;

    virtual int32_t add(int32_t x, int32_t y) = 0;
};

// 服务接口声明
Q_DECLARE_INTERFACE(fit_add_proxy, "huawei.it.fit_add_proxy")


#endif

