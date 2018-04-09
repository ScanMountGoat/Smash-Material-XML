#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "src/searchsettings.h"

#include <QMainWindow>
#include <QList>

#include "src/material.h"
#include "gui/SettingsWindow.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {
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

	void on_actionSearch_Settings_triggered();

	// Search Bar Buttons
	void on_searchPushButton_clicked();

	void on_clearPushButton_clicked();


private:
	Ui::MainWindow *ui;
	SearchSettings searchSettings;
};

#endif // MAINWINDOW_H