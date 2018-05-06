#include "gui/mainwindow.h"

#include "ui_mainwindow.h"
#include "src/materialxml.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QDirIterator>

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

void MainWindow::addMaterialsFromFileDialog() {
	QString fileName = QFileDialog::getOpenFileName(this, "Open Xml", ".", "Xml files (*.xml)");
	if (fileName.isEmpty())
		return;

	MaterialXml::addMaterialsFromXML(fileName, searchSettings);
    printMaterialCount();
}

void MainWindow::on_actionOpen_triggered() {
	addMaterialsFromFileDialog();
}

void MainWindow::on_actionOpen_Folder_triggered() {
	addMaterialsFromFolderDialog();
}

void MainWindow::addMaterialsFromFolderDialog() {
    QString directory = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home",
                                                          QFileDialog::ShowDirsOnly);
	if (directory.isEmpty())
		return;

	QDirIterator it(directory, QDirIterator::Subdirectories);
	while (it.hasNext()) {
		if (it.next().endsWith(".xml")) {
			QString fileName = it.next();
			MaterialXml::addMaterialsFromXML(fileName, searchSettings);
            printMaterialCount();
		}
	}
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
    ui->plainTextEdit->appendPlainText("src: " + src.setNum(material.srcFactor, 16));
}

void MainWindow::printFlags(const Material& material) {
    QString flags;
    ui->plainTextEdit->appendPlainText(flags.setNum(material.flags, 16));
}

void MainWindow::printDst(const Material& material) {
    QString dst;
    ui->plainTextEdit->appendPlainText("dst: " + dst.setNum(material.dstFactor, 16));
}

void MainWindow::printCullMode(const Material& material) {
    QString cullMode;
    ui->plainTextEdit->appendPlainText("cull mode: " + cullMode.setNum(material.cullMode, 16));
}

void MainWindow::printTextures(const Material& material) {
    for (auto const hash : material.textureHashes) {
        ui->plainTextEdit->appendPlainText("texture: " + hash);
    }
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
	for (auto it = material.properties.begin(); it != material.properties.end(); ++it) {
		printMaterialProperty(it.key(), it.value());
	}
}

void MainWindow::printSelectedPropertyValues(const Material & material) {
    QString key = "NU_" + searchSettings.materialProperty;
    printMaterialProperty("NU_" + searchSettings.materialProperty, material.properties[key]);
}

void MainWindow::printMaterialProperty(const QString name, const QList<float> values) {
	// Add padding so that all the values are in the same column. 
	// The longest property name is NU_dualNormalScrollParams.
	QString maxName = "NU_dualNormalScrollParams";
	QString propertyText = name.leftJustified(maxName.length() + 1, ' ');

	// Add the values to the same line.
	for (int i = 0; i < values.size(); i++) {
		QString valueString = QString::number(values.at(i), 'f', 4).leftJustified(20, ' ');
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
	QMessageBox::about(0, "About", link);
}

void MainWindow::on_actionClear_Materials_triggered() {
	searchSettings.materialList.clear();
	ui->plainTextEdit->clear();
	ui->plainTextEdit->appendPlainText("Materials cleared.");
}

