#include "SettingsWindow.h"


SettingsWindow::SettingsWindow(SearchSettings *searchSettings, QWidget *parent) : QMainWindow(parent), ui(new Ui::SettingsWindow)
{
	ui->setupUi(this);
	// Enable/disable the different search options.
	// Containers (QWidget) are used to hide/unhide all child widgets.
	ui->srcContainer->setEnabled(ui->srcCheckBox->isChecked());
	ui->dstContainer->setEnabled(ui->dstCheckBox->isChecked());
	ui->flagsContainer->setEnabled(ui->flagsCheckBox->isChecked());
	ui->matPropContainer->setEnabled(ui->matPropCheckBox->isChecked());
	this->searchSettings = searchSettings;
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

bool SettingsWindow::hasValidSrc(Material material) {
	int index = ui->srcOpComboBox->currentIndex();
	SearchSettings::ComparisonOperation comparison = (SearchSettings::ComparisonOperation) index;
	return SearchSettings::matchesSearch(comparison, material.srcFactor, searchSettings->srcFactor);
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

