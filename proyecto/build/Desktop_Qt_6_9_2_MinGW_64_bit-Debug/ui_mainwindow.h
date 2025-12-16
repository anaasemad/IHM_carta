/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *ini_sesion;
    QVBoxLayout *verticalLayout_4;
    QWidget *fondo;
    QFrame *recuadro_ini;
    QLabel *et_ini;
    QLabel *et_user;
    QLabel *et_pass;
    QLabel *et__nocuenta;
    QLabel *link_registro;
    QLineEdit *campo_user;
    QLineEdit *campo_pass;
    QPushButton *boton_entrar;
    QWidget *historial;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QTableView *tableViewHistorial;
    QLabel *label_filtro;
    QDateEdit *dateEditFiltro;
    QPushButton *Boton_volver;
    QWidget *mapa;
    QVBoxLayout *verticalLayout;
    QLabel *barra_arriba;
    QPushButton *Modificar_perfil;
    QPushButton *boton_historial;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget_2;
    QWidget *menu_principal;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *boton_alet;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *boton_lista;
    QSpacerItem *verticalSpacer_3;
    QWidget *problema;
    QWidget *lista_problemas;
    QListWidget *listWidget;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QWidget *barra_herramienta;
    QPushButton *punto;
    QPushButton *Bcompas;
    QPushButton *Bregla;
    QPushButton *Btransportador;
    QPushButton *texto;
    QPushButton *linea;
    QPushButton *color;
    QPushButton *goma;
    QPushButton *limpiar;
    QSpinBox *grosor;
    QSlider *horizontalSlider;
    QGraphicsView *graphicsView;
    QLabel *labelStatus;
    QWidget *editar_perfil;
    QLabel *modificarperfil;
    QLabel *nombre;
    QLabel *label_email;
    QLabel *label_contrasenia;
    QLabel *label_compleanios;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QDateEdit *dateEdit;
    QPushButton *Boton_guardar;
    QPushButton *Boton_volver_2;
    QLabel *label;
    QPushButton *boton_editar;
    QWidget *registro;
    QWidget *fondo_2;
    QFrame *recuadro_reg;
    QLabel *et_registro;
    QLabel *et_name;
    QLabel *et_correo;
    QLabel *et_pass_2;
    QLabel *et_cumple;
    QLineEdit *campo_name;
    QLineEdit *campo_correo;
    QLineEdit *campo_pass_2;
    QDateEdit *campo_cumple;
    QCalendarWidget *calendario;
    QPushButton *boton_registro;
    QLabel *error_user;
    QLabel *error_correo;
    QLabel *error_pass;
    QLabel *error_edad;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(855, 689);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMaximumSize(QSize(78241, 16777215));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setMaximumSize(QSize(16777215, 16777215));
        ini_sesion = new QWidget();
        ini_sesion->setObjectName("ini_sesion");
        sizePolicy.setHeightForWidth(ini_sesion->sizePolicy().hasHeightForWidth());
        ini_sesion->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(ini_sesion);
        verticalLayout_4->setObjectName("verticalLayout_4");
        fondo = new QWidget(ini_sesion);
        fondo->setObjectName("fondo");
        recuadro_ini = new QFrame(fondo);
        recuadro_ini->setObjectName("recuadro_ini");
        recuadro_ini->setGeometry(QRect(130, 70, 571, 451));
        recuadro_ini->setFrameShape(QFrame::Shape::StyledPanel);
        recuadro_ini->setFrameShadow(QFrame::Shadow::Raised);
        et_ini = new QLabel(recuadro_ini);
        et_ini->setObjectName("et_ini");
        et_ini->setGeometry(QRect(170, 40, 241, 71));
        QFont font;
        font.setPointSize(20);
        et_ini->setFont(font);
        et_user = new QLabel(recuadro_ini);
        et_user->setObjectName("et_user");
        et_user->setGeometry(QRect(70, 130, 63, 20));
        et_pass = new QLabel(recuadro_ini);
        et_pass->setObjectName("et_pass");
        et_pass->setGeometry(QRect(70, 230, 131, 20));
        et__nocuenta = new QLabel(recuadro_ini);
        et__nocuenta->setObjectName("et__nocuenta");
        et__nocuenta->setGeometry(QRect(210, 390, 101, 20));
        QFont font1;
        font1.setPointSize(7);
        et__nocuenta->setFont(font1);
        link_registro = new QLabel(recuadro_ini);
        link_registro->setObjectName("link_registro");
        link_registro->setGeometry(QRect(320, 390, 91, 20));
        link_registro->setFont(font1);
        link_registro->setTextFormat(Qt::TextFormat::RichText);
        link_registro->setOpenExternalLinks(false);
        campo_user = new QLineEdit(recuadro_ini);
        campo_user->setObjectName("campo_user");
        campo_user->setGeometry(QRect(70, 160, 421, 28));
        campo_pass = new QLineEdit(recuadro_ini);
        campo_pass->setObjectName("campo_pass");
        campo_pass->setGeometry(QRect(70, 270, 431, 28));
        campo_pass->setEchoMode(QLineEdit::EchoMode::Password);
        boton_entrar = new QPushButton(recuadro_ini);
        boton_entrar->setObjectName("boton_entrar");
        boton_entrar->setGeometry(QRect(240, 340, 90, 29));

        verticalLayout_4->addWidget(fondo);

        stackedWidget->addWidget(ini_sesion);
        historial = new QWidget();
        historial->setObjectName("historial");
        verticalLayoutWidget = new QWidget(historial);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 130, 781, 461));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tableViewHistorial = new QTableView(verticalLayoutWidget);
        tableViewHistorial->setObjectName("tableViewHistorial");

        verticalLayout_5->addWidget(tableViewHistorial);

        label_filtro = new QLabel(historial);
        label_filtro->setObjectName("label_filtro");
        label_filtro->setGeometry(QRect(480, 100, 121, 20));
        dateEditFiltro = new QDateEdit(historial);
        dateEditFiltro->setObjectName("dateEditFiltro");
        dateEditFiltro->setGeometry(QRect(620, 100, 110, 26));
        Boton_volver = new QPushButton(historial);
        Boton_volver->setObjectName("Boton_volver");
        Boton_volver->setGeometry(QRect(40, 20, 93, 29));
        stackedWidget->addWidget(historial);
        mapa = new QWidget();
        mapa->setObjectName("mapa");
        sizePolicy.setHeightForWidth(mapa->sizePolicy().hasHeightForWidth());
        mapa->setSizePolicy(sizePolicy);
        mapa->setMaximumSize(QSize(811, 628));
        verticalLayout = new QVBoxLayout(mapa);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        barra_arriba = new QLabel(mapa);
        barra_arriba->setObjectName("barra_arriba");
        sizePolicy.setHeightForWidth(barra_arriba->sizePolicy().hasHeightForWidth());
        barra_arriba->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        QBrush brush1(QColor(176, 210, 240, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Light, brush2);
        QBrush brush3(QColor(215, 232, 247, 255));
        brush3.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Midlight, brush3);
        QBrush brush4(QColor(88, 105, 120, 255));
        brush4.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Dark, brush4);
        QBrush brush5(QColor(117, 140, 160, 255));
        brush5.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::BrightText, brush2);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush2);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipBase, brush6);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush7(QColor(0, 0, 0, 127));
        brush7.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Accent, brush2);
