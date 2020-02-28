/**
 * @file fit_add_strategy.h
 * @copyright 2019 Huawei. All rights reserved.
 * @author Zhongbin Yu 00286766
 *
 * @brief
 */

#ifndef FIT_ADD_STRATEGY_H
#define FIT_ADD_STRATEGY_H

#include <QtPlugin>
#include <QString>

#include "fit_fitable.h"

class fit_add_strategy : public fitable, public fitable_strategy {
public:
    virtual ~fit_add_strategy() = default;

    virtual const fitable_id &id() = 0;

    virtual int32_t load() = 0;
    virtual const fitable_id& id() const = 0;

    virtual fitable_strategy_type get() = 0;
    virtual int32_t set(fitable_strategy_type type) = 0;
};

// 服务接口声明
Q_DECLARE_INTERFACE(fit_add_strategy, "huawei.it.fit_add_strategy")


#endif

