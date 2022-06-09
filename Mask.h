#ifndef MASK_H
#define MASK_H
#include<QTableWidget>
#include<QTableWidgetItem>
#include<vector>
#include "MyPos.h"
#include <QMainWindow>
class Mask: public QObject{

public:

    Mask(QTableWidget &table );
    void print(int row,int column);
    void maskProcess();
    void maskVerification(int, int);
    bool isMaskSameValue(int, int);
    void writeTableItem(int, int, int);
    void masksEdge(int, int, int, int);
    bool isEdgeEmpty(int,int );
public slots:
    void MyFunc();

private:
    std::vector<MyPos> tempVec;
     QTableWidget *mTable;;
    int mMaxColumn;
    int mMaxRow;
    char clickedCell = '1';
    char notClickedCell = '0';
    int peaceCount = 2;
    int howManyEdgeEmpty = 0;
    int memoryCellValue = 0;
    bool isOneCount = false;


};

#endif // MASK_H
