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

    // Print material values to text box.
    void printFilteredMaterials();

    void printMaterialCount();

	void printMaterialData(const Material & material);

	void printAllPropertyValues(const Material & material);

	void printMaterialProperty(const QString name, const QList<float> values);

	void printSelectedPropertyValues(const Material & material);

    void printSrc(const Material& material);

    void printFlags(const Material& material);

    void printDst(const Material& material);

    void printCullMode(const Material& material);

    void printTextures(const Material& material);

    // Add materials to material list.
	void addMaterialsFromFolderDialog();

	void addMaterialsFromFileDialog();

        void printZBufferOffset(const Material& material);
        
private slots:
	void on_actionAbout_triggered();

	void on_actionSearch_Settings_triggered();

	void on_searchPushButton_clicked();

	void on_clearPushButton_clicked();

private:
	Ui::MainWindow *ui;
	SearchSettings searchSettings;
};

#endif // MAINWINDOW_H
