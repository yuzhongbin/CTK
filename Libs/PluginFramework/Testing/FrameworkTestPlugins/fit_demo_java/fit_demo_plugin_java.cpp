/**
 * @file fit_demo_plugin_java.cpp
 * @copyright 2019 Huawei. All rights reserved.
 * @author Zhongbin Yu 00286766
 *
 * @brief
 */

#include <QtDebug>
#include <ctkPluginContext.h>

#include "fit_demo_plugin_java.h"

int32_t fit_demo_plugin_java::add(int32_t x, int32_t y)
{
	qDebug() << __FILE__ << __FUNCTION__;

    return x + y;
}

int32_t fit_demo_plugin_java::multiply(int32_t x, int32_t y)
{
	qDebug() << __FILE__ << __FUNCTION__;
	
    return x * y;
}

