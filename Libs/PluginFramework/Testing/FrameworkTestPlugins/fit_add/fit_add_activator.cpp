/**
 * @file fit_add_activator.cpp
 * @copyright 2019 Huawei. All rights reserved.
 * @author Zhongbin Yu 00286766
 *
 * @brief
 */

#include "fit_add_activator.h"
#include "fit_add_plugin.h"

void fit_add_activator::start(ctkPluginContext *context)
{
    m_implement = new fit_add_plugin();
    fitable_id id = m_implement->id();

    ctkDictionary properties;
    properties.insert(ctkPluginConstants::SERVICE_RANKING, 0);
    properties.insert("generic_id", id.generic_id.c_str());
    properties.insert("id", id.fitable_id.c_str());

    context->registerService<fit_add_service>(m_implement, properties);
}

void fit_add_activator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context);

    if (m_implement != nullptr) {
        delete m_implement;
        m_implement = nullptr;
    }
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
    Q_EXPORT_PLUGIN2(fit_add, fit_add_activator)
#endif

