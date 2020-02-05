#include <QCoreApplication>
#include <QDirIterator>
#include <QtDebug>

#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginFramework.h>
#include <ctkPluginException.h>
#include <ctkPluginContext.h>

// authentication服务定义
#include "../service/authentication_service.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    app.setOrganizationName("CTK");
    app.setOrganizationDomain("huawei.it");
    app.setApplicationName("ctkPluginFrameworkAuthPlugsTests");

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
    QDirIterator itPlugin(path, QStringList() << "*auth_plugin*.so", QDir::Files);
    while (itPlugin.hasNext()) {
        QString strPlugin = itPlugin.next();
        try {
            // 安装插件
            QSharedPointer<ctkPlugin> plugin = pluginContext->installPlugin(QUrl::fromLocalFile(strPlugin));
            qDebug() << "Plugin install ..." << QFileInfo(strPlugin).fileName();
#if 0
            // 获取清单头和值
            QHash<QString, QString> headers = plugin->getHeaders();
            qDebug() << "Headers:" << headers;

            // 获取符号名
            QString symb = plugin->getSymbolicName();
            qDebug() << "Symbolic Name:" << symb;

            // 获取版本号
            ctkVersion version = plugin->getVersion();
            qDebug() << "Version:" << version.toString()
                     << "Major:" << version.getMajor()
                     << "Micro:" << version.getMicro()
                     << "Minor:" << version.getMinor()
                     << "Qualifier:" << version.getQualifier();
#endif
            // 启动插件
            plugin->start(ctkPlugin::START_TRANSIENT);
            qDebug() << "Plugin start ...";
        } catch (const ctkPluginException &e) {
            qDebug() << "Failed to install plugin" << e.what();
            return -1;
        }
    }

    // 按CTKCore规则获取最合适的服务（SERVICE_RANKING值小优先）
    auto ref = pluginContext->getServiceReference<AuthenticationService>();
    auto authService = qobject_cast<AuthenticationService *>(pluginContext->getService(ref));

    if (authService != nullptr) {
        // 调用服务，进行认证
        bool isLogin = authService->login("root", "auth2");
        if (isLogin) {
            qDebug() << "Login successfully";
        } else {
            qDebug() << "Login failed";
        }
    }

    // 按关键字过滤服务
    auto refs = pluginContext->getServiceReferences<AuthenticationService>("(&(name=plugin1))");
    foreach (ctkServiceReference ref, refs) {
        if (ref) {
            // 获取指定 ctkServiceReference 引用的服务对象
            auto authService = qobject_cast<AuthenticationService *>(pluginContext->getService(ref));
            if (authService != nullptr) {
                // 调用服务，进行认证
                bool isLogin = authService->login("root", "123456");
                if (isLogin) {
                    qDebug() << "Login successfully";
                } else {
                    qDebug() << "Login failed";
                }
            }
        }
    }

    return app.exec();
}