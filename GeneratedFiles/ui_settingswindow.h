/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *searchPropertiesGroupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *flagsMatPropHorizontalLayout;
    QFrame *flagsFrame;
    QWidget *flagsContainer;
    QWidget *layoutWidget_2;
    QHBoxLayout *flagsHorizontalLayout;
    QLabel *flagsLabel;
    QLineEdit *flags1LineEdit;
    QComboBox *flagsOpComboBox;
    QLineEdit *flags2LineEdit;
    QCheckBox *flagsCheckBox;
    QFrame *matPropertyFrame;
    QCheckBox *matPropCheckBox;
    QWidget *matPropContainer;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *nuLabel;
    QLineEdit *matPropLineEdit;
    QHBoxLayout *dstSrcHorizontalLayout;
    QFrame *dstFrame;
    QCheckBox *dstCheckBox;
    QWidget *dstContainer;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *dstLabel;
    QComboBox *dstOpComboBox;
    QLineEdit *dstLineEdit;
    QFrame *srcFrame;
    QWidget *srcContainer;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *srcLabel;
    QComboBox *srcOpComboBox;
    QLineEdit *srcLineEdit;
    QCheckBox *srcCheckBox;
    QHBoxLayout *texCountCullModeHorizontalLayout;
    QFrame *cullModeFrame;
    QCheckBox *cullModeCheckBox;
    QWidget *cullModeContainer;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *cullModeLabel;
    QComboBox *cullModeOpComboBox;
    QLineEdit *cullModeLineEdit;
    QFrame *textureCountFrame;
    QCheckBox *texCountCheckBox;
    QWidget *dstContainer_2;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *texCountLabel;
    QComboBox *texCountOpComboBox;
    QLineEdit *texCountLineEdit;
    QHBoxLayout *alphaFuncTestHorizontalLayout;
    QFrame *alphaFuncFrame;
    QCheckBox *alphaFuncCheckBox;
    QWidget *alphaFuncContainer;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *alphaFunctionLabel;
    QComboBox *alphaFuncOpComboBox_2;
    QLineEdit *alphaFuncLineEdit;
    QFrame *alphaTestFrame;
    QCheckBox *alphaTestCheckBox;
    QWidget *alphaTestContainer;
    QWidget *layoutWidget_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *alphaFunctionLabel_2;
    QComboBox *alphaTestOpComboBox;
    QLineEdit *alphaTestLineEdit;
    QGroupBox *displayOptionsGroupBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *displayFileNameCheckBox;
    QCheckBox *displaySrcCheckBox;
    QCheckBox *displayDstCheckBox;
    QCheckBox *displayFlagsCheckBox;
    QCheckBox *displayCullCheckBox;
    QCheckBox *displayTexturesCheckBox;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *noPropertyRadioButton;
    QRadioButton *selectedPropertyRadioButton;
    QRadioButton *allPropertiesRadioButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QStringLiteral("SettingsWindow"));
        SettingsWindow->resize(873, 641);
        centralwidget = new QWidget(SettingsWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        searchPropertiesGroupBox = new QGroupBox(centralwidget);
        searchPropertiesGroupBox->setObjectName(QStringLiteral("searchPropertiesGroupBox"));
        searchPropertiesGroupBox->setEnabled(true);
        searchPropertiesGroupBox->setGeometry(QRect(1, 11, 840, 311));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchPropertiesGroupBox->sizePolicy().hasHeightForWidth());
        searchPropertiesGroupBox->setSizePolicy(sizePolicy);
        searchPropertiesGroupBox->setMinimumSize(QSize(840, 230));
        verticalLayout = new QVBoxLayout(searchPropertiesGroupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        flagsMatPropHorizontalLayout = new QHBoxLayout();
        flagsMatPropHorizontalLayout->setObjectName(QStringLiteral("flagsMatPropHorizontalLayout"));
        flagsFrame = new QFrame(searchPropertiesGroupBox);
        flagsFrame->setObjectName(QStringLiteral("flagsFrame"));
        flagsFrame->setFrameShape(QFrame::StyledPanel);
        flagsFrame->setFrameShadow(QFrame::Raised);
        flagsContainer = new QWidget(flagsFrame);
        flagsContainer->setObjectName(QStringLiteral("flagsContainer"));
        flagsContainer->setGeometry(QRect(30, 30, 371, 31));
        layoutWidget_2 = new QWidget(flagsContainer);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 0, 371, 33));
        flagsHorizontalLayout = new QHBoxLayout(layoutWidget_2);
        flagsHorizontalLayout->setObjectName(QStringLiteral("flagsHorizontalLayout"));
        flagsHorizontalLayout->setContentsMargins(0, 0, 0, 0);
        flagsLabel = new QLabel(layoutWidget_2);
        flagsLabel->setObjectName(QStringLiteral("flagsLabel"));

        flagsHorizontalLayout->addWidget(flagsLabel);

        flags1LineEdit = new QLineEdit(layoutWidget_2);
        flags1LineEdit->setObjectName(QStringLiteral("flags1LineEdit"));

        flagsHorizontalLayout->addWidget(flags1LineEdit);

        flagsOpComboBox = new QComboBox(layoutWidget_2);
        flagsOpComboBox->setObjectName(QStringLiteral("flagsOpComboBox"));

        flagsHorizontalLayout->addWidget(flagsOpComboBox);

        flags2LineEdit = new QLineEdit(layoutWidget_2);
        flags2LineEdit->setObjectName(QStringLiteral("flags2LineEdit"));

        flagsHorizontalLayout->addWidget(flags2LineEdit);

        flagsCheckBox = new QCheckBox(flagsFrame);
        flagsCheckBox->setObjectName(QStringLiteral("flagsCheckBox"));
        flagsCheckBox->setGeometry(QRect(0, 10, 70, 17));

        flagsMatPropHorizontalLayout->addWidget(flagsFrame);

        matPropertyFrame = new QFrame(searchPropertiesGroupBox);
        matPropertyFrame->setObjectName(QStringLiteral("matPropertyFrame"));
        matPropertyFrame->setFrameShape(QFrame::StyledPanel);
        matPropertyFrame->setFrameShadow(QFrame::Raised);
        matPropCheckBox = new QCheckBox(matPropertyFrame);
        matPropCheckBox->setObjectName(QStringLiteral("matPropCheckBox"));
        matPropCheckBox->setGeometry(QRect(0, 10, 141, 17));
        matPropContainer = new QWidget(matPropertyFrame);
        matPropContainer->setObjectName(QStringLiteral("matPropContainer"));
        matPropContainer->setGeometry(QRect(20, 30, 251, 41));
        layoutWidget_3 = new QWidget(matPropContainer);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 0, 241, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        nuLabel = new QLabel(layoutWidget_3);
        nuLabel->setObjectName(QStringLiteral("nuLabel"));

        horizontalLayout->addWidget(nuLabel);

        matPropLineEdit = new QLineEdit(layoutWidget_3);
        matPropLineEdit->setObjectName(QStringLiteral("matPropLineEdit"));

        horizontalLayout->addWidget(matPropLineEdit);


        flagsMatPropHorizontalLayout->addWidget(matPropertyFrame);


        verticalLayout->addLayout(flagsMatPropHorizontalLayout);

        dstSrcHorizontalLayout = new QHBoxLayout();
        dstSrcHorizontalLayout->setObjectName(QStringLiteral("dstSrcHorizontalLayout"));
        dstFrame = new QFrame(searchPropertiesGroupBox);
        dstFrame->setObjectName(QStringLiteral("dstFrame"));
        dstFrame->setFrameShape(QFrame::StyledPanel);
        dstFrame->setFrameShadow(QFrame::Raised);
        dstCheckBox = new QCheckBox(dstFrame);
        dstCheckBox->setObjectName(QStringLiteral("dstCheckBox"));
        dstCheckBox->setGeometry(QRect(0, 0, 70, 17));
        dstContainer = new QWidget(dstFrame);
        dstContainer->setObjectName(QStringLiteral("dstContainer"));
        dstContainer->setGeometry(QRect(20, 20, 241, 31));
        layoutWidget_4 = new QWidget(dstContainer);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(0, 0, 241, 33));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        dstLabel = new QLabel(layoutWidget_4);
        dstLabel->setObjectName(QStringLiteral("dstLabel"));

        horizontalLayout_3->addWidget(dstLabel);

        dstOpComboBox = new QComboBox(layoutWidget_4);
        dstOpComboBox->setObjectName(QStringLiteral("dstOpComboBox"));

        horizontalLayout_3->addWidget(dstOpComboBox);

        dstLineEdit = new QLineEdit(layoutWidget_4);
        dstLineEdit->setObjectName(QStringLiteral("dstLineEdit"));

        horizontalLayout_3->addWidget(dstLineEdit);


        dstSrcHorizontalLayout->addWidget(dstFrame);

        srcFrame = new QFrame(searchPropertiesGroupBox);
        srcFrame->setObjectName(QStringLiteral("srcFrame"));
        srcFrame->setFrameShape(QFrame::StyledPanel);
        srcFrame->setFrameShadow(QFrame::Raised);
        srcContainer = new QWidget(srcFrame);
        srcContainer->setObjectName(QStringLiteral("srcContainer"));
        srcContainer->setGeometry(QRect(30, 20, 241, 31));
        layoutWidget_5 = new QWidget(srcContainer);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(0, 0, 241, 33));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        srcLabel = new QLabel(layoutWidget_5);
        srcLabel->setObjectName(QStringLiteral("srcLabel"));

        horizontalLayout_2->addWidget(srcLabel);

        srcOpComboBox = new QComboBox(layoutWidget_5);
        srcOpComboBox->setObjectName(QStringLiteral("srcOpComboBox"));

        horizontalLayout_2->addWidget(srcOpComboBox);

        srcLineEdit = new QLineEdit(layoutWidget_5);
        srcLineEdit->setObjectName(QStringLiteral("srcLineEdit"));

        horizontalLayout_2->addWidget(srcLineEdit);

        srcCheckBox = new QCheckBox(srcFrame);
        srcCheckBox->setObjectName(QStringLiteral("srcCheckBox"));
        srcCheckBox->setGeometry(QRect(0, 0, 91, 17));

        dstSrcHorizontalLayout->addWidget(srcFrame);


        verticalLayout->addLayout(dstSrcHorizontalLayout);

        texCountCullModeHorizontalLayout = new QHBoxLayout();
        texCountCullModeHorizontalLayout->setObjectName(QStringLiteral("texCountCullModeHorizontalLayout"));
        cullModeFrame = new QFrame(searchPropertiesGroupBox);
        cullModeFrame->setObjectName(QStringLiteral("cullModeFrame"));
        cullModeFrame->setFrameShape(QFrame::StyledPanel);
        cullModeFrame->setFrameShadow(QFrame::Raised);
        cullModeCheckBox = new QCheckBox(cullModeFrame);
        cullModeCheckBox->setObjectName(QStringLiteral("cullModeCheckBox"));
        cullModeCheckBox->setGeometry(QRect(0, 0, 101, 17));
        cullModeContainer = new QWidget(cullModeFrame);
        cullModeContainer->setObjectName(QStringLiteral("cullModeContainer"));
        cullModeContainer->setGeometry(QRect(20, 20, 241, 31));
        layoutWidget_6 = new QWidget(cullModeContainer);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(0, 0, 241, 33));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        cullModeLabel = new QLabel(layoutWidget_6);
        cullModeLabel->setObjectName(QStringLiteral("cullModeLabel"));

        horizontalLayout_5->addWidget(cullModeLabel);

        cullModeOpComboBox = new QComboBox(layoutWidget_6);
        cullModeOpComboBox->setObjectName(QStringLiteral("cullModeOpComboBox"));

        horizontalLayout_5->addWidget(cullModeOpComboBox);

        cullModeLineEdit = new QLineEdit(layoutWidget_6);
        cullModeLineEdit->setObjectName(QStringLiteral("cullModeLineEdit"));

        horizontalLayout_5->addWidget(cullModeLineEdit);


        texCountCullModeHorizontalLayout->addWidget(cullModeFrame);

        textureCountFrame = new QFrame(searchPropertiesGroupBox);
        textureCountFrame->setObjectName(QStringLiteral("textureCountFrame"));
        textureCountFrame->setFrameShape(QFrame::StyledPanel);
        textureCountFrame->setFrameShadow(QFrame::Raised);
        texCountCheckBox = new QCheckBox(textureCountFrame);
        texCountCheckBox->setObjectName(QStringLiteral("texCountCheckBox"));
        texCountCheckBox->setGeometry(QRect(0, 0, 101, 17));
        dstContainer_2 = new QWidget(textureCountFrame);
        dstContainer_2->setObjectName(QStringLiteral("dstContainer_2"));
        dstContainer_2->setGeometry(QRect(20, 20, 241, 31));
        layoutWidget_7 = new QWidget(textureCountFrame);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(30, 20, 241, 33));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        texCountLabel = new QLabel(layoutWidget_7);
        texCountLabel->setObjectName(QStringLiteral("texCountLabel"));

        horizontalLayout_4->addWidget(texCountLabel);

        texCountOpComboBox = new QComboBox(layoutWidget_7);
        texCountOpComboBox->setObjectName(QStringLiteral("texCountOpComboBox"));

        horizontalLayout_4->addWidget(texCountOpComboBox);

        texCountLineEdit = new QLineEdit(layoutWidget_7);
        texCountLineEdit->setObjectName(QStringLiteral("texCountLineEdit"));

        horizontalLayout_4->addWidget(texCountLineEdit);


        texCountCullModeHorizontalLayout->addWidget(textureCountFrame);


        verticalLayout->addLayout(texCountCullModeHorizontalLayout);

        alphaFuncTestHorizontalLayout = new QHBoxLayout();
        alphaFuncTestHorizontalLayout->setObjectName(QStringLiteral("alphaFuncTestHorizontalLayout"));
        alphaFuncFrame = new QFrame(searchPropertiesGroupBox);
        alphaFuncFrame->setObjectName(QStringLiteral("alphaFuncFrame"));
        alphaFuncFrame->setFrameShape(QFrame::StyledPanel);
        alphaFuncFrame->setFrameShadow(QFrame::Raised);
        alphaFuncCheckBox = new QCheckBox(alphaFuncFrame);
        alphaFuncCheckBox->setObjectName(QStringLiteral("alphaFuncCheckBox"));
        alphaFuncCheckBox->setGeometry(QRect(0, 0, 101, 17));
        alphaFuncContainer = new QWidget(alphaFuncFrame);
        alphaFuncContainer->setObjectName(QStringLiteral("alphaFuncContainer"));
        alphaFuncContainer->setGeometry(QRect(20, 20, 241, 31));
        layoutWidget_8 = new QWidget(alphaFuncContainer);
        layoutWidget_8->setObjectName(QStringLiteral("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(0, 0, 241, 33));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        alphaFunctionLabel = new QLabel(layoutWidget_8);
        alphaFunctionLabel->setObjectName(QStringLiteral("alphaFunctionLabel"));

        horizontalLayout_7->addWidget(alphaFunctionLabel);

        alphaFuncOpComboBox_2 = new QComboBox(layoutWidget_8);
        alphaFuncOpComboBox_2->setObjectName(QStringLiteral("alphaFuncOpComboBox_2"));

        horizontalLayout_7->addWidget(alphaFuncOpComboBox_2);

        alphaFuncLineEdit = new QLineEdit(layoutWidget_8);
        alphaFuncLineEdit->setObjectName(QStringLiteral("alphaFuncLineEdit"));

        horizontalLayout_7->addWidget(alphaFuncLineEdit);


        alphaFuncTestHorizontalLayout->addWidget(alphaFuncFrame);

        alphaTestFrame = new QFrame(searchPropertiesGroupBox);
        alphaTestFrame->setObjectName(QStringLiteral("alphaTestFrame"));
        alphaTestFrame->setFrameShape(QFrame::StyledPanel);
        alphaTestFrame->setFrameShadow(QFrame::Raised);
        alphaTestCheckBox = new QCheckBox(alphaTestFrame);
        alphaTestCheckBox->setObjectName(QStringLiteral("alphaTestCheckBox"));
        alphaTestCheckBox->setGeometry(QRect(0, 0, 101, 17));
        alphaTestContainer = new QWidget(alphaTestFrame);
        alphaTestContainer->setObjectName(QStringLiteral("alphaTestContainer"));
        alphaTestContainer->setGeometry(QRect(20, 20, 241, 31));
        layoutWidget_9 = new QWidget(alphaTestContainer);
        layoutWidget_9->setObjectName(QStringLiteral("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(0, 0, 241, 33));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_9);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        alphaFunctionLabel_2 = new QLabel(layoutWidget_9);
        alphaFunctionLabel_2->setObjectName(QStringLiteral("alphaFunctionLabel_2"));

        horizontalLayout_8->addWidget(alphaFunctionLabel_2);

        alphaTestOpComboBox = new QComboBox(layoutWidget_9);
        alphaTestOpComboBox->setObjectName(QStringLiteral("alphaTestOpComboBox"));

        horizontalLayout_8->addWidget(alphaTestOpComboBox);

        alphaTestLineEdit = new QLineEdit(layoutWidget_9);
        alphaTestLineEdit->setObjectName(QStringLiteral("alphaTestLineEdit"));

        horizontalLayout_8->addWidget(alphaTestLineEdit);


        alphaFuncTestHorizontalLayout->addWidget(alphaTestFrame);


        verticalLayout->addLayout(alphaFuncTestHorizontalLayout);

        displayOptionsGroupBox = new QGroupBox(centralwidget);
        displayOptionsGroupBox->setObjectName(QStringLiteral("displayOptionsGroupBox"));
        displayOptionsGroupBox->setGeometry(QRect(90, 380, 351, 190));
        sizePolicy.setHeightForWidth(displayOptionsGroupBox->sizePolicy().hasHeightForWidth());
        displayOptionsGroupBox->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(displayOptionsGroupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        displayFileNameCheckBox = new QCheckBox(displayOptionsGroupBox);
        displayFileNameCheckBox->setObjectName(QStringLiteral("displayFileNameCheckBox"));

        verticalLayout_2->addWidget(displayFileNameCheckBox);

        displaySrcCheckBox = new QCheckBox(displayOptionsGroupBox);
        displaySrcCheckBox->setObjectName(QStringLiteral("displaySrcCheckBox"));

        verticalLayout_2->addWidget(displaySrcCheckBox);

        displayDstCheckBox = new QCheckBox(displayOptionsGroupBox);
        displayDstCheckBox->setObjectName(QStringLiteral("displayDstCheckBox"));

        verticalLayout_2->addWidget(displayDstCheckBox);

        displayFlagsCheckBox = new QCheckBox(displayOptionsGroupBox);
        displayFlagsCheckBox->setObjectName(QStringLiteral("displayFlagsCheckBox"));

        verticalLayout_2->addWidget(displayFlagsCheckBox);

        displayCullCheckBox = new QCheckBox(displayOptionsGroupBox);
        displayCullCheckBox->setObjectName(QStringLiteral("displayCullCheckBox"));

        verticalLayout_2->addWidget(displayCullCheckBox);

        displayTexturesCheckBox = new QCheckBox(displayOptionsGroupBox);
        displayTexturesCheckBox->setObjectName(QStringLiteral("displayTexturesCheckBox"));

        verticalLayout_2->addWidget(displayTexturesCheckBox);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        noPropertyRadioButton = new QRadioButton(displayOptionsGroupBox);
        noPropertyRadioButton->setObjectName(QStringLiteral("noPropertyRadioButton"));

        horizontalLayout_6->addWidget(noPropertyRadioButton);

        selectedPropertyRadioButton = new QRadioButton(displayOptionsGroupBox);
        selectedPropertyRadioButton->setObjectName(QStringLiteral("selectedPropertyRadioButton"));

        horizontalLayout_6->addWidget(selectedPropertyRadioButton);

        allPropertiesRadioButton = new QRadioButton(displayOptionsGroupBox);
        allPropertiesRadioButton->setObjectName(QStringLiteral("allPropertiesRadioButton"));

        horizontalLayout_6->addWidget(allPropertiesRadioButton);


        verticalLayout_2->addLayout(horizontalLayout_6);

        SettingsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SettingsWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 873, 21));
        SettingsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SettingsWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SettingsWindow->setStatusBar(statusbar);

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QApplication::translate("SettingsWindow", "Settings ", Q_NULLPTR));
        searchPropertiesGroupBox->setTitle(QApplication::translate("SettingsWindow", "Search Properties", Q_NULLPTR));
        flagsLabel->setText(QApplication::translate("SettingsWindow", "Flags & ", Q_NULLPTR));
        flagsOpComboBox->clear();
        flagsOpComboBox->insertItems(0, QStringList()
         << QApplication::translate("SettingsWindow", "==", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", ">", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", ">=", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", "<", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", "<=", Q_NULLPTR)
        );
        flagsCheckBox->setText(QApplication::translate("SettingsWindow", "Flags", Q_NULLPTR));
        matPropCheckBox->setText(QApplication::translate("SettingsWindow", "Material Property", Q_NULLPTR));
        nuLabel->setText(QApplication::translate("SettingsWindow", "NU_", Q_NULLPTR));
        dstCheckBox->setText(QApplication::translate("SettingsWindow", "dst Factor", Q_NULLPTR));
        dstLabel->setText(QApplication::translate("SettingsWindow", "dstFactor", Q_NULLPTR));
        dstOpComboBox->clear();
        dstOpComboBox->insertItems(0, QStringList()
         << QApplication::translate("SettingsWindow", "==", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", ">", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", ">=", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", "<", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", "<=", Q_NULLPTR)
        );
        srcLabel->setText(QApplication::translate("SettingsWindow", "srcFactor", Q_NULLPTR));
        srcOpComboBox->clear();
        srcOpComboBox->insertItems(0, QStringList()
         << QApplication::translate("SettingsWindow", "==", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", ">", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", ">=", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", "<", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", "<=", Q_NULLPTR)
        );
        srcCheckBox->setText(QApplication::translate("SettingsWindow", "src Factor", Q_NULLPTR));
        cullModeCheckBox->setText(QApplication::translate("SettingsWindow", "Cull Mode", Q_NULLPTR));
        cullModeLabel->setText(QApplication::translate("SettingsWindow", "Cull Mode", Q_NULLPTR));
        cullModeOpComboBox->clear();
        cullModeOpComboBox->insertItems(0, QStringList()
         << QApplication::translate("SettingsWindow", "==", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", ">", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", ">=", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", "<", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", "<=", Q_NULLPTR)
        );
        texCountCheckBox->setText(QApplication::translate("SettingsWindow", "Texture Count", Q_NULLPTR));
        texCountLabel->setText(QApplication::translate("SettingsWindow", "Count", Q_NULLPTR));
        texCountOpComboBox->clear();
        texCountOpComboBox->insertItems(0, QStringList()
         << QApplication::translate("SettingsWindow", "==", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", ">", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", ">=", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", "<", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", "<=", Q_NULLPTR)
        );
        alphaFuncCheckBox->setText(QApplication::translate("SettingsWindow", "Alpha Function", Q_NULLPTR));
        alphaFunctionLabel->setText(QApplication::translate("SettingsWindow", "Function", Q_NULLPTR));
        alphaFuncOpComboBox_2->clear();
        alphaFuncOpComboBox_2->insertItems(0, QStringList()
         << QApplication::translate("SettingsWindow", "==", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", ">", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", ">=", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", "<", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", "<=", Q_NULLPTR)
        );
        alphaTestCheckBox->setText(QApplication::translate("SettingsWindow", "Alpha Test", Q_NULLPTR));
        alphaFunctionLabel_2->setText(QApplication::translate("SettingsWindow", "Test", Q_NULLPTR));
        alphaTestOpComboBox->clear();
        alphaTestOpComboBox->insertItems(0, QStringList()
         << QApplication::translate("SettingsWindow", "==", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", ">", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", ">=", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", "<", Q_NULLPTR)
         << QApplication::translate("SettingsWindow", "<=", Q_NULLPTR)
        );
        displayOptionsGroupBox->setTitle(QApplication::translate("SettingsWindow", "Display Settings", Q_NULLPTR));
        displayFileNameCheckBox->setText(QApplication::translate("SettingsWindow", "File Name", Q_NULLPTR));
        displaySrcCheckBox->setText(QApplication::translate("SettingsWindow", "Src Factor", Q_NULLPTR));
        displayDstCheckBox->setText(QApplication::translate("SettingsWindow", "Dst Factor", Q_NULLPTR));
        displayFlagsCheckBox->setText(QApplication::translate("SettingsWindow", "Flags", Q_NULLPTR));
        displayCullCheckBox->setText(QApplication::translate("SettingsWindow", "Cull Mode", Q_NULLPTR));
        displayTexturesCheckBox->setText(QApplication::translate("SettingsWindow", "Textures", Q_NULLPTR));
        noPropertyRadioButton->setText(QApplication::translate("SettingsWindow", "No Properties", Q_NULLPTR));
        selectedPropertyRadioButton->setText(QApplication::translate("SettingsWindow", "Selected Property", Q_NULLPTR));
        allPropertiesRadioButton->setText(QApplication::translate("SettingsWindow", "All Properties", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
