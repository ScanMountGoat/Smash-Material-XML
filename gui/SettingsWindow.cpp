#include "SettingsWindow.h"

#include <qdebug.h>


SettingsWindow::SettingsWindow(SearchSettings *searchSettings, QWidget *parent) : QMainWindow(parent), ui(new Ui::SettingsWindow)
{
	ui->setupUi(this);

	// Set the GUI elements based on the previous search settings.
	this->searchSettings = searchSettings;

	// Set display settings.
	ui->displayDstCheckBox->setChecked(searchSettings->displayDst);
	ui->displaySrcCheckBox->setChecked(searchSettings->displaySrc);
	ui->displayFileNameCheckBox->setChecked(searchSettings->displayFileName);
	ui->displayFlagsCheckBox->setChecked(searchSettings->displayFlags);
	ui->displayCullCheckBox->setChecked(searchSettings->displayCullMode);

	// Set search settings.
	ui->dstCheckBox->setChecked(searchSettings->filterDst);
	ui->srcCheckBox->setChecked(searchSettings->filterSrc);
	ui->matPropCheckBox->setChecked(searchSettings->filterPropertyName);
	ui->flagsCheckBox->setChecked(searchSettings->filterFlags);
	ui->cullModeCheckBox->setChecked(searchSettings->filterCullMode);

	// Enable/disable the different search options.
	// Containers (QWidget) are used to hide/unhide all child widgets.
	ui->srcContainer->setEnabled(ui->srcCheckBox->isChecked());
	ui->dstContainer->setEnabled(ui->dstCheckBox->isChecked());
	ui->flagsContainer->setEnabled(ui->flagsCheckBox->isChecked());
	ui->matPropContainer->setEnabled(ui->matPropCheckBox->isChecked());
	ui->cullModeContainer->setEnabled(ui->cullModeCheckBox->isChecked());
}

SettingsWindow::~SettingsWindow()
{
	delete ui;
}

void SettingsWindow::on_flagsCheckBox_clicked() {
	bool isChecked = ui->flagsCheckBox->isChecked();
	ui->flagsContainer->setEnabled(isChecked);
	searchSettings->filterFlags = isChecked;
}

void SettingsWindow::on_dstCheckBox_clicked() {
	bool isChecked = ui->dstCheckBox->isChecked();
	ui->dstContainer->setEnabled(isChecked);
	searchSettings->filterDst = isChecked;
}

void SettingsWindow::on_srcCheckBox_clicked() {
	bool isChecked = ui->srcCheckBox->isChecked();
	ui->srcContainer->setEnabled(isChecked);
	searchSettings->filterSrc = isChecked;
}

