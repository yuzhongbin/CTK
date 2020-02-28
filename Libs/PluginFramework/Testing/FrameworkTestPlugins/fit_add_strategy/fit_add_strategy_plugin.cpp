/**
 * @file fit_add_strategy_plugin.cpp
 * @copyright 2019 Huawei. All rights reserved.
 * @author Zhongbin Yu 00286766
 *
 * @brief
 */

#include <QtDebug>

#include "fit_add_strategy_plugin.h"

int32_t fit_add_strategy_plugin::add(int32_t x, int32_t y)
{
	qDebug() << __FILE__ << __FUNCTION__;

    return x + y;
}

