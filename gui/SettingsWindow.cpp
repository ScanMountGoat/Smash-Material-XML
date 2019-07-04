#include "SettingsWindow.h"

#include <qdebug.h>


void SettingsWindow::setLineEditValues(SearchSettings *searchSettings) {
    ui->matPropLineEdit->setText(searchSettings->materialProperty);
    ui->srcLineEdit->setText(QString::number(searchSettings->srcFactor, 16));
    ui->dstLineEdit->setText(QString::number(searchSettings->dstFactor, 16));
    ui->cullModeLineEdit->setText(QString::number(searchSettings->cullMode, 16));
    ui->alphaTestLineEdit->setText(QString::number(searchSettings->alphaTest, 16));
    ui->alphaFuncLineEdit->setText(QString::number(searchSettings->alphaFunc, 16));
    ui->texCountLineEdit->setText(QString::number(searchSettings->textureCount, 10));
    ui->flags1LineEdit->setText(QString::number(searchSettings->flags1, 16));
    ui->flags2LineEdit->setText(QString::number(searchSettings->flags2, 16));
    ui->zBuffLineEdit->setText(QString::number(searchSettings->zBufferOffset, 10));
}

void SettingsWindow::setOpComboBoxValues(SearchSettings* searchSettings) {
    ui->srcOpComboBox->setCurrentIndex(static_cast<int>(searchSettings->srcComparison));
    ui->dstOpComboBox->setCurrentIndex(static_cast<int>(searchSettings->dstComparison));
    ui->zBuffOpComboBox->setCurrentIndex(static_cast<int>(searchSettings->zBuffComparison));
    ui->flagsOpComboBox->setCurrentIndex(static_cast<int>(searchSettings->flagsComparison));
    ui->texCountOpComboBox->setCurrentIndex(static_cast<int>(searchSettings->textureComparison));
    ui->cullModeOpComboBox->setCurrentIndex(static_cast<int>(searchSettings->cullComparison));
    ui->alphaTestOpComboBox->setCurrentIndex(static_cast<int>(searchSettings->alphaTestComparison));
    ui->alphaFuncOpComboBox->setCurrentIndex(static_cast<int>(searchSettings->alphaFuncComparison));
}

void SettingsWindow::setSearchSettings(SearchSettings *searchSettings) {
    ui->srcCheckBox->setChecked(searchSettings->filterSrc);
    ui->dstCheckBox->setChecked(searchSettings->filterDst);
    ui->matPropCheckBox->setChecked(searchSettings->filterPropertyName);
    ui->flagsCheckBox->setChecked(searchSettings->filterFlags);
    ui->cullModeCheckBox->setChecked(searchSettings->filterCullMode);
    ui->alphaFuncCheckBox->setChecked(searchSettings->filterAlphaFunc);
    ui->alphaTestCheckBox->setChecked(searchSettings->filterAlphaTest);
    ui->texCountCheckBox->setChecked(searchSettings->filterTextureCount);
    ui->zBuffCheckBox->setChecked(searchSettings->filterZBufferOffset);
}

void SettingsWindow::setDisplaySettings(SearchSettings *searchSettings) {
    ui->displaySrcCheckBox->setChecked(searchSettings->displaySrc);
    ui->displayDstCheckBox->setChecked(searchSettings->displayDst);
    ui->displayFileNameCheckBox->setChecked(searchSettings->displayFileName);
    ui->displayFlagsCheckBox->setChecked(searchSettings->displayFlags);
    ui->displayCullCheckBox->setChecked(searchSettings->displayCullMode);
    ui->displayTexturesCheckBox->setChecked(searchSettings->displayTextureHashes);
    ui->displayZBuffCheckBox->setChecked(searchSettings->displayZBufferOffset);
}

void SettingsWindow::showHideContainers() {
    // QWidgets for each search option are used to hide/unhide all child widgets.
    ui->srcContainer->setEnabled(ui->srcCheckBox->isChecked());
    ui->dstContainer->setEnabled(ui->dstCheckBox->isChecked());
    ui->flagsContainer->setEnabled(ui->flagsCheckBox->isChecked());
    ui->matPropContainer->setEnabled(ui->matPropCheckBox->isChecked());
    ui->cullModeContainer->setEnabled(ui->cullModeCheckBox->isChecked());
    ui->texCountContainer->setEnabled(ui->texCountCheckBox->isChecked());
    ui->alphaFuncContainer->setEnabled(ui->alphaFuncCheckBox->isChecked());
    ui->alphaTestContainer->setEnabled(ui->alphaTestCheckBox->isChecked());
    ui->zBuffContainer->setEnabled(ui->zBuffCheckBox->isChecked());
}

void SettingsWindow::setPropertyRadioButtons(SearchSettings *searchSettings) {
    switch (searchSettings->propertyDisplayMode) {
        case SearchSettings::PropertDisplay::All:
            ui->allPropertiesRadioButton->click();
            break;
        case SearchSettings::PropertDisplay::None:
            ui->noPropertyRadioButton->click();
            break;
        case SearchSettings::PropertDisplay::Selected:
            ui->selectedPropertyRadioButton->click();
            break;
    }
}

SettingsWindow::SettingsWindow(SearchSettings *searchSettings, QWidget *parent) : QMainWindow(parent), ui(new Ui::SettingsWindow) {
	ui->setupUi(this);

	this->searchSettings = searchSettings;

    // Set the GUI elements based on the previous search settings.
    setOpComboBoxValues(searchSettings);
    setDisplaySettings(searchSettings);
    setSearchSettings(searchSettings);
    setLineEditValues(searchSettings);
    setPropertyRadioButtons(searchSettings);
    showHideContainers();
}