void SettingsWindow::on_flags1LineEdit_editingFinished() {
	// Use hex format. Ex: 9A011063. 8 digits for 4 bytes of hex.
	// Use red background for invalid inputs.
	QString text = ui->flags1LineEdit->text();
	bool validInput = true;
	if (validInput && text.length() == 8) {
		searchSettings->flags1 = (text.toUInt(&validInput, 16));

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

void SettingsWindow::on_flags2LineEdit_editingFinished() {
	// Use hex format. Ex: 9A011063. 8 digits for 4 bytes of hex.
	QString text = ui->flags2LineEdit->text();
	bool validInput = true;
	if (validInput && text.length() == 8) {
		searchSettings->flags2 = (text.toUInt(&validInput, 16));

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

void SettingsWindow::on_srcLineEdit_editingFinished() {
	// Use hex format
	QString text = ui->srcLineEdit->text();
	bool ok;
	searchSettings->srcFactor = (text.toInt(&ok, 16));
}

void SettingsWindow::on_dstLineEdit_editingFinished() {
	// Use hex format
	QString text = ui->dstLineEdit->text();
	bool ok;
	searchSettings->dstFactor = (text.toInt(&ok, 16));
}

void SettingsWindow::on_matPropLineEdit_editingFinished() {
	QString text = ui->matPropLineEdit->text();
	searchSettings->materialProperty = text;
}

void SettingsWindow::on_cullModeCheckBox_clicked() 
{
	bool isChecked = ui->cullModeCheckBox->isChecked();
	searchSettings->filterCullMode = isChecked;
	ui->cullModeContainer->setEnabled(isChecked);
}

void SettingsWindow::on_cullModeLineEdit_editingFinished() 
{
	// Use hex format
	QString text = ui->dstLineEdit->text();
	bool ok;
	searchSettings->cullMode = (text.toInt(&ok, 16));
}

void SettingsWindow::on_cullModeOpComboBox_currentIndexChanged() 
{
	searchSettings->cullOperation = (SearchSettings::ComparisonOperation)ui->cullModeOpComboBox->currentIndex();
}

void SettingsWindow::on_alphaFuncCheckBox_clicked() 
{
	bool isChecked = ui->alphaFuncCheckBox->isChecked();
	searchSettings->filterAlphaFunc = isChecked;
	ui->alphaFuncContainer->setEnabled(isChecked);
}

void SettingsWindow::on_alphaFuncLineEdit_editingFinished() 
{
	// Use hex format
	QString text = ui->alphaFuncLineEdit->text();
	bool ok;
	searchSettings->alphaFunc = (text.toInt(&ok, 16));
}

void SettingsWindow::on_alphaFuncOpComboBox_currentIndexChanged() 
{
}

void SettingsWindow::on_alphaTestCheckBox_clicked() 
{
}

void SettingsWindow::on_alphaTestLineEdit_editingFinished() 
{
}

void SettingsWindow::on_alphaTestOpComboBox_currentIndexChanged() 
{
}

void SettingsWindow::on_flagsOpComboBox_currentIndexChanged() 
{
	searchSettings->flagsOperation = (SearchSettings::ComparisonOperation)ui->flagsOpComboBox->currentIndex();
}

void SettingsWindow::on_srcOpComboBox_currentIndexChanged() {
	searchSettings->srcOperation = (SearchSettings::ComparisonOperation)ui->srcOpComboBox->currentIndex();
}

void SettingsWindow::on_dstOpComboBox_currentIndexChanged() {
	searchSettings->dstOperation = (SearchSettings::ComparisonOperation)ui->dstOpComboBox->currentIndex();
}

void SettingsWindow::on_displayFileNameCheckBox_clicked() {
	searchSettings->displayFileName = ui->displayFileNameCheckBox->isChecked();
}

void SettingsWindow::on_displaySrcCheckBox_clicked() {
	searchSettings->displaySrc = ui->displaySrcCheckBox->isChecked();
}

void SettingsWindow::on_displayDstCheckBox_clicked() {
	searchSettings->displayDst = ui->displayDstCheckBox->isChecked();
}

void SettingsWindow::on_displayFlagsCheckBox_clicked() {
	searchSettings->displayFlags = ui->displayFlagsCheckBox->isChecked();
}

void SettingsWindow::on_displayTexturesCheckBox_clicked() 
{
	searchSettings->displayTextureHashes = ui->displayTexturesCheckBox->isChecked();
}

void SettingsWindow::on_displayCullCheckBox_clicked() 
{
	searchSettings->displayCullMode = ui->displayCullCheckBox->isChecked();
}

void SettingsWindow::on_allPropertiesRadioButton_clicked() {
	if (ui->allPropertiesRadioButton->isChecked()) {
		searchSettings->propertyDisplayMode = SearchSettings::PropertDisplay::All;
	}
}

void SettingsWindow::on_noPropertyRadioButton_clicked() {
	if (ui->noPropertyRadioButton->isChecked()) {
		searchSettings->propertyDisplayMode = SearchSettings::PropertDisplay::None;
	}
}

void SettingsWindow::on_selectedPropertyRadioButton_clicked() {
	if (ui->selectedPropertyRadioButton->isChecked()) {
		searchSettings->propertyDisplayMode = SearchSettings::PropertDisplay::Selected;
	}
}

void SettingsWindow::on_matPropCheckBox_clicked() {
	bool isChecked = ui->matPropCheckBox->isChecked();
	ui->matPropContainer->setEnabled(isChecked);
	searchSettings->filterPropertyName = isChecked;
}

