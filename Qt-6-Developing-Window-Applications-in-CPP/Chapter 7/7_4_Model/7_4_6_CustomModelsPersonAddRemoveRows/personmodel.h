#pragma once

#include <QAbstractListModel>
#include "person.h"

class PersonModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PersonModel(QObject *parent = nullptr);
    ~PersonModel() override;
    void addPerson( Person *person);
    void addPerson();
    void addPerson(const QString & names,const int & age);
    void removePerson(QModelIndex index);

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    //Change the data in the model
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    //Control data in the horizontal and vertical headers
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    //Flags the model as editable
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    bool insertRows(int row, int count, const QModelIndex &parent) override;
    bool removeRows(int row, int count, const QModelIndex &parent) override;

signals:

public slots:
private:
    QList<Person * > persons;
};

