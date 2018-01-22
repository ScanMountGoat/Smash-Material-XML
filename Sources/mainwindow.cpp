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
    searchSettings->searchFlags = ui->flagsCheckBox->isChecked();
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

        // I should be able to simplify this using helper functions.
        bool validMaterial = false;
        bool validFlags = false;
        bool validSrc = false;
        bool validDst = false;

        // Check flags using the selected flags values and comparison operator.
        if (searchSettings->searchFlags) {
            // Hopefully this cast is safe lol.
            int index = ui->flagsOpComboBox->currentIndex();
            SearchSettings::ComparisonOp comparison = (SearchSettings::ComparisonOp) index;

            switch (comparison) {
                case SearchSettings::ComparisonOp::equals:
                    validFlags = (material.getFlags() & searchSettings->getFlags1()) == searchSettings->getFlags2();
                    break;
                case SearchSettings::ComparisonOp::greater:
                    validFlags = (material.getFlags() & searchSettings->getFlags1()) > searchSettings->getFlags2();
                    break;
                case SearchSettings::ComparisonOp::gEqual:
                    validFlags = (material.getFlags() & searchSettings->getFlags1()) >= searchSettings->getFlags2();
                    break;
                case SearchSettings::ComparisonOp::less:
                    validFlags = (material.getFlags() & searchSettings->getFlags1()) < searchSettings->getFlags2();
                    break;
                case SearchSettings::ComparisonOp::lEqual:
                    validFlags = (material.getFlags() & searchSettings->getFlags1()) <= searchSettings->getFlags2();
                    break;
            }
        }

        if (searchSettings->searchSrc) {
            int index = ui->srcOpComboBox->currentIndex();
            SearchSettings::ComparisonOp comparison = (SearchSettings::ComparisonOp) index;
            validDst = SearchSettings::matchesSearch(comparison, material.srcFactor, SearchSettings::srcFactor);
        }

        if (searchSettings->searchDst) {
            int index = ui->dstOpComboBox->currentIndex();
            SearchSettings::ComparisonOp comparison = (SearchSettings::ComparisonOp) index;
            validDst = SearchSettings::matchesSearch(comparison, material.dstFactor, SearchSettings::dstFactor);
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
    // Use hex format
    QString text = ui->srcLineEdit->text();
    bool ok;
    searchSettings->srcFactor(text.toInt(&ok, 16));
}

void MainWindow::on_actionAbout_triggered()
{
    // Display license information.
    QString link = "<a href='https://github.com/ScanMountGoat/Smash-Material-XML/blob/master/license.txt'>GPL License</a>";
    QMessageBox::about(0, "About", link);
}
