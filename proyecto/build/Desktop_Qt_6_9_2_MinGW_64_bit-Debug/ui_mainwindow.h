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
#include <QtGui/QIcon>
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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *MenuSup;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *boton_volver;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *boton_historial;
    QPushButton *B_MenuUsuario;
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
    QLabel *label_filtro;
    QDateEdit *dateEditFiltro;
    QTableView *tableViewHistorial;
    QLabel *Historial;
    QWidget *mapa;
    QVBoxLayout *verticalLayout;
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
    QLabel *enunciado;
    QRadioButton *answer1;
    QRadioButton *answer2;
    QRadioButton *answer3;
    QRadioButton *answer4;
    QPushButton *corregir;
    QWidget *lista_problemas;
    QListWidget *listWidget;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *barra_herramienta;
    QHBoxLayout *horizontalLayout_3;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QPushButton *limpiar;
    QSpinBox *grosor;
    QPushButton *color;
    QLabel *label_3;
    QPushButton *texto;
    QPushButton *linea;
    QPushButton *punto;
    QPushButton *goma;
    QLabel *label_2;
    QPushButton *Bcompas;
    QPushButton *Btransportador;
    QPushButton *Bregla;
    QGraphicsView *graphicsView;
    QLabel *labelStatus;
    QWidget *editar_perfil;
    QLabel *perfil;
    QLabel *nombre;
    QLabel *label_email;
    QLabel *label_contrasenia;
    QLabel *label_compleanios;
    QDateEdit *dateEdit;
    QPushButton *boton_guardar;
    QLabel *avatar;
    QPushButton *boton_editar_avatar;
    QLineEdit *labelNombre;
    QLineEdit *labelEmail;
    QLineEdit *labelContrasenia;
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
        MainWindow->resize(989, 774);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMaximumSize(QSize(78241, 16777215));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        MenuSup = new QWidget(centralwidget);
        MenuSup->setObjectName("MenuSup");
        horizontalLayout_4 = new QHBoxLayout(MenuSup);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        boton_volver = new QPushButton(MenuSup);
        boton_volver->setObjectName("boton_volver");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(boton_volver->sizePolicy().hasHeightForWidth());
        boton_volver->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(boton_volver);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        boton_historial = new QPushButton(MenuSup);
        boton_historial->setObjectName("boton_historial");
        sizePolicy1.setHeightForWidth(boton_historial->sizePolicy().hasHeightForWidth());
        boton_historial->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(boton_historial);

        B_MenuUsuario = new QPushButton(MenuSup);
        B_MenuUsuario->setObjectName("B_MenuUsuario");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(B_MenuUsuario->sizePolicy().hasHeightForWidth());
        B_MenuUsuario->setSizePolicy(sizePolicy2);
        B_MenuUsuario->setAutoDefault(false);

        horizontalLayout_4->addWidget(B_MenuUsuario);


        verticalLayout_2->addWidget(MenuSup);

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
        campo_user->setGeometry(QRect(70, 160, 281, 28));
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
        label_filtro = new QLabel(historial);
        label_filtro->setObjectName("label_filtro");
        label_filtro->setGeometry(QRect(480, 100, 121, 20));
        dateEditFiltro = new QDateEdit(historial);
        dateEditFiltro->setObjectName("dateEditFiltro");
        dateEditFiltro->setGeometry(QRect(620, 100, 110, 26));
        tableViewHistorial = new QTableView(historial);
        tableViewHistorial->setObjectName("tableViewHistorial");
        tableViewHistorial->setGeometry(QRect(190, 140, 541, 459));
        Historial = new QLabel(historial);
        Historial->setObjectName("Historial");
        Historial->setGeometry(QRect(60, 30, 321, 31));
        Historial->setFont(font);
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
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(boton_alet->sizePolicy().hasHeightForWidth());
        boton_alet->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(boton_alet, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        boton_lista = new QPushButton(menu_principal);
        boton_lista->setObjectName("boton_lista");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(boton_lista->sizePolicy().hasHeightForWidth());
        boton_lista->setSizePolicy(sizePolicy4);

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
        enunciado = new QLabel(problema);
        enunciado->setObjectName("enunciado");
        enunciado->setGeometry(QRect(20, 20, 301, 321));
        enunciado->setWordWrap(true);
        answer1 = new QRadioButton(problema);
        answer1->setObjectName("answer1");
        answer1->setGeometry(QRect(10, 370, 291, 24));
        answer2 = new QRadioButton(problema);
        answer2->setObjectName("answer2");
        answer2->setGeometry(QRect(10, 410, 291, 24));
        answer3 = new QRadioButton(problema);
        answer3->setObjectName("answer3");
        answer3->setGeometry(QRect(10, 450, 281, 24));
        answer4 = new QRadioButton(problema);
        answer4->setObjectName("answer4");
        answer4->setGeometry(QRect(10, 490, 291, 24));
        corregir = new QPushButton(problema);
        corregir->setObjectName("corregir");
        corregir->setGeometry(QRect(100, 560, 111, 41));
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
        listWidget->setGeometry(QRect(20, 30, 281, 371));
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
        barra_herramienta = new QWidget(widget_2);
        barra_herramienta->setObjectName("barra_herramienta");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(barra_herramienta->sizePolicy().hasHeightForWidth());
        barra_herramienta->setSizePolicy(sizePolicy5);
        barra_herramienta->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        barra_herramienta->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        barra_herramienta->setAutoFillBackground(false);
        horizontalLayout_3 = new QHBoxLayout(barra_herramienta);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(20, -1, 20, -1);
        horizontalSlider = new QSlider(barra_herramienta);
        horizontalSlider->setObjectName("horizontalSlider");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy6);
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        label_4 = new QLabel(barra_herramienta);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        limpiar = new QPushButton(barra_herramienta);
        limpiar->setObjectName("limpiar");
        sizePolicy3.setHeightForWidth(limpiar->sizePolicy().hasHeightForWidth());
        limpiar->setSizePolicy(sizePolicy3);
        limpiar->setMaximumSize(QSize(167, 167));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icons/I_eliminar.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        limpiar->setIcon(icon);
        limpiar->setIconSize(QSize(10, 16));

        horizontalLayout_3->addWidget(limpiar);

        grosor = new QSpinBox(barra_herramienta);
        grosor->setObjectName("grosor");
        sizePolicy6.setHeightForWidth(grosor->sizePolicy().hasHeightForWidth());
        grosor->setSizePolicy(sizePolicy6);
        grosor->setMinimum(1);
        grosor->setMaximum(20);
        grosor->setValue(6);

        horizontalLayout_3->addWidget(grosor);

        color = new QPushButton(barra_herramienta);
        color->setObjectName("color");
        sizePolicy3.setHeightForWidth(color->sizePolicy().hasHeightForWidth());
        color->setSizePolicy(sizePolicy3);
        color->setMaximumSize(QSize(167, 167));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/icons/I_paleta.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        color->setIcon(icon1);
        color->setIconSize(QSize(10, 16));
        color->setAutoDefault(false);
        color->setFlat(false);

        horizontalLayout_3->addWidget(color);

        label_3 = new QLabel(barra_herramienta);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        texto = new QPushButton(barra_herramienta);
        texto->setObjectName("texto");
        sizePolicy6.setHeightForWidth(texto->sizePolicy().hasHeightForWidth());
        texto->setSizePolicy(sizePolicy6);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/icons/I_texto.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        texto->setIcon(icon2);
        texto->setIconSize(QSize(10, 16));

        horizontalLayout_3->addWidget(texto);

        linea = new QPushButton(barra_herramienta);
        linea->setObjectName("linea");
        sizePolicy3.setHeightForWidth(linea->sizePolicy().hasHeightForWidth());
        linea->setSizePolicy(sizePolicy3);
        linea->setMaximumSize(QSize(167, 167));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/icons/I_lapiz.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        linea->setIcon(icon3);
        linea->setIconSize(QSize(10, 16));
        linea->setCheckable(true);

        horizontalLayout_3->addWidget(linea);

        punto = new QPushButton(barra_herramienta);
        punto->setObjectName("punto");
        sizePolicy3.setHeightForWidth(punto->sizePolicy().hasHeightForWidth());
        punto->setSizePolicy(sizePolicy3);
        punto->setMinimumSize(QSize(0, 0));
        punto->setMaximumSize(QSize(167, 167));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/icons/punto.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        punto->setIcon(icon4);
        punto->setIconSize(QSize(8, 16));
        punto->setCheckable(true);

        horizontalLayout_3->addWidget(punto);

        goma = new QPushButton(barra_herramienta);
        goma->setObjectName("goma");
        sizePolicy3.setHeightForWidth(goma->sizePolicy().hasHeightForWidth());
        goma->setSizePolicy(sizePolicy3);
        goma->setMaximumSize(QSize(167, 167));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/icons/I_goma.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        goma->setIcon(icon5);
        goma->setIconSize(QSize(10, 16));

        horizontalLayout_3->addWidget(goma);

        label_2 = new QLabel(barra_herramienta);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        Bcompas = new QPushButton(barra_herramienta);
        Bcompas->setObjectName("Bcompas");
        Bcompas->setEnabled(true);
        sizePolicy3.setHeightForWidth(Bcompas->sizePolicy().hasHeightForWidth());
        Bcompas->setSizePolicy(sizePolicy3);
        Bcompas->setMaximumSize(QSize(167, 167));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/icons/I_compas.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Bcompas->setIcon(icon6);
        Bcompas->setIconSize(QSize(10, 16));
        Bcompas->setCheckable(true);

        horizontalLayout_3->addWidget(Bcompas);

        Btransportador = new QPushButton(barra_herramienta);
        Btransportador->setObjectName("Btransportador");
        sizePolicy3.setHeightForWidth(Btransportador->sizePolicy().hasHeightForWidth());
        Btransportador->setSizePolicy(sizePolicy3);
        Btransportador->setMaximumSize(QSize(167, 167));
        QFont font2;
        font2.setBold(false);
        font2.setKerning(true);
        Btransportador->setFont(font2);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/icons/I_transportador.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Btransportador->setIcon(icon7);
        Btransportador->setIconSize(QSize(10, 16));
        Btransportador->setCheckable(true);

        horizontalLayout_3->addWidget(Btransportador);

        Bregla = new QPushButton(barra_herramienta);
        Bregla->setObjectName("Bregla");
        sizePolicy3.setHeightForWidth(Bregla->sizePolicy().hasHeightForWidth());
        Bregla->setSizePolicy(sizePolicy3);
        Bregla->setMaximumSize(QSize(167, 167));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/icons/I_regla.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Bregla->setIcon(icon8);
        Bregla->setIconSize(QSize(10, 16));
        Bregla->setCheckable(true);

        horizontalLayout_3->addWidget(Bregla);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 1);
        horizontalLayout_3->setStretch(5, 1);
        horizontalLayout_3->setStretch(6, 1);
        horizontalLayout_3->setStretch(7, 1);
        horizontalLayout_3->setStretch(8, 1);
        horizontalLayout_3->setStretch(9, 1);
        horizontalLayout_3->setStretch(10, 1);
        horizontalLayout_3->setStretch(11, 1);
        horizontalLayout_3->setStretch(12, 1);
        horizontalLayout_3->setStretch(13, 1);

        horizontalLayout->addWidget(barra_herramienta);

        horizontalLayout->setStretch(0, 3);

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

        verticalLayout->setStretch(0, 15);
        stackedWidget->addWidget(mapa);
        editar_perfil = new QWidget();
        editar_perfil->setObjectName("editar_perfil");
        perfil = new QLabel(editar_perfil);
        perfil->setObjectName("perfil");
        perfil->setGeometry(QRect(10, 10, 321, 31));
        perfil->setFont(font);
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
        dateEdit = new QDateEdit(editar_perfil);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(100, 420, 110, 26));
        boton_guardar = new QPushButton(editar_perfil);
        boton_guardar->setObjectName("boton_guardar");
        boton_guardar->setGeometry(QRect(340, 470, 111, 71));
        avatar = new QLabel(editar_perfil);
        avatar->setObjectName("avatar");
        avatar->setGeometry(QRect(500, 160, 181, 171));
        avatar->setPixmap(QPixmap(QString::fromUtf8(":/img/icons/I_avatar.png")));
        avatar->setScaledContents(true);
        boton_editar_avatar = new QPushButton(editar_perfil);
        boton_editar_avatar->setObjectName("boton_editar_avatar");
        boton_editar_avatar->setGeometry(QRect(550, 340, 93, 29));
        boton_editar_avatar->setIcon(icon3);
        labelNombre = new QLineEdit(editar_perfil);
        labelNombre->setObjectName("labelNombre");
        labelNombre->setGeometry(QRect(100, 170, 113, 26));
        labelEmail = new QLineEdit(editar_perfil);
        labelEmail->setObjectName("labelEmail");
        labelEmail->setGeometry(QRect(100, 250, 221, 26));
        labelContrasenia = new QLineEdit(editar_perfil);
        labelContrasenia->setObjectName("labelContrasenia");
        labelContrasenia->setGeometry(QRect(100, 330, 171, 26));
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
        menubar->setGeometry(QRect(0, 0, 989, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        stackedWidget_2->setCurrentIndex(0);
        color->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        boton_volver->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        boton_historial->setText(QCoreApplication::translate("MainWindow", "Historial", nullptr));
        B_MenuUsuario->setText(QCoreApplication::translate("MainWindow", "perfil", nullptr));
        et_ini->setText(QCoreApplication::translate("MainWindow", "INICIAR SESI\303\223N", nullptr));
        et_user->setText(QCoreApplication::translate("MainWindow", "Usuario", nullptr));
        et_pass->setText(QCoreApplication::translate("MainWindow", "Contrase\303\261a", nullptr));
        et__nocuenta->setText(QCoreApplication::translate("MainWindow", "No tienes cuenta?", nullptr));
        link_registro->setText(QCoreApplication::translate("MainWindow", "<a href=\"#\">Reg\303\255strate</a>\n"
"<html><head/><body><p><br/></p></body></html>", nullptr));
        boton_entrar->setText(QCoreApplication::translate("MainWindow", "Entrar", nullptr));
        label_filtro->setText(QCoreApplication::translate("MainWindow", "Filtar por fecha", nullptr));
        Historial->setText(QCoreApplication::translate("MainWindow", "Historial", nullptr));
        boton_alet->setText(QCoreApplication::translate("MainWindow", "Problema aleatorio", nullptr));
        boton_lista->setText(QCoreApplication::translate("MainWindow", "Lista problemas", nullptr));
        enunciado->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        answer1->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        answer2->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        answer3->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        answer4->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        corregir->setText(QCoreApplication::translate("MainWindow", "Corregir", nullptr));

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

        label_4->setText(QCoreApplication::translate("MainWindow", "|", nullptr));
        limpiar->setText(QString());
        color->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "|", nullptr));
        texto->setText(QString());
        linea->setText(QString());
        punto->setText(QString());
        goma->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "|", nullptr));
        Bcompas->setText(QString());
        Btransportador->setText(QString());
        Bregla->setText(QString());
        labelStatus->setText(QCoreApplication::translate("MainWindow", "labelStatus", nullptr));
        perfil->setText(QCoreApplication::translate("MainWindow", "Modificar Perfil", nullptr));
        nombre->setText(QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        label_email->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_contrasenia->setText(QCoreApplication::translate("MainWindow", "Contrase\303\261a", nullptr));
        label_compleanios->setText(QCoreApplication::translate("MainWindow", "Cumplea\303\261os", nullptr));
        boton_guardar->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        avatar->setText(QString());
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
