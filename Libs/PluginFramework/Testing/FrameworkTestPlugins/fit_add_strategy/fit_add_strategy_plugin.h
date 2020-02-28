/**
 * @file fit_add_strategy.h
 * @copyright 2019 Huawei. All rights reserved.
 * @author Zhongbin Yu 00286766
 *
 * @brief
 */

#ifndef FIT_ADD_STRATEGY_PLUGIN_H
#define FIT_ADD_STRATEGY_PLUGIN_H

#include "../service/fit_add_strategy.h"

#include <QObject>

class fit_add_strategy_plugin : public QObject, public fit_add_strategy
{
    Q_OBJECT
    Q_INTERFACES(fit_add_strategy)

public:
    fit_add_strategy_plugin() = default;
    ~fit_add_strategy_plugin() = default;

    const fitable_id &id() override;

    int32_t load() override;
    const fitable_id& id() const override;

    fitable_strategy_type get() override;
    int32_t set(fitable_strategy_type type) override;

private:
    Q_DISABLE_COPY(fit_add_strategy_plugin)
};

#endif

