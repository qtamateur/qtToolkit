#include "widget.h"
#include <QApplication>
#include <QLabel>
#include <stdio.h>
#include <stdlib.h>

static FILE * g_log_fp = 0;  //默认输出日志文件指针
static void closeLogFile()   //关闭输出日志文件
{
    fclose(g_log_fp);
}
static void myMessageOutput(QtMsgType type,const QMessageLogContext &context,const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        fprintf(g_log_fp,"Debug: %s (%s:%u, %s)\n",
                localMsg.constData(),
                context.file,
                context.line,
                context.function);
        break;
    case QtInfoMsg:
            fprintf(stderr, "Info: %s (%s:%u, %s)\n",
                    localMsg.constData(),
                    context.file, context.line,
                    context.function);
            break;
    case QtWarningMsg:
        fprintf(g_log_fp,"Warning: %s (%s:%u, %s)\n",
                localMsg.constData(),
                context.file,
                context.line,
                context.function);
        break;
    case QtCriticalMsg:
        fprintf(g_log_fp,"Critical: %s (%s:%u, %s)\n",
                localMsg.constData(),
                context.file,
                context.line,
                context.function);
        break;
    case QtFatalMsg:
        fprintf(g_log_fp,"Fatal: %s (%s:%u, %s)\n",
                localMsg.constData(),
                context.file,
                context.line,
                context.function);
        abort();
//    default:
//        break;
    }
}

int main(int argc, char *argv[])
{
    //使用方法
    g_log_fp = fopen("my.log","wt");
    //atexit(closeLogFile();
    qInstallMessageHandler(myMessageOutput);
    //下面开始正常程序
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
