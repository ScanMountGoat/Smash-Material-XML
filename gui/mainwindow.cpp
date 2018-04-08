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

	// Use a monospaced font. 
	ui->plainTextEdit->setFont(QFont("Courier", 10));

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

void MainWindow::on_allPropertiesRadioButton_clicked() 
{
	if (ui->allPropertiesRadioButton->isChecked()) {
		searchSettings.propertyDisplayMode = SearchSettings::PropertDisplay::All;
	}
}

void MainWindow::on_noPropertyRadioButton_clicked() 
{
	if (ui->noPropertyRadioButton->isChecked()) {
		searchSettings.propertyDisplayMode = SearchSettings::PropertDisplay::None;
	}
}

void MainWindow::on_selectedPropertyRadioButton_clicked() 
{
	if (ui->selectedPropertyRadioButton->isChecked()) {
		searchSettings.propertyDisplayMode = SearchSettings::PropertDisplay::Selected;
	}
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

