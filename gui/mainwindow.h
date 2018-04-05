#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "src/searchsettings.h"

#include <QMainWindow>
#include <QList>

#include "src/material.h"

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
	
	void addMaterialsFromFolderDialog();

	void displayMaterialCount();

	void addMaterialsFromFileDialog();


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

    void on_srcLineEdit_editingFinished();

    void on_actionAbout_triggered();

    void on_dstLineEdit_editingFinished();

    void on_matPropLineEdit_editingFinished();

    void on_matPropCheckBox_clicked();

	void on_actionClear_Materials_triggered();

private:
    Ui::MainWindow *ui;
    SearchSettings searchSettings;

    bool hasValidSrc(Material material);
};

#endif // MAINWINDOW_H
