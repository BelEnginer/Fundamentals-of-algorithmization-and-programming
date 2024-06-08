#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QMessageBox ErrorBox;

    bool CheckForCorrectness(const int n, const int m);
    bool CheckNumber(const QString n);
    int AkermanFunc(const int m, const int n);
};
#endif // MAINWINDOW_H
