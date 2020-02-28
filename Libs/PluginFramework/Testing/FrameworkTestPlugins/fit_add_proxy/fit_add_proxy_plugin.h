/**
 * @file fit_add_proxy_plugin.h
 * @copyright 2019 Huawei. All rights reserved.
 * @author Zhongbin Yu 00286766
 *
 * @brief
 */

#ifndef FIT_ADD_PROXY_PLUGIN_H
#define FIT_ADD_PROXY_PLUGIN_H

#include "../service/fit_add_proxy.h"

#include <QObject>

class fit_add_proxy_plugin : public QObject, public fit_add_proxy
{
    Q_OBJECT
    Q_INTERFACES(fit_add_proxy)

public:
    fit_add_proxy_plugin() = default;
    ~fit_add_proxy_plugin() = default;

    int32_t add(int32_t x, int32_t y) override;

private:
    Q_DISABLE_COPY(fit_add_proxy_plugin)
};

#endif

