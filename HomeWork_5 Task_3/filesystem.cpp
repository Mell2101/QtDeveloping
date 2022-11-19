#include "filesystem.h"

FileSystem::FileSystem(QWidget* parent ) : QWidget(parent)
{
    _path_0 = QDir::homePath();
    _searchLine = new QLineEdit(this);
    _table = new QTableView(this); 
    _model = new QFileSystemModel(this);



    _model->setRootPath(QDir::rootPath());
    _model->setReadOnly(false);

    _table->setModel(_model);
    _table->setRootIndex(_model->index(QDir::homePath()));

    _grid = new QGridLayout(this);

    _grid->addWidget(_searchLine, 0, 0, 1, 6);
    _grid->addWidget(_table,1, 0, 4, 6 );
    _grid->addWidget(_creatButton("Open File"), 5, 5, 1, 1);
    _grid->addWidget(_creatButton("Back"), 5, 4, 1, 1);

    setLayout(_grid);

}


void FileSystem::slotPushButtonClicked()
{

    QString buttonName = ((QPushButton*)sender())->text();

    if(buttonName == "Open File")
    {

        QString path_1 = "/" + _table->currentIndex().data().toString();
        _list.append(path_1);

        _searchLine->setText(_path_0 += _list[_i]);

        _table->setRootIndex(_model->index(_path_0));
        _table->setModel(_model);
        ++_i;

    }

    if(buttonName == "Back")
    {
        if(_list.empty()) return;
        if( _i == 0)
        {
            _searchLine->setText( _path_0.remove(_list[_i]));
            return;
        }
        --_i;
        _searchLine->setText( _path_0.remove(_list[_i]));
        _list.pop_back();

        _table->setRootIndex(_model->index(_path_0));
        _table->setModel(_model);

    }


}

QPushButton *FileSystem::_creatButton(const QString &name)
{
    QPushButton* buttonOne = new QPushButton(name,this);
    connect(buttonOne, &QPushButton::clicked, this, &FileSystem::slotPushButtonClicked);
    return buttonOne;
}
