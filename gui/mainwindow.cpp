#include "gui/mainwindow.h"

#include "ui_mainwindow.h"
#include "src/materialxml.h"
#include "src/materialfiltering.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QDirIterator>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	// Use a monospaced font. 
	ui->plainTextEdit->setFont(QFont("Courier", 10));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_actionSearch_Settings_triggered() 
{
	SettingsWindow *settingsWindow = new SettingsWindow(&searchSettings);
	settingsWindow->setAttribute(Qt::WA_DeleteOnClose);
	settingsWindow->show();
}

void MainWindow::addMaterialsFromFileDialog() 
{
	QString fileName = QFileDialog::getOpenFileName(this, "Open Xml", ".", "Xml files (*.xml)");
	if (fileName.isEmpty())
		return;

	MaterialXml::addMaterialsFromXML(fileName, searchSettings);
	displayMaterialCount();
}

void MainWindow::on_actionOpen_triggered()
{
	addMaterialsFromFileDialog();
}

void MainWindow::on_actionOpen_Folder_triggered()
{
	addMaterialsFromFolderDialog();
}

void MainWindow::addMaterialsFromFolderDialog() 
{
	QString directory = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (directory.isEmpty())
		return;

	QDirIterator it(directory, QDirIterator::Subdirectories);
	while (it.hasNext()) {
		if (it.next().endsWith(".xml")) {
			QString fileName = it.next();
			MaterialXml::addMaterialsFromXML(fileName, searchSettings);
			displayMaterialCount();
		}
	}
}

void MainWindow::displayMaterialCount() 
{
	ui->plainTextEdit->clear();
	ui->plainTextEdit->appendPlainText(QString::number(searchSettings.materialList.count())
		+ " material(s) added.");
}

void MainWindow::displayFilteredMaterials()
{
	// Clear the text display before each new search.
	ui->plainTextEdit->clear();

	QList<Material> filteredMaterials = materialfiltering::filterMaterials(searchSettings);
	for (auto const &material : filteredMaterials) {
		printMaterialData(material);
	}
}

void MainWindow::printMaterialData(const Material & material) 
{
	if (searchSettings.displayFileName) {
		ui->plainTextEdit->appendPlainText(material.fileName);
	}

	if (searchSettings.displayFlags) {
		QString flags;
		ui->plainTextEdit->appendPlainText(flags.setNum(material.flags, 16));
	}

	if (searchSettings.displaySrc) {
		QString src;
		ui->plainTextEdit->appendPlainText("src: " + src.setNum(material.srcFactor, 16));
	}

	if (searchSettings.displayDst) {
		QString dst;
		ui->plainTextEdit->appendPlainText("dst: " + dst.setNum(material.dstFactor, 16));
	}

	if (searchSettings.displayCullMode) {
		QString cullMode;
		ui->plainTextEdit->appendPlainText("cull mode: " + cullMode.setNum(material.cullMode, 16));
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

void MainWindow::printAllPropertyValues(const Material & material) 
{
	for (auto it = material.properties.begin(); it != material.properties.end(); ++it) {
		printMaterialProperty(it.key(), it.value());
	}
}

void MainWindow::printSelectedPropertyValues(const Material & material) {
	printMaterialProperty("NU_" + searchSettings.materialProperty, material.properties["NU_" + searchSettings.materialProperty]);
}

void MainWindow::printMaterialProperty(const QString name, const QList<float> values) 
{
	// Add padding so that all the values are in the same column. 
	// The longest property name is NU_dualNormalScrollParams.
	QString maxName = "NU_dualNormalScrollParams";
	QString propertyText = name.leftJustified(maxName.length() + 1, ' ');

	// Add the values to the same line.
	for (int i = 0; i < values.size(); i++) {
		QString valueString = QString::number(values.at(i), 'f', 4).leftJustified(20, ' ');
		propertyText += valueString + " ";
	}
	ui->plainTextEdit->appendPlainText(propertyText + "\n");
}

void MainWindow::on_searchPushButton_clicked()
{
	displayFilteredMaterials();
}

void MainWindow::on_clearPushButton_clicked()
{
	ui->plainTextEdit->clear();
}

void MainWindow::on_actionAbout_triggered()
{
	// Display license information.
	QString link = "<a href='https://github.com/ScanMountGoat/Smash-Material-XML/blob/master/license.txt'>GPL License</a>";
	QMessageBox::about(0, "About", link);
}

void MainWindow::on_actionClear_Materials_triggered() 
{
	searchSettings.materialList.clear();
	ui->plainTextEdit->clear();
	ui->plainTextEdit->appendPlainText("Materials cleared.");
}

