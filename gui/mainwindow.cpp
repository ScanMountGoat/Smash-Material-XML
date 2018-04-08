#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "src/materialxml.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QDirIterator>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	// Enable/disable the different search options.
	// Containers (QWidget) are used to hide/unhide all child widgets.
	ui->srcContainer->setEnabled(ui->srcCheckBox->isChecked());
	ui->dstContainer->setEnabled(ui->dstCheckBox->isChecked());
	ui->flagsContainer->setEnabled(ui->flagsCheckBox->isChecked());
	ui->matPropContainer->setEnabled(ui->matPropCheckBox->isChecked());
}

MainWindow::~MainWindow()
{
	delete ui;
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

void MainWindow::on_flagsCheckBox_clicked()
{
	bool isChecked = ui->flagsCheckBox->isChecked();
	ui->flagsContainer->setEnabled(isChecked);
	searchSettings.filterFlags = isChecked;
}

void MainWindow::on_dstCheckBox_clicked()
{
	bool isChecked = ui->dstCheckBox->isChecked();
	ui->dstContainer->setEnabled(isChecked);
	searchSettings.filterDst = isChecked;
}

void MainWindow::on_srcCheckBox_clicked()
{
	bool isChecked = ui->srcCheckBox->isChecked();
	ui->srcContainer->setEnabled(isChecked);
	searchSettings.filterSrc = isChecked;
}

bool MainWindow::hasValidSrc(Material material)
{
	int index = ui->srcOpComboBox->currentIndex();
	SearchSettings::ComparisonOperation comparison = (SearchSettings::ComparisonOperation) index;
	return SearchSettings::matchesSearch(comparison, material.srcFactor, searchSettings.srcFactor);
}

void MainWindow::displayFilteredMaterials()
{
	// Clear the text display before each new search.
	ui->plainTextEdit->clear();

	QList<Material> filteredMaterials = filterMaterials();
	for (auto const &material : filteredMaterials) {
		printMaterialData(material);
	}
}

QList<Material> MainWindow::filterMaterials() 
{
	QList<Material> filteredMaterialList;
	for (auto const &material : searchSettings.materialList) {
		bool validMaterial = true;

		// Check flags using the selected flags values and comparison operator.
		if (searchSettings.filterFlags) {
			int index = ui->flagsOpComboBox->currentIndex();
			SearchSettings::ComparisonOperation comparison = (SearchSettings::ComparisonOperation) index;
			uint value = material.flags & searchSettings.flags1;

			bool validFlags = SearchSettings::matchesSearch(comparison, value, searchSettings.flags2);
			validMaterial = validMaterial && validFlags;
		}

		if (searchSettings.filterSrc) {
			bool validSrc = hasValidSrc(material);
			validMaterial = validMaterial && validSrc;
		}

		if (searchSettings.filterDst) {
			int index = ui->dstOpComboBox->currentIndex();
			SearchSettings::ComparisonOperation comparison = (SearchSettings::ComparisonOperation) index;

			bool validDst = SearchSettings::matchesSearch(comparison, material.dstFactor, searchSettings.dstFactor);
			validMaterial = validMaterial && validDst;
		}

		if (searchSettings.filterPropertyName) {
			bool validMaterialProperty = material.properties.contains("NU_" + searchSettings.materialProperty);
			validMaterial = validMaterial && validMaterialProperty;
		}

		if (validMaterial) {
			filteredMaterialList.append(material);
		}
	}

	return filteredMaterialList;
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

	switch (searchSettings.propertyDisplayMode) {
	case SearchSettings::PropertDisplay::None:
		break;
	case SearchSettings::PropertDisplay::Selected:
		QString propertyText = "NU_" + searchSettings.materialProperty + "\n";

		// Add the space separated values to a new line.
		QList<float> values = material.properties["NU_" + searchSettings.materialProperty];
		for (int i = 0; i < values.size(); i++) {
			propertyText += QString::number(values.at(i)) + " ";
		}
		ui->plainTextEdit->appendPlainText(propertyText);
		break;
	}


	// Put a line between each material.
	ui->plainTextEdit->appendPlainText("\n");
}

void MainWindow::on_searchPushButton_clicked()
{
	displayFilteredMaterials();
}

void MainWindow::on_clearPushButton_clicked()
{
	ui->plainTextEdit->clear();
}

void MainWindow::on_flags1LineEdit_editingFinished()
{
	// Use hex format. Ex: 9A011063. 8 digits for 4 bytes of hex.
	// Use red background for invalid inputs.
	QString text = ui->flags1LineEdit->text();
	bool validInput = true;
	if (validInput && text.length() == 8) {
		searchSettings.flags1 = (text.toUInt(&validInput, 16));

		QPalette palette;
		palette.setColor(QPalette::Base, Qt::white);
		palette.setColor(QPalette::Text, Qt::black);
		ui->flags1LineEdit->setPalette(palette);
	} else {
		QPalette palette;
		palette.setColor(QPalette::Base, Qt::red);
		palette.setColor(QPalette::Text, Qt::black);
		ui->flags1LineEdit->setPalette(palette);
	}
}

void MainWindow::on_flags2LineEdit_editingFinished()
{
	// Use hex format. Ex: 9A011063. 8 digits for 4 bytes of hex.
	QString text = ui->flags2LineEdit->text();
	bool validInput = true;
	if (validInput && text.length() == 8) {
		searchSettings.flags2 = (text.toUInt(&validInput, 16));

		QPalette palette;
		palette.setColor(QPalette::Base, Qt::white);
		palette.setColor(QPalette::Text, Qt::black);
		ui->flags2LineEdit->setPalette(palette);
	} else {
		QPalette palette;
		palette.setColor(QPalette::Base, Qt::red);
		palette.setColor(QPalette::Text, Qt::black);
		ui->flags2LineEdit->setPalette(palette);
	}
}

void MainWindow::on_srcLineEdit_editingFinished()
{
	// Use hex format
	QString text = ui->srcLineEdit->text();
	bool ok;
	searchSettings.srcFactor = (text.toInt(&ok, 16));
}

void MainWindow::on_dstLineEdit_editingFinished()
{
	// Use hex format
	QString text = ui->dstLineEdit->text();
	bool ok;
	searchSettings.dstFactor = (text.toInt(&ok, 16));
}

void MainWindow::on_actionAbout_triggered()
{
	// Display license information.
	QString link = "<a href='https://github.com/ScanMountGoat/Smash-Material-XML/blob/master/license.txt'>GPL License</a>";
	QMessageBox::about(0, "About", link);
}

void MainWindow::on_matPropLineEdit_editingFinished()
{
	QString text = ui->matPropLineEdit->text();
	searchSettings.materialProperty = text;
}

void MainWindow::on_displayFileNameCheckBox_clicked() 
{
	searchSettings.displayFileName = ui->displayFileNameCheckBox->isChecked();
}

void MainWindow::on_displaySrcCheckBox_clicked()
{
	searchSettings.displaySrc = ui->displaySrcCheckBox->isChecked();
}

void MainWindow::on_displayDstCheckBox_clicked() 
{
	searchSettings.displayDst = ui->displayDstCheckBox->isChecked();
}

void MainWindow::on_displayFlagsCheckBox_clicked() 
{
	searchSettings.displayFlags = ui->displayFlagsCheckBox->isChecked();
}

void MainWindow::on_matPropCheckBox_clicked()
{
	bool isChecked = ui->matPropCheckBox->isChecked();
	ui->matPropContainer->setEnabled(isChecked);
	searchSettings.filterPropertyName = isChecked;
}

void MainWindow::on_actionClear_Materials_triggered() 
{
	searchSettings.materialList.clear();
	ui->plainTextEdit->clear();
	ui->plainTextEdit->appendPlainText("Materials cleared.");
}

