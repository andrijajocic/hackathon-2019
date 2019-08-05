#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg *bmp *.gif)"));
    if (QString::compare(filename, QString()) != 0)
    {
        QImage image;
        bool valid = image.load(filename);
        if (valid)
        {
            //image = image.scaled(ui->lbl_image->width(), ui->lbl_image->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->lbl_image->setPixmap(QPixmap::fromImage(image.scaled(ui->lbl_image->width(), ui->lbl_image->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation)));
        }
        else {
            // Error Handling
        }
    }
}
