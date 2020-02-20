/**
 * @file fit_demo_plugin_go.cpp
 * @copyright 2019 Huawei. All rights reserved.
 * @author Zhongbin Yu 00286766
 *
 * @brief
 */

#include <QtDebug>
#include <ctkPluginContext.h>

#include "fit_demo_plugin_go.h"

int32_t fit_demo_plugin_go::add(int32_t x, int32_t y)
{
	qDebug() << __FILE__ << __FUNCTION__;

    return x + y;
}

int32_t fit_demo_plugin_go::multiply(int32_t x, int32_t y)
{
	qDebug() << __FILE__ << __FUNCTION__;
	
    return x * y;
}

