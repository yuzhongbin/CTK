/**
 * @file fit_demo_main.cpp
 * @copyright 2019 Huawei. All rights reserved.
 * @author Zhongbin Yu 00286766
 *
 * @brief
 */

#include <QCoreApplication>
#include <QDirIterator>
#include <QtDebug>

#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginFramework.h>
#include <ctkPluginException.h>
#include <ctkPluginContext.h>

#include "../service/fit_demo_service.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    app.setOrganizationName("CTK");
    app.setOrganizationDomain("huawei.it");
    app.setApplicationName("fit_demo_plugins_test");

    ctkPluginFrameworkFactory frameWorkFactory;
    QSharedPointer<ctkPluginFramework> framework = frameWorkFactory.getFramework();
    try {
        // 初始化并启动插件框架
        framework->init();
        framework->start();

        qDebug() << "CTK Plugin Framework start ...";
    } catch (const ctkPluginException &e) {
        qDebug() << "Failed to initialize the plugin framework: " << e.what();
        return -1;
    }

    // 获取插件上下文
    ctkPluginContext* pluginContext = framework->getPluginContext();

#ifdef CMAKE_INTDIR
    QString path = app.applicationDirPath() + "/../test_plugins/" CMAKE_INTDIR "/";
#else
    QString path = app.applicationDirPath() + "/test_plugins/";
#endif

    // 遍历路径下的所有插件
    QDirIterator itPlugin(path, QStringList() << "*fit_demo*.so", QDir::Files);
    while (itPlugin.hasNext()) {
        QString strPlugin = itPlugin.next();
        try {
            // 安装插件
            QSharedPointer<ctkPlugin> plugin = pluginContext->installPlugin(QUrl::fromLocalFile(strPlugin));
            qDebug() << "Plugin install ..." << QFileInfo(strPlugin).fileName();

            // 启动插件
            plugin->start(ctkPlugin::START_TRANSIENT);
            qDebug() << "Plugin start ...";
        } catch (const ctkPluginException &e) {
            qDebug() << "Failed to install plugin" << e.what();
            return -1;
        }
    }

    // 按CTKCore规则获取最合适的服务（SERVICE_RANKING值小优先）
    auto ref = pluginContext->getServiceReference<fit_demo_service>();
    if (ref) {
        auto fit_demo = qobject_cast<fit_demo_service *>(pluginContext->getService(ref));

        if (fit_demo != nullptr) {
            // 调用服务，进行认证
            auto result = fit_demo->add(4, 5);
            qDebug() << "4 + 5 = " << result;
        }
    }

    // 按关键字过滤服务
    auto refs = pluginContext->getServiceReferences<fit_demo_service>("(&(language=go))");
    foreach (ctkServiceReference ref, refs) {
        if (ref) {
            // 获取指定 ctkServiceReference 引用的服务对象
            auto fit_demo = qobject_cast<fit_demo_service *>(pluginContext->getService(ref));
            if (fit_demo != nullptr) {
                // 调用服务，进行认证
                auto result = fit_demo->add(4, 5);
                qDebug() << "4 + 5 =" << result;
            }
        }
    }

    // 按关键字过滤服务
    refs = pluginContext->getServiceReferences<fit_demo_service>("(&(language=java))");
    foreach (ctkServiceReference ref, refs) {
        if (ref) {
            // 获取指定 ctkServiceReference 引用的服务对象
            auto fit_demo = qobject_cast<fit_demo_service *>(pluginContext->getService(ref));
            if (fit_demo != nullptr) {
                // 调用服务，进行认证
                auto result = fit_demo->add(4, 5);
                qDebug() << "4 + 5 =" << result;
            }
        }
    }

    return app.exec();
}


