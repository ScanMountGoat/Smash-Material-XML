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

    void displayFilteredMaterials();

	QList<Material> filterMaterials();

	void printMaterialData(const Material & material);

	void printAllPropertyValues(const Material & material);

	void printMaterialProperty(const QString name, const QList<float> values);

	void printSelectedPropertyValues(const Material & material);
	
	void addMaterialsFromFolderDialog();

	void displayMaterialCount();

	void addMaterialsFromFileDialog();


private slots:

	// Toolbar Commands
    void on_actionOpen_triggered();

	void on_actionOpen_Folder_triggered();

	void on_actionClear_Materials_triggered();

	void on_actionAbout_triggered();

	// Search Settings
    void on_flagsCheckBox_clicked();

	void on_flags1LineEdit_editingFinished();

	void on_flags2LineEdit_editingFinished();


    void on_dstCheckBox_clicked();

	void on_dstLineEdit_editingFinished();

    void on_srcCheckBox_clicked();

	void on_srcLineEdit_editingFinished();


    void on_searchPushButton_clicked();

    void on_clearPushButton_clicked();


	void on_matPropCheckBox_clicked();

    void on_matPropLineEdit_editingFinished();

	// Display Settings
	void on_displayFileNameCheckBox_clicked();

	void on_displaySrcCheckBox_clicked();

	void on_displayDstCheckBox_clicked();

	void on_displayFlagsCheckBox_clicked();

	void on_allPropertiesRadioButton_clicked();

	void on_noPropertyRadioButton_clicked();

	void on_selectedPropertyRadioButton_clicked();

private:
    Ui::MainWindow *ui;
    SearchSettings searchSettings;

    bool hasValidSrc(Material material);
};

#endif // MAINWINDOW_H
