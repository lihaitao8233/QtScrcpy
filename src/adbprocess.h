#ifndef ADBPROCESS_H
#define ADBPROCESS_H

#include <QProcess>

class AdbProcess : public QProcess
{
    Q_OBJECT

public:
    enum ADB_EXEC_RESULT {
        AER_SUCCESS,                    // 执行成功
        AER_ERROR_START,                // 启动失败
        AER_ERROR_CMD,                  // 命令执行失败
        AER_ERROR_MISSING_BINARY,       // 找不到文件
    };

    explicit AdbProcess(QObject *parent = nullptr);
    ~AdbProcess();

    void execute(const QString& serial, const QStringList& args);
    void forward(const QString& serial, quint16 localPort, const QString& deviceSocketName);
    void forwardRemove(const QString& serial, quint16 localPort);
    void reverse(const QString& serial, const QString& deviceSocketName, quint16 localPort);
    void reverseRemove(const QString& serial, const QString& deviceSocketName);
    void push(const QString& serial, const QString& local, const QString& remote);
    void install(const QString& serial, const QString& local);
    void removePath(const QString& serial, const QString& path);
    bool isRuning();

    static const QString& getAdbPath();

signals:
    void adbProcessResult(ADB_EXEC_RESULT processResult);

private:
    void initSignals();

    static QString s_adbPath;
};

#endif // ADBPROCESS_H