SettingsWindow::~SettingsWindow() {
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
	QString text = ui->flags1LineEdit->text();
	bool validInput = true;
	if (validInput && text.length() == 8) {
		searchSettings->flags1 = (text.toUInt(&validInput, 16));
    }
}

void SettingsWindow::on_flags2LineEdit_editingFinished() {
	// Use hex format. Ex: 9A011063. 8 digits for 4 bytes of hex.
	QString text = ui->flags2LineEdit->text();
	bool validInput = true;
	if (validInput && text.length() == 8) {
		searchSettings->flags2 = (text.toUInt(&validInput, 16));
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

void SettingsWindow::on_cullModeCheckBox_clicked() {
	bool isChecked = ui->cullModeCheckBox->isChecked();
	searchSettings->filterCullMode = isChecked;
	ui->cullModeContainer->setEnabled(isChecked);
}

void SettingsWindow::on_cullModeLineEdit_editingFinished() {
	// Use hex format
	QString text = ui->dstLineEdit->text();
	bool ok;
	searchSettings->cullMode = (text.toInt(&ok, 16));
}

void SettingsWindow::on_cullModeOpComboBox_currentIndexChanged() {
    searchSettings->cullComparison = static_cast<SearchSettings::ComparisonOperation>(ui->cullModeOpComboBox->currentIndex());
}

void SettingsWindow::on_alphaFuncCheckBox_clicked() {
	bool isChecked = ui->alphaFuncCheckBox->isChecked();
	searchSettings->filterAlphaFunc = isChecked;
	ui->alphaFuncContainer->setEnabled(isChecked);
}

void SettingsWindow::on_alphaFuncLineEdit_editingFinished() {
	// Use hex format
	QString text = ui->alphaFuncLineEdit->text();
	bool ok;
	searchSettings->alphaFunc = (text.toInt(&ok, 16));
}

void SettingsWindow::on_alphaFuncOpComboBox_currentIndexChanged() {
    searchSettings->alphaFuncComparison = static_cast<SearchSettings::ComparisonOperation>(ui->alphaFuncOpComboBox->currentIndex());
}

void SettingsWindow::on_alphaTestCheckBox_clicked() {
	bool isChecked = ui->alphaTestCheckBox->isChecked();
	searchSettings->filterAlphaTest = isChecked;
	ui->alphaTestContainer->setEnabled(isChecked);
}

void SettingsWindow::on_alphaTestLineEdit_editingFinished() {
	// Use hex format
	QString text = ui->alphaTestLineEdit->text();
	bool ok;
	searchSettings->alphaTest = (text.toInt(&ok, 16));
}

void SettingsWindow::on_alphaTestOpComboBox_currentIndexChanged() {
    searchSettings->alphaTestComparison = static_cast<SearchSettings::ComparisonOperation>(ui->alphaTestOpComboBox->currentIndex());
}

void SettingsWindow::on_texCountCheckBox_clicked() {
	bool isChecked = ui->texCountCheckBox->isChecked();
	searchSettings->filterTextureCount = isChecked;
	ui->texCountContainer->setEnabled(isChecked);
}

void SettingsWindow::on_texCountLineEdit_editingFinished() {
	QString text = ui->texCountLineEdit->text();
	bool ok;
	searchSettings->textureCount = (text.toInt(&ok, 10));
}

void SettingsWindow::on_texCountOpComboBox_currentIndexChanged() {
    searchSettings->textureComparison = static_cast<SearchSettings::ComparisonOperation>(ui->texCountOpComboBox->currentIndex());
}

void SettingsWindow::on_flagsOpComboBox_currentIndexChanged() {
    searchSettings->flagsComparison = static_cast<SearchSettings::ComparisonOperation>(ui->flagsOpComboBox->currentIndex());
}

void SettingsWindow::on_srcOpComboBox_currentIndexChanged() {
    searchSettings->srcComparison = static_cast<SearchSettings::ComparisonOperation>(ui->srcOpComboBox->currentIndex());
}

void SettingsWindow::on_dstOpComboBox_currentIndexChanged() {
    searchSettings->dstComparison = static_cast<SearchSettings::ComparisonOperation>(ui->dstOpComboBox->currentIndex());
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

void SettingsWindow::on_displayTexturesCheckBox_clicked() {
	searchSettings->displayTextureHashes = ui->displayTexturesCheckBox->isChecked();
}

void SettingsWindow::on_displayCullCheckBox_clicked() {
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

void SettingsWindow::on_zBuffCheckBox_clicked() {
    bool isChecked = ui->zBuffCheckBox->isChecked();
    ui->zBuffContainer->setEnabled(isChecked);
    searchSettings->filterZBufferOffset = isChecked;
}

void SettingsWindow::on_zBuffOpComboBox_currentIndexChanged() {
    searchSettings->zBuffComparison = static_cast<SearchSettings::ComparisonOperation>(ui->zBuffOpComboBox->currentIndex());
}

void SettingsWindow::on_zBuffLineEdit_editingFinished() {
    QString text = ui->zBuffLineEdit->text();
    bool ok;
    searchSettings->zBufferOffset = (text.toInt(&ok, 10));
}

void SettingsWindow::on_displayZBuffCheckBox_clicked() {
    searchSettings->displayZBufferOffset = ui->displayZBuffCheckBox->isChecked();
}
