#ifndef EDITABLESQLMODEL_H
#define EDITABLESQLMODEL_H

#include <QSqlQueryModel>

class EditableSqlModel : public QSqlQueryModel
{
    Q_OBJECT

public:
    EditableSqlModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    QSqlDatabase    db;
    QString         dbHost,
                    dbName,
                    dbUser,
                    dbPass;
    qint32          dbPort;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
private:
    bool setFirstName(int personId, const QString &firstName);
    bool setMiddleInitial(int personId, const QString &middleInitial);
    bool setLastName(int personId, const QString &lastName);
    bool setEmailAddress(int personId, const QString &emailAddress);
    bool setEmailDomain(int personId, const QString &emailDomain);
    bool setIsMember(int personId, const QString &isMember);

    void refresh();
};

#endif
