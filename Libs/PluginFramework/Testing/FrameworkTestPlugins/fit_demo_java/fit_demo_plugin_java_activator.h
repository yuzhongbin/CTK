/**
 * @file fit_demo_plugin_java_activator.h
 * @copyright 2019 Huawei. All rights reserved.
 * @author Zhongbin Yu 00286766
 *
 * @brief
 */

#ifndef FIT_DEMO_PLUGIN_JAVA_ACTIVATOR_H
#define FIT_DEMO_PLUGIN_JAVA_ACTIVATOR_H

#include <ctkPluginActivator.h>
#include "../service/fit_demo_service.h"

class fit_demo_plugin_java_activator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator);

public:
    void start(ctkPluginContext *context) override;
    void stop(ctkPluginContext *context) override;

private:
    class fit_demo_plugin_java *m_implement;
};

#endif

