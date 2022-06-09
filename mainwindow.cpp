#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<vector>
#include"MyPos.h"
#include"Mask.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);



}

MainWindow::~MainWindow()
{
    delete ui;
}
//row vertical  witfh
//column horizntal heigh

void MainWindow::on_pushButton_Apply_clicked()
{
    ui->tableWidget->setRowCount(ui->lineEditRow->text().toInt());
    ui->tableWidget->setColumnCount(ui->lineEditColumn->text().toInt());
    for (auto row = 0 ; row < ui->tableWidget->rowCount() ; row++ ) {
        for (auto column = 0 ; column < ui->tableWidget->columnCount() ; column++ ) {
            ui->tableWidget->setItem(row, column, new QTableWidgetItem);
            ui->tableWidget->item(row,column)->setBackground(QBrush(Qt::black));
            ui->tableWidget->item(row,column)->setText("0");
            ui->tableWidget->item(row,column)->setTextColor((Qt::black));

        }
    }


}
//(ui->tableWidget->columnCount() * (ui->tableWidget->rowCount() - 1 - row)) +(ui->tableWidget->columnCount() - 1 - column))
void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    ui->tableWidget->item(row,column)->setBackground(QBrush(Qt::white));
    ui->tableWidget->item(row,column)->setTextColor((Qt::white));
    ui->tableWidget->item(row,column)->setText(QString::number(1));
    MyPos mp{row,column,"1"};
    mvec.push_back(mp);


}


void MainWindow::on_pushButton_Calculate_clicked()
{
    isFinishChange = true;
    while(isFinishChange)
    {
        Mask tempMask( *ui->tableWidget);
        myMask = &tempMask;
        myMask->maskProcess();
        keepGoingUntilFindIt();
    }


}
void MainWindow::keepGoingUntilFindIt(){
    int sameIndexCounter = 0;
    for(auto index = 0 ; index < mvec.size(); index++){
       if(ui->tableWidget->item(mvec.at(index).getPosRow(), mvec.at(index).getPosColumn())->text() == mvec.at(index).getData()){
           sameIndexCounter++;
       }
       if(sameIndexCounter == mvec.size() ){
           isFinishChange = false;
       }
       mvec.at(index).setData(ui->tableWidget->item(mvec.at(index).getPosRow(), mvec.at(index).getPosColumn())->text());
   }
}
