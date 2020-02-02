#if 1
#include <QCoreApplication>
#include <QtDebug>

#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginFramework.h>
#include <ctkPluginException.h>
#include <ctkPluginContext.h>

#include "Testing/FrameworkTestPlugins/auth_plugin/auth_plugin_service.h"

const QString c_strPluginPath = "/mnt/d/xproject/ctk-superbuild/CTK-build/bin/test_plugins/libauth_plugin.so";

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    app.setOrganizationName("CTK");
    app.setOrganizationDomain("commontk.org");
    app.setApplicationName("ctkPluginFrameworkAuthPlugsTests");    

    ctkPluginFrameworkFactory frameWorkFactory;
    QSharedPointer<ctkPluginFramework> framework = frameWorkFactory.getFramework();
    try {
        // 初始化并启动插件框架
        framework->init();
    } catch (const ctkPluginException &e) {
        qDebug() << "Failed to initialize the plugin framework: " << e.what();
        return -1;
    }

    // 获取插件上下文
    ctkPluginContext* pluginContext = framework->getPluginContext();
    try {
        // 安装插件
        QSharedPointer<ctkPlugin> plugin = pluginContext->installPlugin(QUrl::fromLocalFile(c_strPluginPath));
        
        framework->start();
        qDebug() << "CTK Plugin Framework start ...";

        // 启动插件
        plugin->start(ctkPlugin::START_TRANSIENT);
        qDebug() << "Plugin start ...";
    } catch (const ctkPluginException &e) {
        qDebug() << e.what();
        return -1;
    }

    // 获取服务引用
    ctkServiceReference reference = pluginContext->getServiceReference<AuthPluginService>();
    // 获取指定 ctkServiceReference 引用的服务对象
    AuthPluginService* authService = qobject_cast<AuthPluginService *>(pluginContext->getService(reference));
    if (authService != nullptr) {
        // 调用服务，进行认证
        bool isLogin = authService->login("root", "123456");
        if (isLogin) {
            qDebug() << "Login successfully";
        } else {
            qDebug() << "Login failed";
        }
    }

    return app.exec();
}
#else
/*=============================================================================

  Library: CTK

  Copyright (c) German Cancer Research Center,
    Division of Medical and Biological Informatics

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/

#include <ctkPluginConstants.h>
#include <QtDebug>

#include <ctkPluginFrameworkLauncher.h>

#include "Testing/FrameworkTestPlugins/auth_plugin/auth_plugin_service.h"

#include <QCoreApplication>
#include <QTest>

int main(int argc, char** argv)
{
  QCoreApplication app(argc, argv);

  app.setOrganizationName("CTK");
  app.setOrganizationDomain("commontk.org");
  app.setApplicationName("ctkPluginFrameworkAuthPlugsTests");


  QString pluginDir;
#ifdef CMAKE_INTDIR
  pluginDir = qApp->applicationDirPath() + "/../test_plugins/" CMAKE_INTDIR "/";
#else
  pluginDir = qApp->applicationDirPath() + "/test_plugins/";
#endif

  ctkProperties fwProps;
  fwProps.insert(ctkPluginConstants::FRAMEWORK_STORAGE_CLEAN, ctkPluginConstants::FRAMEWORK_STORAGE_CLEAN_ONFIRSTINIT);
  fwProps.insert(ctkPluginFrameworkLauncher::PROP_PLUGINS, "auth_plugin");
  fwProps.insert("org.commontk.pluginfw.debug.pluginfw", true);

#if defined(Q_CC_GNU) && ((__GNUC__ < 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ < 5)))
  fwProps.insert(ctkPluginConstants::FRAMEWORK_PLUGIN_LOAD_HINTS, QVariant::fromValue<QLibrary::LoadHints>(QLibrary::ExportExternalSymbolsHint));
#endif

  ctkPluginFrameworkLauncher::setFrameworkProperties(fwProps);
  ctkPluginFrameworkLauncher::addSearchPath(pluginDir);
  ctkPluginFrameworkLauncher::run();

  Q_ASSERT_X(QCoreApplication::instance()->property("auth_plugin.success").toBool(), "MyAppContainer", "App did not run");
  qDebug() << "App run successful";
}

#endif

