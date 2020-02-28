/**
 * @file fit_add_proxy_plugin.cpp
 * @copyright 2019 Huawei. All rights reserved.
 * @author Zhongbin Yu 00286766
 *
 * @brief
 */

#include <QtDebug>
#include "fit_add_proxy_plugin.h"

int32_t fit_add_proxy_plugin::add(int32_t x, int32_t y)
{
	qDebug() << __FILE__ << __FUNCTION__;

	// TODO: remote call

    return x + y;
}