#endif
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Light, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Midlight, brush3);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Dark, brush4);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::BrightText, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::AlternateBase, brush3);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipBase, brush6);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Accent, brush2);
#endif
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Light, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Midlight, brush3);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Dark, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::BrightText, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::AlternateBase, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipBase, brush6);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush8(QColor(88, 105, 120, 127));
        brush8.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush8);
#endif
        QBrush brush9(QColor(244, 250, 255, 255));
        brush9.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Accent, brush9);
#endif
        barra_arriba->setPalette(palette);
        barra_arriba->setAutoFillBackground(true);
        barra_arriba->setFrameShape(QFrame::Shape::NoFrame);
        barra_arriba->setFrameShadow(QFrame::Shadow::Plain);

        verticalLayout->addWidget(barra_arriba);

        Modificar_perfil = new QPushButton(mapa);
        Modificar_perfil->setObjectName("Modificar_perfil");

        verticalLayout->addWidget(Modificar_perfil);

        boton_historial = new QPushButton(mapa);
        boton_historial->setObjectName("boton_historial");

        verticalLayout->addWidget(boton_historial);

        horizontalWidget = new QWidget(mapa);
        horizontalWidget->setObjectName("horizontalWidget");
        sizePolicy.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(1, -1, -1, -1);
        stackedWidget_2 = new QStackedWidget(horizontalWidget);
        stackedWidget_2->setObjectName("stackedWidget_2");
        menu_principal = new QWidget();
        menu_principal->setObjectName("menu_principal");
        sizePolicy.setHeightForWidth(menu_principal->sizePolicy().hasHeightForWidth());
        menu_principal->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(menu_principal);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        boton_alet = new QPushButton(menu_principal);
        boton_alet->setObjectName("boton_alet");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(boton_alet->sizePolicy().hasHeightForWidth());
        boton_alet->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(boton_alet, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        boton_lista = new QPushButton(menu_principal);
        boton_lista->setObjectName("boton_lista");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(boton_lista->sizePolicy().hasHeightForWidth());
        boton_lista->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(boton_lista, 3, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 1, 1, 1);

        gridLayout->setRowStretch(0, 2);
        gridLayout->setRowStretch(1, 2);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 2);
        gridLayout->setRowStretch(4, 2);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 1);
        stackedWidget_2->addWidget(menu_principal);
        problema = new QWidget();
        problema->setObjectName("problema");
        stackedWidget_2->addWidget(problema);
        lista_problemas = new QWidget();
        lista_problemas->setObjectName("lista_problemas");
        listWidget = new QListWidget(lista_problemas);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(30, 30, 331, 371));
        stackedWidget_2->addWidget(lista_problemas);

        horizontalLayout_2->addWidget(stackedWidget_2);

        verticalWidget = new QWidget(horizontalWidget);
        verticalWidget->setObjectName("verticalWidget");
        sizePolicy.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(verticalWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(verticalWidget);
        widget_2->setObjectName("widget_2");
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(97, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        barra_herramienta = new QWidget(widget_2);
        barra_herramienta->setObjectName("barra_herramienta");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(barra_herramienta->sizePolicy().hasHeightForWidth());
        barra_herramienta->setSizePolicy(sizePolicy3);
        barra_herramienta->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        barra_herramienta->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        barra_herramienta->setAutoFillBackground(false);
        punto = new QPushButton(barra_herramienta);
        punto->setObjectName("punto");
        punto->setGeometry(QRect(90, 0, 30, 23));
        sizePolicy2.setHeightForWidth(punto->sizePolicy().hasHeightForWidth());
        punto->setSizePolicy(sizePolicy2);
        punto->setMinimumSize(QSize(0, 0));
        punto->setMaximumSize(QSize(167, 167));
        punto->setIconSize(QSize(8, 16));
        punto->setCheckable(true);
        Bcompas = new QPushButton(barra_herramienta);
        Bcompas->setObjectName("Bcompas");
        Bcompas->setEnabled(true);
        Bcompas->setGeometry(QRect(60, 0, 30, 23));
        sizePolicy2.setHeightForWidth(Bcompas->sizePolicy().hasHeightForWidth());
        Bcompas->setSizePolicy(sizePolicy2);
        Bcompas->setMaximumSize(QSize(167, 167));
        Bcompas->setIconSize(QSize(10, 16));
        Bcompas->setCheckable(true);
        Bregla = new QPushButton(barra_herramienta);
        Bregla->setObjectName("Bregla");
        Bregla->setGeometry(QRect(0, 0, 30, 23));
        sizePolicy2.setHeightForWidth(Bregla->sizePolicy().hasHeightForWidth());
        Bregla->setSizePolicy(sizePolicy2);
        Bregla->setMaximumSize(QSize(167, 167));
        Bregla->setIconSize(QSize(10, 16));
        Bregla->setCheckable(true);
        Btransportador = new QPushButton(barra_herramienta);
        Btransportador->setObjectName("Btransportador");
        Btransportador->setGeometry(QRect(30, 0, 30, 23));
        sizePolicy2.setHeightForWidth(Btransportador->sizePolicy().hasHeightForWidth());
        Btransportador->setSizePolicy(sizePolicy2);
        Btransportador->setMaximumSize(QSize(167, 167));
        QFont font2;
        font2.setBold(false);
        font2.setKerning(true);
        Btransportador->setFont(font2);
        Btransportador->setIconSize(QSize(10, 16));
        Btransportador->setCheckable(true);
        texto = new QPushButton(barra_herramienta);
        texto->setObjectName("texto");
        texto->setGeometry(QRect(150, 0, 30, 23));
        texto->setIconSize(QSize(10, 16));
        linea = new QPushButton(barra_herramienta);
        linea->setObjectName("linea");
        linea->setGeometry(QRect(120, 0, 30, 23));
        sizePolicy2.setHeightForWidth(linea->sizePolicy().hasHeightForWidth());
        linea->setSizePolicy(sizePolicy2);
        linea->setMaximumSize(QSize(167, 167));
        linea->setIconSize(QSize(10, 16));
        linea->setCheckable(true);
        color = new QPushButton(barra_herramienta);
        color->setObjectName("color");
        color->setGeometry(QRect(180, 0, 30, 23));
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(color->sizePolicy().hasHeightForWidth());
        color->setSizePolicy(sizePolicy4);
        color->setMaximumSize(QSize(167, 167));
        color->setIconSize(QSize(10, 16));
        color->setAutoDefault(false);
        color->setFlat(false);
        goma = new QPushButton(barra_herramienta);
        goma->setObjectName("goma");
        goma->setGeometry(QRect(250, 0, 30, 23));
        sizePolicy2.setHeightForWidth(goma->sizePolicy().hasHeightForWidth());
        goma->setSizePolicy(sizePolicy2);
        goma->setMaximumSize(QSize(167, 167));
        goma->setIconSize(QSize(10, 16));
        limpiar = new QPushButton(barra_herramienta);
        limpiar->setObjectName("limpiar");
        limpiar->setGeometry(QRect(280, 0, 30, 23));
        sizePolicy2.setHeightForWidth(limpiar->sizePolicy().hasHeightForWidth());
        limpiar->setSizePolicy(sizePolicy2);
        limpiar->setMaximumSize(QSize(167, 167));
        limpiar->setIconSize(QSize(10, 16));
        grosor = new QSpinBox(barra_herramienta);
        grosor->setObjectName("grosor");
        grosor->setGeometry(QRect(209, 0, 41, 23));
        grosor->setMinimum(1);
        grosor->setMaximum(20);
        grosor->setValue(6);
        horizontalSlider = new QSlider(barra_herramienta);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(313, 0, 41, 23));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(barra_herramienta);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        verticalLayout_3->addWidget(widget_2);

        graphicsView = new QGraphicsView(verticalWidget);
        graphicsView->setObjectName("graphicsView");

        verticalLayout_3->addWidget(graphicsView);

        labelStatus = new QLabel(verticalWidget);
        labelStatus->setObjectName("labelStatus");

        verticalLayout_3->addWidget(labelStatus);

        verticalLayout_3->setStretch(1, 18);

        horizontalLayout_2->addWidget(verticalWidget);


        verticalLayout->addWidget(horizontalWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(3, 15);
        stackedWidget->addWidget(mapa);
        editar_perfil = new QWidget();
        editar_perfil->setObjectName("editar_perfil");
        modificarperfil = new QLabel(editar_perfil);
        modificarperfil->setObjectName("modificarperfil");
        modificarperfil->setGeometry(QRect(30, 60, 121, 20));
        nombre = new QLabel(editar_perfil);
        nombre->setObjectName("nombre");
        nombre->setGeometry(QRect(100, 140, 63, 20));
        label_email = new QLabel(editar_perfil);
        label_email->setObjectName("label_email");
        label_email->setGeometry(QRect(100, 220, 63, 20));
        label_contrasenia = new QLabel(editar_perfil);
        label_contrasenia->setObjectName("label_contrasenia");
        label_contrasenia->setGeometry(QRect(100, 300, 81, 20));
        label_compleanios = new QLabel(editar_perfil);
        label_compleanios->setObjectName("label_compleanios");
        label_compleanios->setGeometry(QRect(100, 390, 91, 20));
        textEdit = new QTextEdit(editar_perfil);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(100, 170, 171, 31));
        textEdit_2 = new QTextEdit(editar_perfil);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(100, 250, 211, 31));
        textEdit_3 = new QTextEdit(editar_perfil);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(100, 340, 151, 31));
        dateEdit = new QDateEdit(editar_perfil);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(100, 420, 110, 26));
        Boton_guardar = new QPushButton(editar_perfil);
        Boton_guardar->setObjectName("Boton_guardar");
        Boton_guardar->setGeometry(QRect(340, 470, 111, 71));
        Boton_volver_2 = new QPushButton(editar_perfil);
        Boton_volver_2->setObjectName("Boton_volver_2");
        Boton_volver_2->setGeometry(QRect(20, 10, 93, 29));
        label = new QLabel(editar_perfil);
        label->setObjectName("label");
        label->setGeometry(QRect(500, 160, 181, 171));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/icons/avatar.jpg")));
        label->setScaledContents(true);
        boton_editar = new QPushButton(editar_perfil);
        boton_editar->setObjectName("boton_editar");
        boton_editar->setGeometry(QRect(540, 340, 93, 29));
        stackedWidget->addWidget(editar_perfil);
        registro = new QWidget();
        registro->setObjectName("registro");
        fondo_2 = new QWidget(registro);
        fondo_2->setObjectName("fondo_2");
        fondo_2->setGeometry(QRect(-1, -1, 851, 651));
        recuadro_reg = new QFrame(fondo_2);
        recuadro_reg->setObjectName("recuadro_reg");
        recuadro_reg->setGeometry(QRect(70, 10, 731, 621));
        recuadro_reg->setFrameShape(QFrame::Shape::StyledPanel);
        recuadro_reg->setFrameShadow(QFrame::Shadow::Raised);
        et_registro = new QLabel(recuadro_reg);
        et_registro->setObjectName("et_registro");
        et_registro->setGeometry(QRect(220, 40, 251, 51));
        et_registro->setFont(font);
        et_name = new QLabel(recuadro_reg);
        et_name->setObjectName("et_name");
        et_name->setGeometry(QRect(90, 120, 63, 20));
        et_correo = new QLabel(recuadro_reg);
        et_correo->setObjectName("et_correo");
        et_correo->setGeometry(QRect(90, 240, 63, 20));
        et_pass_2 = new QLabel(recuadro_reg);
        et_pass_2->setObjectName("et_pass_2");
        et_pass_2->setGeometry(QRect(90, 360, 101, 20));
        et_cumple = new QLabel(recuadro_reg);
        et_cumple->setObjectName("et_cumple");
        et_cumple->setGeometry(QRect(90, 480, 63, 20));
        campo_name = new QLineEdit(recuadro_reg);
        campo_name->setObjectName("campo_name");
        campo_name->setGeometry(QRect(90, 150, 511, 28));
        campo_correo = new QLineEdit(recuadro_reg);
        campo_correo->setObjectName("campo_correo");
        campo_correo->setGeometry(QRect(90, 270, 521, 28));
        campo_pass_2 = new QLineEdit(recuadro_reg);
        campo_pass_2->setObjectName("campo_pass_2");
        campo_pass_2->setGeometry(QRect(80, 400, 271, 28));
        campo_pass_2->setEchoMode(QLineEdit::EchoMode::Password);
        campo_cumple = new QDateEdit(recuadro_reg);
        campo_cumple->setObjectName("campo_cumple");
        campo_cumple->setGeometry(QRect(90, 510, 110, 29));
        calendario = new QCalendarWidget(recuadro_reg);
        calendario->setObjectName("calendario");
        calendario->setGeometry(QRect(450, 410, 272, 195));
        boton_registro = new QPushButton(recuadro_reg);
        boton_registro->setObjectName("boton_registro");
        boton_registro->setGeometry(QRect(320, 570, 90, 29));
        error_user = new QLabel(recuadro_reg);
        error_user->setObjectName("error_user");
        error_user->setGeometry(QRect(90, 190, 591, 20));
        error_correo = new QLabel(recuadro_reg);
        error_correo->setObjectName("error_correo");
        error_correo->setGeometry(QRect(90, 320, 511, 20));
        error_pass = new QLabel(recuadro_reg);
        error_pass->setObjectName("error_pass");
        error_pass->setGeometry(QRect(80, 440, 291, 20));
        error_edad = new QLabel(recuadro_reg);
        error_edad->setObjectName("error_edad");
        error_edad->setGeometry(QRect(90, 560, 151, 20));
        stackedWidget->addWidget(registro);

        verticalLayout_2->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 855, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);
        stackedWidget_2->setCurrentIndex(0);
        color->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        et_ini->setText(QCoreApplication::translate("MainWindow", "INICIAR SESI\303\223N", nullptr));
        et_user->setText(QCoreApplication::translate("MainWindow", "Usuario", nullptr));
        et_pass->setText(QCoreApplication::translate("MainWindow", "Contrase\303\261a", nullptr));
        et__nocuenta->setText(QCoreApplication::translate("MainWindow", "No tienes cuenta?", nullptr));
        link_registro->setText(QCoreApplication::translate("MainWindow", "<a href=\"#\">Reg\303\255strate</a>\n"
"<html><head/><body><p><br/></p></body></html>", nullptr));
        boton_entrar->setText(QCoreApplication::translate("MainWindow", "Entrar", nullptr));
        label_filtro->setText(QCoreApplication::translate("MainWindow", "Filtar por fecha", nullptr));
        Boton_volver->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        barra_arriba->setText(QString());
        Modificar_perfil->setText(QCoreApplication::translate("MainWindow", "Modificar perfil", nullptr));
        boton_historial->setText(QCoreApplication::translate("MainWindow", "Historial", nullptr));
        boton_alet->setText(QCoreApplication::translate("MainWindow", "Problema aleatorio", nullptr));
        boton_lista->setText(QCoreApplication::translate("MainWindow", "Lista problemas", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "Problema 1", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "Problema 2", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "Problema 3", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "Problema 4", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "Problema 5", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        punto->setText(QCoreApplication::translate("MainWindow", "punt", nullptr));
        Bcompas->setText(QCoreApplication::translate("MainWindow", "compas", nullptr));
        Bregla->setText(QCoreApplication::translate("MainWindow", "regla", nullptr));
        Btransportador->setText(QCoreApplication::translate("MainWindow", "transportador", nullptr));
        texto->setText(QCoreApplication::translate("MainWindow", "texto", nullptr));
        linea->setText(QCoreApplication::translate("MainWindow", "linea", nullptr));
        color->setText(QCoreApplication::translate("MainWindow", "color", nullptr));
        goma->setText(QCoreApplication::translate("MainWindow", "goma", nullptr));
        limpiar->setText(QCoreApplication::translate("MainWindow", "limpiar", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "labelStatus", nullptr));
        modificarperfil->setText(QCoreApplication::translate("MainWindow", "Modicicar Perfil", nullptr));
        nombre->setText(QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        label_email->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_contrasenia->setText(QCoreApplication::translate("MainWindow", "Contrase\303\261a", nullptr));
        label_compleanios->setText(QCoreApplication::translate("MainWindow", "Cumplea\303\261os", nullptr));
        Boton_guardar->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        Boton_volver_2->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        label->setText(QString());
        boton_editar->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217", nullptr));
        et_registro->setText(QCoreApplication::translate("MainWindow", "      Reg\303\255strate", nullptr));
        et_name->setText(QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        et_correo->setText(QCoreApplication::translate("MainWindow", "Correo", nullptr));
        et_pass_2->setText(QCoreApplication::translate("MainWindow", "Contrase\303\261a", nullptr));
        et_cumple->setText(QCoreApplication::translate("MainWindow", "Cumple", nullptr));
        boton_registro->setText(QCoreApplication::translate("MainWindow", "Registrar", nullptr));
        error_user->setText(QString());
        error_correo->setText(QString());
        error_pass->setText(QString());
        error_edad->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
