/**
 * @file fit_add_plugin.h
 * @copyright 2019 Huawei. All rights reserved.
 * @author Zhongbin Yu 00286766
 *
 * @brief
 */

#ifndef FIT_ADD_PLUGIN_H
#define FIT_ADD_PLUGIN_H

#include "../service/fit_add_service.h"

#include <QObject>

class fit_add_plugin : public QObject, public fit_add_service
{
    Q_OBJECT
    Q_INTERFACES(fit_add_service)

public:
    fit_add_plugin() = default;
    ~fit_add_plugin() = default;

    int32_t add(int32_t x, int32_t y) override;

    const fitable_id &id() override
    {
    	return id_;
    }

private:
	fitable_id id_;
};

#endif

