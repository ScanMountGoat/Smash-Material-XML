#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Headers/searchsettings.h"

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

    void displayMaterials();

private slots:

    void on_actionOpen_triggered();

    void on_flagsCheckBox_clicked();

    void on_dstCheckBox_clicked();

    void on_srcCheckBox_clicked();

    void on_searchPushButton_clicked();

    void on_actionOpen_Folder_triggered();

    void on_clearPushButton_clicked();

    void on_flags1LineEdit_editingFinished();

    void on_flags2LineEdit_editingFinished();

private:
    Ui::MainWindow *ui;
    SearchSettings *searchSettings = new SearchSettings();
};

#endif // MAINWINDOW_H
