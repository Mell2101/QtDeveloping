#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QTableView>
#include <QWidget>
#include <QDir>
#include <QPushButton>
#include <QFileSystemModel>
#include <QLineEdit>
#include <QGridLayout>
#include <QMouseEvent>


class FileSystem : public QWidget
{
    Q_OBJECT
public:
    explicit FileSystem(QWidget* parent = nullptr);


private slots:
    void slotPushButtonClicked();
private:
    QStringList _list;
    int _i = 0;
    QString _path_0;

    //QDir* _dir;
    QFileSystemModel* _model;
    QLineEdit* _searchLine;
    QGridLayout* _grid;
    QPushButton* _creatButton(const QString& name);
    QTableView* _table;


};

#endif // FILESYSTEM_H
