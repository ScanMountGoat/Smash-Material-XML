#include "Headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "Headers/materialxml.h"
#include "Headers/materialcontainer.h"

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
    ui->srcContainer->setEnabled(ui->srcCheckBox->isChecked());
    ui->dstContainer->setEnabled(ui->dstCheckBox->isChecked());
    ui->flagsContainer->setEnabled(ui->flagsCheckBox->isChecked());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Xml", ".", "Xml files (*.xml)");
    MaterialXml::materialDataFromXML(fileName);

    displayMaterials();
}

void MainWindow::on_actionOpen_Folder_triggered()
{
    QString directory = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home",
                                                         QFileDialog::ShowDirsOnly
                                                         | QFileDialog::DontResolveSymlinks);
    QDirIterator it(directory, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        if (it.next().endsWith(".xml")) {
            QString fileName = it.next();
            qInfo() << fileName;
            MaterialXml::materialDataFromXML(fileName);
        }
    }

    displayMaterials();
}

void MainWindow::on_flagsCheckBox_clicked()
{
    bool isChecked = ui->flagsCheckBox->isChecked();
    ui->flagsContainer->setEnabled(isChecked);
    searchSettings->filterFlags = ui->flagsCheckBox->isChecked();
}

void MainWindow::on_dstCheckBox_clicked()
{
    bool isChecked = ui->dstCheckBox->isChecked();
    ui->dstContainer->setEnabled(isChecked);
}

void MainWindow::on_srcCheckBox_clicked()
{
    bool isChecked = ui->srcCheckBox->isChecked();
    ui->srcContainer->setEnabled(isChecked);
}

void MainWindow::displayMaterials()
{
    // clear the text display for each new search
    ui->plainTextEdit->clear();

    for (int i = 0; i < materialList.length(); i++) {
        Material material = materialList.at(i);

        // Check flags using the selected flags values and comparison operator.
        if (searchSettings->filterFlags) {

            bool valid = (material.getFlags() & searchSettings->getFlags1()) == searchSettings->getFlags2();

            // Hopefully this cast is safe lol.
            int index = ui->flagsOpComboBox->currentIndex();
            SearchSettings::flagsComparison comparison = (SearchSettings::flagsComparison) index;
            switch (comparison) {
                case SearchSettings::flagsComparison::equals:
                    valid = (material.getFlags() & searchSettings->getFlags1()) == searchSettings->getFlags2();
                    break;
                case SearchSettings::flagsComparison::greater:
                    valid = (material.getFlags() & searchSettings->getFlags1()) > searchSettings->getFlags2();
                    break;
                case SearchSettings::flagsComparison::gEqual:
                    valid = (material.getFlags() & searchSettings->getFlags1()) >= searchSettings->getFlags2();
                    break;
                case SearchSettings::flagsComparison::less:
                    valid = (material.getFlags() & searchSettings->getFlags1()) < searchSettings->getFlags2();
                    break;
                case SearchSettings::flagsComparison::lEqual:
                    valid = (material.getFlags() & searchSettings->getFlags1()) <= searchSettings->getFlags2();
                    break;
            }

            if (valid) {
                QString flags;
                ui->plainTextEdit->appendPlainText(flags.setNum(material.getFlags(), 16));
            }
        }
    }
}

void MainWindow::on_searchPushButton_clicked()
{
    displayMaterials();
}

void MainWindow::on_clearPushButton_clicked()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_flags1LineEdit_editingFinished()
{
    // Use hex format. Ex: 9A011063
    QString text = ui->flags1LineEdit->text();
    bool ok;
    searchSettings->setFlags1(text.toUInt(&ok, 16));
}

void MainWindow::on_flags2LineEdit_editingFinished()
{
    // Use hex format. Ex: 9A011063
    QString text = ui->flags2LineEdit->text();
    bool ok;
    searchSettings->setFlags2(text.toUInt(&ok, 16));
}

void MainWindow::on_srcLineEdit_editingFinished()
{

}

void MainWindow::on_actionAbout_triggered()
{
    // Display license information.
    QString link = "<a href='https://github.com/ScanMountGoat/Smash-Material-XML/blob/master/license.txt'>GPL License</a>";
    QMessageBox::about(0, "About", link);
}
