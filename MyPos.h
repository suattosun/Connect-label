#ifndef MYPOS_H
#define MYPOS_H
#include<QDebug>
class MyPos{
public:
    MyPos(int _row,int _column,QString _data):m_row{_row}, m_column{_column}, m_data{_data}{

    }
    void print(){
        qDebug()<<m_row << "-" << m_column << "\n";
    }
    int getPosRow(){
        return m_row;
    }
    int getPosColumn(){
        return m_column;
    }
   QString getData(){
        return m_data;

    }

    void setData(QString _data){
        m_data = _data;
    }


private:
    int m_row;
    int m_column;
    QString m_data;
};

#endif // MYPOS_H
