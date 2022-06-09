#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTableWidget>
#include<vector>
#include"MyPos.h"
#include"Mask.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Apply_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_pushButton_Calculate_clicked();
    void keepGoingUntilFindIt();

private:
    Ui::MainWindow *ui;
    static inline std::vector<MyPos> mvec;
    Mask *myMask;
    int valueCounter = 2;
    bool isFinishChange = true;





};
#endif // MAINWINDOW_H
