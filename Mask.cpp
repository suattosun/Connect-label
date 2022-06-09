#include"Mask.h"
#include<vector>
#include"MyPos.h"
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QDebug>
#include"mainwindow.h"
Mask::Mask(QTableWidget &table ): mTable{&table}, mMaxColumn{mTable->columnCount()}, mMaxRow{mTable->rowCount()} {

}
void Mask::print(int row, int column){

    qDebug()<<(mTable->item(row,column)->text() == clickedCell);
}
// merkezi değerimiz üzerinden gidecem merkezi
//r ve c  r deki 1 mi  birse r - 1 r+1 de ki birmi c -1 c+1 deki birmi onlara aynı sayıyı ver
void Mask::maskProcess(){
    for(auto rowIndex = 0; rowIndex < mMaxRow ; rowIndex++){
         for(auto columnIndex = 0; columnIndex < mMaxColumn ; columnIndex++){
            maskVerification(rowIndex, columnIndex);
         }
     }
}

void Mask::maskVerification(int row, int column){
    howManyEdgeEmpty = 0;
    memoryCellValue = peaceCount;
    if(row > 0)
        masksEdge(row, column, row - 1,column);
    if(column > 0)
        masksEdge(row, column, row ,column - 1);
    if(column < mMaxColumn - 1)
        masksEdge(row, column, row ,column + 1);
    if(row < mMaxRow - 1)
        masksEdge(row, column, row + 1,column);


}
bool Mask::isMaskSameValue(int _row, int _column){
       if(mTable->item(_row, _column)->text() == notClickedCell)
           return false;
       return true;
}
void Mask::writeTableItem(int _row, int _column, int _peaceNumber){
    mTable->item(_row, _column)->setText(QString::number(_peaceNumber));
    mTable->item(_row, _column)->setBackgroundColor(QColor((Qt::GlobalColor) _peaceNumber));
   // mTable->item(_row, _column)->setTextColor(QColor((Qt::GlobalColor) _peaceNumber));

}
void Mask::masksEdge(int _row, int _column, int edgeRow, int edgeColumn){
    if(isMaskSameValue(_row, _column) && isMaskSameValue(edgeRow, edgeColumn)){
        if(memoryCellValue < mTable->item(edgeRow,edgeColumn)->text().toInt() )
            memoryCellValue =  mTable->item(edgeRow,edgeColumn)->text().toInt();
        writeTableItem(_row, _column,memoryCellValue);
        isOneCount = true;
    }

    else if(isMaskSameValue(_row, _column) && !isMaskSameValue(edgeRow, edgeColumn)){
       howManyEdgeEmpty++;
       isOneCount = true;
       if(isEdgeEmpty(howManyEdgeEmpty , 4))
       {
         writeTableItem(_row, _column, peaceCount);
       }

    }
   else if(!isMaskSameValue(_row, _column) && !isMaskSameValue(edgeRow, edgeColumn) && isOneCount){
        howManyEdgeEmpty++;
        isEdgeEmpty(howManyEdgeEmpty , 1 );
    }
}
bool Mask::isEdgeEmpty(int _howManyEdgeEmpty, int edgeCount){
    if(_howManyEdgeEmpty == edgeCount && isOneCount){
        peaceCount++;
        isOneCount = false;
        return true;
    }
    return false;
}
