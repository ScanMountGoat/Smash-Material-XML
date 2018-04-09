#ifndef SETTINGS_WINDOW_H
#define SETTINGS_WINDOW_H

#include <QMainWindow>
#include "ui_settingswindow.h"

#include "src/searchsettings.h"

namespace Ui {
	class SettingsWindow;
}

class SettingsWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit SettingsWindow(SearchSettings *searchSettings, QWidget *parent = Q_NULLPTR);
	~SettingsWindow();

private slots:
	// Search Settings
	void on_flagsCheckBox_clicked();

	void on_flags1LineEdit_editingFinished();

	void on_flags2LineEdit_editingFinished();


	void on_dstCheckBox_clicked();

	void on_dstLineEdit_editingFinished();

	void on_srcCheckBox_clicked();

	void on_srcLineEdit_editingFinished();

	void on_matPropCheckBox_clicked();

	void on_matPropLineEdit_editingFinished();

	void on_flagsOpComboBox_currentIndexChanged();

	void on_srcOpComboBox_currentIndexChanged();

	void on_dstOpComboBox_currentIndexChanged();

	// Display Settings
	void on_displayFileNameCheckBox_clicked();

	void on_displaySrcCheckBox_clicked();

	void on_displayDstCheckBox_clicked();

	void on_displayFlagsCheckBox_clicked();

	void on_allPropertiesRadioButton_clicked();

	void on_noPropertyRadioButton_clicked();

	void on_selectedPropertyRadioButton_clicked();

private:
	Ui::SettingsWindow *ui;

	// Probably a cleaner way of handling this. 
	// The object is stored in MainWindow for the duration of the application and modified here.
	SearchSettings *searchSettings;

};

#endif
