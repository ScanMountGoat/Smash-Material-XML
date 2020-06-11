#include "gui/mainwindow.h"

#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QDirIterator>
#include <QtSql>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);

	// Use a monospaced font so all the material property values are aligned.
	ui->plainTextEdit->setFont(QFont("Courier", 10));
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::on_actionSearch_Settings_triggered() {
	SettingsWindow *settingsWindow = new SettingsWindow(&searchSettings);
	settingsWindow->setAttribute(Qt::WA_DeleteOnClose);
	settingsWindow->show();
}

void MainWindow::printMaterialCount() {
	ui->plainTextEdit->clear();
	ui->plainTextEdit->appendPlainText(QString::number(searchSettings.materialList.count())
		+ " material(s) added.");
}

void MainWindow::printFilteredMaterials() {
	// Clear the text display before each new search.
	ui->plainTextEdit->clear();

	QList<Material> filteredMaterials = searchSettings.filterMaterials();
	for (auto const &material : filteredMaterials) {
		printMaterialData(material);
	}
}

void MainWindow::printSrc(const Material& material) {
    QString src;
    ui->plainTextEdit->appendPlainText("src: " + src.setNum(material.srcFactor, 10));
}

void MainWindow::printFlags(const Material& material) {
    QString flags;
    ui->plainTextEdit->appendPlainText(flags.setNum(material.flags, 16));
}

void MainWindow::printDst(const Material& material) {
    QString dst;
    ui->plainTextEdit->appendPlainText("dst: " + dst.setNum(material.dstFactor, 10));
}

void MainWindow::printCullMode(const Material& material) {
    QString cullMode;
    ui->plainTextEdit->appendPlainText("cull mode: " + cullMode.setNum(material.cullMode, 10));
}

void MainWindow::printTextures(const Material& material) {
    ui->plainTextEdit->appendPlainText(material.textures);
}

void MainWindow::printZBufferOffset(const Material& material) {
    QString zBufOffset;
    ui->plainTextEdit->appendPlainText("zbuffoffset: " + zBufOffset.setNum(material.zBufferOffset, 10));
}

void MainWindow::printMaterialData(const Material & material) {
	if (searchSettings.displayFileName) {
		ui->plainTextEdit->appendPlainText(material.fileName);
	}

	if (searchSettings.displayFlags) {
        printFlags(material);
	}

	if (searchSettings.displaySrc) {
        printSrc(material);
	}

	if (searchSettings.displayDst) {
        printDst(material);
	}

	if (searchSettings.displayCullMode) {
        printCullMode(material);
	}

    if (searchSettings.displayZBufferOffset) {
        printZBufferOffset(material);
    }

	if (searchSettings.displayTextureHashes) {
        printTextures(material);
	}

	switch (searchSettings.propertyDisplayMode) {
		case SearchSettings::PropertDisplay::None:
			break;
		case SearchSettings::PropertDisplay::Selected:
			printSelectedPropertyValues(material);
			break;
		case SearchSettings::PropertDisplay::All:
			printAllPropertyValues(material);
			break;
	}

	// Put a line between each material.
	ui->plainTextEdit->appendPlainText("\n");
}

void MainWindow::printAllPropertyValues(const Material & material) {
    ui->plainTextEdit->appendPlainText(material.properties);
}

void MainWindow::printSelectedPropertyValues(const Material & material) {
    QString key = "NU_" + searchSettings.materialProperty;
    for (const auto& line : material.properties.split('\n')) {
        if (line.startsWith(key, Qt::CaseInsensitive)) {
            ui->plainTextEdit->appendPlainText(line);
        }
    }
}

void MainWindow::printMaterialProperty(const QString name, const QList<float> values) {
	// Add padding so that all the values are in the same column. 
	// The longest property name is NU_dualNormalScrollParams.
	QString maxName = "NU_dualNormalScrollParams";
	QString propertyText = name.leftJustified(maxName.length() + 1, ' ');

	// Add the values to the same line.
	for (int i = 0; i < values.size(); i++) {
        QString valueString = QString::number(static_cast<double>(values.at(i)), 'f', 4).leftJustified(20, ' ');
		propertyText += valueString + " ";
	}
	ui->plainTextEdit->appendPlainText(propertyText);
}

void MainWindow::on_searchPushButton_clicked() {
    printFilteredMaterials();
}

void MainWindow::on_clearPushButton_clicked() {
	ui->plainTextEdit->clear();
}

void MainWindow::on_actionAbout_triggered() {
	// Display license information.
	QString link = "<a href='https://github.com/ScanMountGoat/Smash-Material-XML/blob/master/license.txt'>GPL License</a>";
    QMessageBox::about(nullptr, "About", link);
}
