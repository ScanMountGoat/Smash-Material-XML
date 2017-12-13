#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionOpen_triggered();

    void on_flagsCheckBox_clicked();

    void on_dstCheckBox_clicked();

    void on_srcCheckBox_clicked();

    void on_searchPushButton_clicked();

    void on_actionOpen_Folder_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
