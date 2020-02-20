/**
 * @file fit_demo_plugin_go_activator.cpp
 * @copyright 2019 Huawei. All rights reserved.
 * @author Zhongbin Yu 00286766
 *
 * @brief
 */

#include "fit_demo_plugin_go_activator.h"
#include "fit_demo_plugin_go.h"

void fit_demo_plugin_go_activator::start(ctkPluginContext *context)
{
    ctkDictionary properties;
    properties.insert(ctkPluginConstants::SERVICE_RANKING, 1);
    properties.insert("language", "go");

    m_implement = new fit_demo_plugin_go();
    context->registerService<fit_demo_service>(m_implement, properties);
}

void fit_demo_plugin_go_activator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context);

    if (m_implement != nullptr) {
        delete m_implement;
        m_implement = nullptr;
    }
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
    Q_EXPORT_PLUGIN2(fit_demo_go, fit_demo_plugin_go_activator)
#endif

