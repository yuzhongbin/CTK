/**
 * @file fit_demo_plugin_go.h
 * @copyright 2019 Huawei. All rights reserved.
 * @author Zhongbin Yu 00286766
 *
 * @brief
 */

#ifndef FIT_DEMO_PLUGIN_GO_H
#define FIT_DEMO_PLUGIN_GO_H

#include "../service/fit_demo_service.h"

#include <QObject>

class fit_demo_plugin_go : public QObject, public fit_demo_service
{
    Q_OBJECT
    Q_INTERFACES(fit_demo_service)

public:
    fit_demo_plugin_go() = default;
    ~fit_demo_plugin_go() = default;

    int32_t add(int32_t x, int32_t y) override;
    int32_t multiply(int32_t x, int32_t y) override;

private:
    Q_DISABLE_COPY(fit_demo_plugin_go)
};

#endif

