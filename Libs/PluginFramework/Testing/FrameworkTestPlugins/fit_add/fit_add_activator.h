/**
 * @file fit_add_activator.h
 * @copyright 2019 Huawei. All rights reserved.
 * @author Zhongbin Yu 00286766
 *
 * @brief
 */

#ifndef FIT_ADD_ACTIVATOR_H
#define FIT_ADD_ACTIVATOR_H

#include <ctkPluginActivator.h>
#include "../service/fit_add_service.h"

class fit_add_activator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator);

public:
    void start(ctkPluginContext *context) override;
    void stop(ctkPluginContext *context) override;

private:
    class fit_add_plugin *m_implement;
};

#endif

