#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>  // Seriye bağlı portlar hakkında bilgi almak için
#include <QMessageBox>      // Hata mesajı göstermek için

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);  // QSerialPort'u bir parent'e bağlamak iyi bir uygulamadır
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::read_serial);

    // Mevcut portları listelemek için buton tıklama işlemi
    on_refreshBut_clicked();
}

MainWindow::~MainWindow()
{
    if (serial->isOpen()) {
        serial->close();  // Program kapatıldığında portu kapat
    }
    delete ui;
}

void MainWindow::read_serial()
{
    while (serial->canReadLine()) {  // Veri varsa satır satır oku
        QByteArray data = serial->readLine();  // Satır bazında veri okuma
        QString strData = QString::fromUtf8(data).trimmed();  // Gelen veriyi string'e çevir ve boşlukları kaldır

        if (!strData.isEmpty()) {
            ui->plainTextEdit->appendPlainText("Gelen ses şiddeti: " + strData + " dB");
        } else {
            ui->plainTextEdit->appendPlainText("Veri alınamadı: " + QString::number(data.size()));
        }
    }
}

// refreshBut butonuna tıklandığında kullanılabilir portları listelemek
void MainWindow::on_refreshBut_clicked()
{
    // Önce comboBox'taki eski portları temizle
    ui->comboBox_Ports->clear();

    // Mevcut portları al ve comboBox'a ekle
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->comboBox_Ports->addItem(info.portName());  // Port ismini comboBox'a ekle
    }
}

// setPortsBut butonuna tıklandığında port ve baud rate ayarı yapma
void MainWindow::on_setPortsBut_clicked()
{
    QString selectedPort = ui->comboBox_Ports->currentText();
    int selectedBaudRate = ui->comboBox_baudRate->currentText().toInt();

    // Seri portu kapat, ayarları yap ve tekrar aç
    if (serial->isOpen()) {
        serial->close();
    }

    serial->setPortName(selectedPort);
    serial->setBaudRate(selectedBaudRate);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    // Portu okuma/yazma modunda aç
    if (!serial->open(QIODevice::ReadWrite)) {
        ui->plainTextEdit->appendPlainText("Port açılamadı: " + serial->errorString());
        QMessageBox::warning(this, "Port Hatası", "Seri port açılamadı!");
    } else {
        ui->plainTextEdit->appendPlainText("Port başarıyla açıldı: " + selectedPort);
    }
}
